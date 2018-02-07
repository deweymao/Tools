#include "stdafx.h"
#include "testGTest.h"

int _tmain(int argc, _TCHAR* argv[])
{
	{	//test gtest
		testing::InitGoogleTest(&argc, argv);
		RUN_ALL_TESTS();
	}
	

	getchar();
	return 0;
}

