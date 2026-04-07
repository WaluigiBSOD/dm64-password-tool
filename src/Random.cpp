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

/// @file      Random.cpp
///
/// @brief     Objects that handle pseudorandom numbers generation.
///
/// @author    WaluigiBSOD
/// @copyright GPL-3.0 License

#include <chrono>
#include <random>

#include "Constants.h"

using namespace std;

mt19937 MersenneTwister(chrono::high_resolution_clock::now().time_since_epoch().count());

uniform_int_distribution<> Modulo10(0,9);
uniform_int_distribution<> Modulo60(0,59);
uniform_int_distribution<> Modulo100(0,99);

uniform_int_distribution<> RandomPlayerNameInternalCharacter(0,ARRAY_SIZE(InternalToASCIICharactersTable) - 1);

uniform_int_distribution<> GameModePRNG(GameModeClassic,GameModeMarathon);
uniform_int_distribution<> GameLevelPRNG(GameLevelEasy,GameLevelHard);
uniform_int_distribution<> SpeedPRNG(SpeedLow,SpeedHigh);
uniform_int_distribution<> VirusLevelPRNG(0,VirusLevelMaximum);
uniform_int_distribution<> ScorePRNG(0,ScoreMaximum);
uniform_int_distribution<> TimePRNG(0,TimeMaximum);
uniform_int_distribution<> FrameCountPRNG(0,FrameCountMaximum);
