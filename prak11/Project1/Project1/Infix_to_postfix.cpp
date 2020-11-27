#include "Infix_to_postfix.h"

#include <iostream>
using namespace std;

string infixToPosfix(string s) {
	string out;
	stack <string> st;
	st.push("$");

	for (int i = 0; i < s.length(); ++i) {
		string ex = "";
		ex += s[i];

		if ((s[i] >= '0' && s[i] <= '9') || s[i] == '.') {
			out += s[i];
		}
		else if (ex == " ") continue;

		else if (ex == "(") {
			st.push("(");
		}
		else if (s[i] == ')') {
			while (st.top() != "$" && st.top() != "(") {
				string c = st.top();
				st.pop();
				out += " ";
				out += c;
			}

			if (st.top() == "(") {
				string c = st.top();
				st.pop();
			}
		}
		else if (IsDoubleOperator(s[i], s[i + 1])) {
			out += " ";
			string op;
			op += s[i];
			op += s[i + 1];

			while (st.top() != "$" && precedence(op) <= precedence(st.top())) {
				string c = st.top();
				st.pop();
				out += c;
				out += " ";
			}
			st.push(op);
			++i;
		}
		else {
			out += " ";
			while (st.top() != "$" && precedence(ex) <= precedence(st.top())) {
				string c = st.top();
				st.pop();
				out += c;
				out += " ";
			}
			st.push(ex);
		}
	}
	while (st.top() != "$") {
		string c = st.top();
		st.pop();
		out += " ";
		out += c;
	}

	return out;
}

bool IsDoubleOperator(char c1, char c2) {
	string op = "";
	op += c1;
	op += c2;
	if (op == "&&" || op == "||" || op == ">=" || op == ">" || op == "<" || op == "<=" || op == "!=" || op == "==") {
		return true;
	}
	return false;
}

int precedence(string c) {
	if (c == "*" || c == "/") {
		return 5;
	}
	else if (c == "+" || c == "-") {
		return 4;
	}
	else if (c == ">" || c == ">=" || c == "<" || c == "<=") {
		return 3;
	}
	else if (c == "==" || c == "!=") {
		return 2;
	}
	else if (c == "&&" || c == "||") {
		return 1;
	}
	else {
		return -1;
	}
}