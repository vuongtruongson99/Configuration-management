#include "pch.h"
#include "CppUnitTest.h"
#include "..\InfixToPostfix\Infix.h"
#include "..\InfixToPostfix\Infix.cpp"
//#pragma comment(lib, "../Debug/InfixToPostfix.lib")

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Infix in;
			in.set_infix("4+2");
			in.InfixToPostfix();
			std::string ans = in.get_postfix();
			Assert::IsTrue(ans == "4 2 +");
		}
	};
}
