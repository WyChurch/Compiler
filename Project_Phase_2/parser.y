%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<../src/tree.h>
#include<../src/strtab.h>

extern int yylineno;
/* nodeTypes refer to different types of internal and external nodes that can be part of the abstract syntax tree.*/
enum nodeTypes {PROGRAM, DECLLIST, DECL, VARDECL, TYPESPEC, FUNDECL,
                FORMALDECLLIST, FORMALDECL, FUNBODY, LOCALDECLLIST,
                STATEMENTLIST, STATEMENT, COMPOUNDSTMT, ASSIGNSTMT,
                CONDSTMT, LOOPSTMT, RETURNSTMT, EXPRESSION, RELOP,
                ADDEXPR, ADDOP, TERM, MULOP, FACTOR, FUNCCALLEXPR,
                ARGLIST, INTEGER, IDENTIFIER, VAR, ARRAYDECL, CHAR,
                FUNCTYPENAME};

enum opType {ADD, SUB, MUL, DIV, LT, LTE, EQ, GTE, GT, NEQ};

/* NOTE: mC has two kinds of scopes for variables : local and global. Variables declared outside any
function are considered globals, whereas variables (and parameters) declared inside a function foo are local to foo. You should update the scope variable whenever you are inside a production that matches function definition (funDecl production). The rationale is that you are entering that function, so all variables, arrays, and other functions should be within this scope. You should pass this variable whenever you are calling the ST_insert or ST_lookup functions. This variable should be updated to scope = "" to indicate global scope whenever funDecl finishes. Treat these hints as helpful directions only. You may implement all of the functions as you like and not adhere to my instructions. As long as the directory structure is correct and the file names are correct, we are okay with it. */
char* scope = "";
%}

/* the union describes the fields available in the yylval variable */
%union
{
    int value;
    struct treenode *node;
    char *strval;
}

/*Add token declarations below. The type <value> indicates that the associated token will be of a value type such as integer, float etc., and <strval> indicates that the associated token will be of string type.*/
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

%token <strval> LSQ_BRKT
%token <strval> RSQ_BRKT
%token <strval> LCRLY_BRKT
%token <strval> RCRLY_BRKT
%token <strval> LPAREN
%token <strval> RPAREN
%token <strval> COMMA
%token <strval> SEMICLN

/* TODO: Declate non-terminal symbols as of type node. Provided below is one example. node is defined as 'struct treenode *node' in the above union data structure. This declaration indicates to parser that these non-terminal variables will be implemented using a 'treenode *' type data structure. Hence, the circles you draw when drawing a parse tree, the following lines are telling yacc that these will eventually become circles in an AST. This is one of the connections between the AST you draw by hand and how yacc implements code to concretize that. We provide with two examples: program and declList from the grammar. Make sure to add the rest.  */

%type <node> program declList decl varDecl typeSpecifier funDecl formalDeclList formalDecl funBody localDeclList statementList statement compoundStmt assignStmt condStmt loopStmt returnStmt var expression relop addExpr addop term mulop factor funcCallExpr argList





*/
%start program

%%
/* TODO: Your grammar and semantic actions go here. We provide with two example productions and their associated code for adding non-terminals to the AST.*/

program         : declList
                 {
                    tree* progNode = maketree(PROGRAM);
                    addChild(progNode, $1);
                    ast = progNode;
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
varDecl         : typeSpecifier ID LSQ_BRKT INTCONST RSQ_BRKT SEMICLN
                {
                    tree* varDeclNode = maketree(VARDECL);
                    addChild(varDeclNode, $1);
                    $$ = varDeclNode;
                 }
                | typeSpecifier ID SEMICLN
                {
                    tree* varDeclNode = maketree(VARDECL);
                    addChild(varDeclNode, $1);
                    $$ = varDeclNode;
                 }
                ;
typeSpecifier   : KWD_INT
                {
                    tree* typeSpecNode = maketree(TYPESPEC);
                    $$ = typeSpecNode;
                 }
                | KWD_CHAR
                {
                    tree* typeSpecNode = maketree(TYPESPEC);
                    $$ = typeSpecNode;
                 }
                | KWD_STRING
                {
                    tree* typeSpecNode = maketree(TYPESPEC);
                    $$ = typeSpecNode;
                 }
                | KWD_VOID
                {
                    tree* typeSpecNode = maketree(TYPESPEC);
                    $$ = typeSpecNode;
                 }
                ;
funDecl         : typeSpecifier ID LPAREN formalDeclList RPAREN funBody
                {
                    tree* funDeclNode = maketree(FUNDECL);
                    addChild(funDeclNode, $1);
                    addChild(funDeclNode, $4);
                    addChild(funDeclNode, $6);
                    $$ = funDeclNode;
                 }
                | typeSpecifier ID LPAREN RPAREN funBody
                {
                    tree* funDeclNode = maketree(FUNDECL);
                    addChild(funDeclNode, $1);
                    addChild(funDeclNode, $6);
                    $$ = funDeclNode;
                 }
                ;
formalDeclList  : formalDecl
                {
                    tree* formDeclListNode = maketree(FORMALDECLLIST);
                    addChild(formDeclListNode, $1);
                    $$ = formDeclListNode;
                 }
                | formalDecl COMMA formalDeclList
                {
                    tree* formDeclListNode = maketree(FORMALDECLLIST);
                    addChild(formDeclListNode, $1);
                    addChild(formDeclListNode, $3);
                    $$ = formDeclListNode;
                 }
                ;
formalDecl      : typeSpecifier ID
                {
                    tree* formDeclNode = maketree(FORMALDECL);
                    addChild(formDeclNode, $1);
                    $$ = formDeclListNode;
                 }
                | typeSpecifier ID LSQ_BRKT RSQ_BRKT
                {
                    tree* formDeclNode = maketree(FORMALDECL);
                    addChild(formDeclNode, $1);
                    $$ = formDeclListNode;
                 }
                ;
funBody         : LCRLY_BRKT localDeclList statementList RCRLY_BRKT
                {
                    tree* funBodyNode = maketree(FUNBODY);
                    addChild(funBodyNode, $2);
                    addChild(funBodyNode, $3);
                    $$ = funBodyNode;
                 }
                ;
localDeclList   : 
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
statementList   :
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
compoundStmt    : LCRLY_BRKT statementList RCRLY_BRKT
                {
                    tree* compStmtNode = maketree(COMPOUNDSTMT);
                    addChild(compStmtNode, $1);
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
var             : ID
                {
                    tree* varNode = maketree(VAR);
                    $$ = varNode;
                 }
                | ID RSQ_BRKT addExpr LSQ_BRKT
                {
                    tree* varNode = maketree(VAR);
                    addChild(varNode, $3);
                    $$ = varNode;
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
relop           : OPER_LTE
                {
                    tree* relopNode = maketree(RELOP);
                    $$ = relopNode;
                 }
                | OPER_LT
                {
                    tree* relopNode = maketree(RELOP);
                    $$ = relopNode;
                 }
                | OPER_GT
                {
                    tree* relopNode = maketree(RELOP);
                    $$ = relopNode;
                 }
                | OPER_GTE
                {
                    tree* relopNode = maketree(RELOP);
                    $$ = relopNode;
                 }
                | OPER_EQ
                {
                    tree* relopNode = maketree(RELOP);
                    $$ = relopNode;
                 }
                | OPER_NEQ
                {
                    tree* relopNode = maketree(RELOP);
                    $$ = relopNode;
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
addop           : OPER_ADD
                {
                    tree* addopNode = maketree(ADDOP);
                    $$ = addopNode;
                 }
                | OPER_SUB
                {
                    tree* addopNode = maketree(ADDOP);
                    $$ = addopNode;
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
mulop           : OPER_MUL
                {
                    tree* mulopNode = maketree(MULOP);
                    $$ = mulopNode;
                 }
                | OPER_DIV
                {
                    tree* mulopNode = maketree(MULOP);
                    $$ = mulopNode;
                 }
                ;
factor          : LPAREN expression RPAREN
                {
                    tree* factorNode = maketree(FACTOR);
                    addChild(factorNode, $1);
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
                    $$ = factorNode;
                 }
                | CHARCONST
                {
                    tree* factorNode = maketree(FACTOR);
                    $$ = factorNode;
                 }
                | STRCONST
                {
                    tree* factorNode = maketree(FACTOR);
                    $$ = factorNode;
                 }
                ;
funcCallExpr    : ID LPAREN argList RPAREN
                {
                    tree* funcCallExprNode = maketree(FUNCCALLEXPR);
                    addChild(funcCallExprNode, $3);
                    $$ = funcCallExprNode;
                 }
                | ID LPAREN RPAREN
                {
                    tree* funcCallExprNode = maketree(FUNCCALLEXPR);
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

int yyerror(char * msg){
    printf("error: line %d: %s\n", yylineno, msg);
    return 0;
}
