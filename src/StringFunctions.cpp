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

/// @file      StringFunctions.cpp
///
/// @brief     Functions that handle the manipulation of strings.
///
/// @author    WaluigiBSOD
/// @copyright GPL-3.0 License

#include <cstring>

#include "Constants.h"

using namespace std;

/// Computes the program's executable file name from the full path.
///
/// @param[in] FullPath Program's full path.
///
/// @return    Program's executable name.
///
/// @author    WaluigiBSOD
/// @copyright GPL-3.0 License

string _GetExecutableName(char* ExecutableFullPath) {
    string retNAME = "";

    unsigned int i = strlen(ExecutableFullPath) - 1;

    while (i > 0 && ExecutableFullPath[i] != '\\' && ExecutableFullPath[i] != '/') {
        if (ExecutableFullPath[i] > 0)
            retNAME = ExecutableFullPath[i] + retNAME;

        i--;
    }

    return retNAME;
}

/// Generates a centered string or separator.
///
/// @param[in] ToCenter    String to center, if empty generates a separator.
/// @param[in] PrintBorder Prints a surrounding border (**true**) or not (**false**).
/// @param[in] SpacingLeft Amount of left spacing.
/// @param[in] Width       Width of the whole thing.
///
/// @return    The generated string.
///
/// @author    WaluigiBSOD
/// @copyright GPL-3.0 License

string _CenterString(string ToCenter = "", bool PrintBorder = true, unsigned int SpacingLeft = StringCenterLeftSpacing, unsigned int Width = StringCenterWidth) {
    string retSTRING = "";

    unsigned int i;

    if (ToCenter == "" || ToCenter.size() > Width) {
        for (i=0;i<SpacingLeft;i++)
            retSTRING += ' ';

        for (i=0;i<Width;i++)
            if (i == 0 || (i + 1) == Width)
                retSTRING += '+';
            else
                retSTRING += '-';
    } else {
        unsigned int TotalSpacing = (Width - ToCenter.size()) / 2;

        for (i=0;i<TotalSpacing + SpacingLeft;i++)
            if (i == SpacingLeft && PrintBorder)
                retSTRING += '|';
            else
                retSTRING += ' ';

        retSTRING += ToCenter;

        for (i=0;(i + 1)<TotalSpacing + (ToCenter.size() % 2);i++)
            retSTRING +=  ' ';

        if (PrintBorder)
            retSTRING += '|';
    }

    retSTRING += '\n';

    return retSTRING;
}

/// Checks if a string given in input is only numeric or not.
///
/// @param[in] String      String to check.
/// @param[in] OffsetStart Starting index to consider.
/// @param[in] OffsetEnd   Ending index to consider.
///
/// @return    **True** if the string given in input is only numeric, **false** if not.
///
/// @author    WaluigiBSOD
/// @copyright GPL-3.0 License

bool _OnlyDigits(char* String, unsigned int OffsetStart, unsigned int OffsetEnd) {
    for (unsigned int i=OffsetStart;i<=OffsetEnd;i++)
        if (String[i] < '0' || String[i] > '9')
            return false;

    return true;
}

/// Checks if a string given in input is only numeric or not.
///
/// @param[in] String String to check.
///
/// @return    **True** if the string given in input is only numeric, **false** if not.
///
/// @author    WaluigiBSOD
/// @copyright GPL-3.0 License

bool _OnlyDigits(char* String) {
    return _OnlyDigits(String,0,strlen(String) - 1);
}
