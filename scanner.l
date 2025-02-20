
/* definitions */

%{
#include <stdio.h>
#include "tokendef.h"

int scancol = 1;
int yycol = 1;
int scanlineno = 1;

char* yyerror;

void updateCol(); //TODO: Implement this function to keep track of column numbers
void countLines(); //TODO: Implement this function to keep track of line numbers
int processString(); //TODO: Implement this function to check for illegal escape sequences in string literals and print out escape sequences correctly.
%}

newline   		//TODO
whitespace      //TODO
integer         //TODO
character       //TODO

/* String can contain any characters between the double quotes other than a newline or
// unescaped doublequotes.
*/
string       //TODO

/* multiline string has \n somewhere in the middle */
multlnstring //TODO

/* If the end quote is found, one of the two regexes above will be matched. Otherwise,
// the string is unterminated.
*/
untermstring //TODO

comment         //TODO
multlncomment   //TODO
untermcomment   //TODO

identifier      //TODO
illidentifier   //TODO: regular expression for an illegal identifier

yylineno = 1;

%%

 /* rules */

 /* Keywords */;
	//TODO: Support all keywords in mC
	/* Define keyword rules */
	if       { updateCol(); return KWD_IF; }
	else     { updateCol(); return KWD_ELSE; }
	while    { updateCol(); return KWD_WHILE; }
	return   { updateCol(); return KWD_RETURN; }

	int      { updateCol(); return KWD_INT; }
	string	 { updateCol(); return KWD_STRING; }
	char     { updateCol(); return KWD_CHAR; }
	void     { updateCol(); return KWD_VOID; }
	
 /* Operators */;
	//TODO: Support all operators and special symbols in mC (done)
	"+"		{ updateCol(); return OPER_ADD; }
	"-"		{ updateCol(); return OPER_SUB; }
	"*"		{ updateCol(); return OPER_MUL; }
	"/"		{ updateCol(); return OPER_DIV; }
	"%%"	{ updateCol(); return OPER_MOD; }
	"<"		{ updateCol(); return OPER_LT; }
	">"		{ updateCol(); return OPER_GT; }
	"<="	{ updateCol(); return OPER_LTE; }
	">="	{ updateCol(); return OPER_GTE; }
	"=="	{ updateCol(); return OPER_EQ; }
	"!="	{ updateCol(); return OPER_NEQ; }
	"="		{ updateCol(); return OPER_ASSN; }
	"@"		{ updateCol(); return OPER_AT; }
	"++"	{ updateCol(); return OPER_INC; }
	"--"	{ updateCol(); return OPER_DEC; }
	"&&"	{ updateCol(); return OPER_AND; }
	"||"	{ updateCol(); return OPER_OR; }
	"!"		{ updateCol(); return OPER_NOT; }


 /* Delimiter */
 	"["		{ updateCol(); return LSQ_BRKT; }
	"]"		{ updateCol(); return RSQ_BRKT; }
	"{"		{ updateCol(); return LCRLY_BRKT; }
	"}"		{ updateCol(); return RCRLY_BRKT; }
	"("		{ updateCol(); return LPAREN; }
	")"		{ updateCol(); return RPAREN; }
	","		{ updateCol(); return COMMA; }
	";"		{ updateCol(); return SEMICLN; }

 /* Identifiers */;
{identifier}    {updateCol(); return ID;}
{illidentifier} {updateCol();return ILLEGAL_TOK;}

 /* Constants */;
{integer}       //TODO
{integerlead0}  //TODO: "Integers may not have leading zeros"
{character}     //TODO
{string}        {updateCol(); return processString();}
{untermstring}  {updateCol(); yyerror = "Unterminated string"; return ERROR;}
{multlnstring}  {updateCol(); countLines(); yyerror = "String spans multiple lines"; return ERROR;} // Catching a multi-line string and generating an error.

 /* Comments */;
{comment}       //TODO
{untermcomment} //TODO
{multlncomment} //TODO

 /* Other */;
{newline}	{ scanlineno++; yycol = 1; updateCol();}       //TODO (done), this resets the column count when it hit a newline or \n
{whitespace}    //TODO
.               {return ILLEGAL_TOK;}

%%

/* user routines */

void updateCol(){
	//TODO: Keep track of column number (done)

	yycol += yyleng; // Increase column count by the length of the matched token

}

void countLines(){
	//TODO: Count the number of lines (done)
	scanlineno++;
}


int processString(){
	// TODO: Process a string literal and return the appropriate microsyntax.
}