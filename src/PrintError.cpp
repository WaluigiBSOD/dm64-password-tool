// Dr. Mario 64 Password Generator/Decoder Tool
// Copyright (C) 2020 WaluigiBSOD (waluigibsod.github.io)
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

#include <iostream>
#include <sstream>

using namespace std;

#include "AsciiArt.h"
#include "StringFunctions.h"
#include "Constants.h"
#include "Random.h"

void _PrintErrorMessage(string Message, bool End = true) {
    cout << _CenterString();
    cout << _CenterString("Error");
    cout << _CenterString();

    switch (Modulo3(MersenneTwister)) {
        case 0:
            cout << AsciiArtViruses[Modulo3(MersenneTwister)];
            break;
        case 1:
            cout << AsciiArtVirusesLaughing[Modulo3(MersenneTwister)];
            break;
        case 2:
            cout << AsciiArtDrMario[Modulo2(MersenneTwister)];
            break;
    }

    cout << _CenterString();

    cout << _CenterString(Message);

    if (End)
        cout << _CenterString();
}

bool _PrintDataTypeError(string Name, unsigned int CurrentByteSize, unsigned int CorrectByteSize) {
    if (CurrentByteSize != CorrectByteSize) {
        _PrintErrorMessage("\"" + Name + "\" byte size mismatch",false);

        stringstream PrintErrorInfo;

        PrintErrorInfo << "Expected " << CorrectByteSize << ", found " << CurrentByteSize << '.';
        cout << _CenterString(PrintErrorInfo.str());

        cout << _CenterString();

        cout << _CenterString("The program needs to be recompiled.");

        cout << _CenterString();

        cout << endl;

        return true;
    }
    return false;
}


int _PrintErrorMessageWithReturnValue(string Name, int ReturnValue, bool Irreversible = false) {
    _PrintErrorMessage("\"" + Name + "\" error",false);

    cout << _CenterString();

    if (Irreversible)
        cout << _CenterString("Something went wrong internally in the program.");
    else
        cout << _CenterString("Correct the respective argument value and retry.");

    cout << _CenterString();

    cout << endl;

    return ReturnValue;
}
