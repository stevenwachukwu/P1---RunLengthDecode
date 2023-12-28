/*Steve Nwachukwu
Data Structures and Algorithms
Spring 2023
P1 - RunLengthDecode*/

#pragma once
#include <iostream> //input/output library
#include <fstream> //file library
using namespace std;

int main()
{
	char mycharacter; //the input character(s) from compressed.txt
	char mycounter; //the character variable for the letter counter
	ofstream ConsoleOutput("console_output.ext"); //using outputfile stream as a console output for "console_output.ext"
	ifstream FileInput("compressed.txt"); //using inputfile stream as a file input for "compressed.txt"


	if (!FileInput.is_open()) {
		cout << "The Input file could not be opened." << endl;
		return 0;
	} //The program will print out a message if it can't open the input file of "compressed.txt"
	if (!ConsoleOutput.is_open()) {
		cout << "The Console Output file could not be opened." << endl;
		return 0;
	} //The program will print out a message if it can't open the console output file

	while (true) {
		FileInput >> noskipws >> mycharacter; //reading in the input character (without skipping whitespace) from "compressed.txt"
		if (FileInput.eof()) {
			cout << "\n\nYou have reached the end of the file." << endl;
			ConsoleOutput << "\n\nYou have reached the end of the file." << endl;
			return 0;
		} //The program will output the end of file message to both the console and the console_output file
		if (mycharacter != 0x7f) {
			cout << mycharacter;
			ConsoleOutput << mycharacter;
		} //The program will print out your character to both the console and the console_output file only if it isn't an escape character
		else {
			FileInput >> mycharacter; //the first read in char
			FileInput >> mycounter; //the second read in char
			for (int i = 0; i < (unsigned short int) mycounter; i++) {
				cout << mycharacter;
				ConsoleOutput << mycharacter;
			} //The for loop is used to output the multiple copies of a character

		}
	}

};

