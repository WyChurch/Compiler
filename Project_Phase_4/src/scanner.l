%{
#include <stdio.h>
#include "parser.tab.h"

int scancol = 1;
int yycol = 1;
int scanlineno = 1;

char* yyerrormsg;

void updateCol();
void countLines();
int processChar();
%}

newline         \n
whitespace      [ \t]+
integerlead0    0[0-9]+
integer         0|[1-9][0-9]*
character       \'([^\']|\\[\\nt\'])\'
comment         \/\*([^*]|\*[^\/])*\*\/
untermcomment   \/\*([^*]|\*[^\/])*
identifier      [a-zA-Z][a-zA-Z0-9]*
illidentifier   [0-9]+[a-zA-Z][a-zA-Z0-9]*

%%

"if"        { updateCol(); return KWD_IF; }
"else"      { updateCol(); return KWD_ELSE; }
"while"     { updateCol(); return KWD_WHILE; }
"int"       { updateCol(); return KWD_INT; }
"char"      { updateCol(); return KWD_CHAR; }
"return"    { updateCol(); return KWD_RETURN; }
"void"      { updateCol(); return KWD_VOID; }
"for"       { updateCol(); return KWD_FOR; }

\+         { updateCol(); return OPER_ADD; }
\-         { updateCol(); return OPER_SUB; }
\*         { updateCol(); return OPER_MUL; }
\/         { updateCol(); return OPER_DIV; }
\<=        { updateCol(); return OPER_LTE; }
\>=        { updateCol(); return OPER_GTE; }
\<         { updateCol(); return OPER_LT; }
\>         { updateCol(); return OPER_GT; }
==        { updateCol(); return OPER_EQ; }
!=        { updateCol(); return OPER_NEQ; }
=         { updateCol(); return OPER_ASSN; }

\[         { updateCol(); return LSQ_BRKT; }
\]         { updateCol(); return RSQ_BRKT; }
\{         { updateCol(); return LCRLY_BRKT; }
\}         { updateCol(); return RCRLY_BRKT; }
\(         { updateCol(); return LPAREN; }
\)         { updateCol(); return RPAREN; }
,         { updateCol(); return COMMA; }
;         { updateCol(); return SEMICLN; }

{illidentifier}   { updateCol(); yyerrormsg = "Identifiers may not start with a digit"; return ERROR; }
{identifier}      { updateCol(); yylval.strval = strdup(yytext); return ID; }
{integerlead0}    { updateCol(); yyerrormsg = "Integers may not have leading zeros"; return ERROR; }
{integer}         { updateCol(); yylval.value = atoi(yytext); return INTCONST; }
{character}       { updateCol(); return processChar(); }

{comment}         { updateCol(); }
{untermcomment}   { updateCol(); yyerrormsg = "Unterminated comment"; return ERROR; }

{newline}         { scancol = 1; scanlineno++; yylineno = scanlineno; }
{whitespace}      { updateCol(); }
.                 { return ILLEGAL_TOKEN; }

%%

void updateCol() {
    yycol = scancol;
    scancol += yyleng;
}

void countLines() {
    yylineno = scanlineno;
    for (int i = 0; i < yyleng; i++) {
        if (yytext[i] == '\n')
            scanlineno++;
    }
}

int processChar() {
    if (yytext[1] == '\\') {
        switch (yytext[2]) {
            case 'n': yylval.value = '\n'; break;
            case 't': yylval.value = '\t'; break;
            case '\\': yylval.value = '\\'; break;
            case '\'': yylval.value = '\''; break;
            default:
                yyerrormsg = "Unrecognized escape character";
                return ERROR;
        }
    } else {
        yylval.value = yytext[1];
    }
    return CHARCONST;
}

int yywrap() {
    return 1;
}