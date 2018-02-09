#include "stdafx.h"
#include "testExcel.h"
#include <iostream>

bool TEST_EXCEL::ExportExcel() {
	TEST_EXCEL::com_t com;
	TEST_EXCEL::wait_cursor_t wait;
	try {
		Excel::_ApplicationPtr excel;
		HRESULT hr = excel.CreateInstance(__uuidof(Excel::Application));
		if (FAILED(hr)) throw _com_error(hr);

		auto workbook = excel->Workbooks->Add();
		Excel::SheetsPtr sheets = workbook->GetWorksheets();
		Excel::_WorksheetPtr sheet = sheets->GetItem((short)1);
		sheet->Name = L"testExcelSheet1";
		Excel::RangePtr range = sheet->Cells;

		Excel::RangePtr titleRange = range->GetRange(range->GetItem(1, 1), range->GetItem(1, 4));
		titleRange->Merge();
		titleRange->PutItem(1, 1, L"testExcel");
		titleRange->HorizontalAlignment = Excel::XlHAlign::xlHAlignCenter;
		titleRange->BorderAround(Excel::XlLineStyle::xlContinuous, Excel::XlBorderWeight::xlThin, Excel::XlColorIndex::xlColorIndexNone);
	
		sheet->Columns->AutoFit();
		excel->PutDisplayAlerts(0, variant_t(false));
		workbook->SaveAs(L"G:\\testExcel.xlsx", vtMissing, vtMissing, vtMissing, vtMissing, vtMissing, Excel::XlSaveAsAccessMode::xlNoChange, Excel::XlSaveConflictResolution::xlLocalSessionChanges);
		workbook->Close(true);
		excel->Quit();

		//open excel
		ShellExecute(NULL, L"open", L"G://testExcel.xlsx", NULL, NULL, SW_SHOW);

	}catch (_com_error& err) {
		std::cout << "EXCEL error code:" << err.ErrorMessage() << std::endl;
		return false;
	}
	std::cout << "EXCEL succeeded!" << std::endl;
	return true;
}
