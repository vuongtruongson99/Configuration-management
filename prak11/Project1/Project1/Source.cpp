#include <iostream>
#include <string>
#include "Infix_to_postfix.h"
#include "Calculate_From_Postfix.h"

using namespace std;

int main() {
	string infix;
	cout << "Input infix expression: ";
	getline(cin, infix);
	cout << "Postfix expression: " << infixToPosfix(infix) << endl;
	cout << "Answer: " << Calculate(infixToPosfix(infix)) << endl;

	system("pause");
	return 0;
}