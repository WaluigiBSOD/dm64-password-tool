#ifndef PASSWORDCHECK_H_INCLUDED
#define PASSWORDCHECK_H_INCLUDED

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

#include <string>

using namespace std;

unsigned char _CheckPasswordData(unsigned char GameMode, unsigned char Level, unsigned char Speed, unsigned int Score, unsigned short Time, unsigned char Name[], unsigned int FrameCount);
unsigned char _IsPasswordWrong(string Password);
void _DisplayPasswordResult(unsigned char Result);
unsigned char _CheckPassword(string Password, bool DisplayResult = true, bool DisplayPassword = true);

#endif // PASSWORDCHECK_H_INCLUDED
