// testTools.cpp : 定义控制台应用程序的入口点。
//

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

