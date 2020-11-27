#include "Infix.h"
#include <stack>

Infix::Infix() {
	this->init_infix = "";
	this->postfix = "";
}

Infix::Infix(std::string _init_infix) {
	this->init_infix = _init_infix;
	this->postfix = "";
}

void Infix::set_infix(std::string _init_infix) {
	this->init_infix = _init_infix;
}
std::string Infix::get_infix() {
	return this->init_infix;
}

std::string Infix::get_postfix() {
	return this->postfix;
}

int Infix::precedence(char c) {
	if (c == '*' || c == '/') {
		return 2;
	}
	else if (c == '+' || c == '-') {
		return 1;
	}
	else {
		return -1;
	}
}

void Infix::InfixToPostfix() {
	std::string out;
	std::stack <char> st;
	st.push('$');

	for (int i = 0; i < init_infix.length(); ++i) {
		if ((init_infix[i] >= '0' && init_infix[i] <= '9') || init_infix[i] == '.') {
			out += init_infix[i];
		}
		else if (init_infix[i] == '(') {
			st.push('(');
		}
		else if (init_infix[i] == ')') {
			while (st.top() != '$' && st.top() != '(') {
				char c = st.top();
				st.pop();
				out += " ";
				out += c;
			}

			if (st.top() == '(') {
				char c = st.top();
				st.pop();
			}
		}
		else {
			out += " ";
			while (st.top() != '$' && precedence(init_infix[i]) <= precedence(st.top())) {
				char c = st.top();
				st.pop();
				out += c;
				out += " ";
			}
			st.push(init_infix[i]);
		}
	}
	while (st.top() != '$') {
		char c = st.top();
		st.pop();
		out += " ";
		out += c;
	}

	postfix = out;
}