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

extern const unsigned char SpecialCharacterTilde;
extern const unsigned char SpecialCharacterSlashSmall;
extern const unsigned char SpecialCharacterCenteredDot;
extern const unsigned char SpecialCharacterDot;
extern const unsigned char SpecialCharacterQuestionMark;
extern const unsigned char SpecialCharacterHeart;
extern const unsigned char SpecialCharacterStar;
extern const unsigned char SpecialCharacterCircle;
extern const unsigned char SpecialCharacterMarkX;
extern const unsigned char SpecialCharacterSlashBig;
extern const unsigned char SpecialCharacterColon;
extern const unsigned char SpecialCharacterPercentual;
extern const unsigned char SpecialCharacterAccent;
extern const unsigned char SpecialCharacterAmperstand;
extern const unsigned char SpecialCharacterDotAlternative;

extern const unsigned char InternalToASCIICharacterTable[];
extern const unsigned int InternalCharacterTableSize;

extern const string AlphabeticNumericASCII;
extern const char SpecialASCII[];

extern const char ConversionInternalToAsciiError;
extern const char ConversionAsciiToInternal;
extern const string ConversionInternalToConversationalError;

bool _PlayerNameValidCharacter(unsigned char Character) {
    for (unsigned char i=0;i<InternalCharacterTableSize;i++)
        if (InternalToASCIICharacterTable[i] == Character)
            return true;
    return false;
}

unsigned char _ConvertInternalCharacterToASCII(unsigned char InternalCharacter) {
    if (_PlayerNameValidCharacter(InternalCharacter)) {
        // Space
        if (InternalCharacter == 0)
            return ' ';
        // Alphabetic and numeric characters
        if (InternalCharacter >= 163 && InternalCharacter <= 224)
            return AlphabeticNumericASCII[(InternalCharacter + 23) % AlphabeticNumericASCII.size()];
        // Special Characters
        switch (InternalCharacter) {
            // ~
            case 225:
                return SpecialASCII[0];
                break;
            // / (small)
            case 226:
                return SpecialASCII[1];
                break;
            // Centered dot
            case 227:
                return SpecialASCII[2];
                break;
            // .
            case 228:
                return SpecialASCII[3];
                break;
            // ?
            case 229:
                return SpecialASCII[4];
                break;
            // Heart
            case 231:
                return SpecialASCII[5];
                break;
            // Star
            case 232:
                return SpecialASCII[6];
                break;
            // Circle
            case 233:
                return SpecialASCII[7];
                break;
            // X mark
            case 234:
                return SpecialASCII[8];
                break;
            // / (big)
            case 235:
                return SpecialASCII[9];
                break;
            // :
            case 236:
                return SpecialASCII[10];
                break;
            // %
            case 237:
                return SpecialASCII[11];
                break;
            // ´
            case 238:
                return SpecialASCII[12];
                break;
            // &
            case 242:
                return SpecialASCII[13];
                break;
            // . (copy)
            case 243:
                return SpecialASCII[14];
                break;
        }
    }

    return ConversionInternalToAsciiError;
}

unsigned char _ConvertASCIICharacterToInternal(unsigned char ASCIICharacter) {
    // Space
    if (ASCIICharacter == ' ')
        return 0;
    // Alphabetic (upper case)
    if (ASCIICharacter >= 'A' && ASCIICharacter <= 'Z')
        return ((signed)ASCIICharacter - 'A') + 163;
    // Alphabetic (lower case)
    if (ASCIICharacter >= 'a' && ASCIICharacter <= 'a')
        return ((signed)ASCIICharacter - 'a') + 189;
    // Numeric
    if (ASCIICharacter >= '0' && ASCIICharacter <= '9')
        return ((signed)ASCIICharacter - '0') + 215;
    // Special Characters
    if (ASCIICharacter == SpecialCharacterTilde)
        return 225; // ~
    else if (ASCIICharacter == SpecialCharacterSlashSmall)
        return 226; // / (small)
    else if (ASCIICharacter == SpecialCharacterCenteredDot)
        return 227; // Centered dot
    else if (ASCIICharacter == SpecialCharacterDot)
        return 228; // .
    else if (ASCIICharacter == SpecialCharacterQuestionMark)
        return 229; // ?
    else if (ASCIICharacter == SpecialCharacterHeart)
        return 231; // Heart
    else if (ASCIICharacter == SpecialCharacterStar)
        return 232; // Star
    else if (ASCIICharacter == SpecialCharacterCircle)
        return 233; // Circle
    else if (ASCIICharacter == SpecialCharacterMarkX)
        return 234; // X mark
    else if (ASCIICharacter == SpecialCharacterSlashBig)
        return 235; // / (big)
    else if (ASCIICharacter == SpecialCharacterColon)
        return 236; // )
    else if (ASCIICharacter == SpecialCharacterPercentual)
        return 237; // %
    else if (ASCIICharacter == SpecialCharacterAccent)
        return 238; // ´
    else if (ASCIICharacter == SpecialCharacterAmperstand)
        return 242; // &
    else if (ASCIICharacter == SpecialCharacterDotAlternative)
        return 243; // . (copy)

    return ConversionAsciiToInternal;
}

string _ConversationalInternalCharacter(unsigned char InternalCharacter) {
        switch (InternalCharacter) {
            // Space
            case 0:
                return "(Space)";
            // / (small)
            case 226:
                return "/ (small)";
                break;
            // Centered dot
            case 227:
                return "(Centered dot)";
                break;
            // Heart
            case 231:
                return "(Heart)";
                break;
            // Star
            case 232:
                return "(Star)";
                break;
            // Circle
            case 233:
                return "(Circle)";
                break;
            // X mark
            case 234:
                return "(X mark)";
                break;
            // / (big)
            case 235:
                return "/ (big)";
                break;
            // . (copy)
            case 243:
                return ". (copy)";
                break;
        }
    return ConversionInternalToConversationalError;
}
