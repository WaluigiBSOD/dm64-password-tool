// Dr. Mario 64 Password Encoder/Decoder Tool
// Copyright (C) 2020  Waluigi BSOD (waluigibsod.github.io)
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
#include <iomanip>
#include <random>

using namespace std;

#include "PlayerName.h"
#include "PasswordMiscellaneous.h"
#include "PasswordShow.h"

#define USAGE_TABULATIONS_1     "\t"
#define USAGE_TABULATIONS_2     "\t\t"
#define USAGE_TABULATIONS_3     "\t\t\t"

#define USAGE_SPACING           1
#define USAGE_WIDTH             64

extern const string ProgramVersion;

extern const char SpecialASCII[];
extern const unsigned int SpecialASCIISize;

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

extern mt19937 MersenneTwister;
extern uniform_int_distribution<> Modulo60;
extern uniform_int_distribution<> Modulo100;

extern string ExecutableName;

string _GetExecutableName(char* FullPath, int Size) {
    string retNAME = "";
    int i = Size - 1;

    while (i > 0 && FullPath[i] != '\\' && FullPath[i] != '/') {
        if (FullPath[i] > 0)
            retNAME = FullPath[i] + retNAME;
        i--;
    }

    return retNAME;
}

void _CenterString(string ToCenter, unsigned int SpacingLeft, unsigned int Width) {
    if (ToCenter == "" || ToCenter.size() > Width) {
        for (unsigned int i=0;i<SpacingLeft;i++)
            cout << ' ';
        for (unsigned int i=0;i<Width;i++)
            if (i == 0 || (i + 1) == Width)
                cout << '+';
            else
                cout << '-';
    } else {
        unsigned int TotalSpacing = (Width - ToCenter.size()) / 2;
        for (unsigned int i=0;i<TotalSpacing + SpacingLeft;i++)
            if (i == SpacingLeft)
                cout << '|';
            else
                cout << ' ';
        cout << ToCenter;
        for (unsigned int i=0;(i + 1)<TotalSpacing + (ToCenter.size() % 2);i++)
            cout << ' ';
        cout << '|';
    }
}

void _PrintSpecialCharacterTable() {
    cout << " --- Special Characters ---" << endl << endl;

    cout << "To Input" << '\t' << "Result" << endl << endl;

    for (unsigned int i=0;i<SpecialASCIISize;i++)
        cout << SpecialASCII[i] << "\t\t" << _ConversationalInternalCharacter(_ConvertASCIICharacterToInternal(SpecialASCII[i])) << endl;

    cout << endl << " ---";

    cout << endl;
}

void _PrintUsageInfo() {
    string Password = _GenerateRandomPassword();

    cout << " ### Decode ###" << endl << endl;

    cout << ExecutableName << " <password>";
    cout << endl << endl;

    cout << "password" << USAGE_TABULATIONS_2 << "Password to decode (e.g. " << Password << ")."<< endl;
    cout << endl;

    cout << "Example output:" << endl << endl;

    _ShowDecodedPassword(Password);

    cout << endl;

    cout << " ### Encode (in-game information) ###" << endl << endl;

    cout << ExecutableName << " <mode> <game/virus level> <speed> <score> <in-game time> <name>";
    cout << endl << endl;

    cout << "mode" << USAGE_TABULATIONS_3 << "Game mode (" << (unsigned int)(GameModeClassic) << " - Classic, " << (unsigned int)(GameModeScoreAttack) << " - Score Attack, " << (unsigned int)(GameModeMarathon) << " - Marathon)." << endl;

    cout << "game/virus level" << USAGE_TABULATIONS_1 << "Virus Level (" << (unsigned int)(VirusLevelMinimum) << " to " << (unsigned int)(VirusLevelMaximum) << ") for Classic mode, Game Level otherwise (" << (unsigned int)(GameLevelEasy) << " - Easy, " << (unsigned int)(GameLevelMedium) << " - Medium, " << (unsigned int)(GameLevelHard) << " - Hard)" << endl;

    cout << "speed" << USAGE_TABULATIONS_3 << "Speed of the game (" << (unsigned int)(SpeedLow) << " - Low, " << (unsigned int)(SpeedMedium) << " - Medium, " << (unsigned int)(SpeedHigh) << " - High)." << endl;

    cout << "score" << USAGE_TABULATIONS_3 << "In-game score as shown on the screen, from " << setw(6) << setfill('0') << (unsigned int)(ScoreMinimum) << '0' << " to " << setw(6) << setfill('0') << (unsigned int)(ScoreMaximum) << "0." << endl;

    cout << "in-game time" << USAGE_TABULATIONS_2 << "In-game time as shown on the screen (e.g " << setw(2) << setfill('0') << Modulo100(MersenneTwister) << ':' << setw(2) << setfill('0') << Modulo60(MersenneTwister) << ")" << endl;

    cout << "name" << USAGE_TABULATIONS_3 << "4-character in-game name. To input special characters, see the table below." << endl;

    cout << endl;

    cout << "The missing information (tenths of a second in the time and the frame count) is added pseudorandomly." << endl;

    cout << endl;

    cout << " ### Encode (full information) ###" << endl << endl;

    cout << ExecutableName << " <mode> <game/virus level> <speed> <score> <time (tenths of a second)> <name> <frame count>";
    cout << endl << endl;

    cout << "mode" << USAGE_TABULATIONS_3 << "Game mode (" << (unsigned int)(GameModeClassic) << " - Classic, " << (unsigned int)(GameModeScoreAttack) << " - Score Attack, " << (unsigned int)(GameModeMarathon) << " - Marathon)." << endl;

    cout << "game/virus level" << USAGE_TABULATIONS_1 << "Virus Level (" << (unsigned int)(VirusLevelMinimum) << " to " << (unsigned int)(VirusLevelMaximum) << ") for Classic mode, Game Level otherwise (" << (unsigned int)(GameLevelEasy) << " - Easy, " << (unsigned int)(GameLevelMedium) << " - Medium, " << (unsigned int)(GameLevelHard) << " - Hard)" << endl;

    cout << "speed" << USAGE_TABULATIONS_3 << "Speed of the game (" << (unsigned int)(SpeedLow) << " - Low, " << (unsigned int)(SpeedMedium) << " - Medium, " << (unsigned int)(SpeedHigh) << " - High)." << endl;

    cout << "score" << USAGE_TABULATIONS_3 << "Score of the game, excluding the last digit, from " << setw(6) << setfill('0') << (unsigned int)(ScoreMinimum) << " to " << setw(6) << setfill('0') << (unsigned int)(ScoreMaximum) << '.' << endl;

    cout << "time" << USAGE_TABULATIONS_3 << "In-game time expressed in tenths of a second, from " << TimeMinimum << " to " << TimeMaximum << '.' << endl;

    cout << "name" << USAGE_TABULATIONS_3 << "4-character in-game name. To input special characters, see the table below." << endl;

    cout << "frame count" << USAGE_TABULATIONS_2 << "The count of frames passed since the start of the videogame, modulo 1024 (from " << FrameCountMinimum << " to " << FrameCountMaximum << ")." << endl;

    cout << endl;

    _PrintSpecialCharacterTable();
}

void _PrintSplashScreen() {
    cout << endl;

    _CenterString("",USAGE_SPACING,USAGE_WIDTH);

    cout << endl;

    _CenterString("Dr. Mario 64 Password Encoder/Decoder Tool",USAGE_SPACING,USAGE_WIDTH);

    cout << endl;

    _CenterString("",USAGE_SPACING,USAGE_WIDTH);

    cout << endl;

    _CenterString("Version " + ProgramVersion,USAGE_SPACING,USAGE_WIDTH);

    cout << endl;

    _CenterString("Copyright (C) 2020  Waluigi BSOD (waluigibsod.github.io)",USAGE_SPACING,USAGE_WIDTH);

    cout << endl;

    _CenterString("",USAGE_SPACING,USAGE_WIDTH);

    cout << endl;

    _CenterString("This program comes with ABSOLUTELY NO WARRANTY.",USAGE_SPACING,USAGE_WIDTH);

    cout << endl;

    _CenterString("This is free software, and you are welcome to redistribute it",USAGE_SPACING,USAGE_WIDTH);

    cout << endl;

    _CenterString("under certain conditions.",USAGE_SPACING,USAGE_WIDTH);

    cout << endl;

    _CenterString("See the GNU General Public License v3.0 for more details.",USAGE_SPACING,USAGE_WIDTH);

    cout << endl;

    _CenterString("",USAGE_SPACING,USAGE_WIDTH);

    cout << endl << endl;
}
