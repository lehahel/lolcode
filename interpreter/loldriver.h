#pragma once

#include "lexems.h"
#include <vector>
#include <map>

class CDriver {
public:
    CDriver();
    void initialize(CCodeblockManager& code);
    void if_branch(CExpression &expr, CCodeblockManager& manager);
    void loop_branch(/* TODO */);
    CCodeblockManager &manager();
    void add_block(size_t location, const CCodeBlock &block);

private:
    std::map<size_t, CCodeblockManager> blocks;
    std::map<size_t, std::vector<size_t>> branches;
};