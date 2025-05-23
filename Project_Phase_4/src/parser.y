%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "src/tree.h"
#include "src/strtab.h"

#define YYDEBUG 1

int yylex(void);
int yyerror(const char *s);


extern int yylineno;
char* scope = "";
int param_count = 0;
%}

%union
{
    int value;
    struct treenode *node;
    char *strval;
}

%token <strval> ID
%token <value> INTCONST
%token <strval> CHARCONST
%token <strval> STRCONST

%token <strval> KWD_INT
%token <strval> KWD_CHAR
%token <strval> KWD_STRING
%token <strval> KWD_VOID
%token <strval> KWD_WHILE
%token <strval> KWD_IF
%token <strval> KWD_ELSE
%token <strval> KWD_RETURN
%token <strval> KWD_FOR

%token <strval> OPER_ADD
%token <strval> OPER_SUB
%token <strval> OPER_MUL
%token <strval> OPER_DIV
%token <strval> OPER_ASSN
%token <strval> OPER_LT
%token <strval> OPER_LTE
%token <strval> OPER_EQ
%token <strval> OPER_GTE
%token <strval> OPER_GT
%token <strval> OPER_NEQ
%token <strval> OPER_ASGN

%token <strval> LSQ_BRKT
%token <strval> RSQ_BRKT
%token <strval> LCRLY_BRKT
%token <strval> RCRLY_BRKT
%token <strval> LPAREN
%token <strval> RPAREN
%token <strval> COMMA
%token <strval> SEMICLN

%token <strval> ERROR
%token <strval> ILLEGAL_TOKEN

%type <node> funcReturnType program declList decl varDecl varTypeSpecifier funDecl formalDeclList formalDecl funBody localDeclList statementList statement compoundStmt assignStmt condStmt loopStmt returnStmt var expression relop addExpr addop term mulop factor funcCallExpr argList

%start program

%%

program         : declList
                 {
                    tree* progNode = maketree(PROGRAM);
                    addChild(progNode, $1);
                    ast = progNode;
                    $$ = progNode;
                 }
                ;

varTypeSpecifier : KWD_INT
                 {
                     $$ = maketreeWithIntVal(TYPESPEC, INT_TYPE);
                 }
                 | KWD_CHAR
                 {
                     $$ = maketreeWithIntVal(TYPESPEC, CHAR_TYPE);
                 }
                 ;

funcReturnType : KWD_INT
               {
                   $$ = maketreeWithIntVal(TYPESPEC, INT_TYPE);
               }
               | KWD_CHAR
               {
                   $$ = maketreeWithIntVal(TYPESPEC, CHAR_TYPE);
               }
               | KWD_VOID
               {
                   $$ = maketreeWithIntVal(TYPESPEC, VOID_TYPE);
               }
               ;

decl            : varDecl
                {
                    tree* declNode = maketree(DECL);
                    addChild(declNode, $1);
                    $$ = declNode;
                 }
                | funDecl
                {
                    tree* declNode = maketree(DECL);
                    addChild(declNode, $1);
                    $$ = declNode;
                 }
                ;

declList        : decl
                 {
                    tree* declListNode = maketree(DECLLIST);
                    addChild(declListNode, $1);
                    $$ = declListNode;
                 }
                | declList decl
                 {
                    tree* declListNode = maketree(DECLLIST);
                    addChild(declListNode, $1);
                    addChild(declListNode, $2);
                    $$ = declListNode;
                 }
                ;

varDecl         : varTypeSpecifier ID LSQ_BRKT INTCONST RSQ_BRKT SEMICLN
                {
                    ST_insert($2,scope,$1->val,ARRAY);
                    tree* varDeclNode = maketree(VARDECL);
                    addChild(varDeclNode, $1);
                    tree* idNode = maketreeWithVal(IDENTIFIER,$2);
                    addChild(varDeclNode, idNode);
                    tree* integerNode = maketreeWithIntVal(INTEGER,$4); 
                    addChild(varDeclNode, integerNode);
                    $$ = varDeclNode;
                 }
                | varTypeSpecifier ID SEMICLN
                {
                    ST_insert($2,scope,$1->val,SCALAR);
                    tree* varDeclNode = maketree(VARDECL);
                    addChild(varDeclNode, $1);
                    tree* idNode = maketreeWithVal(IDENTIFIER,$2);
                    addChild(varDeclNode, idNode);
                    $$ = varDeclNode;
                 }
                ;
formalDecl      : varTypeSpecifier ID
                {
                    ST_insert($2, scope, $1->val, SCALAR);
                    tree* formDeclNode = maketree(FORMALDECL);
                    addChild(formDeclNode, $1);
                    tree* idNode = maketreeWithVal(IDENTIFIER, $2);
                    addChild(formDeclNode, idNode);
                    $$ = formDeclNode;

                    add_param($1->val, SCALAR);
                    param_count++;
                 }
                | varTypeSpecifier ID LSQ_BRKT RSQ_BRKT
                {
                    ST_insert($2, scope, $1->val, ARRAY);
                    tree* formDeclNode = maketree(FORMALDECL);
                    addChild(formDeclNode, $1);
                    tree* idNode = maketreeWithVal(IDENTIFIER, $2);
                    addChild(formDeclNode, idNode);
                    $$ = formDeclNode;

                    add_param($1->val, ARRAY);
                    param_count++;
                 }
                ;
formalDeclList  : formalDecl
                {
                    tree* formDeclNode = maketree(FORMALDECLLIST);
                    addChild(formDeclNode, $1);
                    $$ = formDeclNode;
                 }
                | formalDecl COMMA formalDeclList
                {
                    tree* formDeclNode = maketree(FORMALDECLLIST);
                    addChild(formDeclNode, $1);
                    addChild(formDeclNode, $3);
                    $$ = formDeclNode;
                 }
                ;
funDecl         : funcReturnType ID LPAREN RPAREN funBody
                {
                    int index = ST_insert($2, scope, $1->val, FUNCTION);
                    scope = $2;
                    connect_params(index, 0);
                    scope = "";

                    tree* funDeclNode = maketree(FUNDECL);
                    addChild(funDeclNode, $1); // return type
                    tree* formals = maketree(FORMALDECLLIST); // empty param list
                    addChild(funDeclNode, formals);
                    addChild(funDeclNode, $5); // body
                    tree* idNode = maketreeWithVal(IDENTIFIER, $2);
                    addChild(funDeclNode, idNode);
                    $$ = funDeclNode;
                }
                | funcReturnType ID LPAREN formalDeclList RPAREN funBody
                {
                    int index = ST_insert($2, scope, $1->val, FUNCTION);
                    scope = $2;
                    connect_params(index, param_count);
                    param_count = 0;
                    scope = "";

                    tree* funDeclNode = maketree(FUNDECL);
                    addChild(funDeclNode, $1); // return type
                    addChild(funDeclNode, $4); // formal list
                    addChild(funDeclNode, $6); // body
                    tree* idNode = maketreeWithVal(IDENTIFIER, $2);
                    addChild(funDeclNode, idNode);
                    $$ = funDeclNode;
                }
                ;

compoundStmt    : LCRLY_BRKT statementList RCRLY_BRKT
                {
                    tree* compStmtNode = maketree(COMPOUNDSTMT);
                    addChild(compStmtNode, $2);  // $2 is the statementList
                    $$ = compStmtNode;
                 }
                ;
assignStmt      : var OPER_ASSN expression SEMICLN
                {
                    tree* assignStmtNode = maketree(ASSIGNSTMT);
                    addChild(assignStmtNode, $1);
                    addChild(assignStmtNode, $3);
                    $$ = assignStmtNode;
                 }
                | expression SEMICLN
                {
                    tree* assignStmtNode = maketree(ASSIGNSTMT);
                    addChild(assignStmtNode, $1);
                    $$ = assignStmtNode;
                }
                ;
condStmt        : KWD_IF LPAREN expression RPAREN statement
                {
                    tree* condStmtNode = maketree(CONDSTMT);
                    addChild(condStmtNode, $3);
                    addChild(condStmtNode, $5);
                    $$ = condStmtNode;
                 }
                | KWD_IF LPAREN expression RPAREN statement KWD_ELSE statement
                {
                    tree* condStmtNode = maketree(CONDSTMT);
                    addChild(condStmtNode, $3);
                    addChild(condStmtNode, $5);
                    addChild(condStmtNode, $7);
                    $$ = condStmtNode;
                 }
                ;
loopStmt        : KWD_WHILE LPAREN expression RPAREN statement
                {
                    tree* loopStmtNode = maketree(LOOPSTMT);
                    addChild(loopStmtNode, $3);
                    addChild(loopStmtNode, $5);
                    $$ = loopStmtNode;
                 }
                ;
returnStmt      : KWD_RETURN SEMICLN
                {
                    tree* returnStmtNode = maketree(RETURNSTMT);
                    $$ = returnStmtNode;
                 }
                | KWD_RETURN expression SEMICLN
                {
                    tree* returnStmtNode = maketree(RETURNSTMT);
                    addChild(returnStmtNode, $2);
                    $$ = returnStmtNode;
                 }
                ;

statement       : compoundStmt
                {
                    tree* statementNode = maketree(STATEMENT);
                    addChild(statementNode, $1);
                    $$ = statementNode;
                 }
                | assignStmt
                {
                    tree* statementNode = maketree(STATEMENT);
                    addChild(statementNode, $1);
                    $$ = statementNode;
                 }
                | condStmt
                {
                    tree* statementNode = maketree(STATEMENT);
                    addChild(statementNode, $1);
                    $$ = statementNode;
                 }
                | loopStmt
                {
                    tree* statementNode = maketree(STATEMENT);
                    addChild(statementNode, $1);
                    $$ = statementNode;
                 }
                | returnStmt
                {
                    tree* statementNode = maketree(STATEMENT);
                    addChild(statementNode, $1);
                    $$ = statementNode;
                 }
                ;

statementList   : /* empty */
                {
                    tree* statementListNode = maketree(STATEMENTLIST);
                    $$ = statementListNode;
                 }
                | statement statementList
                {
                    tree* statementListNode = maketree(STATEMENTLIST);
                    addChild(statementListNode, $1);
                    addChild(statementListNode, $2);
                    $$ = statementListNode;
                 }
                ;

funBody         : LCRLY_BRKT localDeclList statementList RCRLY_BRKT
                {
                    new_scope();  // Open a new scope for function body

                    tree* funBodyNode = maketree(FUNBODY);
                    addChild(funBodyNode, $2);
                    addChild(funBodyNode, $3);

                    up_scope();    // Close the scope at the end
                    scope = "";    // Reset to global
                    $$ = funBodyNode;
                }
                ;
localDeclList   : /* empty */
                {
                    tree* localDeclListNode = maketree(LOCALDECLLIST);
                    $$ = localDeclListNode;
                }
                | varDecl localDeclList
                {
                    tree* localDeclListNode = maketree(LOCALDECLLIST);
                    addChild(localDeclListNode,$1);
                    addChild(localDeclListNode,$2);
                    $$ = localDeclListNode;
                 }
                ;

var             : ID
                {
                    tree* varNode = maketree(VAR);
                    tree* idNode = maketreeWithVal(IDENTIFIER,$1);
                    addChild(varNode, idNode);
                    $$ = varNode;
                 }
                | ID  LSQ_BRKT addExpr RSQ_BRKT
                {
                    tree* varNode = maketree(VAR);
                    tree* idNode = maketreeWithVal(IDENTIFIER, $1);
                    addChild(varNode, idNode);
                    addChild(varNode, $3);  // index expression
                    $$ = varNode;
                 }
                ;

addExpr         : term
                {
                    tree* addExprNode = maketree(ADDEXPR);
                    addChild(addExprNode, $1);
                    $$ = addExprNode;
                 }
                | addExpr addop term
                {
                    tree* addExprNode = maketree(ADDEXPR);
                    addChild(addExprNode, $1);
                    addChild(addExprNode, $2);
                    addChild(addExprNode, $3);
                    $$ = addExprNode;
                 }
                ;

relop           : OPER_LTE
                {
                    tree* relopNode = maketreeWithIntVal(RELOP, LTE);
                    $$ = relopNode;
                 }
                | OPER_LT
                {
                    tree* relopNode = maketreeWithIntVal(RELOP, LT);
                    $$ = relopNode;
                 }
                | OPER_GT
                {
                    tree* relopNode = maketreeWithIntVal(RELOP, GT);
                    $$ = relopNode;
                 }
                | OPER_GTE
                {
                    tree* relopNode = maketreeWithIntVal(RELOP, GTE);
                    $$ = relopNode;
                 }
                | OPER_EQ
                {
                    tree* relopNode = maketreeWithIntVal(RELOP, EQ);
                    $$ = relopNode;
                 }
                | OPER_NEQ
                {
                    tree* relopNode = maketreeWithIntVal(RELOP, NEQ);
                    $$ = relopNode;
                 }
                ;

expression      : addExpr
                {
                    tree* expressionNode = maketree(EXPRESSION);
                    addChild(expressionNode, $1);
                    $$ = expressionNode;
                 }
                | expression relop addExpr
                {
                    tree* expressionNode = maketree(EXPRESSION);
                    addChild(expressionNode, $1);
                    addChild(expressionNode, $2);
                    addChild(expressionNode, $3);
                    $$ = expressionNode;
                 }
                ;

addop           : OPER_ADD
                {
                    tree* addopNode = maketreeWithIntVal(ADDOP,ADD);
                    $$ = addopNode;
                 }
                | OPER_SUB
                {
                    tree* addopNode = maketreeWithIntVal(ADDOP,SUB);
                    $$ = addopNode;
                 }
                ;

mulop           : OPER_MUL
                {
                    tree* mulopNode = maketreeWithIntVal(MULOP,MUL);
                    $$ = mulopNode;
                 }
                | OPER_DIV
                {
                    tree* mulopNode = maketreeWithIntVal(MULOP,DIV);
                    $$ = mulopNode;
                 }
                ;
factor          : LPAREN expression RPAREN
                {
                    tree* factorNode = maketree(FACTOR);
                    addChild(factorNode, $2);
                    $$ = factorNode;
                 }
                | var
                {
                    tree* factorNode = maketree(FACTOR);
                    addChild(factorNode, $1);
                    $$ = factorNode;
                 }
                | funcCallExpr
                {
                    tree* factorNode = maketree(FACTOR);
                    addChild(factorNode, $1);
                    $$ = factorNode;
                 }
                | INTCONST
                {
                    tree* factorNode = maketree(FACTOR);
                    tree* integerNode = maketreeWithIntVal(INTEGER,$1);
                    addChild(factorNode,integerNode);
                    $$ = factorNode;
                 }
                | CHARCONST
                {
                    tree* factorNode = maketree(FACTOR);
                    tree* charNode = maketreeWithVal(CHAR,$1);
                    addChild(factorNode,charNode);
                    $$ = factorNode;
                 }
                | STRCONST
                {
                    tree* factorNode = maketree(FACTOR);
                    tree* strNode = maketreeWithVal(STRING, $1);
                    addChild(factorNode, strNode);
                    $$ = factorNode;
                 }
                ;

term            : factor
                {
                    tree* termNode = maketree(TERM);
                    addChild(termNode, $1);
                    $$ = termNode;
                 }
                | term mulop factor
                {
                    tree* termNode = maketree(TERM);
                    addChild(termNode, $1);
                    addChild(termNode, $2);
                    addChild(termNode, $3);
                    $$ = termNode;
                 }
                ;

funcCallExpr    : ID LPAREN argList RPAREN
                {
                    tree* funcCallExprNode = maketree(FUNCCALLEXPR);
                    tree* idNode = maketreeWithVal(IDENTIFIER,$1);
                    addChild(funcCallExprNode, idNode);
                    addChild(funcCallExprNode, $3);
                    $$ = funcCallExprNode;
                 }
                | ID LPAREN RPAREN
                {
                    tree* funcCallExprNode = maketree(FUNCCALLEXPR);
                    tree* idNode = maketreeWithVal(IDENTIFIER, $1);
                    tree* emptyArgs = maketree(ARGLIST);
                    addChild(funcCallExprNode, idNode);
                    addChild(funcCallExprNode, emptyArgs);
                    $$ = funcCallExprNode;
                 }
                ;
argList         : expression
                {
                    tree* argListNode = maketree(ARGLIST);
                    addChild(argListNode, $1);
                    $$ = argListNode;
                 }
                | argList COMMA expression
                {
                    tree* argListNode = maketree(ARGLIST);
                    addChild(argListNode, $1);
                    addChild(argListNode, $3);
                    $$ = argListNode;
                 }
                ;
%%

int yywarning(char * msg){
    printf("warning: line %d: %s\n", yylineno, msg);
    return 0;
}

int yyerror(const char * msg){
    printf("error: line %d: %s\n", yylineno, msg);
    return 0;
}
