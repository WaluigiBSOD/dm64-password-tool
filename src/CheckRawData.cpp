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

/// @file      CheckRawData.cpp
///
/// @brief     Functions that validate command-line arguments as raw data and decoded password data.
///
/// @author    WaluigiBSOD
/// @copyright GPL-3.0 License

#include <iostream>

#include "Constants.h"

#include "PlayerName.h"

#include "PrintError.h"

using namespace std;

/// Checks if the raw game data given input is valid or not.
///
/// More information on valid in-game data that can be found in the documentation of _GeneratePassword().
///
/// @param[in] GameMode   Game mode to check.
/// @param[in] Level      Virus/game level to check.
/// @param[in] Speed      Speed to check.
/// @param[in] Score      Score to check.
/// @param[in] Time       Time to check.
/// @param[in] PlayerName Player name to check.
/// @param[in] FrameCount Frame count to check.
/// @param[in] Argument   Specifies if data was comes from command-line arguments (**true**) or comes from a decoded password (**false**).
///
/// @return    **PasswordOK** value if all the data is valid, the corresponding error code if not after having printed an error message to screen.
///
/// @author    WaluigiBSOD
/// @copyright GPL-3.0 License

unsigned char _CheckDecodedPasswordData(unsigned char GameMode, unsigned char Level, unsigned char Speed, unsigned int Score, unsigned short Time, unsigned char PlayerName[], unsigned short FrameCount, bool Argument = false) {
    // Game Mode

    if (Argument && GameMode != GameModeClassic && GameMode != GameModeMarathon && GameMode != GameModeScoreAttack)
        return _PrintErrorMessage("Entered game mode",ArgumentInvalidGameMode);

    // Level

    if (GameMode == GameModeClassic && Level > VirusLevelMaximum) {
        if (Argument)
            return _PrintErrorMessage("Entered classic virus level",ArgumentInvalidLevel);

        return PasswordInvalidClassicLevel;
    }

    if (GameMode != GameModeClassic && (Level != GameLevelEasy && Level != GameLevelNormal && Level != GameLevelHard)) {
        if (Argument)
            return _PrintErrorMessage("Entered non-classic game level",ArgumentInvalidLevel);

        return PasswordInvalidNonClassicLevel;
    }

    // Speed

    if (Argument && Speed != SpeedLow && Speed != SpeedMedium && Speed != SpeedHigh)
        return _PrintErrorMessage("Entered speed",ArgumentInvalidSpeed);

    // Score

    if (Score > ScoreMaximum) {
        if (Argument)
            return _PrintErrorMessage("Entered score",ArgumentInvalidScore);

        return PasswordInvalidScore;
    }

    // Time

    if (Time > TimeMaximum) {
        if (Argument)
            return _PrintErrorMessage("Entered time",ArgumentInvalidTime);

        return PasswordInvalidTime;
    }

    // Player Name

    if (!_PlayerNameValidCharacter(PlayerName[0]) || !_PlayerNameValidCharacter(PlayerName[1]) || !_PlayerNameValidCharacter(PlayerName[2]) || !_PlayerNameValidCharacter(PlayerName[3])) {
        if (Argument)
            return _PrintErrorMessage("Entered player name",ArgumentInvalidPlayerName);

        return PasswordInvalidPlayerName;
    }

    // Frame Count (modulo 1024)

    if (Argument && FrameCount > FrameCountMaximum)
        return _PrintErrorMessage("Entered frame count",ArgumentInvalidFrameCount);

    return PasswordOK;
}

/// Displays password decoding errors on screen.
///
/// @param[in] Result The corresponding error code.
///
/// @return    The error code given in input.
///
/// @author    WaluigiBSOD
/// @copyright GPL-3.0 License

unsigned char _DisplayDecodedPasswordError(unsigned char Result) {
    cout << endl << endl;

    if (Result == PasswordInvalidLength)
        return _PrintErrorMessage("Password length",Result);

    if (Result == PasswordInvalidCharacters)
        return _PrintErrorMessage("At least a character inside the password",Result);

    if (Result == PasswordInvalidChecksum)
        return _PrintErrorMessage("Password checksum",Result);

    if (Result == PasswordInvalidClassicLevel)
        return _PrintErrorMessage("Decoded classic virus level",Result);

    if (Result == PasswordInvalidNonClassicLevel)
        return _PrintErrorMessage("Decoded non-classic game level",Result);

    if (Result == PasswordInvalidScore)
        return _PrintErrorMessage("Decoded score",Result);

    if (Result == PasswordInvalidTime)
        return _PrintErrorMessage("Decoded time",Result);

    if (Result == PasswordInvalidPlayerName)
        return _PrintErrorMessage("Decoded player name",Result);

    return _PrintErrorMessage("An unknown thing",Result);
}
