#include "stdafx.h"
#include "testGTest.h"
#include "testExcel.h"
#include "testCplex.h"
#include "testCGAL.h"

int _tmain(int argc, _TCHAR* argv[])
{
	{	//test gtest
		testing::InitGoogleTest(&argc, argv);
		RUN_ALL_TESTS();
	}
	
	{	//test Microsoft Excel
		TEST_EXCEL::ExportExcel();
	}

	{	//test CPLEX
		TEST_CPLEX::testCplex();
	}

	getchar();
	return 0;
}

