#include "pch.h"
#include "CppUnitTest.h"
#include "../Project1/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestHasAdjacentDuplicates)
        {
            Elem* first = NULL;
            Elem* last = NULL;
            enqueue(first, last, 1);
            enqueue(first, last, 2);
            enqueue(first, last, 3);
            enqueue(first, last, 3);
            Assert::IsTrue(hasAdjacentDuplicates(first));
        }

        TEST_METHOD(TestNoAdjacentDuplicates)
        {
            Elem* first = NULL;
            Elem* last = NULL;
            enqueue(first, last, 1);
            enqueue(first, last, 2);
            enqueue(first, last, 3);
            enqueue(first, last, 4);
            Assert::IsFalse(hasAdjacentDuplicates(first));
        }
    };
}