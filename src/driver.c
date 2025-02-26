#include <tokendef.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>


extern char *yytext;

extern int yylineno;
extern int yylex();
extern int yycol;
extern char* yyerror;

void printToken(int tokenNum) {
  switch(tokenNum) {
  case ID:
    printf("<ID, %s> : (%d:%d)\n", yytext, yylineno, yycol);
    break;
  case INTCONST:
    printf("<INTEGER, %s> : (%d:%d)\n", yytext, yylineno, yycol);
    break;
  case CHARCONST:
    printf("<CHARACTER, %s> : (%d:%d)\n", yytext, yylineno, yycol);
    break;
  case STRCONST:
    printf("<STRING, %s> : (%d:%d)\n", yytext, yylineno, yycol);
    break;
  case KWD_IF:
    printf("<KEYWORD, if> : (%d:%d)\n", yylineno, yycol);
    break;
  case KWD_ELSE:
    printf("<KEYWORD, else> : (%d:%d)\n", yylineno, yycol);
    break;
  case KWD_WHILE:
    printf("<KEYWORD, while> : (%d:%d)\n", yylineno, yycol);
    break;
  case KWD_DO:
    printf("<KEYWORD, do> : (%d:%d)\n", yylineno, yycol);
    break;
  case KWD_FOR:
    printf("<KEYWORD, for> : (%d:%d)\n", yylineno, yycol);
    break;
  case KWD_BREAK:
    printf("<KEYWORD, break> : (%d:%d)\n", yylineno, yycol);
    break;
  case KWD_CONTINUE:
    printf("<KEYWORD, continue> : (%d:%d)\n", yylineno, yycol);
    break;
  case KWD_INT:
    printf("<KEYWORD, int> : (%d:%d)\n", yylineno, yycol);
    break;
  case KWD_DOUBLE:
    printf("<KEYWORD, double> : (%d:%d)\n", yylineno, yycol);
    break;
  case KWD_FLOUT:
    printf("<KEYWORD, flout> : (%d:%d)\n", yylineno, yycol);
    break;
  case KWD_RETURN:
    printf("<KEYWORD, return> : (%d:%d)\n", yylineno, yycol);
    break;
  case KWD_CHAR:
    printf("<KEYWORD, char> : (%d:%d)\n", yylineno, yycol);
    break;
  case KWD_CASE:
    printf("<KEYWORD, case> : (%d:%d)\n", yylineno, yycol);
    break;
  case KWD_SIZEOF:
    printf("<KEYWORD, sizeof> : (%d:%d)\n", yylineno, yycol);
    break;
  case KWD_LONG:
    printf("KEYWORD, long> : (%d:%d)\n", yylineno, yycol);
    break;
  case KWD_SHORT:
    printf("<KEYWORD, short> : (%d:%d)\n", yylineno, yycol);
    break;
  case KWD_TYPEDEF:
    printf("<KEYWORD, typedef> : (%d,%d)\n", yylineno, yycol);
    break;
  case KWD_SWITCH:
    printf("<KEYWORD, switch> : (%d:%d)\n", yylineno, yycol);
    break;
  case KWD_UNSIGNED:
    printf("<KEYWORD, unsigned> : (%d:%d)\n", yylineno, yycol);
    break;
  case KWD_VOID:
    printf("<KEYWORD, void> : (%d:%d)\n", yylineno, yycol);
    break;
  case KWD_STATIC:
    printf("<KEYWORD, static> : (%d:%d)\n", yylineno, yycol);
    break;
  case KWD_STRUCT:
    printf("<KEYWORD, struck> : (%d:%d)\n", yylineno, yycol);
    break;
  case KWD_GOTO:
    printf("KEYWORD, goto> : (%d:%d)\n", yylineno, yycol);
    break;
  case KWD_STRING:
    printf("<KEYWORD, string> : (%d:%d)\n", yylineno, yycol);
    break;
  case KWD_DEFAULT:
    printf("<KEYWORD, default> : (%d:%d)\n", yylineno, yycol);
    break;
  case KWD_SIGNED:
    printf("<KEYWORD, signed> : (%d:%d)\n", yylineno, yycol);
    break;
  case OPER_ADD:
    printf("<OPERATOR, +> : (%d:%d)\n", yylineno, yycol);
    break;
  case OPER_SUB:
    printf("<OPERATOR, -> : (%d:%d)\n", yylineno, yycol);
    break;
  case OPER_MUL:
    printf("<OPERATOR, *> : (%d:%d)\n", yylineno, yycol);
    break;
  case OPER_DIV:
    printf("<OPERATOR, /> : (%d:%d)\n", yylineno, yycol);
    break;
  case OPER_LT:
    printf("<OPERATOR, <> : (%d:%d)\n", yylineno, yycol);
    break;
  case OPER_GT:
    printf("<OPERATOR, >> : (%d:%d)\n", yylineno, yycol);
    break;
  case OPER_GTE:
    printf("<OPERATOR, >=> : (%d:%d)\n", yylineno, yycol);
    break;
  case OPER_LTE:
    printf("<OPERATOR, <=> : (%d:%d)\n", yylineno, yycol);
    break;
  case OPER_EQ:
    printf("<OPERATOR, ==> : (%d:%d)\n", yylineno, yycol);
    break;
  case OPER_NEQ:
    printf("<OPERATOR, !=> : (%d:%d)\n", yylineno, yycol);
    break;
  case OPER_ASGN:
    printf("<OPERATOR, => : (%d:%d)\n", yylineno, yycol);
    break;
  case OPER_AT:
    printf("<OPERATOR, @> : (%d:%d)\n", yylineno, yycol);
    break;
  case OPER_INC:
    printf("<OPERATOR, ++> : (%d:%d)\n", yylineno, yycol);
    break;
  case OPER_DEC:
    printf("<OPERATOR, --> : (%d:%d)\n", yylineno, yycol);
    break;
  case OPER_AND:
    printf("<OPERATOR, &&> : (%d:%d)\n", yylineno, yycol);
    break;
  case OPER_OR:
    printf("<OPERATOR, ||> : (%d:%d)\n", yylineno, yycol);
    break;
  case OPER_NOT:
    printf("<OPERATOR, !> : (%d:%d)\n", yylineno, yycol);
    break;
  case OPER_MOD:
    printf("<OPERATOR, %%> : (%d:%d)\n", yylineno, yycol);
    break;
  case LSQ_BRKT:
    printf("<PUNCTUATION, [> : (%d:%d)\n", yylineno, yycol);
    break;
  case RSQ_BRKT:
    printf("<PUNCTUATION, ]> : (%d:%d)\n", yylineno, yycol);
    break;
  case LCRLY_BRKT:
    printf("<PUNCTUATION, {> : (%d:%d)\n", yylineno, yycol);
    break;
  case RCRLY_BRKT:
    printf("<PUNCTUATION, }> : (%d:%d)\n", yylineno, yycol);
    break;
  case LPAREN:
    printf("<PUNCTUATION, (> : (%d:%d)\n", yylineno, yycol);
    break;
  case RPAREN:
    printf("<PUNCTUATION, )> : (%d:%d)\n", yylineno, yycol);
    break;
  case COMMA:
    printf("<PUNCTUATION, ,> : (%d:%d)\n", yylineno, yycol);
    break;
  case SEMICLN:
    printf("<PUNCTUATION, ;> : (%d:%d)\n", yylineno, yycol);
    break;
  case ERROR:
    printf("<ERROR, %s> : (%d:%d)\n", yyerror, yylineno, yycol);
    break;
  default:
    printf("<ILLEGAL TOKEN>\n");
  }
  return;
}

int main() {

  int ret = yylex();
  while (ret) {
    printToken(ret);
    ret = yylex();
  }
  return 0;
}