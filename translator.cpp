#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
using namespace std;
/* Look for all **'s and complete them */
//=====================================================
// File scanner.cpp written by: Group Number: 20
//=====================================================
// --------- Two DFAs ---------------------------------
// WORD DFA
// Done by: Robert Painter
// RE: (vowel | vowel n | constant vowel | constant vowel n | constant-pair vowel | constant-pair
vowel n) ^ +
bool word(string s)
{
	int state = 0;
	int charpos = 0;
	while (s[charpos] != '\0')
	{

		// state0 (q0 to other states)
		if (state == 0 && (s[charpos] == 'b' || s[charpos] == 'g' || s[charpos] == 'h' || s[charpos] ==
			'k' || s[charpos] == 'm' || s[charpos] == 'n' || s[charpos] == 'p' || s[charpos] == 'r'))
			state = 2;
		else if (state == 0 && (s[charpos] == 'd' || s[charpos] == 'w' || s[charpos] == 'z' ||
			s[charpos] == 'y' || s[charpos] == 'j'))
			state = 1;
		else if (state == 0 && (s[charpos] == 'a' || s[charpos] == 'e' || s[charpos] == 'i' || s[charpos]
			== 'o' || s[charpos] == 'u' || s[charpos] == 'I' || s[charpos] == 'E'))
			state = 6;
		else if (state == 0 && s[charpos] == 't')
			state = 3;
		else if (state == 0 && s[charpos] == 's')
			state = 4;
		else if (state == 0 && s[charpos] == 'c')
			state = 5;
		// state1 (qsa to other states)
		else if (state == 1 && (s[charpos] == 'a' || s[charpos] == 'e' || s[charpos] == 'i' || s[charpos]
			== 'o' || s[charpos] == 'u' || s[charpos] == 'I' || s[charpos] == 'E'))
			state = 6;
		// state2 (qy to other states)
		else if (state == 2 && (s[charpos] == 'a' || s[charpos] == 'e' || s[charpos] == 'i' || s[charpos]
			== 'o' || s[charpos] == 'u' || s[charpos] == 'I' || s[charpos] == 'E'))
			state = 6;
		else if (state == 2 && s[charpos] == 'y')
			state = 1;
		// state3 (qt to other states)
		else if (state == 3 && (s[charpos] == 'a' || s[charpos] == 'e' || s[charpos] == 'i' || s[charpos]
			== 'o' || s[charpos] == 'u' || s[charpos] == 'I' || s[charpos] == 'E'))
			state = 6;
		else if (state == 3 && s[charpos] == 's')
			state = 1;
		// state4 (qs to other states)
		else if (state == 4 && (s[charpos] == 'a' || s[charpos] == 'e' || s[charpos] == 'i' || s[charpos]
			== 'o' || s[charpos] == 'u' || s[charpos] == 'I' || s[charpos] == 'E'))
			state = 6;
		else if (state == 4 && s[charpos] == 'h')
			state = 1;
		// state5 (qc to other states)
		else if (state == 5 && s[charpos] == 'h')
			state = 1;
		// state6 (q0q1 to other states)
		else if (state == 6 && (s[charpos] == 'b' || s[charpos] == 'g' || s[charpos] == 'h' ||
			s[charpos] == 'k' || s[charpos] == 'm' || s[charpos] == 'p' || s[charpos] == 'r'))
			state = 2;
		else if (state == 6 && (s[charpos] == 'd' || s[charpos] == 'w' || s[charpos] == 'z' ||
			s[charpos] == 'y' || s[charpos] == 'j'))
			state = 1;
		else if (state == 6 && (s[charpos] == 'a' || s[charpos] == 'e' || s[charpos] == 'i' || s[charpos]
			== 'o' || s[charpos] == 'u' || s[charpos] == 'I' || s[charpos] == 'E'))
			state = 6;

		else if (state == 6 && s[charpos] == 'n')
			state = 7;
		else if (state == 6 && s[charpos] == 's')
			state = 4;
		else if (state == 6 && s[charpos] == 't')
			state = 3;
		else if (state == 6 && s[charpos] == 'c')
			state = 5;
		// state7 (q0qy to other states)
		else if (state == 7 && (s[charpos] == 'b' || s[charpos] == 'g' || s[charpos] == 'h' ||
			s[charpos] == 'k' || s[charpos] == 'm' || s[charpos] == 'n' || s[charpos] == 'p' || s[charpos] == 'r'))
			state = 2;
		else if (state == 7 && (s[charpos] == 'd' || s[charpos] == 'w' || s[charpos] == 'z' ||
			s[charpos] == 'y' || s[charpos] == 'j'))
			state = 1;
		else if (state == 7 && (s[charpos] == 'a' || s[charpos] == 'e' || s[charpos] == 'i' || s[charpos]
			== 'o' || s[charpos] == 'u' || s[charpos] == 'I' || s[charpos] == 'E'))
			state = 6;
		else if (state == 7 && s[charpos] == 's')
			state = 4;
		else if (state == 7 && s[charpos] == 't')
			state = 3;
		else if (state == 7 && s[charpos] == 'c')
			state = 5;
		else // invalid character
		{
			return(false);
		}
		charpos++; // increment character position
	} //end of while
	// check if we are at the end state
	if (state == 0 || state == 6 || state == 7) return (true);
	else return(false);
}
// PERIOD DFA
// Done by: Robert Painter
bool period(string s)
{ // check for period
	if (s == ".")
		return(true);
	else
		return(false);
}
// ------ Three Tables -------------------------------------
// TABLES Done by: Brandon Nguyen

// ** Update the tokentype to be WORD1, WORD2, PERIOD, ERROR, EOFM, etc.
enum tokentype {
	ERROR, VERB, VERBNEG, VERBPAST, VERBPASTNEG, IS, WAS,
	OBJECT, SUBJECT, DESTINATION, PRONOUN, CONNECTOR, EOFM, WORD1, WORD2,
	PERIOD
};
// ** For the display names of tokens - must be in the same order as the tokentype.
string tokenName[30] = { "ERROR", "VERB", "VERBNEG", "VERBPAST", "VERBPASTNEG",
"IS", "WAS", "OBJECT", "SUBJECT", "DESTINATION", "PRONOUN", "CONNECTOR",
"EOFM", "WORD1", "WORD2", "PERIOD" };
// ** Need the reservedwords table to be set up here.
string reservedwords[30] = { "masu", "masen", "mashita", "masendeshita", "desu", "deshita", "o",
"wa", "ni", "watashi",
"anata", "kare", "kanojo", "sore", "mata", "soshite", "shikashi", "dakara", "eofm" };
// ** Do not require any file input for this. Hard code the table.
// ** a.out should work without any additional files.
// ------------ Scanner and Driver -----------------------
ifstream fin; // global stream for reading from the input file
// Scanner processes only one word each time it is called
// Gives back the token type and the word itself
// ** Done by: Mohammed Ramlaoui
int scanner(tokentype& tt, string& w)
{
	// ** Grab the next word from the file via fin
	// 1. If it is eofm, return right now.
	/* **
	2. Call the token functions (word and period)
	one after another (if-then-else).
	Generate a lexical error message if both DFAs failed.
	Let the tokentype be ERROR in that case.
	3. If it was a word,
	check against the reservedwords list.
	If not reserved, tokentype is WORD1 or WORD2
	decided based on the last character.
	4. Return the token type & string (pass by reference)
	*/
	fin >> w; // read in word
	int count = -1; // count initalied at -1, used to determine the token (word) type
	if (w == "eofm") // if the word is "eofm"
		return 0; // exit

		// check if the word is a period, then tokentype is period
	if (period(w))
		tt = PERIOD;
	else if (word(w)) // else if check w is a valid word
	{
		// for loop to iterrate through the reserved words array and increment count when word
		(w)matches a word in the reserved words array
			for (int i = 0; i < 19; i++)
			{
				// if the word matches a word in the reserved words array, then count gets i
				if (reservedwords[i] == w)
					count = i;
			}
		// if count = -1
		if (count < 0)
		{
			// if the last character in the word is 'I' or 'E' then the tokentype is WORD2
			if (w[w.size() - 1] == 'I' || w[w.size() - 1] == 'E')
				tt = WORD2;
			else // if not, then tokentype is WORD1
				tt = WORD1;
		}
		// if count = 0, then the tokentype is a verb
		else if (count == 0)
			tt = VERB;
		// if count = 1, then the tokentype is a verbneg
		else if (count == 1)
			tt = VERBNEG;
		// if count = 2, then the tokentype is a verbpast
		else if (count == 2)
			tt = VERBPAST;
		// if count = 3, then the tokentype is a verbpastneg
		else if (count == 3)
			tt = VERBPASTNEG;
		// if count = 4, then the tokentype is a is
		else if (count == 4)
			tt = IS;
		// if count = 5, then the tokentype is a was
		else if (count == 5)
			tt = WAS;
		// if count = 6, then the tokentype is an object
		else if (count == 6)
			tt = OBJECT;
		// if count = 7, then the tokentype is a subject
		else if (count == 7)
			tt = SUBJECT;
		// if count = 8, then the tokentype is a destination
		else if (count == 8)
			tt = DESTINATION;
		// if count = 9, 10, 11, 12, or 13, then the tokentype is a pronoun
		else if (count == 9 || count == 10 || count == 11 || count == 12 || count == 13)

			tt = PRONOUN;
		// if count = 14, 15, 16, 17, or 18, then the tokentype is a connector
		else if (count == 14 || count == 15 || count == 16 || count == 17 || count == 18)
			tt = CONNECTOR;
	}
	else // Error, token is invalid
	{
		cout << "Lexical error: " << w << " is not a valid token" << endl;
		tt = ERROR;
	}
}//the end of scanner
//////////////// Parser.cpp /////////////////
/* INSTRUCTION: Complete all ** parts.
You may use any method to connect this file to scanner.cpp
that you had written.
e.g. You can copy scanner.cpp here by:
cp ../ScannerFiles/scanner.cpp .
and then append the two files into one:
cat scanner.cpp parser.cpp > myparser.cpp
*/
//=================================================
// File parser.cpp written by Group Number: 20
//=================================================
// ----- Four Utility Functions and Globals -----------------------------------
string saved_lexeme; // holds the word
tokentype saved_token; // holds the word (token) type
bool token_toCheck; // True if the next token has already been checked by next_token()
// ** Need syntaxerror1 and syntaxerror2 functions (each takes 2 args)
//
to display syntax error messages as specified by me.
// Type of error: Match Fails
// Done by: Mohammed Ramlaoui (We all implemented the EC for skip token)
void syntaxerror1(tokentype token_type, string saved_lexeme) // when the token type does not
match the expected word
{
	char skipresp; // skip response from the user
	cout << "SYNTAX ERROR: expected " << tokenName[token_type] << " but found " <<
		saved_lexeme << endl;
	cout << "Error occurred, skip to next token? y or n? "; // prompt user to skip // extra credit
	cin >> skipresp;
	// if user wants to skip to next token 'y' // extra credit
	if (skipresp == 'y')
	{
		cout << "token skipped\n";

		return; // allows the program to continue working but not end the program
	}
	else
		exit(1); // exit program due to error found
}
// Type of error: Switch Default
// Done by: Mohammed Ramlaoui
void syntaxerror2(string saved_lexeme, string parser_function) // when a word fails all cases in a
non - terminal function
{
cout << "SYNTAX ERROR: unexpected " << saved_lexeme << " found in " << parser_function
<< endl;
exit(1); // exit program due to error found
}
// ** Need the updated match and next_token with 2 global vars
// saved_token and saved_lexeme
// Purpose: Check the next token. If there is a token return the type, otherwise no next token will
return a syntax error.Returns the saved token type.
// Done by: Brandon Nguyen
tokentype next_token()
{
	string word; //Holds the word that was found as next
	if (!token_toCheck) //Continues if the next token hasn't been checked
	{
		scanner(saved_token, word); //Scan to see the next word and return type and word
		cout << "\nScanner called using word: " << word << endl;
		if (saved_token == ERROR) //Print error if scanner returns an error
			cout << "Lexical Error: " << word << " is not a valid token\n"; //TODO: make a flag to exit
		program
			token_toCheck = true; //Set after being checked
		saved_lexeme = word; //Set the saved word
	}
	return(saved_token);
}
// Purpose: Check if the next token type matches the expected. Eat the token and return true. If it doesn't match return false with a syntax error.
// Done by: Brandon Nguyen
bool match(tokentype expected)
{
	if (next_token() != expected) //Return false if there is a mismatch between expected and
		checked word type
	{
	syntaxerror1(expected, saved_lexeme); //Print error to user
	return false;
	}

	else //The type is matched
	{
		cout << "Matched " << tokenName[expected] << endl;
		token_toCheck = false; //"Eats" the token
		return true;
	}
}
// ----- RDP functions - one per non-term -------------------
// ** Make each non-terminal into a function here
// ** Be sure to put the corresponding grammar rule above each function
// ** Be sure to put the name of the programmer above each function
// prototypes for non-terminal functions
void s();
void after_subject();
void after_noun();
void after_object();
void noun();
void verb();
void be();
void tense();
void getEword();
void gen(string);
// Grammer: <story> ::= <s> { <s> }
// Done by: Mohammed Ramlaoui
void story()
{
	bool is_S = true; // boolean variable created and initialized to true, used to determine if a word
	can be parsed
		cout << "Processing <story>\n" << endl;
	s(); // call non-terminal function s()
	while (is_S) // while is_S is true, loop
	{
		// if the next token type is a connector, word1, or a pronoun. Call the non-terminal
		function s() to begin parsing
			if (next_token() == CONNECTOR || next_token() == WORD1 || next_token() ==
				PRONOUN)
				s();
			else // set is_S to false
				is_S = false;
	}
}
// Grammar: <s> ::= [CONNECTOR #getEword# #gen("CONNECTOR")#] <noun> #getEword#
SUBJECT #gen("ACTOR")# <after subject>

// Done by: Mohammed Ramlaoui, Brandon Nguyen, Robert Painter
void s()
{
	cout << "Processing <s>\n" << endl;
	// if the next token type is a connector
	if (next_token() == CONNECTOR)
	{
		match(CONNECTOR); // call match() to determine whether the expected
		(CONNECTOR)token type matches the next token type
			getEword();
		// call getEword() to get the corresponding english word for a japanese
		word
			gen("CONNECTOR"); // word is CONNECTOR
	}
	noun();
	// call non-terminal function noun()
	getEword();
	// call getEword() to get the corresponding english word for a japanese word
	match(SUBJECT); // call match() to determine whether the expected (SUBJECT) token type
	matches the next token type
		gen("ACTOR");
	// word is ACTOR
	after_subject(); // call non-terminal function after_subject()
}
// Grammer: <after subject> ::= <verb> #getEword# #gen("ACTION") <tense> #gen("TENSE)#
PERIOD | <noun> #getEword# <after noun>
// Done by: Mohammed Ramlaoui, Brandon Nguyen, Robert Painter
void after_subject()
{
	cout << "Processing <after subject>\n" << endl;
	switch (next_token()) // switch between token types
	{
	case WORD2:
		// case WORD2 handles verb
		match(WORD2); // call match() to determine whether the expected (WORD2) token type
		matches the next token type
			getEword();
		// call getEword() to get the corresponding english word for a japanese
		word
			gen("ACTION"); // word is ACTION
		tense();
		// call non-terminal function tense()
		gen("TENSE"); // word is TENSE
		match(PERIOD); // call match() to determine whether the expected (PERIOD) token type
		matches the next token type
			break;
		// break out of switch block
	case WORD1:
		// case WORD1 handles noun
	case PRONOUN:
		// case handles PRONOUN (Particles)
		noun();
		// call non-terminal function noun()
		getEword();
		// call getEword() to get the corresponding english word for a japanese
		word
			after_noun(); // call non-terminal function after_noun()
		break;
		// break out of switch block
	default:
		// no case matches
		syntaxerror2(saved_lexeme, "after_subject"); // call syntaxerror2() function

		break; // break out of switch block
	}
}
// Grammer: <after noun> ::= <be> #gen(“DESCRIPTION”)# #gen(“TENSE”)# PERIOD |
DESTINATION #gen(“TO”)# <verb> #getEword# #gen(“ACTION”)# <tense> #gen(“TENSE”)#
PERIOD | OBJECT #gen(“OBJECT”)# <after object>
// Done by: Mohammed Ramlaoui, Brandon Nguyen, Robert Painter
void after_noun()
{
	cout << "Processing <after noun>\n" << endl;
	switch (next_token()) // switch between token types
	{
	case IS:
		// case handles IS (Verb Marker)
	case WAS:
		// case handles WAS (Verb Marker)
		be();
		// call non-terminal function be()
		gen("DESCRIPTION"); // word is DESCRIPTION
		gen("TENSE");
		// word is TENSE
		match(PERIOD);
		// call match() to determine whether the expected (PERIOD) token
		type matches the next token type
			break;
		// break out of switch block
	case DESTINATION: // case handles DESTINATION (Particles)
		match(DESTINATION); // call match() to determine whether the expected
		(DESTINATION)token type matches the next token type
			gen("TO");
		// word is TO
		verb();
		// call non-termianl function verb()
		getEword();
		// call getEword() to get the corresponding english word for a
		japanese word
			gen("ACTION");
		// word is ACTION
		tense();
		// call non-terminal function tense()
		gen("TENSE");
		// word is TENSE
		match(PERIOD);
		// call match() to determine whether the expected (PERIOD) token
		type matches the next token type
			break;
		// break out of switch block
	case OBJECT:
		// case handles OBJECT (Particles)
		match(OBJECT);
		// call match() to determine whether the expected (OBJECT) token
		type matches the next token type
			gen("OBJECT");
		// word is OBJECT
		after_object(); // call non-terminal function after_object()
		break;
		// break out of switch block
	default:
		// no case matches
		syntaxerror2(saved_lexeme, "after_noun"); // call syntaxerror2() function
		break; // break out of switch block
	}
}
// Grammar: <after_object> ::= [<noun> #getEword# DESTINATION #gen(“TO”)#] <verb>
#getEword# #gen(“ACTION”)# <tense> #gen(“TENSE”)# PERIOD
// Done by: Brandon Nguyen, Mohammed Ramlaoui, Robert Painter
void after_object()
{

	cout << "Processing <after_object>\n";
	// if the next token type is a word1 or a pronoun
	if (next_token() == WORD1 || next_token() == PRONOUN)
	{
		noun();
		// call non-terminal function noun()
		getEword();
		// call getEword() to get the corresponding english word for a
		japanese word
			match(DESTINATION); // call match() to determine whether the expected
		(DESTINATION)token type matches the next token type
			gen("TO");
		// word is TO
	}
	verb();
	// call non-terminal function verb()
	getEword();
	// call getEword() to get the corresponding english word for a japanese word
	gen("ACTION"); // word is ACTION
	tense();
	// call non-terminal function tense()
	gen("TENSE"); // word is TENSE
	match(PERIOD); // call match() to determine whether the expected (PERIOD) token type
	matches the next token type
}
// Grammar: <noun> ::= WORD1 | PRONOUN
// Done by: Brandon Nguyen
void noun()
{
	cout << "Processing <noun>\n";
	switch (next_token()) // switch between token types
	{
	case WORD1:
		// case WORD1 handles noun
		match(WORD1); // call match() to determine whether the expected (WORD1) token
		type matches the next token type
			break;
		// break out of switch block
	case PRONOUN:
		// handles PRONOUN
		match(PRONOUN); // call match() to determine whether the expected (PRONOUN)
		token type matches the next token type
			break;
		// break out of switch block
	default:
		// no case matches
		syntaxerror2(saved_lexeme, "noun"); // call syntaxerror2() function
	}
}
// Grammar: <verb> ::= WORD2
// Done by: Brandon Nguyen
void verb()
{
	cout << "Processing <verb>\n";
	match(WORD2); // call match() to determine whether the expected (WORD2) token type
	matches the next token type
}
// Grammer: <be> ::= IS | WAS

// Done by: Robert Painter
void be()
{
	cout << "Processing <be>\n" << endl;
	switch (next_token()) // switch between token types
	{
	case IS:
		// case handles IS (Verb Marker)
		match(IS); // call match() to determine whether the expected (IS) token type matches
		the next token type
			break;
		// break out of switch block
	case WAS:
		// case handles WAS (Verb Marker)
		match(WAS); // call match() to determine whether the expected (WAS) token type
		matches the next token type
			break;
		// break out of switch block
	default:
		// no case matches
		syntaxerror2(saved_lexeme, "be"); // call syntaxerror2() function
		break; // break out of switch block
	}
}
// Grammer: <tense> ::= VERBPAST | VERBPASTNEG | VERB | VERBNEG
// Done by: Robert Painter
void tense()
{
	cout << "Processing <tense>\n" << endl;
	switch (next_token()) // switch between token types
	{
	case VERBPAST:
		// case handles VERBPAST (Verb Marker)
		match(VERBPAST);
		// call match() to determine whether the expected (VERBPAST)
		token type matches the next token type
			break;
		// break out of switch block
	case VERBPASTNEG:
		// case handles VERBPASTNEG (Verb Marker)
		match(VERBPASTNEG); // call match() to determine whether the expected
		(VERBPASTNEG)token type matches the next token type
			break;
		// break out of switch block
	case VERB:
		// case handles VERB (Verb Marker)
		match(VERB);
		// call match() to determine whether the expected (VERB) token
		type matches the next token type
			break;
		// break out of switch block
	case VERBNEG:
		// case handles VERBNEG (Verb Marker)
		match(VERBNEG);
		// call match() to determine whether the expected (VERBNEG)
		token type matches the next token type
			break;
		// break out of switch block
	default:
		// no case matches
		syntaxerror2(saved_lexeme, "tense"); // call syntaxerror2() function
		break; // break out of switch block
	}
}
string filename; // filename declared to be used in main() to take file inputed by user

//----------- Driver ---------------------------
/*
// The new test driver to start the parser
// Done by: Robert Painter
int main()
{
cout << "Enter the input file name: ";
cin >> filename; // user inputs input file name to be read from
fin.open(filename.c_str()); // file is opened
story();
// calls the <story> to start parsing
fin.close(); // closes the input file
cout << "\nSuccessfully parsed <story>." << endl;
}// end
//** require no other input files!
//** syntax error EC requires producing errors.txt of error messages
//** tracing On/Off EC requires sending a flag to trace message output functions
*/
///////////////// translator.cpp //////////////////////
/* INSTRUCTION: copy your parser.cpp here
cp ../ParserFiles/parser.cpp .
Then, insert or append its contents into this file and edit.
Complete all ** parts.
*/
//=================================================
// File translator.cpp written by Group Number: 20
//=================================================
// ----- Additions to the parser.cpp ---------------------
//Global variable
ofstream output; // global stream to print output to translated.txt
string saved_E_word; // English translation of word from getEword() [or jpn word if translation
not found]
string JapToEng[47][2]; // 2D-array to hold contents of lexicon.txt
// ** Declare Lexicon (i.e. dictionary) that will hold the content of lexicon.txt
// Make sure it is easy and fast to look up the translation.
// Do not change the format or content of lexicon.txt
// Done by: Mohammed Ramlaoui
void readLexicon()
{
	// for loop to cylce through each row
	for (int i = 0; i < 47; i++)
	{
		// nested for to cyle through each column

		for (int j = 0; j < 2; j++)
		{
			fin >> JapToEng[i][j]; // read content of lexicon.txt into 2D-array
		}
	}
}
// ** Additions to parser.cpp here:
//
getEword() - using the current saved_lexeme, look up the English word
//
in Lexicon if it is there -- save the result
//
in saved_E_word
// Done by: Robert Painter
void getEword()
{
	int i = 0; // temporary variable
	// keep looping until every word is checked
	for (int i = 0; i < 47; i++)
	{
		// if statement incase japanese word matches japenese in lexicon
		if (JapToEng[i][0] == saved_lexeme)
		{
			saved_E_word = JapToEng[i][1]; // overwrites the saved_E_word to second column of the
			JapToEng array
				return; // exits the function once found
		}
	}
	// if japanese word not found, enter function
	if (i == 46) {
		saved_E_word = saved_lexeme; // overwrite saved_E_word with japanese word that we
		looked for in lexicon
			return; // exit the function
	}
}
//
gen(line_type) - using the line type,
//
sends a line of an IR to translated.txt
//
(saved_E_word or saved_token is used)
// Done by: Brandon Nguyen
void gen(string line_type)
{
	output << line_type << ": "; // Print the line type into the file
	if (line_type == ("TENSE")) // Check if is tense
		output << tokenName[saved_token] << endl; // Print tokentype
	else
		output << saved_E_word << endl; // If not, print the word
	return;
}
// ----- Changes to the parser.cpp content ---------------------

// ** Comment update: Be sure to put the corresponding grammar
//
rule with semantic routine calls
//
above each non - terminal function
// ** Each non-terminal function should be calling
//
getEword and /or gen now.
// ---------------- Driver ---------------------------
// The final test driver to start the translator
// Done by: Mohammed Ramlaoui
int main()
{
	fin.open("lexicon.txt"); // opens the lexicon.txt file and reads it into Lexicon
	readLexicon(); // call readLexicon
	fin.close(); // closes lexicon.txt
	output.open("translated.txt"); // opens the output file translated.txt
	cout << "Enter the input file name: ";
	cin >> filename;
	fin.open(filename.c_str());
	story(); // calls the <story> to start parsing
	fin.close();
	// closes the input file
	output.close(); // closes traslated.txt
}// end
//** require no other input files!
//** syntax error EC requires producing errors.txt of error messages
//** tracing On/Off EC requires sending a flag to trace message output functions