#include "pch.h"
#include "CppUnitTest.h"
#include "../Project1/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestAdjacentDuplicates)
		{
			Elem* first = NULL;
			Elem* last = NULL;
			enqueue(first, last, 1);
			enqueue(first, last, 2);
			enqueue(first, last, 2); 
			enqueue(first, last, 3);

			Assert::IsTrue(hasAdjacentDuplicates(first));

			Elem* first_no_duplicates = NULL;
			Elem* last_no_duplicates = NULL;
			enqueue(first_no_duplicates, last_no_duplicates, 1);
			enqueue(first_no_duplicates, last_no_duplicates, 2);
			enqueue(first_no_duplicates, last_no_duplicates, 3);

			Assert::IsFalse(hasAdjacentDuplicates(first_no_duplicates));
		}
	};
}
