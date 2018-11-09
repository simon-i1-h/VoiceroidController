#pragma once
#include <atlconv.h>
#include <sstream>
#include <windows.h>

#include "VoiceroidEx.h"

// 「VOICEROID＋ 東北きりたん EX」を表すクラス
class KiritanEx :
	public VoiceroidEx
{
public:
	KiritanEx();
	virtual ~KiritanEx();

private:
	// テキスト編集前のメインウィンドウ名
	static const _TCHAR* TARGET_WIN_NAME1;

	// テキスト編集後のメインウィンドウ名
	static const _TCHAR* TARGET_WIN_NAME2;

	// "VOICEROID＋ 東北きりたん EX" ウィンドウを探す
	static HWND SearchMainWindow();
	static BOOL CALLBACK SearchKiritanEx(HWND hwnd, LPARAM lp);
};
