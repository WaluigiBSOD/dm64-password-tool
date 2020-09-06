// Dr. Mario 64 Password Encoder/Decoder Tool
// Copyright (C) 2020  WaluigiBSOD (waluigibsod.github.io)
//
// This file is part of Dr. Mario 64 Password Encoder/Decoder Tool.
//
// Dr. Mario 64 Password Encoder/Decoder Tool is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Dr. Mario 64 Password Encoder/Decoder Tool is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#include <iostream>

#include "Password.h"
#include "PlayerName.h"

extern const unsigned char GameModeClassic;
extern const unsigned char GameModeScoreAttack;
extern const unsigned char GameModeMarathon;

extern const unsigned char GameLevelEasy;
extern const unsigned char GameLevelMedium;
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

extern const string PasswordCharacters;

unsigned char _CheckPasswordData(unsigned char GameMode, unsigned char Level, unsigned char Speed, unsigned int Score, unsigned short Time, unsigned char Name[], unsigned int FrameCount) {

    if (GameMode != GameModeClassic && GameMode != GameModeMarathon && GameMode != GameModeScoreAttack)
        return PasswordInvalidGameMode;

    if (GameMode != GameModeClassic && (Level != GameLevelEasy && Level != GameLevelMedium && Level != GameLevelHard))
        return PasswordInvalidNonClassicLevel;

    if (Level < VirusLevelMinimum || Level > VirusLevelMaximum)
        return PasswordInvalidLevel;

    if (Speed != SpeedLow && Speed != SpeedMedium && Speed != SpeedHigh)
        return PasswordInvalidSpeed;

    if (Score < ScoreMinimum || Score > ScoreMaximum)
        return PasswordInvalidScore;

    if (Time < TimeMinimum || Time > TimeMaximum)
        return PasswordInvalidTime;

    if (!_PlayerNameValidCharacter(Name[0]) || !_PlayerNameValidCharacter(Name[1]) || !_PlayerNameValidCharacter(Name[2]) || !_PlayerNameValidCharacter(Name[3]))
        return PasswordInvalidName;

    if (FrameCount < FrameCountMinimum || FrameCount > FrameCountMaximum)
        return PasswordInvalidFrameCount;

    return PasswordOK;
}

unsigned char _IsPasswordWrong(string Password) {
    // Length check (must be equal to 20 characters)
    if (Password.size() != 20)
        return PasswordInvalidLength;

    // Character check (must not contain invalid characters)
    unsigned char j;

    for (unsigned char i=0;i<Password.size();i++) {
        for (j=0;j<PasswordCharacters.size();j++)
            if (PasswordCharacters[j] == Password[i])
                break;
        if (j == PasswordCharacters.size())
            return PasswordInvalidCharacters;
    }

    // Data check (must not contain invalid data)
    unsigned char GameMode;
    unsigned char Level;
    unsigned char Speed;
    unsigned int Score;
    unsigned short Time;
    unsigned char Name[4];
    unsigned int FrameCount;

    if(!_DecodePassword(Password.c_str(),GameMode,Level,Speed,Score,Time,Name,FrameCount))
        return PasswordDecodeError;

    return _CheckPasswordData(GameMode,Level,Speed,Score,Time,Name,FrameCount);
}

void _DisplayPasswordResult(unsigned char Result) {
    if (Result == PasswordOK)
        cout << "OK";
    else if (Result == PasswordInvalidLength)
        cout << "Length not valid";
    else if (Result == PasswordInvalidCharacters)
        cout << "It contains one or more invalid characters";
    else if (Result == PasswordDecodeError)
        cout << "Checksum error";
    else if (Result == PasswordInvalidGameMode)
        cout << "The decoded game mode is invalid";
    else if (Result == PasswordInvalidNonClassicLevel)
        cout << "The decoded level is invalid with the decoded game mode";
    else if (Result == PasswordInvalidLevel)
        cout << "The decoded level is invalid (must be between " << VirusLevelMinimum << " and " << VirusLevelMaximum << ", both inclusive)";
    else if (Result == PasswordInvalidScore)
        cout << "The decoded score is invalid (must be between " << ScoreMinimum << " and " << ScoreMaximum << ", both inclusive)";
    else if (Result == PasswordInvalidTime)
        cout << "The decoded time is invalid (must be between " << TimeMinimum << " and " << TimeMaximum << ", both inclusive)";
    else if (Result == PasswordInvalidFrameCount)
        cout << "The decoded frame count is invalid (must be between " << FrameCountMinimum << " and " << FrameCountMaximum << ", both inclusive)";
}

unsigned char _CheckPassword(string Password, bool DisplayResult = true, bool DisplayPassword = true) {
    if (DisplayResult) {
        cout << " [!] Checking ";
        if (DisplayPassword)
            cout << '\"' << Password << '\"';
        else
            cout << "the Password";
        cout << " ... ";
    }

    unsigned char Result = _IsPasswordWrong(Password);

    if (DisplayResult && Result != PasswordOK)
        cout << "ERROR (";

    if (DisplayResult) {

        _DisplayPasswordResult(Result);

        if (Result != PasswordOK)
            cout << ")";

        cout << endl << endl;
    }

    return Result;
}
