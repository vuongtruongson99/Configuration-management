#pragma once
#include <string>

class Infix
{
private:
	std::string init_infix;
	std::string postfix;

public:
	Infix();
	Infix(std::string _init_exp);
	void set_infix(std::string _init_infix);
	std::string get_infix();
	std::string get_postfix();
	void InfixToPostfix();
	int precedence(char c);
};

