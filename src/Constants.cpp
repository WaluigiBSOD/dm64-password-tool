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

#include <string>

using namespace std;

extern const string ProgramVersion =                                        "1.0 Beta";

extern const unsigned int AutotestIterations =                              1 << 2; // 1 << 31 for very very very very very extensive testing.

extern const unsigned char StringCenterLeftSpacing =                        1;
extern const unsigned char StringCenterWidth =                              64;

extern const unsigned char GameModeClassic =                                0;
extern const unsigned char GameModeScoreAttack =                            1;
extern const unsigned char GameModeMarathon =                               2;

extern const unsigned char GameLevelEasy =                                  0;
extern const unsigned char GameLevelNormal =                                1;
extern const unsigned char GameLevelHard =                                  2;

extern const unsigned char SpeedLow =                                       0;
extern const unsigned char SpeedMedium =                                    1;
extern const unsigned char SpeedHigh =                                      2;

extern const unsigned char VirusLevelMinimum =                              0;
extern const unsigned char VirusLevelMaximum =                              24;

extern const unsigned int ScoreMinimum =                                    0;
extern const unsigned int ScoreMaximum =                                    999999;

extern const unsigned short TimeMinimum =                                   0;
extern const unsigned short TimeMaximum =                                   59999;

extern const unsigned int FrameCountMinimum =                               0;
extern const unsigned int FrameCountMaximum =                               1023;

extern const unsigned char PasswordOK =                                     0;
extern const unsigned char PasswordInvalidLength =                          1;
extern const unsigned char PasswordInvalidCharacters =                      2;
extern const unsigned char PasswordDecodeError =                            3;
extern const unsigned char PasswordInvalidGameMode =                        4;
extern const unsigned char PasswordInvalidNonClassicLevel =                 5;
extern const unsigned char PasswordInvalidLevel =                           6;
extern const unsigned char PasswordInvalidSpeed =                           7;
extern const unsigned char PasswordInvalidScore =                           8;
extern const unsigned char PasswordInvalidTime =                            9;
extern const unsigned char PasswordInvalidName =                            10;
extern const unsigned char PasswordInvalidFrameCount =                      11;

extern const unsigned int ArgumentInvalidPasswordLength =                   12;
extern const unsigned int ArgumentInvalidGameMode =                         13;
extern const unsigned int ArgumentInvalidLevel =                            14;
extern const unsigned int ArgumentInvalidSpeed =                            15;
extern const unsigned int ArgumentInvalidScore =                            16;
extern const unsigned int ArgumentInvalidTime =                             17;
extern const unsigned int ArgumentInvalidName =                             18;
extern const unsigned int ArgumentInvalidFrameCount =                       19;

extern const unsigned int ReturnAutoTestFail =                              20;
extern const unsigned int ReturnAutoTestPass =                              PasswordOK;

extern const unsigned int DataTypeCharCorrectByteSize =                     1;
extern const unsigned int DataTypeShortCorrectByteSize =                    2;
extern const unsigned int DataTypeIntCorrectByteSize =                      4;
extern const unsigned int DataTypeLongLongCorrectByteSize =                 8;

extern const unsigned int DataTypeSignedCharWrongSize =                     21;
extern const unsigned int DataTypeUnsignedCharWrongSize =                   22;
extern const unsigned int DataTypeSignedShortWrongSize =                    23;
extern const unsigned int DataTypeUnsignedShortWrongSize =                  24;
extern const unsigned int DataTypeSignedIntWrongSize =                      25;
extern const unsigned int DataTypeUnsignedIntWrongSize =                    26;
extern const unsigned int DataTypeSignedLongLongWrongSize =                 27;
extern const unsigned int DataTypeUnsignedLongLongWrongSize =               28;

extern const string AlphabeticUppercaseASCII =                              "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
extern const string AlphabeticLowercaseASCII =                              "abcdefghijklmnopqrstuvwxyz";
extern const string NumericASCII =                                          "0123456789";

extern const string AlphabeticNumericASCII =                                AlphabeticUppercaseASCII + AlphabeticLowercaseASCII + NumericASCII;

extern const unsigned char SpecialCharacterTilde =                          '~';
extern const unsigned char SpecialCharacterSlashSmall =                     '/';
extern const unsigned char SpecialCharacterCenteredDot =                    '$';
extern const unsigned char SpecialCharacterDot =                            '.';
extern const unsigned char SpecialCharacterQuestionMark =                   '?';
extern const unsigned char SpecialCharacterHeart =                          '@';
extern const unsigned char SpecialCharacterStar =                           '*';
extern const unsigned char SpecialCharacterCircle =                         '#';
extern const unsigned char SpecialCharacterMarkX =                          '+';
extern const unsigned char SpecialCharacterSlashBig =                       '\\';
extern const unsigned char SpecialCharacterColon =                          ':';
extern const unsigned char SpecialCharacterPercentual =                     '%';
extern const unsigned char SpecialCharacterAccent =                         '\'';
extern const unsigned char SpecialCharacterAmperstand =                     '&';
extern const unsigned char SpecialCharacterDotAlternative =                 ',';

extern const char SpecialASCII[] = {
    SpecialCharacterTilde,
    SpecialCharacterSlashSmall,
    SpecialCharacterCenteredDot,
    SpecialCharacterDot,
    SpecialCharacterQuestionMark,
    SpecialCharacterHeart,
    SpecialCharacterStar,
    SpecialCharacterCircle,
    SpecialCharacterMarkX,
    SpecialCharacterSlashBig,
    SpecialCharacterColon,
    SpecialCharacterPercentual,
    SpecialCharacterAccent,
    SpecialCharacterAmperstand,
    SpecialCharacterDotAlternative
};

extern const unsigned char InternalToASCIICharacterTable[] = {
    0,          // (Space)

    163,        // A
    164,        // B
    165,        // C
    166,        // D
    167,        // E
    168,        // F
    169,        // G
    170,        // H
    171,        // I
    172,        // J
    173,        // K
    174,        // L
    175,        // M
    176,        // N
    177,        // O
    178,        // P
    179,        // Q
    180,        // R
    181,        // S
    182,        // T
    183,        // U
    184,        // V
    185,        // W
    186,        // X
    187,        // Y
    188,        // Z
    189,        // a
    190,        // b
    191,        // c
    192,        // d
    193,        // e
    194,        // f
    195,        // g
    196,        // h
    197,        // i
    198,        // j
    199,        // k
    200,        // l
    201,        // m
    202,        // n
    203,        // o
    204,        // p
    205,        // q
    206,        // r
    207,        // s
    208,        // t
    209,        // u
    210,        // v
    211,        // w
    212,        // x
    213,        // y
    214,        // z
    215,        // 0
    216,        // 1
    217,        // 2
    218,        // 3
    219,        // 4
    220,        // 5
    221,        // 6
    222,        // 7
    223,        // 8
    224,        // 9

    225,        // ~
    226,        // / (small)
    227,        // (Centered Dot)
    228,        // .
    229,        // ?
    231,        // (Heart)
    232,        // (Star)
    233,        // (Circle)
    234,        // (Cross)
    235,        // / (big)
    236,        // :
    237,        // %
    238,        // ´
    242,        // &
    243,        // . (copy)
};

extern const unsigned int ConversionInternalToAsciiError =                  0;
extern const unsigned char ConversionAsciiToInternalError =                 ' ';
extern const string ConversionInternalToConversationalError =               "";

extern const unsigned int InternalCharacterTableSize =                      sizeof(InternalToASCIICharacterTable) / sizeof(unsigned char);
extern const unsigned int SpecialASCIISize =                                sizeof(SpecialASCII) / sizeof(unsigned char);

extern const string PasswordCharacters =                                    "ABCDEFGHJKLMNPQRSTVWXY1234567890";

// XOR masks for the three chunks of binary data (high, middle and lower chunk), chosen by the last two bits of the checksum.

extern const unsigned int TableMaskHigh[4] = {
    0x0B626835,
    0x0763337A,
    0x0F4D6F49,
    0x06343069
};

extern const unsigned int TableMaskMiddle[4] = {
    0x03DF4B61,
    0x040E7254,
    0x0A456B4F,
    0x092E476F
};

extern const unsigned int TableMaskLower[4] = {
    0x08C26B8A,
    0x0D73B9A1,
    0x053AD652,
    0x024DF62E
};

// XOR masks for additional entropy of the password, depending on the number of frames passed since startup (modulo 1024) when the password was generated.
// Two values from these tables are XORed together to make a constant.

extern const unsigned int TableMaskFrameCountLower[32] = {
    0x81021794,
    0xF4967A99,
    0xB403DEC6,
    0x7FD52F56,
    0x5086D67F,
    0xD10A4924,
    0x939AEA49,
    0x24925292,
    0x492494A4,
    0x92492529,
    0x79775FFF,
    0x00942FFE,
    0xB95EA2BC,
    0xC3EB108E,
    0xA377F5BF,
    0xEFAC4D93,
    0x6307CC7F,
    0xBAE8741C,
    0x46B6AF5C,
    0x8F73890D,
    0xFEA85A79,
    0x5536EA9C,
    0xC7F04155,
    0x3A6E4D2D,
    0xC567B808,
    0x1AEE23E9,
    0x7F8454BA,
    0xA7586398,
    0x69A0CCE8,
    0xE7FF0027,
    0xF90A7044,
    0x62C46329
};

extern const unsigned int TableMaskFrameCountUpper[32] = {
    0xE435FBDF,
    0xE2384C76,
    0xD702AE2A,
    0x9E8D9B77,
    0xED3B7F7A,
    0x3DA8B55B,
    0xD8A8F1CA,
    0xB42CF9E0,
    0x4FA87E8F,
    0xCC992492,
    0x53B51492,
    0x4924A4B8,
    0xFF00CE0F,
    0x8ADD0B06,
    0x8FA63E2B,
    0x78205490,
    0x22350C22,
    0x3505266A,
    0x33505A8C,
    0xD4D5240B,
    0x0FEB4FF4,
    0x767F5FFE,
    0xFAF5B816,
    0x27D68FE8,
    0xCCFEB8FF,
    0x00A9B536,
    0x5B32E2F9,
    0xC35FEAC7,
    0xD0B7E2D5,
    0xD0AE7BEA,
    0xCE95D9FD,
    0x61F91740
};

extern const unsigned char GameModes[3] =                                   {GameModeClassic,GameModeScoreAttack,GameModeMarathon};
extern const unsigned char GameLevel[3] =                                   {GameLevelEasy,GameLevelNormal,GameLevelHard};
extern const unsigned char GameSpeed[3] =                                   {SpeedLow,SpeedMedium,SpeedHigh};
