#include <cassert>
#include <iostream>
#include <fstream>
#include <exception>
#include "ArgvProcess.hpp"
#include "AST.hpp"
#include "CodeGenerator.hpp"


using namespace std;

extern int yyparse(shared_ptr<BaseAST> &ast);

int main(int argc, const char* argv[]){
    // 处理输入 - argc:输入个数 - argv:输入内容
    // argv[0] = "./complier"
    if(argc == 1){
        // 缺少必要的输入
        std::cout<<"Necessary input is missing!"<<std::endl;
        return 0;
    }
    // output file name
    std::string InputFile;
    std::string OutputFile;
    ArgvProcess ArgvProcess(argc,argv);
    // input file
    if(!ArgvProcess.findName("i",InputFile)||InputFile.length()==0){
        std::cout<<"no input file"<<std::endl;
        return 0;
    }
    freopen(InputFile.c_str(),"r",stdin);

    // output file
    if(!ArgvProcess.findName("o",OutputFile)||OutputFile.length()==0){
        OutputFile = "a.o";
    }
    // else if(OutputFile.length()<=2 || OutputFile.substr(OutputFile.length()-2)!=".o"){
    //     OutputFile = OutputFile + ".o";
    // }

    shared_ptr<BaseAST> ast;
    auto ret  = yyparse(ast);
    assert(!ret);
    // ast->print(0);

    CodeGenerator program("test");
    shared_ptr<CompUnit> program_ast(reinterpret_pointer_cast<CompUnit>(ast));
    program.ProgramGen(program_ast,OutputFile);

}