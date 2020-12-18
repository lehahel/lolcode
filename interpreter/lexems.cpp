#include "lexems.h"
#include <typeinfo>

////////////////////////////////////////////////////////////////////////////

LolObject &CVariablesManager::get(const std::string &name) {
    if (locals.count(name)) {
        return *(locals[name]);
    }
    return *(globals[name]);
}

void CVariablesManager::set(const std::string &name, const LolObject &object) {
    if(!locals.count(name) && globals.count(name)) {
        *(globals[name]) = object;
    } else {
        *(locals[name]) = object;
    }
}

CVariablesManager CVariablesManager::branch() const {
    CVariablesManager new_manager;
    new_manager.globals = locals;
    for (auto var : globals) {
        if (!new_manager.globals.count(var.first)) {
            new_manager.globals[var.first] = var.second;
        }
    }
    return new_manager;
}

////////////////////////////////////////////////////////////////////////////

CCodeblockManager::CCodeblockManager(const CVariablesManager &vars)
  : blocks() {
    variables = vars;
}

void CCodeblockManager::add_block(CCodeBlock &block) {
    blocks.emplace_back(&block);
}

void CCodeblockManager::exec() {
    for (size_t i = 0; i < blocks.size(); ++i) {
        CExpression *expr = dynamic_cast<CExpression *>(blocks[i]);
        if (expr != nullptr) {
            expr->exec();
            continue;
        }
        CIfBlock *ifbl = dynamic_cast<CIfBlock *>(blocks[i]);
        if (ifbl != nullptr) {
            ifbl->exec();
            continue;
        }
        CLoopBlock *loop = dynamic_cast<CLoopBlock *>(blocks[i]);
        if (loop != nullptr) {
            loop->exec();
            continue;
        }
    }
}

LolObject CCodeblockManager::get_var(const std::string &name) {
    variables.get(name);
}

void CCodeblockManager::set_var(const std::string &name, LolObject object) {
    variables.set(name, object);
}

////////////////////////////////////////////////////////////////////////////

CExpression::CExpression(
    ExprType type,
    CExpression *left,
    CExpression *right,
    const CVariablesManager &vars)
  : value (    ),
    type  (type),
    left  (left), 
    right (right),
    variables(vars.branch()) {}

CExpression::CExpression(LolObject object, const CVariablesManager &vars)
  : type(ExprType::TERMINAL),
    value(object),
    left(nullptr),
    right(nullptr),
    variables(vars.branch()) {}

CExpression::CExpression(const std::string &varname, const CVariablesManager &vars) 
  : type(ExprType::VARIABLE),
    left(nullptr),
    right(nullptr),
    varname(varname),
    value(),
    variables(vars.branch()) {}

LolObject CExpression::eval() {
    if (type == ExprType::ASSIGNMENT) {
        if (left->type != ExprType::VARIABLE) {
            return LolObject();
        }
        variables.set(left->varname, right->eval());
        return variables.get(left->varname);
    }
    if (type == ExprType::TERMINAL) {
        return value;
    }
    if (type == ExprType::VARIABLE) {
        return variables.get(varname);
    }
    if (type == ExprType::ADD) {
        return left->eval() + right->eval();
    }
    if (type == ExprType::SUB) {
        return left->eval() - right->eval();
    }
    if (type == ExprType::MUL) {
        return left->eval() * right->eval();
    }
    if (type == ExprType::DIV) {
        return left->eval() / right->eval();
    }
    if (type == ExprType::MOD) {
        return left->eval() % right->eval();
    }
    if (type == ExprType::AND) {
        return LolObject(left->eval() && right->eval());
    }
    if (type == ExprType::OR ) {
        return LolObject(left->eval() || right->eval());
    }
    return LolObject();
}

void CExpression::exec() {
    eval();
}

LolObject CExpression::get_val() {
    return eval();
}

CExpression::~CExpression() {
    delete[] left;
    delete[] right;
}

////////////////////////////////////////////////////////////////////////////

CIfBlock::CIfBlock(CExpression &expr,
             CCodeblockManager &true_code,
             CCodeblockManager &false_code,
             const CVariablesManager &vars)
  : statement(expr),
    true_manager(true_code),
    false_manager(false_code),
    variables(vars.branch()) {}

void CIfBlock::exec() {
    if (statement.get_val()) {
        true_manager.exec();
    } else {
        false_manager.exec();
    }
}

CLoopBlock::CLoopBlock(const std::string &block_name,
                       LoopOperator op,
                       LoopType tp,
                       std::string varname,
                       CExpression expr,
                       CCodeblockManager &code,
                       const CVariablesManager &vars)
  : name(block_name),
    statement(expr),
    oper(op),
    type(tp),
    variables(vars.branch()),
    manager(code),
    var(varname) {}

void CLoopBlock::exec() {
    if (type == LoopType::WHILE) {
        while (statement.get_val()) {
            manager.exec();
            if (oper == LoopOperator::INC) {
                variables.set(var, ++variables.get(var));
            } else {
                variables.set(var, --variables.get(var));
            }
        }
    } else {
        while (!statement.get_val()) {
            manager.exec();
            if (oper == LoopOperator::INC) {
                variables.set(var, ++variables.get(var));
            } else {
                variables.set(var, --variables.get(var));
            }
        }
    }
}