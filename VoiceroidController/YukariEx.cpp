#include "YukariEx.h"


YukariEx::YukariEx() : VoiceroidEx(SearchMainWindow)
{
}

YukariEx::~YukariEx()
{
}


const _TCHAR* YukariEx::TARGET_WIN_NAME1 = _T("VOICEROID＋ 結月ゆかり EX");
const _TCHAR* YukariEx::TARGET_WIN_NAME2 = _T("VOICEROID＋ 結月ゆかり EX*");


HWND YukariEx::SearchMainWindow() {
	// "VOICEROID＋ 結月ゆかり EX" を探す
	SearchHwndParam syep;
	EnumWindows(YukariEx::SearchYukariEx, (LPARAM)&syep);

	if (syep.hwnd == NULL) {
		throw _T("VOICEROID＋ 結月ゆかり EX が見つかりませんでした。");
	}

	return syep.hwnd;
}

BOOL CALLBACK YukariEx::SearchYukariEx(HWND hwnd, LPARAM lp) {
	SearchHwndParam* syep = (SearchHwndParam*)lp;

	TCHAR strWindowText[1024];
	GetWindowText(hwnd, strWindowText, 1024);

	if (_tcscmp(TARGET_WIN_NAME1, strWindowText) == 0
		|| _tcscmp(YukariEx::TARGET_WIN_NAME2, strWindowText) == 0)
	{
		syep->hwnd = hwnd;
		return false;
	}

	syep->hwnd = NULL;
	return true;
}

