#include "CppUnitTest.h"
#include "plane.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testing
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(TestMethod1)
		{
			plane p(vector3d(point3d(1, 1, 1), point3d(2, 2, 2)));
			Assert::AreEqual(true, p.isInside(point3d(0.5,0.5,0.5)), L"message", LINE_INFO());
		}
	};
}