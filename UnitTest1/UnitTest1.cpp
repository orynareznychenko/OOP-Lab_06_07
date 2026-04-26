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
            int a[] = { 1, 1, 2, 3, 3, 3, 4, 1 };
            int size_a = sizeof(a) / sizeof(a[0]);
            int b[10];

            int b_size = unique_copy_custom(&a[0], &a[size_a], &b[0]);

            Assert::AreEqual(5, b_size);
            Assert::AreEqual(1, b[0]);
            Assert::AreEqual(2, b[1]);
            Assert::AreEqual(3, b[2]);
            Assert::AreEqual(4, b[3]);
            Assert::AreEqual(1, b[4]);

            int c[] = { 2, 2, 3, 3, 4, 4, 4 };
            int size_c = sizeof(c) / sizeof(c[0]);
            int d[10];
            Even<int> even_pred;

            int d_size = unique_copy_if_custom(&c[0], &c[size_c], &d[0], even_pred);

            Assert::AreEqual(4, d_size);
            Assert::AreEqual(2, d[0]);
            Assert::AreEqual(3, d[1]);
            Assert::AreEqual(3, d[2]);
            Assert::AreEqual(4, d[3]);
		}
	};
}
