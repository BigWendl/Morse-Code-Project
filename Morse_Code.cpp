#include <iostream>
#include "Morse.h"

using namespace std;

int main()
{
	Morse_Code M;
	
	M.create_morse_map();
	cout << "computer = " << M.encode_msg("computer") << endl;
	
	cout << ".__. ._. ___ __. ._. ._ __ decoded is: " << M.decode_msg(".__. ._. ___ __. ._. ._ __") << endl;

	system("pause");
	return 0;
}
