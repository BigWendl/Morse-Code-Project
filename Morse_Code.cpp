#include "Morse_Code.h"
#include <iostream>

using namespace std;

int main()
{
	Morse_Code M;
	
	M.create_morse_map();
	cout << "computer = " << M.encode_msg("computer") << endl;

	system("pause");
	return 0;
}
