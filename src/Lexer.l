%{
    // #include "AST.hpp"
    #include "Parser.hpp"
    #include <stdio.h>
    // #include <stdlib.h>
    #include <string>
    #include <iostream>

    char Escape(char c){
        switch(c){
            case 'n':return '\n';
            case 'r':return '\r';
            case 't':return '\t';
            case '\\':return '\\';
            case '\'':return '\'';
            case '\"':return '\"';
            default:
                if('0'<=c && c <= '9')
                    return (char)(c-'0');
                else
                    return c;
        }
    }
%}

%option never-interactive
%option outfile="lex.cpp"

%%

"struct"    {return STRUCT;}
"typedef"   {return TYPEDEF;}
"const"     {return CONST;}
"if"        {return IF;}
"else"      {return ELSE;}
"for"       {return FOR;}
"while"     {return WHILE;}
"continue"  {return CONTINUE;}
"break"     {return BREAK;}
"switch"    {return SWITCH;}
"case"      {return CASE;}
"default"   {return DEFAULT;}
"return"    {return RETURN;}
"true"      {return TRUE;}
"false"     {return FALSE;}
"bool"      {return BOOL;}
"short"     {return SHORT;}
"long"      {return LONG;}
"int"       {return INT;}
"float"     {return FLOAT;}
"double"    {return DOUBLE;}
"char"      {return CHAR;}
"void"      {return VOID;}
"printf"    {return PRINTF;}
"scanf"     {return SCANF;}

","     {return COMMA;}
"..."   {return ELLIPSIS;}
"."     {return DOT;}
";"     {return SEMI;}
"("     {return LPAREN;}
")"     {return RPAREN;}
"["     {return LBRACKET;}
"]"     {return RBRACKET;}
"{"     {return LBRACE;}
"}"     {return RBRACE;}
"=="    {return EQ;}
">="    {return GE;}
"<="    {return LE;}
"<"     {return LT;}
">"     {return GT;}
"!="    {return NE;}
"!"     {return NOT;}
"="     {return ASSIGN;}
"&&"    {return AND;}
"&="    {return BANDEQ;}
"&"     {return BAND;}
"||"    {return OR;}
"|="    {return BOREQ;}
"|"     {return BOR;}
"^="    {return BXOREQ;}
"^"     {return BXOR;}
"~"     {return BNOT;}
"++"    {return AADD;}
"+="    {return ADDEQ;}
"+"     {return ADD;}
"--"    {return SSUB;}
"-="    {return SUBEQ;}
"-"     {return SUB;}
"*="    {return MULEQ;}
"*"     {return MUL;}
"/="    {return DIVEQ;}
"/"     {return DIV;}
"%="    {return MODEQ;}
"%"     {return MOD;}
"->"    {return ARROW;}
"?"     {return QUES;}
":"     {return COLON;}

"/*"[^*]*[*]+([^*/][^*]*[*]+)*"/"   {;}
"//".*	                            {;}

"\'"\\."\'"         {yylval.cVal = Escape(yytext[2]);   return CHARACTER;}
"\'"[^\\']"\'"      {yylval.cVal = yytext[1];           return CHARACTER;}
"\'"                {return SQUOTE;}      

"\""(\\.|[^"\\])*"\""   {
                            yylval.sVal = new std::string("");
                            for(int i = 1; i < yyleng-1; i++){
                                if(yytext[i]=='\\'){
                                    i++;
                                    yylval.sVal->push_back(Escape(yytext[i]));
                                }
                                else{
                                    yylval.sVal->push_back(yytext[i]);
                                }
                            }
                            return STRING;
                        }
"\""                    {return DQUOTE;}

[a-zA-Z_][a-zA-Z0-9_]*  {yylval.sVal = new std::string(yytext,yyleng);  return IDENTIFIER;}
[0-9]+\.[0-9]+          {yylval.dVal = atof(yytext);                    return REAL;}
[0-9]+                  {yylval.iVal = atoi(yytext);                    return INTERGER;}

[ \t\n]     {;}
.           {;}

%%

int yywrap(void) { return 1; }