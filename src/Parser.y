%code requires {
    #include <string>
    #include <iostream>
    #include <memory>
    #include <vector>
    #include "AST.hpp"
    using namespace std;

    int yylex();
    void yyerror(shared_ptr<BaseAST> &ast, const char *s);
}

%parse-param { shared_ptr<BaseAST> &ast }
%output "Parser.cpp"

%code{
    #include <string>
    #include <iostream>
    #include <memory>
    #include <vector>
    #include "AST.hpp"
    using namespace std;

    int yylex();
    void yyerror(shared_ptr<BaseAST> &ast, const char *s);
}

%union{
    int iVal;
    double dVal;
    char cVal;
    string *sVal;
    BaseAST *astVal;
}

%token  COMMA ELLIPSIS DOT SEMI ARROW QUES COLON
        LPAREN RPAREN LBRACKET RBRACKET LBRACE RBRACE
        EQ GE LE GT LT NE NOT ASSIGN
        AND BANDEQ BAND OR BOREQ BOR BXOR BXOREQ BNOT
        AADD ADDEQ ADD SSUB SUBEQ SUB 
        MULEQ MUL DIVEQ DIV MOD MODEQ
        STRUCT TYPEDEF CONST  RETURN
        IF ELSE FOR WHILE CONTINUE BREAK
        SWITCH CASE DEFAULT TRUE FALSE
        BOOL SHORT LONG INT FLOAT DOUBLE CHAR VOID SQUOTE DQUOTE
        PRINTF SCANF
        
%token<iVal>    INTERGER
%token<sVal>    IDENTIFIER
%token<sVal>  STRING
%token<dVal>    REAL
%token<cVal>    CHARACTER

// non-terminal type
%type <astVal> InitValWrap VarDeclWrap StructDecl FuncFParamsWrap FuncRParamsWrap FuncFParams FuncFParam ExpWrap FuncRParams LVal LOrExp LAndExp EqExp RelExp Cond AddExp MulExp PrimaryExp UnaryExp Exp FuncDef FuncType Block Stmt Decl CompUnit ConstDecl VarDecl BType ConstDef BlockItemWrap BlockItem VarDef Number InitVal ConstInitVal ConstInitValWrap UnaryOp

%%

CompUnit
    : FuncDef{
        auto func = new CompUnit();
        func->Name = "CompUnits";
        func->AST_type = COMPUNIT;
		func->CompUnits.push_back(shared_ptr<BaseAST>($1));
		ast = shared_ptr<CompUnit>(func);
		$$ = func;
    }
    | Decl {
		auto decl = new CompUnit();
		decl->Name = "CompUnits";
		decl->AST_type = COMPUNIT;
		decl->CompUnits.push_back(shared_ptr<BaseAST>($1));
		ast = shared_ptr<CompUnit>(decl);
		$$ = decl;
	}
    | CompUnit Decl {
		auto comp_unit = new CompUnit();
		comp_unit->Name = "CompUnits";
		comp_unit->AST_type = COMPUNIT;
		comp_unit->CompUnits = move(reinterpret_cast<CompUnit*>$1->CompUnits);
		comp_unit->CompUnits.push_back(shared_ptr<BaseAST>($2));
		ast = shared_ptr<CompUnit>(comp_unit);
		$$ = comp_unit;
	}
    | CompUnit FuncDef {
		auto comp_unit = new CompUnit();
		comp_unit->Name = "CompUnits";
		comp_unit->AST_type = COMPUNIT;
		comp_unit->CompUnits = move(reinterpret_cast<CompUnit*>$1->CompUnits);
		comp_unit->CompUnits.push_back(shared_ptr<BaseAST>($2));
		ast = shared_ptr<CompUnit>(comp_unit);
		$$ = comp_unit;
	} 
	;

Decl
	: ConstDecl { 
		$1->Name = "ConstDecl";
		$1->AST_type = DECL;
		$$ = $1; 
	} 
	| VarDecl { 
		$1->Name = "VarDecl"; 
		$1->AST_type = DECL;
		$$ = $1; 
	}
	| StructDecl {
		$1->Name = "StructDecl";
		$1->AST_type = DECL;
		$$ = $1;
	}
	; 

StructDecl
    : STRUCT IDENTIFIER LBRACE VarDeclWrap RBRACE SEMI {
        auto ast = new Decl();
        ast->Decl_type = Struct;
        ast->Struct_name = *shared_ptr<string>($2);
        ast->Member = move(reinterpret_cast<Decl*>$4->Member);
        $$ = ast;
    }
    | STRUCT IDENTIFIER IDENTIFIER ASSIGN InitVal SEMI {
        auto ast = new Decl();
        ast->Decl_type = Struct;
		ast->Struct_name = *shared_ptr<string>($2);
		auto var_ast = new Variable();
		var_ast->Var_name = *shared_ptr<string>($3);
		var_ast->Length = vector<shared_ptr<BaseAST>>();
		ast->Var = shared_ptr<BaseAST>(var_ast);
		ast->Exp = shared_ptr<BaseAST>($5);
		$$ = ast;
    }
    ;

VarDeclWrap
    : VarDecl {
        auto ast = new Decl();
		ast->Member.push_back(shared_ptr<BaseAST>($1));
		$$ = ast;
    }
    | VarDeclWrap VarDecl {
        auto ast = reinterpret_cast<Decl*>$1;
		ast->Member.push_back(shared_ptr<BaseAST>($2));
		$$ = ast;
    }
    ;

BType
    : INT {
        auto ast = new Decl();
		ast->Decl_type = Int;
		$$ = ast;
    }
    | DOUBLE {
        auto ast = new Decl();
		ast->Decl_type = Double;
		$$ = ast;
    }
    ;

// TODO: add rule for const value
ConstDecl
	: CONST BType ConstDef SEMI { }
	;

// const 数组
ConstDef
    : IDENTIFIER ExpWrap ASSIGN ConstInitVal { }
    ;

ConstInitVal
    : Exp { }
    | LBRACE RBRACE { }
    | LBRACE ConstInitVal RBRACE { }
    | LBRACE ConstInitVal ConstInitValWrap RBRACE { }
    ;

ConstInitValWrap
    : COMMA ConstInitVal { }
    | COMMA ConstInitVal ConstInitValWrap { }
    ;

VarDecl
    : VarDef SEMI {
        $$ = $1;
    }
    ;

// rule for const value
VarDef
    : INT IDENTIFIER {
        auto ast = new Decl();
		ast->Decl_type = Int;
		auto var_ast = new Variable();
		var_ast->Var_name = *shared_ptr<string>($2);
		var_ast->Length = vector<shared_ptr<BaseAST>>();
		ast->Var = shared_ptr<BaseAST>(var_ast);
		ast->Exp = nullptr;
		$$ = ast;
    }
    | INT IDENTIFIER ASSIGN InitVal {
        auto ast = new Decl();
		ast->Decl_type = Int;
		auto var_ast = new Variable();
		var_ast->Var_name = *shared_ptr<string>($2);
		var_ast->Length = vector<shared_ptr<BaseAST>>();
		ast->Var = shared_ptr<BaseAST>(var_ast);
		ast->Exp = shared_ptr<BaseAST>($4);
		$$ = ast;
    }
    | INT IDENTIFIER ExpWrap {
        auto ast = new Decl();
		ast->Decl_type = Int;
		auto var_ast = new Variable();
		var_ast->Var_name = *shared_ptr<string>($2);
		var_ast->Length = move(reinterpret_cast<Variable*>$3->Length);
		ast->Var = shared_ptr<BaseAST>(var_ast);
		ast->Exp = nullptr;
		$$ = ast;
    }
    | INT IDENTIFIER ExpWrap ASSIGN InitVal { }
    | DOUBLE IDENTIFIER {
        auto ast = new Decl();
		ast->Decl_type = Double;
		auto var_ast = new Variable();
		var_ast->Var_name = *shared_ptr<string>($2);
		var_ast->Length = vector<shared_ptr<BaseAST>>();
		ast->Var = shared_ptr<BaseAST>(var_ast);
		ast->Exp = nullptr;
		$$ = ast;
    }
    | DOUBLE IDENTIFIER ASSIGN InitVal {
        auto ast = new Decl();
		ast->Decl_type = Double;
		auto var_ast = new Variable();
		var_ast->Var_name = *shared_ptr<string>($2);
		var_ast->Length = vector<shared_ptr<BaseAST>>();
		ast->Var = shared_ptr<BaseAST>(var_ast);
		ast->Exp = shared_ptr<BaseAST>($4);
		$$ = ast;
    }
    | DOUBLE IDENTIFIER ExpWrap {
        auto ast = new Decl();
		ast->Decl_type = Double;
		auto var_ast = new Variable();
		var_ast->Var_name = *shared_ptr<string>($2);
		var_ast->Length = move(reinterpret_cast<Variable*>$3->Length);
		ast->Var = shared_ptr<BaseAST>(var_ast);
		ast->Exp = nullptr;
		$$ = ast;
    }
    | DOUBLE IDENTIFIER ExpWrap ASSIGN InitVal { }
    ;

// TODO: add rule for array init
InitVal
    : Exp {
        $$ = $1;
    }
    | LBRACE RBRACE { }
    | LBRACE InitVal RBRACE{
        $$ = $2;
    }
    | LBRACE InitVal InitValWrap RBRACE{
        auto ast = reinterpret_cast<ExpList*>$3;
		ast->AST_type = EXPLIST;
		ast->Exps.insert(ast->Exps.begin(), shared_ptr<BaseAST>($2));
		$$ = ast;
    }
    ;

InitValWrap
    : COMMA InitVal {
        auto ast = new ExpList();
		ast->Exps.push_back(shared_ptr<BaseAST>($2));
		$$ = ast;
    }
    | COMMA InitVal InitValWrap {
        auto ast = reinterpret_cast<ExpList*>$3;
		ast->Exps.insert(ast->Exps.begin(), shared_ptr<BaseAST>($2));
		$$ = ast;
    }
    ;

FuncDef
    : FuncType LPAREN RPAREN Block {
        auto ast = new Func();
		ast->Name = "FuncDef";
		ast->AST_type = FUNC;
		ast->Prototype = shared_ptr<BaseAST>($1);
		ast->Blocks = move(reinterpret_cast<Func*>$4->Blocks);
		$$ = ast;
    }
    | FuncType LPAREN FuncFParams RPAREN Block {
        auto ast = new Func();
		ast->Name = "FuncDef";
		ast->AST_type = FUNC;
		auto func_prototype = move(reinterpret_cast<FuncPrototype*>$1);
		func_prototype->Params = move(reinterpret_cast<FuncPrototype*>$3->Params);
		ast->Prototype = shared_ptr<BaseAST>(func_prototype);
		ast->Blocks = move(reinterpret_cast<Func*>$5->Blocks);
		$$ = ast;
    }
    ;

FuncType
    : INT IDENTIFIER {
        auto ast = new FuncPrototype();
		ast->AST_type = FUNCPROTO;
		ast->Func_name = *shared_ptr<string>($2);
		ast->Func_type = Int;
		$$ = ast;
    }
    | DOUBLE IDENTIFIER {
        auto ast = new FuncPrototype();
		ast->AST_type = FUNCPROTO;
		ast->Func_name = *shared_ptr<string>($2);
		ast->Func_type = Double;
		$$ = ast;
    }
    | VOID IDENTIFIER {
		auto ast = new FuncPrototype();
		ast->AST_type = FUNCPROTO;
		ast->Func_name = *shared_ptr<string>($2);
		ast->Func_type = Void;
		$$ = ast;
	}
    ;

FuncFParams
    : FuncFParam {
        $$ = $1;
    }
    | FuncFParam FuncFParamsWrap {
        auto ast = reinterpret_cast<FuncPrototype*>$2;
		ast->Params.insert(ast->Params.begin(), reinterpret_cast<FuncPrototype*>$1->Params[0]);
		$$ = ast;
    }
    ;

FuncFParamsWrap
    : COMMA FuncFParam {
        $$ = $2;
    }
    | COMMA FuncFParam FuncFParamsWrap {
        auto ast = reinterpret_cast<FuncPrototype*>$3;
		ast->Params.insert(ast->Params.begin(), reinterpret_cast<FuncPrototype*>$2->Params[0]);
		$$ = ast;
    }
    ;

FuncFParam
    : BType IDENTIFIER {
        auto ast = new FuncPrototype();
		auto decl = new Decl();
		decl->Decl_type = reinterpret_cast<Decl*>$1->Decl_type;
		auto var_ast = new Variable();
		var_ast->Var_name = *shared_ptr<string>($2);
		var_ast->Length = vector<shared_ptr<BaseAST>>();
		decl->Var = shared_ptr<BaseAST>(var_ast);
		decl->Exp = nullptr;
		ast->Params = vector<shared_ptr<BaseAST>>();
		ast->Params.push_back(shared_ptr<BaseAST>(decl));
		$$ = ast;
    }
    | BType IDENTIFIER LBRACKET RBRACKET {
        auto ast = new FuncPrototype();
		auto decl = new Decl();
		decl->Decl_type = reinterpret_cast<Decl*>$1->Decl_type;
		auto var_ast = new Variable();
		var_ast->Var_name = *shared_ptr<string>($2);
		var_ast->Length = vector<shared_ptr<BaseAST>>();
		auto fake_exp = new Exp();
		fake_exp->AST_type = EXP;
		fake_exp->Name = "fake";
		var_ast->Length.push_back(shared_ptr<BaseAST>(fake_exp));
		decl->Var = shared_ptr<BaseAST>(var_ast);
		decl->Exp = nullptr;
		ast->Params = vector<shared_ptr<BaseAST>>();
		ast->Params.push_back(shared_ptr<BaseAST>(decl));
		$$ = ast;
    }
    | BType IDENTIFIER LBRACKET RBRACKET ExpWrap { }
    ;

ExpWrap
    : LBRACKET Exp RBRACKET {
        auto ast = new Variable();
		ast->Length = vector<shared_ptr<BaseAST>>();
		ast->Length.push_back(shared_ptr<BaseAST>($2));
		$$ = ast;
    }
    | LBRACKET Exp RBRACKET ExpWrap {
        auto ast = reinterpret_cast<Variable*>$4;
		ast->Length.insert(ast->Length.begin(), shared_ptr<BaseAST>($2));
		$$ = move(ast);
    }
    ;

Block
    : LBRACE BlockItemWrap RBRACE {
        $$ = $2;
    }
    ;

BlockItemWrap
    : BlockItem {
        auto ast = new Func();
		ast->Blocks.push_back(shared_ptr<BaseAST>($1));
		$$ = ast;
    }
    | BlockItem BlockItemWrap {
        auto ast = reinterpret_cast<Func*>$2;
		ast->Blocks.insert(ast->Blocks.begin(), shared_ptr<BaseAST>($1));
		$$ = move(ast);
    }
    ;

BlockItem
    : Decl {
        $$ = $1;
    }
    | Stmt {
        $$ = $1;
    }
    ;

Stmt
    : LVal ASSIGN Exp SEMI {
        auto ast = new Stmt();
		ast->Name = "BinaryOpStmt";
		ast->AST_type = STMT;
		ast->Stmt_type = Assign;
		ast->LVal = shared_ptr<BaseAST>($1);
		ast->RVal = shared_ptr<BaseAST>($3);
		$$ = ast;
    }
    | PRINTF LPAREN STRING RPAREN SEMI {
        auto ast = new Stmt();
		ast->Name = "PrintfStmt";
		ast->AST_type = STMT;
		ast->Stmt_type = Printf;
		ast->IO = *shared_ptr<string>($3);
		ast->First_block = vector<shared_ptr<BaseAST>>();
		$$ = ast;
    }
    | PRINTF LPAREN STRING COMMA FuncRParams RPAREN SEMI {
        auto ast = new Stmt();
		ast->Name = "PrintfStmt";
		ast->AST_type = STMT;
		ast->Stmt_type = Printf;
		ast->IO = *shared_ptr<string>($3);
		ast->First_block = move(reinterpret_cast<FuncPrototype*>$5->Params);
		$$ = ast;
    }
    | SCANF LPAREN STRING COMMA FuncRParams RPAREN SEMI {
        auto ast = new Stmt();
		ast->Name = "ScanfStmt";
		ast->AST_type = STMT;
		ast->Stmt_type = Scanf;
		ast->IO = *shared_ptr<string>($3);
		ast->First_block = move(reinterpret_cast<FuncPrototype*>$5->Params);
		$$ = ast;
    }
    | Exp SEMI {
        auto ast = new Stmt();
		ast->Name = "ExpStmt";
		ast->AST_type = STMT;
		ast->Stmt_type = Expression;
		ast->RVal = shared_ptr<BaseAST>($1);
		$$ = ast;
    }
    | Block {
        $$ = $1;
    }
    | IF LPAREN Cond RPAREN Stmt {
        auto ast = new Stmt();
		ast->Name = "IfStmt";
		ast->AST_type = STMT;
		ast->Stmt_type = If;
		ast->Condition = shared_ptr<BaseAST>($3);
		ast->First_block = move(reinterpret_cast<Func*>$5->Blocks);
		ast->Second_block = vector<shared_ptr<BaseAST>>();
		$$ = ast;
    }
    | IF LPAREN Cond RPAREN Stmt ELSE Stmt {
        auto ast = new Stmt();
		ast->Name = "IfElseStmt";
		ast->AST_type = STMT;
		ast->Stmt_type = If;
		ast->Condition = shared_ptr<BaseAST>($3);
		ast->First_block = move(reinterpret_cast<Func*>$5->Blocks);
		ast->Second_block = move(reinterpret_cast<Func*>$7->Blocks);
		$$ = ast;
    }
    | WHILE LPAREN Cond RPAREN Stmt {
        auto ast = new Stmt();
		ast->Name = "WhileStmt";
		ast->AST_type = STMT;
		ast->Stmt_type = While;
		ast->Condition = shared_ptr<BaseAST>($3);
		ast->First_block = move(reinterpret_cast<Func*>$5->Blocks);
		$$ = ast;
    }
    | BREAK SEMI {
        auto ast = new Stmt();
		ast->Name = "BreakStmt";
		ast->AST_type = STMT;
		ast->Stmt_type = Break;
		ast->RVal = nullptr;
		$$ = ast;
    }
    | CONTINUE SEMI {
        auto ast = new Stmt();
		ast->Name = "ContinueStmt";
		ast->AST_type = STMT;
		ast->Stmt_type = Continue;
		ast->RVal = nullptr;
		$$ = ast;
    }
    | RETURN Exp SEMI {
        auto ast = new Stmt();
		ast->Name = "ReturnStmt";
		ast->AST_type = STMT;
		ast->Stmt_type = Return;
		ast->RVal = shared_ptr<BaseAST>($2);
		$$ = ast;
    }
    | RETURN SEMI {
        auto ast = new Stmt();
		ast->Name = "ReturnStmt";
		ast->AST_type = STMT;
		ast->Stmt_type = Return;
		ast->RVal = nullptr;
		$$ = ast;
    }
    | error SEMI {
		auto ast = new ErrorAST();
		ast->AST_type = ERROR;
		$$ = ast;
	}
    ;

Exp
    : AddExp {
        $$ = $1;
    }
    | LOrExp {
        $$ = $1;
    }
    ;

Cond
    : LOrExp {
        $$ = $1;
    }
    ;

LVal
    : IDENTIFIER {
        auto ast = new Variable();
		ast->AST_type = VARIABLE;
		ast->Var_name = *shared_ptr<string>($1);
		ast->Length = vector<shared_ptr<BaseAST>>();
		$$ = ast;
    }
    | IDENTIFIER ExpWrap {
        auto ast = new Variable();
		ast->AST_type = VARIABLE;
		ast->Var_name = *shared_ptr<string>($1);
		ast->Length = move(reinterpret_cast<Variable*>$2->Length);
		$$ = ast;
    }
    | IDENTIFIER DOT IDENTIFIER {
        auto ast = new Variable();
		ast->AST_type = VARIABLE;
		ast->Var_name = *shared_ptr<string>($1);
		ast->Length = vector<shared_ptr<BaseAST>>();
		ast->Member_name = *shared_ptr<string>($3);
		$$ = ast;
    }
    ;

PrimaryExp
    : LPAREN Exp RPAREN {
        $$ = $2;
    }
    | LVal {
        $$ = $1;
    }
    | Number {
        auto ast = new Exp();
		ast->AST_type = EXP;
		ast->Name = "Number";
		ast->Left_exp = shared_ptr<BaseAST>($1);
		ast->Right_exp = nullptr;
		ast->Operator = "";
		$$ = ast;
    }
    ;

Number
    : INTERGER {
        auto ast = new FinalExp();
		ast->Name = "IntConst";
		ast->AST_type = FINALEXP;
		ast->Exp_type = Int;
		ast->Number = $1;
		$$ = ast;
    }
    | REAL {
        auto ast = new FinalExp();
		ast->Name = "DoubleConst";
		ast->AST_type = FINALEXP;
		ast->Exp_type = Double;
		ast->Number = $1;
		$$ = ast;
    }
    ;

UnaryExp
    : PrimaryExp {
        $$ = $1;
    }
    | IDENTIFIER LPAREN RPAREN {
        auto ast = new FuncPrototype();
		ast->AST_type = FUNCPROTO;
		ast->Name = "FuncCall";
		ast->Func_name = *shared_ptr<string>($1);
		$$ = ast;
    }
    | IDENTIFIER LPAREN FuncRParams RPAREN {
        auto ast = new FuncPrototype();
		ast->AST_type = FUNCPROTO;
		ast->Name = "FuncCall";
		ast->Func_name = *shared_ptr<string>($1);
		ast->Params = move(reinterpret_cast<FuncPrototype*>$3->Params);
		$$ = ast;
    }
    | UnaryOp UnaryExp { }
    ;

UnaryOp
    : SUB { }
    | ADD { }
    | NOT { }
    ;

FuncRParams
    : Exp {
        auto ast = new FuncPrototype();
		ast->AST_type = FUNCPROTO;
		ast->Params.push_back(shared_ptr<BaseAST>($1));
		$$ = ast;
    }
    | Exp FuncRParamsWrap {
        auto ast = reinterpret_cast<FuncPrototype*>$2;
		ast->Params.insert(ast->Params.begin(), shared_ptr<BaseAST>($1));
		$$ = ast;
    }
    ;

FuncRParamsWrap
    : COMMA Exp {
        auto ast = new FuncPrototype();
		ast->AST_type = FUNCPROTO;
		ast->Params.push_back(shared_ptr<BaseAST>($2));
		$$ = ast;
    }
    | COMMA Exp FuncRParamsWrap {
        auto ast = reinterpret_cast<FuncPrototype*>$3;
		ast->Params.insert(ast->Params.begin(), shared_ptr<BaseAST>($2));
		$$ = ast;
    }
    ;

MulExp
    : UnaryExp {
        $$ = $1;
    }
    | MulExp MUL UnaryExp {
        auto ast = new Exp();
		ast->AST_type = EXP;
		ast->Name = "MulExp";
		ast->Left_exp = shared_ptr<BaseAST>($1);
		ast->Right_exp = shared_ptr<BaseAST>($3);
		ast->Operator = "*";
		$$ = ast;
    }
    | MulExp DIV UnaryExp {
        auto ast = new Exp();
		ast->AST_type = EXP;
		ast->Name = "MulExp";
		ast->Left_exp = shared_ptr<BaseAST>($1);
		ast->Right_exp = shared_ptr<BaseAST>($3);
		ast->Operator = "/";
		$$ = ast;
    }
    | MulExp MOD UnaryExp {
        auto ast = new Exp();
		ast->AST_type = EXP;
		ast->Name = "MulExp";
		ast->Left_exp = shared_ptr<BaseAST>($1);
		ast->Right_exp = shared_ptr<BaseAST>($3);
		ast->Operator = "%";
		$$ = ast;
    }
    ;

AddExp
    : MulExp {
        $$ = $1;
    }
    | AddExp ADD MulExp {
        auto ast = new Exp();
		ast->AST_type = EXP;
		ast->Name = "AddExp";
		ast->Left_exp = shared_ptr<BaseAST>($1);
		ast->Right_exp = shared_ptr<BaseAST>($3);
		ast->Operator = "+";
		$$ = ast;
    }
    | AddExp SUB MulExp {
        auto ast = new Exp();
		ast->AST_type = EXP;
		ast->Name = "AddExp";
		ast->Left_exp = shared_ptr<BaseAST>($1);
		ast->Right_exp = shared_ptr<BaseAST>($3);
		ast->Operator = "-";
		$$ = ast;
    }
    ;

RelExp
    : AddExp {
        $$ = $1;
    }
    | RelExp LT AddExp {
        auto ast = new Exp();
		ast->AST_type = EXP;
		ast->Name = "RelExp";
		ast->Left_exp = shared_ptr<BaseAST>($1);
		ast->Operator = "<";
		ast->Right_exp = shared_ptr<BaseAST>($3);
		$$ = ast;
    }
    | RelExp GT AddExp {
        auto ast = new Exp();
		ast->AST_type = EXP;
		ast->Name = "RelExp";
		ast->Left_exp = shared_ptr<BaseAST>($1);
		ast->Operator = ">";
		ast->Right_exp = shared_ptr<BaseAST>($3);
		$$ = ast;
    }
    | RelExp LE AddExp {
        auto ast = new Exp();
		ast->AST_type = EXP;
		ast->Name = "RelExp";
		ast->Left_exp = shared_ptr<BaseAST>($1);
		ast->Operator = "<=";
		ast->Right_exp = shared_ptr<BaseAST>($3);
		$$ = ast;
    }
    | RelExp GE AddExp {
        auto ast = new Exp();
		ast->AST_type = EXP;
		ast->Name = "RelExp";
		ast->Left_exp = shared_ptr<BaseAST>($1);
		ast->Operator = ">=";
		ast->Right_exp = shared_ptr<BaseAST>($3);
		$$ = ast;
    }
    ;

EqExp
    : RelExp {
        $$ = $1;
    }
    | EqExp EQ RelExp {
        auto ast = new Exp();
		ast->AST_type = EXP;
		ast->Name = "EqExp";
		ast->Left_exp = shared_ptr<BaseAST>($1);
		ast->Operator = "==";
		ast->Right_exp = shared_ptr<BaseAST>($3);
		$$ = ast;
    }
    | EqExp NE RelExp {
        auto ast = new Exp();
		ast->AST_type = EXP;
		ast->Name = "EqExp";
		ast->Left_exp = shared_ptr<BaseAST>($1);
		ast->Operator = "!=";
		ast->Right_exp = shared_ptr<BaseAST>($3);
		$$ = ast;
    }
    ;

LAndExp
    : EqExp {
        $$ = $1;
    }
    | LAndExp AND EqExp {
        auto ast = new Exp();
		ast->AST_type = EXP;
		ast->Name = "LAndExp";
		ast->Left_exp = shared_ptr<BaseAST>($1);
		ast->Operator = "&&";
		ast->Right_exp = shared_ptr<BaseAST>($3);
		$$ = ast;
    }
    ;

LOrExp
    : LAndExp {
        $$ = $1;
    }
    | LOrExp OR LAndExp {
        auto ast = new Exp();
		ast->AST_type = EXP;
		ast->Name = "LOrExp";
		ast->Left_exp = shared_ptr<BaseAST>($1);
		ast->Operator = "||";
		ast->Right_exp = shared_ptr<BaseAST>($3);
		$$ = ast;
    }
    ;


%%

void yyerror(shared_ptr<BaseAST> &ast, const char *s) {
	cerr << "error: " << s << endl;
}