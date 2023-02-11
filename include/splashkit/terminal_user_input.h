//This is the beginning of the Header Guard which protects against duplicate header inclusions
#ifndef TERMINAL_USER_INPUT
#define TERMINAL_USER_INPUT
#include <string>
using std::string;

// This function reads a string from user input, then returns the result
string read_name(string message);

//This function reads a string from user input, then converts that string to an integer and returns the result
int read_integer (string prompt);

// Ends the if statement
#endif