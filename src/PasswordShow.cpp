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

/// @file      PasswordShow.cpp
///
/// @brief     Function that shows a decoded password to screen.
///
/// @author    WaluigiBSOD
/// @copyright GPL-3.0 License

#include <iostream>
#include <iomanip>

#include "Constants.h"
#include "PlayerName.h"

#include "PasswordDecode.h"

#include "CheckRawData.h"

using namespace std;

/// Decodes, checks and shows details of a password.
///
/// @param[in] Password Entered password.
///
/// @return    **PasswordOK** value if the password and all the data inside is valid, the corresponding error code if not after having printed an error message to screen.
///
/// @author    WaluigiBSOD
/// @copyright GPL-3.0 License

unsigned char _DecodeCheckAndShowPassword(string Password) {
    unsigned char PasswordCheck;

    cout << " [!] Checking \"" << Password << "\" ... ";

    // Length check (must be equal to 20 characters).

    if (Password.size() != PasswordLength)
        return _DisplayDecodedPasswordError(PasswordInvalidLength);

    // Uppercase conversion and characters check (must not contain invalid characters).

    unsigned char i;
    unsigned char j;

    for (i=0;i<Password.size();i++) {
        Password[i] = toupper(Password[i]);

        for (j=0;j<PasswordCharacters.size();j++)
            if (PasswordCharacters[j] == Password[i])
                break;

        if (j == PasswordCharacters.size())
            return _DisplayDecodedPasswordError(PasswordInvalidCharacters);
    }

    unsigned char GameMode;
    unsigned char Level;
    unsigned char Speed;
    unsigned int Score;
    unsigned short Time;
    unsigned char PlayerName[4];
    string ConversationalName[4];
    unsigned short FrameCount;

    if (_DecodePassword(Password.c_str(),GameMode,Level,Speed,Score,Time,PlayerName,FrameCount)) {
        PasswordCheck = _CheckDecodedPasswordData(GameMode,Level,Speed,Score,Time,PlayerName,FrameCount);

        if (PasswordCheck == PasswordOK) {
            cout << "OK" << endl << endl;

            cout << " --- " << Password << " ---" << endl << endl;

            cout << "Mode: ";

            if (GameMode == GameModeClassic)
                cout << "Classic";
            else if (GameMode == GameModeScoreAttack)
                cout << "Score Attack";
            else if (GameMode == GameModeMarathon)
                cout << "Marathon";

            cout << endl << endl;

            if (GameMode != GameModeClassic) {
                cout << "Game Level: ";

                if (Level == GameLevelEasy)
                    cout << "Easy";
                else if (Level == GameLevelNormal)
                    cout << "Normal";
                else if (Level == GameLevelHard)
                    cout << "Hard";
            } else
                cout << "Virus Level: " << (unsigned short)Level;

            cout << endl << endl;

            cout << "Speed: ";

            if (Speed == SpeedLow)
                cout << "Low";
            else if (Speed == SpeedMedium)
                cout << "Medium";
            else if (Speed == SpeedHigh)
                cout << "High";

            cout << endl << endl;

            cout << "Score: " << setw(6) << setfill('0') << Score << '0';

            cout << endl << endl;

            unsigned short TimeSec = Time / 10;
            unsigned short TimeMin = TimeSec / 60;

            TimeSec %= 60;

            cout << "      mm : ss . f" << endl << endl;
            cout << "Time: " << setw(2) << setfill('0') << TimeMin << " : " << setw(2) << setfill('0') << TimeSec << " . " << (Time % 10);

            cout << endl << endl;

            cout << "Player Name: ";

            for (i=0;i<4;i++) {
                ConversationalName[i] = _ConversationalInternalCharacter(PlayerName[i]);

                if (ConversationalName[i] != "")
                    cout << ConversationalName[i];
                else
                    cout << _ConvertInternalCharacterToASCII(PlayerName[i]);

                cout << endl;

                if (i < 3)
                    cout << "             ";
            }

            cout << endl;

            cout << "Frame Count (modulo 1024): " << FrameCount;

            cout << endl << endl;

            cout << " ---";

            cout << endl << endl;
        } else
            return _DisplayDecodedPasswordError(PasswordCheck);
    } else
        return _DisplayDecodedPasswordError(PasswordInvalidChecksum);

    return PasswordOK;
}
