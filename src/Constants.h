// Dr. Mario 64 Password Generator/Decoder Tool
// Copyright (C) 2020 WaluigiBSOD (waluigibsod.github.io)
//
// This file is part of Dr. Mario 64 Password Generator/Decoder Tool.
//
// Dr. Mario 64 Password Generator/Decoder Tool is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Dr. Mario 64 Password Generator/Decoder Tool is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include <string>
#include <random>

using namespace std;

extern const string ProgramVersion;

extern const unsigned int AutotestIterations;

extern const unsigned char StringCenterLeftSpacing;
extern const unsigned char StringCenterWidth;

extern const unsigned char GameModeClassic;
extern const unsigned char GameModeScoreAttack;
extern const unsigned char GameModeMarathon;

extern const unsigned char GameLevelEasy;
extern const unsigned char GameLevelNormal;
extern const unsigned char GameLevelHard;

extern const unsigned char SpeedLow;
extern const unsigned char SpeedMedium;
extern const unsigned char SpeedHigh;

extern const unsigned char VirusLevelMinimum;
extern const unsigned char VirusLevelMaximum;

extern const unsigned int ScoreMinimum;
extern const unsigned int ScoreMaximum;

extern const unsigned short TimeMinimum;
extern const unsigned short TimeMaximum;

extern const unsigned int FrameCountMinimum;
extern const unsigned int FrameCountMaximum;

extern const unsigned char PasswordOK;
extern const unsigned char PasswordInvalidLength;
extern const unsigned char PasswordInvalidCharacters;
extern const unsigned char PasswordDecodeError;
extern const unsigned char PasswordInvalidGameMode;
extern const unsigned char PasswordInvalidNonClassicLevel;
extern const unsigned char PasswordInvalidLevel;
extern const unsigned char PasswordInvalidSpeed;
extern const unsigned char PasswordInvalidScore;
extern const unsigned char PasswordInvalidTime;
extern const unsigned char PasswordInvalidName;
extern const unsigned char PasswordInvalidFrameCount;

extern const unsigned int ArgumentInvalidPasswordLength;
extern const unsigned int ArgumentInvalidGameMode;
extern const unsigned int ArgumentInvalidLevel;
extern const unsigned int ArgumentInvalidSpeed;
extern const unsigned int ArgumentInvalidScore;
extern const unsigned int ArgumentInvalidTime;
extern const unsigned int ArgumentInvalidName;
extern const unsigned int ArgumentInvalidFrameCount;

extern const unsigned int ReturnAutoTestFail;
extern const unsigned int ReturnAutoTestPass;

extern const unsigned int DataTypeCharCorrectByteSize;
extern const unsigned int DataTypeShortCorrectByteSize;
extern const unsigned int DataTypeIntCorrectByteSize;
extern const unsigned int DataTypeLongLongCorrectByteSize;

extern const unsigned int DataTypeSignedCharWrongSize;
extern const unsigned int DataTypeUnsignedCharWrongSize;
extern const unsigned int DataTypeSignedShortWrongSize;
extern const unsigned int DataTypeUnsignedShortWrongSize;
extern const unsigned int DataTypeSignedIntWrongSize;
extern const unsigned int DataTypeUnsignedIntWrongSize;
extern const unsigned int DataTypeSignedLongLongWrongSize;
extern const unsigned int DataTypeUnsignedLongLongWrongSize;

extern const string AlphabeticUppercaseASCII;
extern const string AlphabeticLowercaseASCII;
extern const string NumericASCII;

extern const string AlphabeticNumericASCII;

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
extern const unsigned char SpecialCharacterAmperstand;
extern const unsigned char SpecialCharacterDotAlternative;

extern const char SpecialASCII[];

extern const unsigned char InternalToASCIICharacterTable[];

extern const unsigned int ConversionInternalToAsciiError;
extern const unsigned char ConversionAsciiToInternalError;
extern const string ConversionInternalToConversationalError;

extern const unsigned int InternalCharacterTableSize;
extern const unsigned int SpecialASCIISize;

extern const string PasswordCharacters;

extern const unsigned int TableMaskHigh[4];

extern const unsigned int TableMaskMiddle[4];

extern const unsigned int TableMaskLower[4];

extern const unsigned int TableMaskFrameCountLower[32];

extern const unsigned int TableMaskFrameCountUpper[32];

extern const unsigned char GameModes[3];
extern const unsigned char GameLevel[3];
extern const unsigned char GameSpeed[3];
