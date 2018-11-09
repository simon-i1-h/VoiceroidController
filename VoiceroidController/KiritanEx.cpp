#include "KiritanEx.h"


KiritanEx::KiritanEx() : VoiceroidEx(SearchMainWindow)
{
}

KiritanEx::~KiritanEx()
{
}


const _TCHAR* KiritanEx::TARGET_WIN_NAME1 = _T("VOICEROID�{ ���k���肽�� EX");
const _TCHAR* KiritanEx::TARGET_WIN_NAME2 = _T("VOICEROID�{ ���k���肽�� EX*");


HWND KiritanEx::SearchMainWindow() {
	// "VOICEROID�{ ���k���肽�� EX" ��T��
	SearchHwndParam syep;
	EnumWindows(KiritanEx::SearchKiritanEx, (LPARAM)&syep);

	if (syep.hwnd == NULL) {
		char* voiceroid_exe = std::getenv("VOICEROID_KIRITAN_EX_EXE");
		if (!voiceroid_exe) {
			voiceroid_exe = "C:\\Program Files (x86)\\AHS\\VOICEROID+\\KiritanEX\\VOICEROID.exe";
		}

		struct stat st;
		int ret = stat(voiceroid_exe, &st);
		if (ret != 0) {
			throw "VOICEROID ���s�t�@�C����������܂���ł����B";
		}

		// voiceroid �N���R�}���h�g��
		std::stringstream command;
		command << "start cmd /c " << voiceroid_exe;
		system(command.str().c_str());

		// �N���҂�
		while (TRUE) {
			EnumWindows(KiritanEx::SearchKiritanEx, (LPARAM)&syep);
			if (syep.hwnd) {
				break;
			}
		}
	}

	return syep.hwnd;
}

BOOL CALLBACK KiritanEx::SearchKiritanEx(HWND hwnd, LPARAM lp) {
	SearchHwndParam* syep = (SearchHwndParam*)lp;

	TCHAR strWindowText[1024];
	GetWindowText(hwnd, strWindowText, 1024);

	if (_tcscmp(TARGET_WIN_NAME1, strWindowText) == 0
		|| _tcscmp(KiritanEx::TARGET_WIN_NAME2, strWindowText) == 0)
	{
		/*
		* ���C���E�B���h�E����
		* �q�v�f�Ƀ��j���[������΃��C���E�B���h�E���J�����Ɣ��f����B
		*/
		HWND tmp = GetWindow(hwnd, GW_CHILD);
		tmp = GetWindow(tmp, GW_HWNDNEXT);
		tmp = GetWindow(tmp, GW_HWNDNEXT);

		GetWindowText(tmp, strWindowText, 1024);

		if (_tcscmp(_T("menuStrip1"), strWindowText) == 0) {
			syep->hwnd = hwnd;
			return false;
		}
	}

	syep->hwnd = NULL;
	return true;
}
