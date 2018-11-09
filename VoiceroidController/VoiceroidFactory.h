#pragma once

#include "Voiceroid.h"
#include "Yukari.h"
#include "YukariEx.h"
#include "Aoi.h"
#include "Akane.h"
#include "KiritanEx.h"

enum class VoiceroidType {
	YUKARI,
	YUKARI_EX,
	AOI,
	AKANE,
	KIRITAN_EX
};

class VoiceroidFactory
{
public:
	static Voiceroid* create(VoiceroidType type);
};

