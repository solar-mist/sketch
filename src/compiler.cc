#include <compiler.hh>
#include <lexing/lexer.hh>
#include <diagnostics.hh>
#include <sstream>
#include <iostream>


Compiler::Compiler(OutputType outputType, const std::string& inputFileName)
    :_outputType(outputType), _inputFileName(inputFileName)
{
    _inputHandle = std::ifstream(inputFileName);
    if(!_inputHandle.is_open())
        Diagnostics::FatalError("viper", inputFileName + ": No such file or directory");
    Diagnostics::setFileName(inputFileName);
    
    std::stringstream buf;
    buf << _inputHandle.rdbuf();
    _contents = buf.str();

    _inputHandle.close();
}

void Compiler::Compile()
{
    Lexing::Lexer lexer(_contents);
    for(Lexing::Token& token : lexer.Lex())
        std::cout << token << std::endl;
}