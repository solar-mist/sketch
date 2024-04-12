// Copyright 2024 solar-mist

#ifndef VIPER_FRAMEWORK_PARSER_AST_AST_NODE_H
#define VIPER_FRAMEWORK_PARSER_AST_AST_NODE_H 1

#include <vipir/IR/IRBuilder.h>

#include <memory>

namespace parser
{
    class ASTNode
    {
    public:
        ASTNode() { }
        virtual ~ASTNode() { }

        virtual vipir::Value* emit(vipir::IRBuilder& builder, vipir::Module& module) = 0;
    };
    using ASTNodePtr = std::unique_ptr<ASTNode>;
}

#endif // VIPER_FRAMEWORK_PARSER_AST_AST_NODE_H