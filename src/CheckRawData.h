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

/// @file      CheckRawData.h
///
/// @brief     CheckRawData.cpp's header file.
///
/// @author    WaluigiBSOD
/// @copyright GPL-3.0 License

#pragma once

unsigned char _CheckDecodedPasswordData(unsigned char GameMode, unsigned char Level, unsigned char Speed, unsigned int Score, unsigned short Time, unsigned char PlayerName[], unsigned short FrameCount, bool Argument = false);

unsigned char _DisplayDecodedPasswordError(unsigned char Result);
