// Dr. Mario 64 Password Generator/Decoder Tool
// Copyright (C) 2020-present WaluigiBSOD (waluigibsod.github.io)
//
// This file is part of Dr. Mario 64 Password Generator/Decoder Tool.
//
// Dr. Mario 64 Password Generator/Decoder Tool is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Dr. Mario 64 Password Generator/Decoder Tool is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program. If not, see <https://www.gnu.org/licenses/>.

#include <string>

using namespace std;

#include "Constants.h"

string _CenterString(string ToCenter = "", bool PrintBorder = true, unsigned int SpacingLeft = StringCenterLeftSpacing, unsigned int Width = StringCenterWidth) {
    string retSTRING = "";

    if (ToCenter == "" || ToCenter.size() > Width) {
        for (unsigned int i=0;i<SpacingLeft;i++)
            retSTRING += ' ';

        for (unsigned int i=0;i<Width;i++)
            if (i == 0 || (i + 1) == Width)
                retSTRING += '+';
            else
                retSTRING += '-';
    } else {
        unsigned int TotalSpacing = (Width - ToCenter.size()) / 2;

        for (unsigned int i=0;i<TotalSpacing + SpacingLeft;i++)
            if (i == SpacingLeft && PrintBorder)
                retSTRING += '|';
            else
                retSTRING += ' ';

        retSTRING += ToCenter;

        for (unsigned int i=0;(i + 1)<TotalSpacing + (ToCenter.size() % 2);i++)
            retSTRING +=  ' ';

        if (PrintBorder)
            retSTRING += '|';
    }

    retSTRING += '\n';

    return retSTRING;
}
