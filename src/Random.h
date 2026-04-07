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

/// @file      Random.h
///
/// @brief     Random.cpp's header file.
///
/// @author    WaluigiBSOD
/// @copyright GPL-3.0 License

#pragma once

#include <random>

using namespace std;

extern mt19937 MersenneTwister;

extern uniform_int_distribution<> Modulo10;
extern uniform_int_distribution<> Modulo60;
extern uniform_int_distribution<> Modulo100;

extern uniform_int_distribution<> RandomPlayerNameInternalCharacter;

extern uniform_int_distribution<> GameModePRNG;
extern uniform_int_distribution<> GameLevelPRNG;
extern uniform_int_distribution<> SpeedPRNG;
extern uniform_int_distribution<> VirusLevelPRNG;
extern uniform_int_distribution<> ScorePRNG;
extern uniform_int_distribution<> TimePRNG;
extern uniform_int_distribution<> FrameCountPRNG;
