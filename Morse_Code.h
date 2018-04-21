#ifndef MORSE_H_
#define MORSE_H_

#include <string>
#include <fstream>
#include <map>
#include <iostream>

using namespace std;

class Morse_Code {

private:
	char letter;
	string morse;

public:
	map<char, string>Morse_Map;//The last line in the technical requirements says "You may use a binary search tree or a map to store the codes for letters."
	//I've emailed the instructor for clarification because it seemed easier to store the values in a map. 
	//I made the map public for now because I was struggling with the getter. We can fix that and make it private later if needed.
	//Reply from instructor said "The map or BST is intended for encoding whereas the Morse tree is intended for decoding. That means you still need
	//to build the Morse tree and use it for decoding."
		
	void create_morse_map()//Function to populate the map with the letters and morse code equivalent.
	{
		ifstream fin("morse.txt");//read from the morse.txt file provided by instructor
		while (fin >> letter >> morse)//while there is still another line to read
		{
			Morse_Map[letter] = morse;//set key to letter and value to the associated morse code
		}
	}

	void create_morse_tree()//Function to populate a tree with letters and morse code equivalents
	{


	}

	string decode_msg(string input)//Function accepts morse code input string to and returns result of conversion
	{

	}

	string encode_msg(string input)//Function accepts input string and returns morse code result 
	{
		string result = "";//initialize result string to null
		for (int i = 0; i < input.size(); i++)//for loop to go through each character in the input string
		{
			result += Morse_Map[input[i]] + " ";//add morse code result of each character to result string followed by a space
		}
		return result;//return result string
	}
};
#endif

