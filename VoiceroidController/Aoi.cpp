#include "Aoi.h"


Aoi::Aoi() : VoiceroidEx(SearchMainWindow)
{
}

Aoi::~Aoi()
{
}


const _TCHAR* Aoi::TARGET_WIN_NAME1 = _T("VOICEROID＋ 琴葉葵");
const _TCHAR* Aoi::TARGET_WIN_NAME2 = _T("VOICEROID＋ 琴葉葵*");


HWND Aoi::SearchMainWindow() {
	// "VOICEROID＋ 琴葉葵" を探す
	SearchHwndParam syep;
	EnumWindows(Aoi::SearchAoi, (LPARAM)&syep);

	if (syep.hwnd == NULL) {
		throw _T("VOICEROID＋ 琴葉葵 が見つかりませんでした。");
	}

	return syep.hwnd;
}

BOOL CALLBACK Aoi::SearchAoi(HWND hwnd, LPARAM lp) {
	SearchHwndParam* syep = (SearchHwndParam*)lp;

	TCHAR strWindowText[1024];
	GetWindowText(hwnd, strWindowText, 1024);

	if (_tcscmp(TARGET_WIN_NAME1, strWindowText) == 0
		|| _tcscmp(Aoi::TARGET_WIN_NAME2, strWindowText) == 0)
	{
		syep->hwnd = hwnd;
		return false;
	}

	syep->hwnd = NULL;
	return true;
}
