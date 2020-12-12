// Dr. Mario 64 Password Encoder/Decoder Tool
// Copyright (C) 2020 WaluigiBSOD (waluigibsod.github.io)
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
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program. If not, see <https://www.gnu.org/licenses/>.

#include <iostream>
#include <iomanip>

using namespace std;

#include "Constants.h"
#include "PasswordDecodeEncode.h"
#include "PasswordCheck.h"
#include "PlayerName.h"

unsigned char _ShowDecodedPassword(string Password) {
    unsigned char PasswordCheck = _CheckPassword(Password);

    if (PasswordCheck != PasswordOK)
        return PasswordCheck;

    unsigned char GameMode;
    unsigned char Level;
    unsigned char Speed;
    unsigned int Score;
    unsigned short Time;
    unsigned char Name[4];
    string ConversationalName[4];
    unsigned int FrameCount;

    if (_DecodePassword(Password.c_str(),GameMode,Level,Speed,Score,Time,Name,FrameCount)) {
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
            cout << "Virus Level: " << (unsigned int)Level;

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

        unsigned int TimeSec = Time / 10;
        unsigned int TimeMin = TimeSec / 60;

        TimeSec %= 60;

        cout << "      mm : ss . f" << endl << endl;
        cout << "Time: " << setw(2) << setfill('0') << TimeMin << " : " << setw(2) << setfill('0') << TimeSec << " . " << (Time % 10);

        cout << endl << endl;

        ConversationalName[0] = _ConversationalInternalCharacter(Name[0]);
        ConversationalName[1] = _ConversationalInternalCharacter(Name[1]);
        ConversationalName[2] = _ConversationalInternalCharacter(Name[2]);
        ConversationalName[3] = _ConversationalInternalCharacter(Name[3]);

        Name[0] = _ConvertInternalCharacterToASCII(Name[0]);
        Name[1] = _ConvertInternalCharacterToASCII(Name[1]);
        Name[2] = _ConvertInternalCharacterToASCII(Name[2]);
        Name[3] = _ConvertInternalCharacterToASCII(Name[3]);

        cout << "Player Name: ";

        if (ConversationalName[0] != "")
            cout << ConversationalName[0];
        else
            cout << Name[0];

        cout << endl;
        cout << "             ";

        if (ConversationalName[1] != "")
            cout << ConversationalName[1];
        else
            cout << Name[1];

        cout << endl;
        cout << "             ";

        if (ConversationalName[2] != "")
            cout << ConversationalName[2];
        else
            cout << Name[2];

        cout << endl;
        cout << "             ";

        if (ConversationalName[3] != "")
            cout << ConversationalName[3];
        else
            cout << Name[3];

        cout << endl << endl;

        cout << "Frame Count (modulo 1024): " << FrameCount;

        cout << endl << endl;

        cout << " ---";

        cout << endl;
    }

    return PasswordOK;
}
