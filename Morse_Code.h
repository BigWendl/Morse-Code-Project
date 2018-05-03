#ifndef MORSE_H_
#define MORSE_H_

#include <string>
#include <fstream>
#include <map>
#include <iostream>
#include "Binary_Search_Tree.h"

using namespace std;

class Morse_Code {
private:
	char letter, dot = '.', dash = '_';
	string morse;
	Binary_Search_Tree<char> letterTree;
	map<char, string>Morse_Map;

	void create_morse_map()//Function to populate the map with the letters and morse code equivalent.
	{
		ifstream fin("morse.txt");//read from the morse.txt file provided by instructor
		while (fin >> letter >> morse)//while there is still another line to read
		{
			Morse_Map[letter] = morse;//set key to letter and value to the associated morse code
		}
	}
	void buildTree() //wrapper function to build the letter binary tree
	{
		letterTree.insert(' ');
		ifstream in("morse.txt");

		while (in >> letter >> morse) 
		{
			insert(letter, morse);
		}
	}
	void insert(char letter, string code)//places each node in correct node
	{
		BTNode<char> *n = letterTree.getRoot();
		for (int i = 0; i < code.size(); i++)
		{

				if (code[i] == '.') 
				{
					if (n->left)
						n = n->left;
					else
					{
						n->left = new BTNode<char> (' ', NULL, NULL);
						n = n->left;
					}
				}
				else 
				{
					if (n->right)
						n = n->right;
					else
					{
						n->right = new BTNode<char> (' ', NULL, NULL);
						n = n->right;
					}
				}
		}
		if (n == NULL)
			n = new BTNode<char>(letter, NULL, NULL);
		else if (n->data == ' ')
			n->data = letter;
	}

public:
	string decode_msg(string input)//Function accepts morse code input string to and returns result of conversion
	{		
		buildTree();
		BTNode<char>* n = letterTree.getRoot();
		string result = "", mCode;

		istringstream tokens(input);

		while (tokens >> mCode)//evaulate each letter individually
		{
			n = letterTree.getRoot();//set to root of tree

			for (int i = 0; i < mCode.size(); i++)//run through entire size of the given code
			{	
				if (mCode[i] != '.' && mCode[i] != '_')
					return "Character is not valid for decoding morse code.";
				else if (mCode[i] == dot)//if code has a dot nagviate the left side of the tree
					n = n->left;
				else if (mCode[i] == dash)//if code has a dot nagviate the right side of the tree
					n = n->right;
			}

			result += n->data;//add each letter as found
		}
		return result;
	}
	string encode_msg(string input)//Function accepts input string and returns morse code result 
	{
		create_morse_map();
		string result = "";//initialize result string to null

		for (int i = 0; i < input.size(); i++)//for loop to go through each character in the input string
			result += Morse_Map[input[i]] + " ";//add morse code result of each character to result string followed by a space

		return result;//return result string
	}
};
#endif

