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

#include <iostream>

using namespace std;

#include "PasswordCheck.h"
#include "PasswordMiscellaneous.h"

extern const unsigned int AutotestIterations;

extern const unsigned char PasswordOK;

bool _AutoTest(bool Show = false) {
    if (Show)
        cout << endl << " [!] AutoTest ... ";

    string Password;

    for (unsigned int i=0;i<AutotestIterations;i++) {
        Password = _GenerateRandomPassword();
        if (_CheckPassword(Password,false,false) != PasswordOK) {
            cout << endl << " [!] AutoTest ... " << "FAIL" << endl;
            _CheckPassword(Password,true,true);
            cout << "Send the password to Waluigi BSOD and tell him about the error." << endl;
            return false;
        }
    }

    if (Show)
        cout << "PASS" << endl;

    return true;
}
