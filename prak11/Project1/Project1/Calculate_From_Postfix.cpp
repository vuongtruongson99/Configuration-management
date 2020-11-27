#include "Calculate_From_Postfix.h"
#include "Infix_to_postfix.h"
#include <stack>
#include <iostream>

float ApplyOperator(float a, float b, std::string op) {
	if (op == "+") return a + b;
	else if (op == "-") return a - b;
	else if (op == "*") return a * b;
	else if (op == "/") return float(a / b);
	else if (op == ">") {
		if (a > b) return 1;
		else return 0;
	}
	else if (op == "<") {
		if (a < b) return 1;
		else return 0;
	}
}

int ApplyDoubleOperator(float a, float b, std::string op) {
	if (op == "==") {
		if (a == b) return 1;
		else return 0;
	}
	else if (op == "!=") {
		if (a != b) return 1;
		else return 0;
	}
	else if (op == ">=") {
		if (a >= b) return 1;
		else return 0;
	}
	else if (op == "<=") {
		if (a <= b) return 1;
		else return 0;
	}
	else if (op == "&&") {
		if (a == 0 || b == 0) return 0;
		else return 1;
	}
	else {
		if (a > 0 || b > 0) return 1;
		else return 0;
	}
}

float Calculate(std::string postfix) {
	std::stack <float> vals;
	int i;

	for (i = 0; i < postfix.length(); ++i) {
		if (postfix[i] == ' ') continue;

		else if (isdigit(postfix[i])) {
			std::string val;
			while (i != postfix.length() && (isdigit(postfix[i]) || postfix[i] == '.')) {
				val += postfix[i];
				++i;
			}
			float tmp_val = std::stof(val);
			vals.push(tmp_val);
			i--;
		}
		else if (IsDoubleOperator(postfix[i], postfix[i + 1])) {
			float val1 = vals.top();
			vals.pop();
			float val2 = vals.top();
			vals.pop();
			std::string op;
			op += postfix[i];
			op += postfix[i + 1];
			int new_val = ApplyDoubleOperator(val1, val2, op);
			vals.push(new_val);
			++i;
		}
		else {
			float val1 = vals.top();
			vals.pop();
			float val2 = vals.top();
			vals.pop();
			std::string ops;
			ops += postfix[i];
			float new_val = ApplyOperator(val2, val1, ops);
			vals.push(new_val);
		}
	}

	float ans = vals.top();
	vals.pop();
	return ans;
}