#ifndef TESTTOOLS_TESTEXCEL_H_
#define TESTTOOLS_TESTEXCEL_H_

#include "excel/excelTypeLibs.h"

namespace TEST_EXCEL {
	struct com_t { 
		com_t() { CoInitializeEx(NULL, COINIT_APARTMENTTHREADED); }
		~com_t() { CoUninitialize(); }
	};
	struct wait_cursor_t { 
		HCURSOR cursor; 
		wait_cursor_t() { cursor = SetCursor(LoadCursor(NULL, IDC_WAIT)); } 
		~wait_cursor_t() { SetCursor(cursor); } 
	};
	bool ExportExcel();
}

#endif //TESTTOOLS_TESTEXCEL_H_