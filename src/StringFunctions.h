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

#pragma once

#include <string>

using namespace std;

extern const unsigned char StringCenterLeftSpacing;
extern const unsigned char StringCenterWidth;

string _CenterString(string ToCenter = "", bool PrintBorder = true, unsigned int SpacingLeft = StringCenterLeftSpacing, unsigned int Width = StringCenterWidth);
