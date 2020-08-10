#ifndef PRINTUSAGE_H_INCLUDED
#define PRINTUSAGE_H_INCLUDED

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

string _GetExecutableName(char* FullPath, int Size);
void _CenterString(string ToCenter, unsigned int SpacingLeft, unsigned int Width);
void _PrintSpecialCharacterTable();
void _PrintUsageInfo();
void _PrintSplashScreen();

#endif // PRINTUSAGE_H_INCLUDED
