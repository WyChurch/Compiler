
/* definitions */

%{
#include <stdio.h>
#include "tokendef.h"

whitespace  [ \t\r\f\v]+

int scancol = 1;
int yycol = 1;
int scanlineno = 1;

char* yyerror;

void updateCol(); //TODO: Implement this function to keep track of column numbers (done)
void countLines(); //TODO: Implement this function to keep track of line numbers (done)
int processString(); //TODO: Implement this function to check for illegal escape sequences in string literals and print out escape sequences correctly. (done)
%}

newline   		\n
whitespace      [ \t\r\f\v]+
integer         [1-9][0-9]*|0
character       \'([^\'\\]|\\.)\'

/* String can contain any characters between the double quotes other than a newline or
// unescaped doublequotes.
*/
string       	\"([^\"]|\\.)*\"

/* multiline string has \n somewhere in the middle */
multlnstring 	\"([^\"\n]|\\.)*\n([^\"\n]|\\.)*\"

/* If the end quote is found, one of the two regexes above will be matched. Otherwise,
// the string is unterminated.
*/
untermstring 	\"([^\"\n]|\\.)*

comment         "//".*
multlncomment   "/\*([^*]|\*+[^*/])*\*+/"
untermcomment   "/\*([^*]|\*+[^*/])*"

identifier      [a-zA-Z_][a-zA-Z0-9+]*
illidentifier   [0-9][a-zA-Z0-9]*

yylineno = 1;

%%

 /* rules */

 /* Keywords */;
	//TODO: Support all keywords in mC
	/* Define keyword rules */
	if       { updateCol(); return if; }
	else     { updateCol(); return else; }
	while    { updateCol(); return while; }
	do       { updateCol(); return do; }
	for      { updateCol(); return for; }
	break    { updateCol(); return break; }
	continue { updateCol(); return continue; }
	switch   { updateCol(); return switch; }
	case     { updateCol(); return case; }
	default  { updateCol(); return default; }
	return   { updateCol(); return return; }
	goto     { updateCol(); return goto; }

	int      { updateCol(); return int; }
	char     { updateCol(); return char; }
	float    { updateCol(); return float; }
	double   { updateCol(); return double; }
	void     { updateCol(); return void; }
	short    { updateCol(); return short; }
	long     { updateCol(); return long; }
	unsigned { updateCol(); return unsigned; }
	signed   { updateCol(); return signed; }

	static   { updateCol(); return static; }
	typedef  { updateCol(); return typedef; }

	sizeof   { updateCol(); return sizeof; }
	struct   { updateCol(); return struct; }
	
 /* Operators */;
	//TODO: Support all operators in mC
	//added comment

 /* Delimiter */

 /* Identifiers */;
{identifier}    { updateCol(); return IDENTIFIER; } 	//TODO (done)
{illidentifier} { updateCol(); yyerror = "Illegal idetifier: Cannot start with a digit"; return ERROR; } 	//TODO (done)

 /* Constants */;
{integer}       { updateCol(); return INT; }
{integerlead0}  { updateCol(); yyerror = "Integers mayy not have leading zero"; return ERROR; }				//TODO: "Integers may not have leading zeros" (done)
{character}     { updateCol(); return CHAR; }
{string}        { updateCol(); return processString(); }
{untermstring}  { updateCol(); yyerror = "Unterminated string"; return ERROR; }
{multlnstring}  { updateCol(); countLines(); yyerror = "String spans multiple lines"; return ERROR; } 		// Catching a multi-line string and generating an error.

 /* Comments */;
{comment}       { updateCol(); return COMMENT }										//TODO (done)
{untermcomment} { updateCol(); coutLines(); return COMMENT }						//TODO (done)
{multlncomment} { updateCol(); yyerrror = "Unterminated comment"; return ERROR; }	//TODO (done)

 /* Other */;
{newline}		{ scanlineno++; yycol = 1; updateCol(); }       	//TODO (done), this resets the column count when it hit a newline or \n
{whitespace}    { updateCol(); }								//TODO (done) Ignores whitspace
.               { return ILLEGAL_TOK; }

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

/* Process String Literal (Uses yytext Directly) */
int processString(){
	// TODO: Process a string literal and return the appropriate microsyntax. (done)

	char processedStr[1024];			//Buffer for processed string
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
				default;
					yyerror = "illegal escape sequence";
					return ERROR;
 
			}

		} else {

			processed[j++] = str[i];

		}

		i++;

	}

	processedStr[j] = '\0';
	printf("Processed String: %s\n", processedStr);		//Debugging output
	return STRING;										//Return string token

}