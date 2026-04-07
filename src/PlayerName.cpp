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

/// @file      PlayerName.cpp
///
/// @brief     Functions that handle how the player name is encoded internally.
///
/// @author    WaluigiBSOD
/// @copyright GPL-3.0 License

#include <string>

#include "Constants.h"

using namespace std;

/// Converts an internal character used for the player name to ASCII.
///
/// @param[in] InternalCharacter The internal character to convert.
///
/// @return    The corresponding ASCII character.
///
/// @author    WaluigiBSOD
/// @copyright GPL-3.0 License

unsigned char _ConvertInternalCharacterToASCII(unsigned char InternalCharacter) {
    // Space

    if (InternalCharacter == 0)
        return ' ';

    // Alphabetic and numeric characters

    if (InternalCharacter >= 163 && InternalCharacter <= 224)
        return AlphabeticNumericASCII[(InternalCharacter + 23) % AlphabeticNumericASCII.size()];

    // Special Characters

    switch (InternalCharacter) {
        case 225:
            // ~

            return SpecialCharacterTilde;
        case 226:
            // / (small)

            return SpecialCharacterSlashSmall;
        case 227:
            // Centered dot

            return SpecialCharacterCenteredDot;
        case 228:
            // .

            return SpecialCharacterDot;
        case 229:
            // ?

            return SpecialCharacterQuestionMark;
        case 231:
            // Heart

            return SpecialCharacterHeart;
        case 232:
            // Star

            return SpecialCharacterStar;
        case 233:
            // Circle

            return SpecialCharacterCircle;
        case 234:
            // X mark

            return SpecialCharacterMarkX;
        case 235:
            // / (big)

            return SpecialCharacterSlashBig;
        case 236:
            // :

            return SpecialCharacterColon;
        case 237:
            // %

            return SpecialCharacterPercentual;
        case 238:
            // ´

            return SpecialCharacterAccent;
        case 242:
            // &

            return SpecialCharacterAmpersand;
        case 243:
            // . (copy)

            return SpecialCharacterDotAlternate;
    }

    return ConversionInternalToAsciiError;
}

/// Converts an ASCII character to an internal character used for the player name.
///
/// @param[in] ASCIICharacter The ASCII character to convert.
///
/// @return    The corresponding internal character.
///
/// @author    WaluigiBSOD
/// @copyright GPL-3.0 License

unsigned char _ConvertASCIICharacterToInternal(unsigned char ASCIICharacter) {
    // Space

    if (ASCIICharacter == ' ')
        return 0;

    // Alphabetic (uppercase)

    if (ASCIICharacter >= 'A' && ASCIICharacter <= 'Z')
        return (ASCIICharacter - 'A') + 163;

    // Alphabetic (lowercase)

    if (ASCIICharacter >= 'a' && ASCIICharacter <= 'z')
        return (ASCIICharacter - 'a') + 189;

    // Numeric

    if (ASCIICharacter >= '0' && ASCIICharacter <= '9')
        return (ASCIICharacter - '0') + 215;

    // Special Characters

    // (Space)

    if (ASCIICharacter == SpecialCharacterSpace)
        return 0;

    // ~

    if (ASCIICharacter == SpecialCharacterTilde)
        return 225;

    // / (small)

    if (ASCIICharacter == SpecialCharacterSlashSmall)
        return 226;

    // Centered dot

    if (ASCIICharacter == SpecialCharacterCenteredDot)
        return 227;

    // .

    if (ASCIICharacter == SpecialCharacterDot)
        return 228;

    // ?

    if (ASCIICharacter == SpecialCharacterQuestionMark)
        return 229;

    // Heart

    if (ASCIICharacter == SpecialCharacterHeart)
        return 231;

    // Star

    if (ASCIICharacter == SpecialCharacterStar)
        return 232;

    // Circle

    if (ASCIICharacter == SpecialCharacterCircle)
        return 233;

    // X mark

    if (ASCIICharacter == SpecialCharacterMarkX)
        return 234;

    // / (big)

    if (ASCIICharacter == SpecialCharacterSlashBig)
        return 235;

    // )

    if (ASCIICharacter == SpecialCharacterColon)
        return 236;

    // %

    if (ASCIICharacter == SpecialCharacterPercentual)
        return 237;

    // ´

    if (ASCIICharacter == SpecialCharacterAccent)
        return 238;

    // &

    if (ASCIICharacter == SpecialCharacterAmpersand)
        return 242;

    // . (copy)

    if (ASCIICharacter == SpecialCharacterDotAlternate)
        return 243;

    return ConversionAsciiToInternalError;
}

/// Checks if an internal character used for the player name is valid.
///
/// @param[in] InternalCharacter Internal character used for the player name to check.
///
/// @return    **True** if it's valid, **false** if not.
///
/// @author    WaluigiBSOD
/// @copyright GPL-3.0 License

bool _PlayerNameValidCharacter(unsigned char InternalCharacter) {
    if (_ConvertInternalCharacterToASCII(InternalCharacter) != ConversionInternalToAsciiError)
        return true;

    return false;
}

/// Transforms an internal character used for the player name in "conversational" form.
///
/// @param[in] InternalCharacter The internal character used for the player name to convert.
///
/// @return    The conversational name, the string contained inside **ConversionInternalToConversationalError** if it's not valid.
///
/// @author    WaluigiBSOD
/// @copyright GPL-3.0 License

string _ConversationalInternalCharacter(unsigned char InternalCharacter) {
        switch (InternalCharacter) {
            case 0:
                // Space

                return "(Space)";
            case 226:
                // / (small)

                return "/ (small)";
            case 227:
                // Centered dot

                return "(Centered dot)";
            case 231:
                // Heart

                return "(Heart)";
            case 232:
                // Star

                return "(Star)";
            case 233:
                // Circle

                return "(Circle)";
            case 234:
                // X mark

                return "(X mark)";
            case 235:
                // / (big)

                return "/ (big)";
            case 242:
                // &

                return "&";
            case 243:
                // . (copy)

                return ". (copy)";
        }

    return ConversionInternalToConversationalError;
}
