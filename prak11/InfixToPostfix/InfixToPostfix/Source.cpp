#include <iostream>
#include "Infix.h"

using namespace std;

int main() {
	Infix inf;
	inf.set_infix("(4+2)*3+1");
	inf.InfixToPostfix();
	cout << inf.get_postfix();

	system("pause");
	return 0;
}