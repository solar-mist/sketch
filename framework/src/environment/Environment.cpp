// Copyright 2023 solar-mist


#include "environment/Environment.h"

#include <iostream>

vipir::AllocaInst* Environment::findVariable(const std::string& name)
{
    Environment* environment = this;
    while (environment)
    {
        if (environment->variables.find(name) != environment->variables.end())
        {
            return environment->variables.at(name);
        }

        environment = environment->parent;
    }
    std::cerr << "Unknown local symbol: " << name << "\n";
    std::exit(1);
}

std::unordered_map<std::string, vipir::Function*> functions;