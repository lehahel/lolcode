#pragma once

#include "lexems.h"
#include <vector>
#include <map>

class CDriver {
public:
    CDriver() = default;
    CVariablesManager vars;
    // void initialize(CCodeblockManager& code);
    // void if_branch(CExpression &expr, CCodeblockManager& manager);
    // void loop_branch(/* TODO */);
    // void add_block(size_t location, CCodeBlock *block);

private:
    CCodeblockManager manager;  // TEMPORARY !!
    std::map<size_t, CCodeblockManager> blocks;
    std::map<size_t, std::vector<size_t>> branches;
};