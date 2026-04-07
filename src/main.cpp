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

/// @file      main.cpp
///
/// @brief     Main program file.
///
/// @author    WaluigiBSOD
/// @copyright GPL-3.0 License

#include "Constants.h"

#include "Random.h"

#include "PrintUsage.h"

#include "PlayerName.h"

#include "PasswordGenerate.h"
#include "PasswordShow.h"

#include "CheckCommandLineArguments.h"
#include "CheckRawData.h"

/// The main program function.
///
/// Handles all the command-line input/output, displaying the program's splash screen and calling the appropriate password decoding/generation functions.
///
/// @param[in] argc Number of command-line arguments (zeroth one is always the program's executable full path).
/// @param[in] argv Command-line arguments.
///
/// @return    The program's exit code (0 if everything was ok, > 0 if a decoding/generation error occurred).
///
/// @author    WaluigiBSOD
/// @copyright GPL-3.0 License

int main(int argc, char** argv) {
    _PrintSplashScreen();

    switch (argc) {
        case 2:
            // Decodes a password

            return _DecodeCheckAndShowPassword(argv[1]);
        case 7:
        case 8:
            {
                // Generates a password

                unsigned char ArgumentsCheck;

                ArgumentsCheck = _CheckCommandLineArguments(argv,argc == 7);

                if (ArgumentsCheck > 0)
                    return ArgumentsCheck;

                unsigned char GameMode = atoi(argv[1]) & 0xFF;
                unsigned char Level = atoi(argv[2]) & 0xFF;
                unsigned char Speed = atoi(argv[3]) & 0xFF;
                unsigned int Score = atoi(argv[4]);
                unsigned short Time;
                unsigned char PlayerName[4];
                unsigned short FrameCount;

                if (argc == 7) {
                    Score /= 10;

                    unsigned char TimeMinutes = ((argv[5][0] - '0') * 10) + (argv[5][1] - '0');
                    unsigned char TimeSeconds = ((argv[5][3] - '0') * 10) + (argv[5][4] - '0');

                    Time = (TimeMinutes * 60 * 10) + (TimeSeconds * 10) + Modulo10(MersenneTwister);

                    FrameCount  = FrameCountPRNG(MersenneTwister);
                } else {
                    Time = atoi(argv[5]) & 0xFFFF;

                    FrameCount = atoi(argv[7]);
                }

                for (unsigned char i=0;i<4;i++)
                    PlayerName[i] = _ConvertASCIICharacterToInternal(argv[6][i]);

                ArgumentsCheck = _CheckDecodedPasswordData(GameMode,Level,Speed,Score,Time,PlayerName,FrameCount,true);

                if (ArgumentsCheck != PasswordOK)
                    return ArgumentsCheck;

                return _DecodeCheckAndShowPassword(_GeneratePassword(GameMode,Level,Speed,Score,Time,PlayerName,FrameCount));
            }
        default:
            // Otherwise, it prints usage info.

            _PrintUsageInfo(argv[0]);
    }

    return 0;
}
