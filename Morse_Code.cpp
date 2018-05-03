#include "stdafx.h"
#include "Morse.h"

int main()
{
	Morse_Code M;

	cout << "computer coded is: " << M.encode_msg("computer") << endl;
	cout << ".__. ._. ___ __. ._. ._ __ decoded is: " << M.decode_msg(".__. ._. ___ __. ._. ._ __") << endl;

	cout << "apple coded is: " << M.encode_msg("apple") << endl;
	cout << "_._. ._ _. _.. _.__ decoded is: " << M.decode_msg("_._. ._ _. _.. _.__") << endl;

	cout << endl;
	system("pause");
	return 0;
}
