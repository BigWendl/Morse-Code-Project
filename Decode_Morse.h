#ifndef DECODE_MORSE_H_
#define DECODE_MORSE_H_

#include <string>
#include <fstream>
#include <map>
#include <iostream>

using namespace std;

class Decode_Morse {

private:
	char letter;
	string morse;

public:
	map<char, string>Morse_Map;//The last line in the technical requirements says "You may use a binary search tree or a map to store the codes for letters."
	//I've emailed the instructor for clarification because it seemed easier to store the values in a map. 
	//I made the map public for now because I was struggling with the getter. We can fix that and make it private later if needed.
		
	void create_morse_map()//Function to populate the map with the letters and morse code equivalent.
	{
		ifstream fin("morse.txt");//read from the morse.txt file provided by instructor
		while (fin >> letter >> morse)//while there is still another line to read
		{
			Morse_Map[letter] = morse;//set key to letter and value to the associated morse code
		}
	}

	string decode_msg(string input)//Need a function that will accept an input string to convert FROM morse code
	{

	}

	string code_msg(string input)//Need a function that will accept an input string to convert TO morse code
	{


	}
};
#endif
