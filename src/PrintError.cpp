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

/// @file      PrintError.cpp
///
/// @brief     Functions that display error messages on screen.
///
/// @author    WaluigiBSOD
/// @copyright GPL-3.0 License

#include <iostream>

#include "StringFunctions.h"

using namespace std;

/// Prints an error message on screen.
///
/// @param[in] Message Message to print.
///
/// @author    WaluigiBSOD
/// @copyright GPL-3.0 License

void _PrintErrorMessage(string Message) {
    cout << _CenterString();
    cout << _CenterString("Error!");
    cout << _CenterString();

    cout << _CenterString(Message);

    cout << _CenterString();

    cout << endl;
}

/// Prints an error message on screen.
///
/// @param[in] Message     Message to print.
/// @param[in] ReturnValue Error code to return.
///
/// @return    Error code specified in **ReturnValue**.
///
/// @author    WaluigiBSOD
/// @copyright GPL-3.0 License

unsigned char _PrintErrorMessage(string Message, unsigned char ReturnValue) {
    _PrintErrorMessage(Message + " is not valid");

    return ReturnValue;
}
