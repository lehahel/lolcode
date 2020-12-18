#pragma once

#include "lolobject.h"
#include <vector>
#include <map>

class CVariablesManager {
public:
    CVariablesManager() = default;
    LolObject &get(const std::string &name);
    void set(const std::string &name, const LolObject &object);
    CVariablesManager branch() const;

private:
    std::map<std::string, LolObject *> locals;
    std::map<std::string, LolObject *> globals;
};


////////////////////////////////////////////////////////////////////////////

class CCodeBlock {
public:
    virtual void exec() = 0;
};

////////////////////////////////////////////////////////////////////////////

class CCodeblockManager {
public:
    CCodeblockManager();
    CCodeblockManager(const CVariablesManager &vars);
    void add_block(const CCodeBlock &block);
    void exec();
    LolObject get_var(const std::string &name);
    void set_var(const std::string &name, LolObject object);

private:
    std::vector<CCodeBlock *> blocks;
    CVariablesManager variables;
};

////////////////////////////////////////////////////////////////////////////

enum class ExprType {
    TERMINAL, VARIABLE,
    ADD, SUB, MUL, DIV, MOD,
    AND, OR
};

class CExpression : public CCodeBlock {
public:
    CExpression(LolObject object);
    CExpression(const std::string &varname);
    CExpression(ExprType type,
                CExpression *left,
                CExpression *right
                );
    ~CExpression();
    void exec() override;

private:
    LolObject eval();
    LolObject   value;
    std::string varname;
    ExprType    type;
    CExpression *left;
    CExpression *right;    
};

////////////////////////////////////////////////////////////////////////////

class CAssignment : CCodeBlock {
public:
    CAssignment() = delete;
    CAssignment(LolObject lval, CExpression rval);
    void exec() override;

private:
    LolObject lval;
    CExpression rval;
};

////////////////////////////////////////////////////////////////////////////

class CIfBlock : public CCodeBlock {
public:
    CIfBlock() = delete;
    CIfBlock(CExpression &expr,
             CCodeblockManager &true_code,
             CCodeblockManager &false_code,
             const CVariablesManager &vars);

private:
    CExpression statement;
    CCodeblockManager true_manager;
    CCodeblockManager false_manager;
};

////////////////////////////////////////////////////////////////////////////

enum class LoopOperator { INC,   DEC };
enum class LoopType     { WHILE, TILL };

class CLoopBlock : public CCodeBlock {
public:
    CLoopBlock() = delete;
    CLoopBlock(const std::string &block_name,
               LoopOperator op,
               CExpression expr,
               CCodeblockManager &code,
               const CVariablesManager &vars);

private:
    CExpression statement;
    CCodeblockManager manager;
    LoopOperator oper;
    LoopType type;
};

////////////////////////////////////////////////////////////////////////////
