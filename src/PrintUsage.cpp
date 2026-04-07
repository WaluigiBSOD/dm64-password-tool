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

/// @file      PrintUsage.cpp
///
/// @brief     Functions that display the program's usage on screen.
///
/// @author    WaluigiBSOD
/// @copyright GPL-3.0 License

#include <iostream>
#include <iomanip>

#include "StringFunctions.h"

#include "Random.h"

#include "PlayerName.h"

#include "PasswordGenerate.h"
#include "PasswordShow.h"

#define USAGE_TABULATIONS_1     "\t"
#define USAGE_TABULATIONS_2     "\t\t"
#define USAGE_TABULATIONS_3     "\t\t\t"

using namespace std;

/// Prints on screen the table for inputting special characters in the player's name.
///
/// @author    WaluigiBSOD
/// @copyright GPL-3.0 License

void _PrintSpecialCharacterTable() {
    cout << " --- Special Characters ---" << endl << endl;

    cout << "To Input" << '\t' << "Result" << endl << endl;

    for (unsigned char i=0;i<ARRAY_SIZE(SpecialToASCIICharactersTable);i++)
        cout << SpecialToASCIICharactersTable[i] << "\t\t" << _ConversationalInternalCharacter(_ConvertASCIICharacterToInternal(SpecialToASCIICharactersTable[i])) << endl;

    cout << endl << " ---";

    cout << endl << endl;
}

/// Prints on screen the program's usage info.
///
/// @param[in] ExecutableFullPath Program's executable file full path.
///
/// @author    WaluigiBSOD
/// @copyright GPL-3.0 License

void _PrintUsageInfo(char* ExecutableFullPath) {
    string ExecutableName = _GetExecutableName(ExecutableFullPath);

    string Password = _GenerateRandomPassword();

    cout << " ### Decode ###" << endl << endl;

    cout << ExecutableName << " <password>";

    cout << endl << endl;

    cout << "password" << USAGE_TABULATIONS_2 << "Password to decode (e.g. " << Password << "), case insensitive."<< endl;

    cout << endl;

    cout << "Example output:" << endl << endl;

    _DecodeCheckAndShowPassword(Password);

    cout << endl;

    cout << " ### Generate (in-game information) ###" << endl << endl;

    cout << ExecutableName << " <mode> <game/virus level> <speed> <score (in-game)> <time (in-game)> <player name>";

    cout << endl << endl;

    cout << "mode" << USAGE_TABULATIONS_3 << "Game mode (" << (unsigned int)(GameModeClassic) << " - Classic, " << (unsigned int)(GameModeScoreAttack) << " - Score Attack, " << (unsigned int)(GameModeMarathon) << " - Marathon)." << endl;

    cout << "game/virus level" << USAGE_TABULATIONS_1 << "Virus Level (0 to " << (unsigned int)(VirusLevelMaximum) << ") for Classic mode, Game Level otherwise (" << (unsigned int)(GameLevelEasy) << " - Easy, " << (unsigned int)(GameLevelNormal) << " - Medium, " << (unsigned int)(GameLevelHard) << " - Hard)" << endl;

    cout << "speed" << USAGE_TABULATIONS_3 << "Speed of the game (" << (unsigned int)(SpeedLow) << " - Low, " << (unsigned int)(SpeedMedium) << " - Medium, " << (unsigned int)(SpeedHigh) << " - High)." << endl;

    cout << "score" << USAGE_TABULATIONS_3 << "In-game score as shown on the screen, from 0000000 to " << setw(6) << setfill('0') << (unsigned int)(ScoreMaximum) << "0." << endl;

    cout << "time" << USAGE_TABULATIONS_3 << "In-game time as shown on the screen (e.g. " << setw(2) << setfill('0') << Modulo100(MersenneTwister) << ':' << setw(2) << setfill('0') << Modulo60(MersenneTwister) << ")." << endl;

    cout << "player name" << USAGE_TABULATIONS_2 << "4-characters in-game player name. To input special characters, see the table below." << endl;

    cout << endl;

    cout << "The missing information (tenths of a second of the time and the frame count) is added pseudorandomly." << endl;

    cout << endl;

    cout << " ### Generate (full information) ###" << endl << endl;

    cout << ExecutableName << " <mode> <game/virus level> <speed> <score (internal)> <time (internal)> <player name> <frame count>";

    cout << endl << endl;

    cout << "mode" << USAGE_TABULATIONS_3 << "Game mode (" << (unsigned int)(GameModeClassic) << " - Classic, " << (unsigned int)(GameModeScoreAttack) << " - Score Attack, " << (unsigned int)(GameModeMarathon) << " - Marathon)." << endl;

    cout << "game/virus level" << USAGE_TABULATIONS_1 << "Virus Level (0 to " << (unsigned int)(VirusLevelMaximum) << ") for Classic mode, Game Level otherwise (" << (unsigned int)(GameLevelEasy) << " - Easy, " << (unsigned int)(GameLevelNormal) << " - Medium, " << (unsigned int)(GameLevelHard) << " - Hard)" << endl;

    cout << "speed" << USAGE_TABULATIONS_3 << "Speed of the game (" << (unsigned int)(SpeedLow) << " - Low, " << (unsigned int)(SpeedMedium) << " - Medium, " << (unsigned int)(SpeedHigh) << " - High)." << endl;

    cout << "score" << USAGE_TABULATIONS_3 << "Score of the game, excluding the last digit, from 000000 to " << setw(6) << setfill('0') << (unsigned int)(ScoreMaximum) << '.' << endl;

    cout << "time" << USAGE_TABULATIONS_3 << "In-game time expressed in tenths of a second, from 0 to " << TimeMaximum << '.' << endl;

    cout << "player name" << USAGE_TABULATIONS_2 << "4-characters in-game player name. To input special characters, see the table below." << endl;

    cout << "frame count" << USAGE_TABULATIONS_2 << "Total count of frames passed since the game started, modulo 1024 (from 0 to " << FrameCountMaximum << ")." << endl;

    cout << endl;

    _PrintSpecialCharacterTable();
}

/// Prints on screen the program's splash screen.
///
/// @author    WaluigiBSOD
/// @copyright GPL-3.0 License

void _PrintSplashScreen() {
    cout << _CenterString();

    cout << _CenterString("Dr. Mario 64 Password Tool");

    cout << _CenterString();

    cout << _CenterString("Version " + ProgramVersion);

    cout << _CenterString(" ");

    cout << _CenterString("Copyright (C) 2020-present WaluigiBSOD (waluigibsod.github.io)");

    cout << _CenterString();

    cout << _CenterString("This program comes with ABSOLUTELY NO WARRANTY.");

    cout << _CenterString("This is free software, and you are welcome to redistribute it");

    cout << _CenterString("under certain conditions.");

    cout << _CenterString("See the GNU General Public License v3.0 for more details.");

    cout << _CenterString();

    cout << endl;
}
