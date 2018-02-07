#include "stdafx.h"
#include "testExcel.h"
#include <iostream>

bool TEST_EXCEL::ExportExcel() {
	TEST_EXCEL::com_t com;
	TEST_EXCEL::wait_cursor_t wait;
	try {
	
	}catch (_com_error& err) {
		std::cout << err.ErrorMessage() << std::endl;
		return false;
	}
	return true;
}
