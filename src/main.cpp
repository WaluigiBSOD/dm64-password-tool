// Dr. Mario 64 Password Generator/Decoder Tool
// Copyright (C) 2020-present WaluigiBSOD (waluigibsod.github.io)
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

#include <cstring>

using namespace std;

#include "Constants.h"
#include "PasswordGenerateDecode.h"
#include "PasswordCheck.h"
#include "PasswordShow.h"
#include "PlayerName.h"
#include "AutoTest.h"
#include "PrintUsage.h"
#include "InputCheck.h"
#include "PrintError.h"
#include "StringFunctions.h"
#include "Random.h"

string ExecutableName;

int main(int argc, char** argv) {
    _PrintSplashScreen();

    if (_PrintDataTypeError("signed char",sizeof(signed char),DataTypeCharCorrectByteSize))
        return DataTypeSignedCharWrongSize;
    if (_PrintDataTypeError("unsigned char",sizeof(unsigned char),DataTypeCharCorrectByteSize))
        return DataTypeUnsignedCharWrongSize;

    if (_PrintDataTypeError("signed short",sizeof(signed short),DataTypeShortCorrectByteSize))
        return DataTypeSignedShortWrongSize;
    if (_PrintDataTypeError("unsigned short",sizeof(unsigned short),DataTypeShortCorrectByteSize))
        return DataTypeUnsignedShortWrongSize;

    if (_PrintDataTypeError("signed int",sizeof(signed int),DataTypeIntCorrectByteSize))
        return DataTypeSignedIntWrongSize;
    if (_PrintDataTypeError("unsigned int",sizeof(unsigned int),DataTypeIntCorrectByteSize))
        return DataTypeUnsignedIntWrongSize;

    if (_PrintDataTypeError("signed long long",sizeof(signed long long),DataTypeLongLongCorrectByteSize))
        return DataTypeSignedLongLongWrongSize;
    if (_PrintDataTypeError("unsigned long long",sizeof(unsigned long long),DataTypeLongLongCorrectByteSize))
        return DataTypeUnsignedLongLongWrongSize;

    if (_AutoTest()) {
        ExecutableName = _GetExecutableName(argv[0],strlen(argv[0]));

        switch (argc) {
            // Decodes a password.
            case 2:
                {
                    if (strlen(argv[1]) != 20)
                        return ArgumentInvalidPasswordLength;

                    return _ShowDecodedPassword(argv[1]);

                    break;
                }
            // Generates a password (in-game information).
            case 7:
                {
                    if (strlen(argv[1]) != 1 || !_OnlyDigits(argv[1],strlen(argv[1])))
                        return _PrintErrorMessageWithReturnValue("Game Mode",ArgumentInvalidGameMode);
                    if (strlen(argv[2]) > 3 || !_OnlyDigits(argv[2],strlen(argv[2])))
                        return _PrintErrorMessageWithReturnValue("Level",ArgumentInvalidLevel);
                    if (strlen(argv[3]) > 1 || !_OnlyDigits(argv[3],strlen(argv[3])))
                        return _PrintErrorMessageWithReturnValue("Speed",ArgumentInvalidSpeed);
                    if (strlen(argv[4]) < 1 || strlen(argv[4]) > 7 || !_OnlyDigits(argv[4],strlen(argv[4])) || argv[4][strlen(argv[4]) - 1] != '0')
                        return _PrintErrorMessageWithReturnValue("Score",ArgumentInvalidScore);
                    if (strlen(argv[5]) != 5 || (strlen(argv[5]) >= 2 && argv[5][2] != ':'))
                        return _PrintErrorMessageWithReturnValue("Time",ArgumentInvalidTime);
                    if (strlen(argv[6]) != 4 || _ConvertASCIICharacterToInternal(argv[6][0]) == ' ' || _ConvertASCIICharacterToInternal(argv[6][1]) == ' ' || _ConvertASCIICharacterToInternal(argv[6][2]) == ' ' || _ConvertASCIICharacterToInternal(argv[6][3]) == ' ')
                        return _PrintErrorMessageWithReturnValue("Name",ArgumentInvalidName);

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
                        return _PrintErrorMessageWithReturnValue("Time",ArgumentInvalidTime);

                    unsigned short TimeMinutes = ((argv[5][0] - '0') * 10) + (argv[5][1] - '0');
                    unsigned short TimeSeconds = ((argv[5][3] - '0') * 10) + (argv[5][4] - '0');
                    Time = (TimeMinutes * 60 * 10) + (TimeSeconds * 10) + Modulo10(MersenneTwister);

                    memcpy(Name,argv[6],4);
                    Name[0] = _ConvertASCIICharacterToInternal(Name[0]);
                    Name[1] = _ConvertASCIICharacterToInternal(Name[1]);
                    Name[2] = _ConvertASCIICharacterToInternal(Name[2]);
                    Name[3] = _ConvertASCIICharacterToInternal(Name[3]);

                    unsigned int SecondArgumentsCheck = _CheckPasswordData(GameMode,Level,Speed,Score,Time,Name,FrameCount,true);

                    if (SecondArgumentsCheck != PasswordOK)
                        return SecondArgumentsCheck;
                    else {
                        string Password = _GeneratePassword(GameMode,Level,Speed,Score,Time,Name,FrameCount);
                        return _ShowDecodedPassword(Password);
                    }

                    break;
                }
            // Generates a password (full information).
            case 8:
                {
                    if (strlen(argv[1]) != 1 || !_OnlyDigits(argv[1],strlen(argv[1])))
                        return _PrintErrorMessageWithReturnValue("Game Mode",ArgumentInvalidGameMode);
                    if (strlen(argv[2]) > 3 || !_OnlyDigits(argv[2],strlen(argv[2])))
                        return _PrintErrorMessageWithReturnValue("Level",ArgumentInvalidLevel);
                    if (strlen(argv[3]) > 1 || !_OnlyDigits(argv[3],strlen(argv[3])))
                        return _PrintErrorMessageWithReturnValue("Speed",ArgumentInvalidSpeed);
                    if (!_OnlyDigits(argv[4],strlen(argv[4])))
                        return _PrintErrorMessageWithReturnValue("Score",ArgumentInvalidScore);
                    if (strlen(argv[5]) != 5 && !_OnlyDigits(argv[5],strlen(argv[5])))
                        return _PrintErrorMessageWithReturnValue("Time",ArgumentInvalidTime);
                    if (strlen(argv[6]) != 4 || _ConvertASCIICharacterToInternal(argv[6][0]) == ' ' || _ConvertASCIICharacterToInternal(argv[6][1]) == ' ' || _ConvertASCIICharacterToInternal(argv[6][2]) == ' ' || _ConvertASCIICharacterToInternal(argv[6][3]) == ' ')
                        return _PrintErrorMessageWithReturnValue("Name",ArgumentInvalidName);
                    if (strlen(argv[7]) > 4 && !_OnlyDigits(argv[7],strlen(argv[7])))
                        return _PrintErrorMessageWithReturnValue("Frame Count",ArgumentInvalidFrameCount);

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

                    unsigned int SecondArgumentsCheck = _CheckPasswordData(GameMode,Level,Speed,Score,Time,Name,FrameCount,true);

                    if (SecondArgumentsCheck != PasswordOK)
                        return SecondArgumentsCheck;
                    else {
                        string Password = _GeneratePassword(GameMode,Level,Speed,Score,Time,Name,FrameCount);
                        return _ShowDecodedPassword(Password);
                    }

                    break;
                }
            // Otherwise, it prints usage info.
            default:

                _PrintUsageInfo();

                break;
        }

        return ReturnAutoTestPass;
    }

    return _PrintErrorMessageWithReturnValue("Auto Test",ReturnAutoTestFail,true);
}
