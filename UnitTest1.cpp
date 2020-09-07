#include "pch.h"
#include "CppUnitTest.h"
#include "../SimpleServer/Accounts.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		Server server;

		TEST_METHOD(TestMethod1)
		{
			Assert::AreEqual(server.getTotal(), 100);
		}
		TEST_METHOD(TestMethod2)
		{
			Assert::AreEqual(server.getUsing(), 0);
		}
		TEST_METHOD(TestMethod3)
		{
			Assert::AreEqual(server.getID(0), "testID");
		}
		TEST_METHOD(TestMethod4)
		{
			Assert::AreEqual(server.getPassword(0), "testPW");
		}
		TEST_METHOD(TestMethod5)
		{
			Assert::AreEqual(server.getAutho(0), "RW");
		}
		TEST_METHOD(TestMethod6)
		{
			Assert::AreEqual(server.getSleep(0), false);
		}
		TEST_METHOD(TestMethod7)
		{
			Assert::AreEqual(server.getLoginCount(0), 3);
		}
	};
}
