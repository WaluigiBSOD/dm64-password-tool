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

#include <iostream>
#include <sstream>

#include "Constants.h"
#include "PasswordGenerateDecode.h"
#include "PlayerName.h"
#include "PrintError.h"

unsigned int _CheckPasswordData(unsigned char GameMode, unsigned char Level, unsigned char Speed, unsigned int Score, unsigned short Time, unsigned char Name[], unsigned int FrameCount, bool Argument = false) {

    if (GameMode != GameModeClassic && GameMode != GameModeMarathon && GameMode != GameModeScoreAttack) {
        if (Argument)
            return _PrintErrorMessageWithReturnValue("Game Mode",ArgumentInvalidGameMode);
        return PasswordInvalidGameMode;
    }

    if (GameMode != GameModeClassic && (Level != GameLevelEasy && Level != GameLevelNormal && Level != GameLevelHard)) {
        if (Argument)
            return _PrintErrorMessageWithReturnValue("Level",ArgumentInvalidLevel);
        return PasswordInvalidNonClassicLevel;
    }

    if (Level < VirusLevelMinimum || Level > VirusLevelMaximum) {
        if (Argument)
            return _PrintErrorMessageWithReturnValue("Level",ArgumentInvalidLevel);
        return PasswordInvalidLevel;
    }

    if (Speed != SpeedLow && Speed != SpeedMedium && Speed != SpeedHigh) {
        if (Argument)
            return _PrintErrorMessageWithReturnValue("Speed",ArgumentInvalidSpeed);
        return PasswordInvalidSpeed;
    }

    if (Score < ScoreMinimum || Score > ScoreMaximum) {
        if (Argument)
            return _PrintErrorMessageWithReturnValue("Score",ArgumentInvalidScore);
        return PasswordInvalidScore;
    }

    if (Time < TimeMinimum || Time > TimeMaximum) {
        if (Argument)
            return _PrintErrorMessageWithReturnValue("Time",ArgumentInvalidTime);
        return PasswordInvalidTime;
    }

    if (!_PlayerNameValidCharacter(Name[0]) || !_PlayerNameValidCharacter(Name[1]) || !_PlayerNameValidCharacter(Name[2]) || !_PlayerNameValidCharacter(Name[3])) {
        if (Argument)
            return _PrintErrorMessageWithReturnValue("Name",ArgumentInvalidName);
        return PasswordInvalidName;
    }

    if (FrameCount < FrameCountMinimum || FrameCount > FrameCountMaximum) {
        if (Argument)
            return _PrintErrorMessageWithReturnValue("Frame Count",ArgumentInvalidFrameCount);
        return PasswordInvalidFrameCount;
    }

    return PasswordOK;
}

unsigned int _IsPasswordWrong(string Password) {
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

void _DisplayPasswordResult(unsigned int Result) {
    if (Result == PasswordOK)
        cout << "OK";
    else {
        stringstream PrintError;

        if (Result == PasswordInvalidLength)
            _PrintErrorMessage("Length not valid");
        else if (Result == PasswordInvalidCharacters)
            _PrintErrorMessage("It contains one or more invalid characters");
        else if (Result == PasswordDecodeError)
            _PrintErrorMessage("Checksum error");
        else if (Result == PasswordInvalidGameMode)
            _PrintErrorMessage("The decoded game mode is invalid");
        else if (Result == PasswordInvalidNonClassicLevel)
            _PrintErrorMessage("The decoded level is invalid with the decoded game mode");
        else if (Result == PasswordInvalidLevel) {
            PrintError << "The decoded level is invalid (must be between " << VirusLevelMinimum << " and " << VirusLevelMaximum << ", both inclusive)";

            _PrintErrorMessage(PrintError.str());
        } else if (Result == PasswordInvalidScore) {
            PrintError << "The decoded score is invalid (must be between " << ScoreMinimum << " and " << ScoreMaximum << ", both inclusive)";

            _PrintErrorMessage(PrintError.str());
        } else if (Result == PasswordInvalidTime) {
            PrintError << "The decoded time is invalid (must be between " << TimeMinimum << " and " << TimeMaximum << ", both inclusive)";

            _PrintErrorMessage(PrintError.str());
        } else if (Result == PasswordInvalidFrameCount) {
            PrintError << "The decoded frame count is invalid (must be between " << FrameCountMinimum << " and " << FrameCountMaximum << ", both inclusive)";

            _PrintErrorMessage(PrintError.str());
        }
    }
}

unsigned int _CheckPassword(string Password, bool DisplayResult = true, bool DisplayPassword = true) {
    if (DisplayResult) {
        cout << " [!] Checking ";
        if (DisplayPassword)
            cout << '\"' << Password << '\"';
        else
            cout << "the Password";
        cout << " ... ";
    }

    unsigned int Result = _IsPasswordWrong(Password);

    if (DisplayResult && Result != PasswordOK)
        cout << endl << endl;

    if (DisplayResult) {

        _DisplayPasswordResult(Result);

        if (Result == PasswordOK)
            cout << endl << endl;
    }

    return Result;
}
