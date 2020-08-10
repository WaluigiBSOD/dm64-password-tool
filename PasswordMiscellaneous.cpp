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

#include <random>

#include "Password.h"

extern const unsigned char GameModeClassic;
extern const unsigned char GameModes[3];
extern const unsigned char GameLevel[3];
extern const unsigned char GameSpeed[3];

extern const unsigned char InternalToASCIICharacterTable[];

extern mt19937 MersenneTwister;

extern uniform_int_distribution<> Modulo3;

extern uniform_int_distribution<> RandomInternalCharacter;

extern uniform_int_distribution<> VirusLevelPRNG;
extern uniform_int_distribution<> ScorePRNG;
extern uniform_int_distribution<> TimePRNG;
extern uniform_int_distribution<> FrameCountPRNG;

string _GenerateRandomPassword() {

    unsigned char GameMode = GameModes[Modulo3(MersenneTwister)];

    unsigned char Level;

    if (GameMode == GameModeClassic)
        Level = VirusLevelPRNG(MersenneTwister);
    else
        Level = GameLevel[Modulo3(MersenneTwister)];

    unsigned char Speed = GameSpeed[Modulo3(MersenneTwister)];

    unsigned int Score = ScorePRNG(MersenneTwister);

    unsigned short Time = TimePRNG(MersenneTwister);

    unsigned char Name[4];

    Name[0] = InternalToASCIICharacterTable[RandomInternalCharacter(MersenneTwister)];
    Name[1] = InternalToASCIICharacterTable[RandomInternalCharacter(MersenneTwister)];
    Name[2] = InternalToASCIICharacterTable[RandomInternalCharacter(MersenneTwister)];
    Name[3] = InternalToASCIICharacterTable[RandomInternalCharacter(MersenneTwister)];

    unsigned int FrameCount = FrameCountPRNG(MersenneTwister);

    return _EncodePassword(GameMode,Level,Speed,Score,Time,Name,FrameCount);
}
