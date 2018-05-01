#ifndef MORSE_H_
#define MORSE_H_

#include <string>
#include <fstream>
#include <map>
#include <iostream>
#include "Binary_Tree.h" 

using namespace std;

class Morse_Code {

private:
	char letter;
	string morse;
	vector<string> codeVector{ " ",".","..","...","....","NULL","NULL","..._","NULL","NULL",".._",".._.","NULL","NULL","NULL","._","._.","._..","NULL","NULL","NULL",".__",".__.","NULL","NULL",".___","NULL","NULL","_","_.","_..","_...","NULL" ,"NULL","_.._","NULL" ,"NULL" ,"_._","_._.","NULL","NULL","_.__","NULL","NULL","__","__.","__..","NULL","NULL","__._","NULL","NULL","___","NULL","NULL" };
	vector<string> letterVector{ " ","e","i","s","h","NULL","NULL","v","NULL","NULL","u","f","NULL","NULL","NULL","a","r","l","NULL","NULL","NULL","w","p","NULL","NULL","j","NULL","NULL","t","n","d","b","NULL" ,"NULL","x","NULL" ,"NULL" ,"k","c","NULL","NULL","y","NULL","NULL","m","g","z","NULL","NULL","q","NULL","NULL","o","NULL","NULL" };
	
public:
	map<char, string>Morse_Map;//Map for encoding Morse Code
		
	void create_morse_map()//Function to populate the map with the letters and morse code equivalent.
	{
		ifstream fin("morse.txt");//read from the morse.txt file provided by instructor
		while (fin >> letter >> morse)//while there is still another line to read
		{
			Morse_Map[letter] = morse;//set key to letter and value to the associated morse code
		}
	}
	// builds the tree
	string buildTree(string& filename) {
		string result = "", mCode;
		
		ifstream in(filename);
		if (!in) {
			cout << "cannot find file specified";
		}
		std::string str;
		while (std::getline(in, str)) {
			Insert2(str[0], str.erase(0));
		}
	}
	//inserts data into the node
	void Insert1(Node *&n, char letter, string code) {
		if (n == NULL) {
			n = new Node;
			n->l = letter;
			n->code = code;
			n->left = n->right = NULL;
		}
	}
	//wrapper function for insertion methods
	void Insert2(char letter, string code) {
		Node *n = root;
		if (n != NULL) {
			for (int i = 0; i < code.length(); i++) {
				if (code[i] != '.' || code[i] != '_')
					
				if (code[i] == '.') {
					if (n->left)
						n = n->left;
					else {
						break;
					}
				}
				else {
					if (n->right)
						n = n->right;
					else
						break;
				}
				
			}
			Insert1(n, letter, code);

		}
		else Insert1(root, letter, code);
		

	}
	
	string decode_msg(string input)//Function accepts morse code input string to and returns result of conversion
	{		
		string result = "", mCode;
		Binary_Tree<string> letter;
		letter.read_tree(letterVector);
		Binary_Tree<string> code;
		code.read_tree(codeVector);

		istringstream tokens(input);

		while (tokens >> mCode)
		{
			for (int i = 0; i < mCode.size(); i++)
			{
				if (mCode[i] == '.')
					letter = letter.get_left_subtree();
				if (mCode[i] == '_')
					letter = letter.get_right_subtree();
			}

			result += letter.get_data();
			letter.read_tree(letterVector);
		}
		return result;
	}

	string encode_msg(string input)//Function accepts input string and returns morse code result 
	{
		string result = "";//initialize result string to null
		for (int i = 0; i < input.size(); i++)//for loop to go through each character in the input string
		{
			result += Morse_Map[input[i]] + "|";//add morse code result of each character to result string followed by a space
		}
		return result;//return result string
	}
};
#endif

