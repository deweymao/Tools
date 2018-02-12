#include "stdafx.h"
#include "testGTest.h"
#include "testExcel.h"
#include "testCplex.h"
#include "testCGAL.h"
#include "testBoost.h"

int _tmain(int argc, _TCHAR* argv[])
{
	{	
		std::cout << "==========test gtest==========" << std::endl;
		testing::InitGoogleTest(&argc, argv);
		RUN_ALL_TESTS();
	}
	
	{	
		std::cout << "==========test Microsoft Excel==========" << std::endl;
		TEST_EXCEL::ExportExcel();
	}

	{	
		std::cout << "==========test CPLEX==========" << std::endl;
		TEST_CPLEX::testCplex();
	}
	
	{
		std::cout << "==========test Boost==========" << std::endl;
		TEST_BOOST::testBoost();
	}

	{	
		std::cout << "==========test CGAL==========" << std::endl;
		TEST_CGAL::testCGALByAlphaShapes2D();
	}

	getchar();
	return 0;
}

