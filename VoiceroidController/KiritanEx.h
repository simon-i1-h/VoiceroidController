#pragma once
#include <atlconv.h>
#include <sstream>
#include <windows.h>

#include "VoiceroidEx.h"

// �uVOICEROID�{ ���k���肽�� EX�v��\���N���X
class KiritanEx :
	public VoiceroidEx
{
public:
	KiritanEx();
	virtual ~KiritanEx();

private:
	// �e�L�X�g�ҏW�O�̃��C���E�B���h�E��
	static const _TCHAR* TARGET_WIN_NAME1;

	// �e�L�X�g�ҏW��̃��C���E�B���h�E��
	static const _TCHAR* TARGET_WIN_NAME2;

	// "VOICEROID�{ ���k���肽�� EX" �E�B���h�E��T��
	static HWND SearchMainWindow();
	static BOOL CALLBACK SearchKiritanEx(HWND hwnd, LPARAM lp);
};
