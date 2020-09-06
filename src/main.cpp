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

#include <chrono>
#include <cstring>
#include <random>

using namespace std;

#include "Password.h"
#include "PasswordShow.h"
#include "PlayerName.h"
#include "AutoTest.h"
#include "PrintUsage.h"
#include "InputCheck.h"

extern const unsigned int ArgumentInvalidPasswordLength;
extern const unsigned int ArgumentInvalidGameMode;
extern const unsigned int ArgumentInvalidLevel;
extern const unsigned int ArgumentInvalidSpeed;
extern const unsigned int ArgumentInvalidScore;
extern const unsigned int ArgumentInvalidTime;
extern const unsigned int ArgumentInvalidName;

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

extern const unsigned int ReturnAutotestFail;
extern const unsigned int ReturnAutoTestPass;

mt19937 MersenneTwister(chrono::high_resolution_clock::now().time_since_epoch().count());
extern uniform_int_distribution<> FrameCountPRNG;
extern uniform_int_distribution<> Modulo10;

string ExecutableName;

int main(int argc, char** argv) {

    if (sizeof(signed char) != DataTypeCharCorrectByteSize)
        return DataTypeSignedCharWrongSize;
    if (sizeof(unsigned char) != DataTypeCharCorrectByteSize)
        return DataTypeUnsignedCharWrongSize;

    if (sizeof(signed short) != DataTypeShortCorrectByteSize)
        return DataTypeSignedShortWrongSize;
    if (sizeof(unsigned short) != DataTypeShortCorrectByteSize)
        return DataTypeUnsignedShortWrongSize;

    if (sizeof(signed int) != DataTypeIntCorrectByteSize)
        return DataTypeSignedIntWrongSize;
    if (sizeof(unsigned int) != DataTypeIntCorrectByteSize)
        return DataTypeUnsignedIntWrongSize;

    if (sizeof(signed long long) != DataTypeLongLongCorrectByteSize)
        return DataTypeSignedLongLongWrongSize;
    if (sizeof(unsigned long long) != DataTypeLongLongCorrectByteSize)
        return DataTypeUnsignedLongLongWrongSize;

    if (_AutoTest()) {
        ExecutableName = _GetExecutableName(argv[0],strlen(argv[0]));

        switch (argc) {
            // Decodes a password.
            case 2:
                {
                    if (strlen(argv[1]) != 20)
                        return ArgumentInvalidPasswordLength;

                    _PrintSplashScreen();

                    return _ShowDecodedPassword(argv[1]);

                    break;
                }
            // Generates a password (in-game information).
            case 7:
                {
                    if (strlen(argv[1]) != 1 || !_OnlyDigits(argv[1],strlen(argv[1])))
                        return ArgumentInvalidGameMode;
                    if (strlen(argv[2]) > 3 || !_OnlyDigits(argv[2],strlen(argv[2])))
                        return ArgumentInvalidLevel;
                    if (strlen(argv[3]) > 1 || !_OnlyDigits(argv[3],strlen(argv[3])))
                        return ArgumentInvalidSpeed;
                    if (strlen(argv[4]) < 1 || strlen(argv[4]) > 7 || !_OnlyDigits(argv[4],strlen(argv[4])) || argv[4][strlen(argv[4]) - 1] != '0')
                        return ArgumentInvalidScore;
                    if (strlen(argv[5]) != 5 || (strlen(argv[5]) >= 2 && argv[5][2] != ':'))
                        return ArgumentInvalidTime;
                    if (strlen(argv[6]) != 4 || _ConvertASCIICharacterToInternal(argv[6][0]) == ' ' || _ConvertASCIICharacterToInternal(argv[6][1]) == ' ' || _ConvertASCIICharacterToInternal(argv[6][2]) == ' ' || _ConvertASCIICharacterToInternal(argv[6][3]) == ' ')
                        return ArgumentInvalidName;

                    unsigned char GameMode = atoi(argv[1]) & 0xFF;
                    unsigned char Level = atoi(argv[2]) & 0xFF;
                    unsigned char Speed = atoi(argv[3]) & 0xFF;
                    unsigned int Score = atoi(argv[4]);
                    unsigned short Time;
                    unsigned char Name[4];
                    unsigned int FrameCount = FrameCountPRNG(MersenneTwister);

                    Score /= 10;

                    string TimeString = "";
                    TimeString += argv[5][0];
                    TimeString += argv[5][1];
                    TimeString += argv[5][3];
                    TimeString += argv[5][4];

                    if (!_OnlyDigits((char*)TimeString.c_str(),TimeString.size()))
                        return ArgumentInvalidTime;

                    unsigned short TimeMinutes = ((argv[5][0] - '0') * 10) + (argv[5][1] - '0');
                    unsigned short TimeSeconds = ((argv[5][3] - '0') * 10) + (argv[5][4] - '0');
                    Time = (TimeMinutes * 60 * 10) + (TimeSeconds * 10) + Modulo10(MersenneTwister);

                    memcpy(Name,argv[6],4);
                    Name[0] = _ConvertASCIICharacterToInternal(Name[0]);
                    Name[1] = _ConvertASCIICharacterToInternal(Name[1]);
                    Name[2] = _ConvertASCIICharacterToInternal(Name[2]);
                    Name[3] = _ConvertASCIICharacterToInternal(Name[3]);

                    _PrintSplashScreen();

                    string Password = _EncodePassword(GameMode,Level,Speed,Score,Time,Name,FrameCount);
                    return _ShowDecodedPassword(Password);

                    break;
                }
            // Generates a password (full information).
            case 8:
                {
                    if (strlen(argv[1]) != 1 || !_OnlyDigits(argv[1],strlen(argv[1])))
                        return ArgumentInvalidGameMode;
                    if (strlen(argv[2]) > 3 || !_OnlyDigits(argv[2],strlen(argv[2])))
                        return ArgumentInvalidLevel;
                    if (strlen(argv[3]) > 1 || !_OnlyDigits(argv[3],strlen(argv[3])))
                        return ArgumentInvalidSpeed;
                    if (!_OnlyDigits(argv[4],strlen(argv[4])))
                        return ArgumentInvalidScore;
                    if (strlen(argv[5]) != 5 && !_OnlyDigits(argv[5],strlen(argv[5])))
                        return ArgumentInvalidTime;
                    if (strlen(argv[6]) != 4 || _ConvertASCIICharacterToInternal(argv[6][0]) == ' ' || _ConvertASCIICharacterToInternal(argv[6][1]) == ' ' || _ConvertASCIICharacterToInternal(argv[6][2]) == ' ' || _ConvertASCIICharacterToInternal(argv[6][3]) == ' ')
                        return ArgumentInvalidName;

                    unsigned char GameMode = atoi(argv[1]) & 0xFF;
                    unsigned char Level = atoi(argv[2]) & 0xFF;
                    unsigned char Speed = atoi(argv[3]) & 0xFF;
                    unsigned int Score = atoi(argv[4]);
                    unsigned short Time = atoi(argv[5]) & 0xFFFF;
                    unsigned char Name[4];
                    unsigned int FrameCount = atoi(argv[7]);

                    memcpy(Name,argv[6],4);
                    Name[0] = _ConvertASCIICharacterToInternal(Name[0]);
                    Name[1] = _ConvertASCIICharacterToInternal(Name[1]);
                    Name[2] = _ConvertASCIICharacterToInternal(Name[2]);
                    Name[3] = _ConvertASCIICharacterToInternal(Name[3]);

                    _PrintSplashScreen();

                    string Password = _EncodePassword(GameMode,Level,Speed,Score,Time,Name,FrameCount);
                    return _ShowDecodedPassword(Password);

                    break;
                }
            // Otherwise, it prints usage.
            default:

                _PrintSplashScreen();

                _PrintUsageInfo();

                break;
        }

        return ReturnAutoTestPass;
    }

    return ReturnAutotestFail;
}
