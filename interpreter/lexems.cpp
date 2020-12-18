#include "lexems.h"

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

CExpression::CExpression(
    ExprType type,
    CExpression *left,
    CExpression *right)
  : value (    ),
    type  (type),
    left  (left), 
    right (right) {};

CExpression::CExpression(LolObject object)
  : type  (ExprType::TERMINAL),
    left  (nullptr),
    right (nullptr),
    value (object) {};

CExpression::CExpression(const std::string &varname) 
  : type(ExprType::VARIABLE),
    left(nullptr),
    right(nullptr),
    varname(varname),
    value() {};

LolObject CExpression::eval() {
    if (type == ExprType::TERMINAL) {
        return value;
    }
    if (type == ExprType::VARIABLE) {

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
}

CExpression::~CExpression() {
    delete[] left;
    delete[] right;
}
