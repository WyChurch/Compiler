
/* definitions */

%{
#include <stdio.h>
#include <tokendef.h>

int scancol = 1;
int yycol = 1;
int scanlineno = 1;

char* yyerror;

void updateCol(); //TODO: Implement this function to keep track of column numbers (done)
void countLines(); //TODO: Implement this function to keep track of line numbers (done)
int processString(); //TODO: Implement this function to check for illegal escape sequences in string literals and print out escape sequences correctly. (done)
%}

%option noyywrap

integerlead0    [0][0-9]+
integer         [1-9][0-9]*

newline   		\n
whitespace      [ \t\r\f\v]+
character       \'(\\.|[^'\\])\'

/* String can contain any characters between the double quotes other than a newline or unescaped doublequotes.*/
string       	\"([^\"\n]|\\.)*\"

/* multiline string has \n somewhere in the middle */
multlnstring 	\"([^\"\n]|\\.)*\n([^\"\n]|\\.)*\"

/* If the end quote is found, one of the two regexes above will be matched. Otherwise, the string is unterminated.*/
untermstring 	\"([^\"\n]|\\.)*

comment         "//.*|/\*[\s\S]*?\*/"
multlncomment   "/\\*([^*]|\\*+[^*/])*\\*+/"
untermcomment   "/\\*([^*]|\\*+[^*/])*"

identifier      [a-zA-Z_][a-zA-Z0-9]*
illidentifier   [0-9][a-zA-Z0-9_]*

yylineno = 1;

%%

 /* rules */;

 /* Keywords */;
"if"       { updateCol(); return KWD_IF; }
"else"     { updateCol(); return KWD_ELSE; }
"while"    { updateCol(); return KWD_WHILE; }
"do"       { updateCol(); return KWD_DO; }
"for"      { updateCol(); return KWD_FOR; }
"break"    { updateCol(); return KWD_BREAK; }
"continue" { updateCol(); return KWD_CONTINUE; }
"switch"   { updateCol(); return KWD_SWITCH; }
"case"     { updateCol(); return KWD_CASE; }
"default"  { updateCol(); return KWD_DEFAULT; }
"return"   { updateCol(); return KWD_RETURN; }
"goto"     { updateCol(); return KWD_GOTO; }

"int"      { updateCol(); return KWD_INT; }
"char"     { updateCol(); return KWD_CHAR; }
"float"    { updateCol(); return KWD_FLOUT; }
"double"   { updateCol(); return KWD_DOUBLE; }
"void"     { updateCol(); return KWD_VOID; }
"short"    { updateCol(); return KWD_SHORT; }
"long"     { updateCol(); return KWD_LONG; }
"unsigned" { updateCol(); return KWD_UNSIGNED; }
"signed"   { updateCol(); return KWD_SIGNED; }

"static"   { updateCol(); return KWD_STATIC; }
"typedef"  { updateCol(); return KWD_TYPEDEF; }

"sizeof"   { updateCol(); return KWD_SIZEOF; }
"struct"   { updateCol(); return KWD_STRUCT; }
	
 /* Operators */;
"+"		{ updateCol(); return OPER_ADD; }
"-"		{ updateCol(); return OPER_SUB; }
"*"		{ updateCol(); return OPER_MUL; }
"/"		{ updateCol(); return OPER_DIV; }
"\%"	{ updateCol(); return OPER_MOD; }
"<"		{ updateCol(); return OPER_LT; }
">"		{ updateCol(); return OPER_GT; }
"<="	{ updateCol(); return OPER_LTE; }
">="	{ updateCol(); return OPER_GTE; }
"=="	{ updateCol(); return OPER_EQ; }
"!="	{ updateCol(); return OPER_NEQ; }
"="		{ updateCol(); return OPER_ASGN; }
"@"		{ updateCol(); return OPER_AT; }
"++"	{ updateCol(); return OPER_INC; }
"--"	{ updateCol(); return OPER_DEC; }
"&&"	{ updateCol(); return OPER_AND; }
"||"	{ updateCol(); return OPER_OR; }
"!"		{ updateCol(); return OPER_NOT; }
"["		{ updateCol(); return LSQ_BRKT; }
"]" 	{ updateCol(); return RSQ_BRKT; }
"{"		{ updateCol(); return LCRLY_BRKT; }
"}"		{ updateCol(); return RCRLY_BRKT; }
"("		{ updateCol(); return LPAREN; }
")"		{ updateCol(); return RPAREN; }
","		{ updateCol(); return COMMA; }
";"		{ updateCol(); return SEMICLN; }

 /* Delimiter */
"{"		{ updateCol(); return LCRLY_BRKT; }
"}"		{ updateCol(); return RCRLY_BRKT; }
"("		{ updateCol(); return LPAREN; }
")"		{ updateCol(); return RPAREN; }
","		{ updateCol(); return COMMA; }
";"		{ updateCol(); return SEMICLN; }

 /* Other */;
{newline}		{ scanlineno++; yycol = 1; countLines(); }       	//TODO (done), this resets the column count when it hit a newline or \n
{whitespace}    { updateCol(); }								//TODO (done) Ignores whitspace
.               { printf("Unmatched input: %s\n", yytext); return ERROR; }

 /* Constants */;
{integerlead0}  { updateCol(); yyerror = "There should be no leading zeros"; return ERROR; } //TODO: "Integers may not have leading zeros" (done)
{integer}       { updateCol(); return INTCONST; }
{character}     { updateCol(); return CHARCONST; }
{string}        { updateCol(); return processString(); }
{untermstring}  { updateCol(); yyerror = "Unterminated string"; return ERROR; }
{multlnstring}  { yyerror = "String spans multiple lines"; return ERROR; } 		// Catching a multi-line string and generating an error.

 /* Identifiers */;
{identifier}    { updateCol(); return ID; } 	//TODO (done)
{illidentifier} { updateCol(); yyerror = "Illegal idetifier: Cannot start with a digit"; return ERROR; } 	//TODO (done)

 /* Comments */;
{comment}       { updateCol(); return COMMENT; }									//TODO (done)
{untermcomment} { updateCol(); countLines(); return COMMENT; }						//TODO (done)
{multlncomment} { yyerror = "Unterminated comment"; return ERROR; }	//TODO (done)

%%

/* user routines */

void updateCol(){
	//TODO: Keep track of column number (done)

	yycol += yyleng; // Increase column count by the length of the matched token

}

void countLines(){
	//TODO: Count the number of lines (done)

	yylineno++;

}

/* Process String Literal (Uses yytext Directly) */
int processString(){
	// TODO: Process a string literal and return the appropriate microsyntax. (done)

	char processedStr[1024];			//Buffer for processed string
	char* str = yytext;
	int i = 0, j = 0;

	while(str[i] != '\0') {

		if(str[i] == '\\'){				//Handle escape sequences

			i++;
			switch(str[i]) {

				case 'n': 
					processedStr[j++] = '\n';	// Checks for newline
					break;
				case 't':
					processedStr[j++] = '\t';	// Checks for tabs
					break;
				case '\\':
					processedStr[j++] = '\\';
					break;
				case '"':
					processedStr[j++] = '"';	
					break;
				default:
					yyerror = "illegal escape sequence";
					return ERROR;
 
			}

		} else {

			processedStr[j++] = str[i];

		}

		i++;

	}

	processedStr[j] = '\0';
	return STRCONST;										//Return string token

}