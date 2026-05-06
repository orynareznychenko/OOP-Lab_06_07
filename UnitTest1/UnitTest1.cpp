#include "pch.h"
#include "CppUnitTest.h"
#include "../ООП РІ-13 Резниченко ЛР-6.7/Long.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            int a[] = { 1, 1, 1, 2, 2, -3, -3, -4, -4, 5 };
            int size = sizeof(a) / sizeof(a[0]);
            int b[20], c[20], d[20];

            int n1 = unique_copy(&a[0], &a[size], &b[0]);

            Assert::AreEqual(5, n1, L"unique_copy: Неправильна кiлькiсть елементiв");
            int expected_b[] = { 1, 2, -3, -4, 5 };
            for (int i = 0; i < n1; i++) {
                Assert::AreEqual(expected_b[i], b[i], L"unique_copy: Невiдповiднiсть елемента");
            }
		}
	};
}
