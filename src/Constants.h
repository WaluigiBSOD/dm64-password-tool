// Dr. Mario 64 Password Tool
// Copyright (C) 2020-present WaluigiBSOD (waluigibsod.github.io)
//
// This file is part of Dr. Mario 64 Password Tool.
//
// Dr. Mario 64 Password Tool is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Dr. Mario 64 Password Tool is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program. If not, see <https://www.gnu.org/licenses/>.

/// @file      Constants.h
///
/// @brief     Constants.cpp's header file. It's used to import the program's constants inside every source file.
///
/// @author    WaluigiBSOD
/// @copyright GPL-3.0 License

#pragma once

#include <string>

using namespace std;

#define ARRAY_SIZE(Source)                                                      (sizeof(Source) > 0 ? sizeof(Source) / sizeof(Source[0]) : 0)

extern const string ProgramVersion;

extern const unsigned char StringCenterLeftSpacing;
extern const unsigned char StringCenterWidth;

// Game Mode

extern const unsigned char GameModeClassic;
extern const unsigned char GameModeScoreAttack;
extern const unsigned char GameModeMarathon;

extern const unsigned char GameModes[3];

// Game Level

extern const unsigned char GameLevelEasy;
extern const unsigned char GameLevelNormal;
extern const unsigned char GameLevelHard;

extern const unsigned char GameLevel[3];

// Virus Level

extern const unsigned char VirusLevelMaximum;

// Speed

extern const unsigned char SpeedLow;
extern const unsigned char SpeedMedium;
extern const unsigned char SpeedHigh;

extern const unsigned char GameSpeed[3];

// Score

extern const unsigned int ScoreMaximum;

// Time

extern const unsigned short TimeMaximum;

// Frame Count (modulo 1024)

extern const unsigned int FrameCountMaximum;

// Password

extern const string PasswordCharacters;

extern const unsigned char PasswordLength;

// Password (error codes)

extern const unsigned char PasswordOK;
extern const unsigned char PasswordInvalidLength;
extern const unsigned char PasswordInvalidCharacters;
extern const unsigned char PasswordInvalidChecksum;
extern const unsigned char PasswordInvalidClassicLevel;
extern const unsigned char PasswordInvalidNonClassicLevel;
extern const unsigned char PasswordInvalidScore;
extern const unsigned char PasswordInvalidTime;
extern const unsigned char PasswordInvalidPlayerName;

// Arguments (error codes)

extern const unsigned char ArgumentInvalidGameMode;
extern const unsigned char ArgumentInvalidLevel;
extern const unsigned char ArgumentInvalidSpeed;
extern const unsigned char ArgumentInvalidScore;
extern const unsigned char ArgumentInvalidTime;
extern const unsigned char ArgumentInvalidPlayerName;
extern const unsigned char ArgumentInvalidFrameCount;

// Player Name

extern const string AlphabeticNumericASCII;

extern const unsigned char SpecialCharacterSpace;
extern const unsigned char SpecialCharacterTilde;
extern const unsigned char SpecialCharacterSlashSmall;
extern const unsigned char SpecialCharacterCenteredDot;
extern const unsigned char SpecialCharacterDot;
extern const unsigned char SpecialCharacterQuestionMark;
extern const unsigned char SpecialCharacterHeart;
extern const unsigned char SpecialCharacterStar;
extern const unsigned char SpecialCharacterCircle;
extern const unsigned char SpecialCharacterMarkX;
extern const unsigned char SpecialCharacterSlashBig;
extern const unsigned char SpecialCharacterColon;
extern const unsigned char SpecialCharacterPercentual;
extern const unsigned char SpecialCharacterAccent;
extern const unsigned char SpecialCharacterAmpersand;
extern const unsigned char SpecialCharacterDotAlternate;

extern const char SpecialToASCIICharactersTable[16];

extern const unsigned char InternalToASCIICharactersTable[78];

extern const unsigned char ConversionInternalToAsciiError;
extern const unsigned char ConversionAsciiToInternalError;
extern const string ConversionInternalToConversationalError;

// XOR masks

extern const unsigned int TableMaskPasswordChunkX[4];
extern const unsigned int TableMaskPasswordChunkY[4];
extern const unsigned int TableMaskPasswordChunkZ[4];

// XOR masks for additional entropy of the password

extern const unsigned int TableMaskFrameCountX[32];
extern const unsigned int TableMaskFrameCountY[32];
