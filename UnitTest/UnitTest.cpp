#define _CRT_SECURE_NO_WARNINGS

#include "pch.h"
#include <CppUnitTest.h>
#include <stdio.h>
#include <conio.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

// Macros from the original code
#define Z_VALUE 11
#define SQR(a) ((a) * (a))
#define CUBE(a) ((a) * (a) * (a))
#define ABS(a) ((a) < 0 ? -(a) : (a))
#define MAX(b, c) ((b) > (c) ? (b) : (c))
#define MIN(b, c) ((b) < (c) ? (b) : (c))

// Unit test class
namespace UnitTest1
{
	TEST_CLASS(MacroTests)
	{
	public:

		TEST_METHOD(TestSQR)
		{
			Assert::AreEqual(SQR(3), 9);
			Assert::AreEqual(SQR(-3), 9);
			Assert::AreEqual(SQR(0), 0);
		}

		TEST_METHOD(TestCUBE)
		{
			Assert::AreEqual(CUBE(3), 27);
			Assert::AreEqual(CUBE(-3), -27);
			Assert::AreEqual(CUBE(0), 0);
		}

		TEST_METHOD(TestABS)
		{
			Assert::AreEqual(ABS(3), 3);
			Assert::AreEqual(ABS(-3), 3);
			Assert::AreEqual(ABS(0), 0);
		}

		TEST_METHOD(TestMAX)
		{
			Assert::AreEqual(MAX(3, 5), 5);
			Assert::AreEqual(MAX(-3, 5), 5);
			Assert::AreEqual(MAX(3, 3), 3);
		}

		TEST_METHOD(TestMIN)
		{
			Assert::AreEqual(MIN(3, 5), 3);
			Assert::AreEqual(MIN(-3, 5), -3);
			Assert::AreEqual(MIN(3, 3), 3);
		}

		TEST_METHOD(TestMainLogicForMax)
		{
			// Test case where Z_VALUE is greater than 10 (maximum logic)
			if (Z_VALUE > 10) {
				int x = 3, y = 4, z = 5;
				int x_kvadr = CUBE(x);
				int x_plus_y_cube = SQR(x + y);
				int maxim = MAX(x_kvadr, x_plus_y_cube);
				maxim = MAX(maxim, z);
				Assert::AreEqual(maxim, 49); // 49 is the expected maximum value
			}
		}

		TEST_METHOD(TestMainLogicForMin)
		{
			// Test case where Z_VALUE is 10 or less (minimum logic)
			// Simulate Z_VALUE <= 10 here for the test
			int x = 3, y = 4, z = 5;
			int abs_x_minus_z = ABS(x - z);
			int abs_x_plus_z = ABS(x + z);
			int minim = MIN(abs_x_minus_z, abs_x_plus_z);
			minim = MIN(minim, z);
			Assert::AreEqual(minim, 2); // 2 is the expected minimum value
		}
	};
}
