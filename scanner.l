
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
	if       { updateCol(); return IF; }
	else     { updateCol(); return ELSE; }
	while    { updateCol(); return WHILE; }
	do       { updateCol(); return DO; }
	for      { updateCol(); return FOR; }
	break    { updateCol(); return BREAK; }
	continue { updateCol(); return CONTINUE; }
	switch   { updateCol(); return SWITCH; }
	case     { updateCol(); return CASE; }
	default  { updateCol(); return DEFAULT; }
	return   { updateCol(); return RETURN; }
	goto     { updateCol(); return GOTO; }

	int      { updateCol(); return INT; }
	char     { updateCol(); return CHAR; }
	float    { updateCol(); return FLOAT; }
	double   { updateCol(); return DOUBLE; }
	void     { updateCol(); return VOID; }
	short    { updateCol(); return SHORT; }
	long     { updateCol(); return LONG; }
	unsigned { updateCol(); return UNSIGNED; }
	signed   { updateCol(); return SIGNED; }

	static   { updateCol(); return STATIC; }
	typedef  { updateCol(); return TYPEDEF; }

	sizeof   { updateCol(); return SIZEOF; }
	struct   { updateCol(); return STRUCT; }
	
 /* Operators */;
	//TODO: Support all operators in mC
	

 /* Delimiter */

 /* Identifiers */;
{identifier}    //TODO
{illidentifier} //TODO

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