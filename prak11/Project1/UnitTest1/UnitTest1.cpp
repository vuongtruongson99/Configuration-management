#include "pch.h"
#include "CppUnitTest.h"
#include "../Project1/Infix_to_postfix.h"
#include "../Project1/Infix_to_postfix.cpp"
#include "../Project1/Calculate_From_Postfix.h"
#include "../Project1/Calculate_From_Postfix.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(TestInfixToPostfix1)
		{
			string test = infixToPosfix("4+2");
			Assert::IsTrue(test == "4 2 +");
		}

		TEST_METHOD(TestInfixToPostfix2)
		{
			string test = infixToPosfix("4-2");
			Assert::IsTrue(test == "4 2 -");
		}

		TEST_METHOD(TestInfixToPostfix3)
		{
			string test = infixToPosfix("(3+4)*2-1*3");
			Assert::IsTrue(test == "3 4 + 2 * 1 3 * -");
		}

		TEST_METHOD(TestInfixToPostfix4)
		{
			string test = infixToPosfix("(2.12-1.32)/3.41*2.12-3");
			Assert::IsTrue(test == "2.12 1.32 - 3.41 / 2.12 * 3 -");
		}

		TEST_METHOD(TestInfixToPostfix5)
		{
			string test = infixToPosfix("4-2*(3 + 1) / 2");
			Assert::IsTrue(test == "4 2 3 1 + * 2 / -");
		}

		TEST_METHOD(TestInfixToPostfix6)
		{
			string test = infixToPosfix("3*(2+ 5)");
			Assert::IsTrue(test == "3 2 5 + *");
		}
		TEST_METHOD(TestInfixToPostfix7)
		{
			string test = infixToPosfix("((((1*(2+3))-3)+4)*5)");
			Assert::IsTrue(test == "1 2 3 + * 3 - 4 + 5 *");
		}
		TEST_METHOD(TestInfixToPostfix8)
		{
			string test = infixToPosfix("12 * (2.3 + 23.2) * 123 / 23");
			Assert::IsTrue(test == "12 2.3 23.2 + * 123 * 23 /");
		}

		TEST_METHOD(TestInfixToPostfix9)
		{
			string test = infixToPosfix("4*2");
			Assert::IsTrue(test == "4 2 *");
		}

		TEST_METHOD(TestInfixToPostfix10)
		{
			string test = infixToPosfix("4 /2");
			Assert::IsTrue(test == "4 2 /");
		}

		TEST_METHOD(TestInfixToPostfix11)
		{
			string test = infixToPosfix("4.0*2.1");
			Assert::IsTrue(test == "4.0 2.1 *");
		}

		TEST_METHOD(TestInfixToPostfix12)
		{
			string test = infixToPosfix("(300+23)*(43-21)/(84+7)");
			Assert::IsTrue(test == "300 23 + 43 21 - * 84 7 + /");
		}

		TEST_METHOD(TestInfixToPostfix13)
		{
			string test = infixToPosfix("(4+8)*(6-5)/((3-2)*(2+2))");
			Assert::IsTrue(test == "4 8 + 6 5 - * 3 2 - 2 2 + * /");
		}

		TEST_METHOD(TestInfixToPostfix14)
		{
			string test = infixToPosfix("3+4*5/6");
			Assert::IsTrue(test == "3 4 5 * 6 / +");
		}

		TEST_METHOD(TestInfixToPostfix15)
		{
			string test = infixToPosfix("2.31 - 313/12");
			Assert::IsTrue(test == "2.31 313 12 / -");
		}

		TEST_METHOD(TestCalculateExpession1)
		{
			float test = Calculate("4 2 +");
			float ans = 4 + 2;
			Assert::IsTrue(abs(test - ans) < 0.00001);
		}

		TEST_METHOD(TestCalculateExpession2)
		{
			float test = Calculate("4 2 -");
			float ans = 4 - 2;
			Assert::IsTrue(abs(test - ans) < 0.00001);
		}

		TEST_METHOD(TestCalculateExpession3)
		{
			float test = Calculate("3 4 + 2 * 1 3 * -");
			float ans = (3 + 4) * 2 - 1 * 3;
			Assert::IsTrue(abs(test - ans) < 0.00001);
		}

		TEST_METHOD(TestCalculateExpession4)
		{
			float test = Calculate("2.12 1.32 - 3.41 / 2.12 * 3 -");
			float ans = (2.12 - 1.32) / 3.41*2.12 - 3;
			Assert::IsTrue(abs(test-ans) < 0.00001);
		}

		TEST_METHOD(TestCalculateExpession5)
		{
			float test = Calculate("4 2 3 1 + * 2 / -");
			float ans = 4 - 2 * (3 + 1) / 2;
			Assert::IsTrue(abs(test - ans) < 0.00001);
		}

		TEST_METHOD(TestCalculateExpession6)
		{
			float test = Calculate("3 2 5 + *");
			float ans = 3 * (2 + 5);
			Assert::IsTrue(abs(test - ans) < 0.00001);
		}

		TEST_METHOD(TestCalculateExpession7)
		{
			float test = Calculate("1 2 3 + * 3 - 4 + 5 *");
			float ans = ((((1 * (2 + 3)) - 3) + 4) * 5);
			Assert::IsTrue(abs(test - ans) < 0.00001);
		}

		TEST_METHOD(TestCalculateExpession8)
		{
			float test = Calculate("12 2.3 23.2 + * 123 * 23 /");
			float ans = 12 * (2.3 + 23.2) * 123 / 23;
			Assert::IsTrue(abs(test - ans) < 0.00001);
		}

		TEST_METHOD(TestCalculateExpession9)
		{
			float test = Calculate("4 2 *");
			float ans = 4 * 2;
			Assert::IsTrue(abs(test - ans) < 0.00001);
		}

		TEST_METHOD(TestCalculateExpession10)
		{
			float test = Calculate("4 2 /");
			float ans = 4 /2;
			Assert::IsTrue(abs(test - ans) < 0.00001);
		}

		TEST_METHOD(TestCalculateExpession11)
		{
			float test = Calculate("4.0 2.1 *");
			float ans = 4.0 * 2.1;
			Assert::IsTrue(abs(test - ans) < 0.00001);
		}

		TEST_METHOD(TestCalculateExpession12)
		{
			float test = Calculate("300 23 + 43 21 - * 84 7 + /");
			float ans = (300.0 + 23.0)*(43.0 - 21.0) / (84.0 + 7.0);
			Assert::IsTrue(abs(test - ans) < 0.00001);
		}

		TEST_METHOD(TestCalculateExpession13)
		{
			float test = Calculate("4 8 + 6 5 - * 3 2 - 2 2 + * /");
			float ans = (4 + 8)*(6 - 5) / ((3 - 2)*(2 + 2));
			Assert::IsTrue(abs(test - ans) < 0.00001);
		}

		TEST_METHOD(TestCalculateExpession14)
		{
			float test = Calculate("3 4 5 * 6 / +");
			float ans = 3 + 4.0 * 5.0 / 6.0;
			Assert::IsTrue(abs(test - ans) < 0.00001);
		}

		TEST_METHOD(TestCalculateExpession15)
		{
			float test = Calculate("2.31 313 12 / -");
			float ans = 2.31 - 313.0 / 12.0;
			Assert::IsTrue(abs(test - ans) < 0.00001);
		}
	};

	TEST_CLASS(UnitTest2)
	{
	public:
		TEST_METHOD(TestInfixToPostfixBinaryOp1)
		{
			string test = infixToPosfix("4 == 2");
			Assert::IsTrue(test == "4 2 ==");
		}

		TEST_METHOD(TestInfixToPostfixBinaryOp2)
		{
			string test = infixToPosfix("4 != 2");
			Assert::IsTrue(test == "4 2 !=");
		}

		TEST_METHOD(TestInfixToPostfixBinaryOp3)
		{
			string test = infixToPosfix("4 > 2");
			Assert::IsTrue(test == "4 2 >");
		}

		TEST_METHOD(TestInfixToPostfixBinaryOp4)
		{
			string test = infixToPosfix("4 && 2");
			Assert::IsTrue(test == "4 2 &&");
		}

		TEST_METHOD(TestInfixToPostfixBinaryOp5)
		{
			string test = infixToPosfix("4 || 2");
			Assert::IsTrue(test == "4 2 ||");
		}

		TEST_METHOD(TestCalPostfixBinaryOp1)
		{
			float test = Calculate("4 2 &&");
			float ans = 4 && 2;
			Assert::IsTrue(test == ans);
		}

		TEST_METHOD(TestCalPostfixBinaryOp2)
		{
			float test = Calculate("4 2 ||");
			float ans = 4 || 2;
			Assert::IsTrue(test == ans);
		}

		TEST_METHOD(TestCalPostfixBinaryOp3)
		{
			float test = Calculate("3 1 + 2.2 3 - >=");
			float ans = (3 + 1) >= (2.2 + 3);
			Assert::IsTrue(test == ans);
		}

		TEST_METHOD(TestCalPostfixBinaryOp4)
		{
			float test = Calculate("2 4 * 2.2 3 / ||");
			float ans = (2*4) || (2.2 / 3);
			Assert::IsTrue(test == ans);
		}

		TEST_METHOD(TestCalPostfixBinaryOp5)
		{
			float test = Calculate("2 3 - 6 7 - >");
			float ans = (2-3) > (6-7);
			Assert::IsTrue(test == ans);
		}
	};
}
