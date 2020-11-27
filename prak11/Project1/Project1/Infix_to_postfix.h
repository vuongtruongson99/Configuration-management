#pragma once

#include <string>
#include <stack>

using namespace std;

string infixToPosfix(string s);
int precedence(string c);
bool IsDoubleOperator(char c1, char c2);