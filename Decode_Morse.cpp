#include "Decode_Morse.h"
#include <iostream>

using namespace std;

int main()
{
	Decode_Morse M;
	
	M.create_morse_map();
	cout << "computer = " << M.encode_msg("computer") << endl;

	system("pause");
	return 0;
}
