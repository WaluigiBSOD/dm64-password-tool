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

#include "PlayerName.h"
#include "PasswordCheck.h"
#include "PasswordShow.h"
#include "PasswordMiscellaneous.h"

#define PASSWORD_CHUNK_HIGH                                         Chunk[0]
#define PASSWORD_CHUNK_MEDIUM                                       Chunk[1]
#define PASSWORD_CHUNK_LOW                                          Chunk[2]

extern const unsigned int TableMaskHigh[4];
extern const unsigned int TableMaskMiddle[4];
extern const unsigned int TableMaskLower[4];

extern const unsigned int TableMaskFrameCountLower[32];
extern const unsigned int TableMaskFrameCountUpper[32];

extern const string PasswordCharacters;

extern const unsigned char PasswordOK;

// Parameters
//
// Game Mode = 0 - Original, 1 - Time attack, 2 - Marathon.
// Level = If the Game Mode is "Original" it contains the Virus Level number, otherwise 0 - Easy, 1 - Normal, 2 - Hard
// Speed = 0 - Low, 1 - Medium, 2 - High.
// Score = Final score without the last digit (it is always 0). Assuming a score from 0 to 9999990, this parameter can assume values from from 0 to 999999.
// Time = Time when the game ended, expressed in tenths of second ranging from 0 to 59999. Represents the in-game time from 0'00.0 to 99'59.9 (including tenths of a second not shown in-game).
// Name = Name of the player (4 letters). It uses a special in-game encoding, even for symbols.
// Frame Count = The total count of frames passed since the game started modulo 1024. Used to add randomness in the password.
//
// Result: a 20-character password encoding all this information (e.g. 2TL8A8WYDP5M5J80BT0P from https://tcrf.net/File:DrMario64-password.png).

string _EncodePassword(unsigned char GameMode, unsigned char Level, unsigned char Speed, unsigned int Score, unsigned short Time, unsigned char Name[], unsigned int FrameCount) {
    string IntermediatePassword[3] = {"","",""};
    string retPASSWORD = "";

    unsigned char SplitFrameCount[2];
    unsigned int CheckSum;
    unsigned int Chunk[3];

	SplitFrameCount[0] = FrameCount & 0x1F;
	SplitFrameCount[1] = (FrameCount >> 5) & 0x1F;

    CheckSum = (unsigned int)(GameMode) + (unsigned int)(Level) + (unsigned int)(Speed);
	CheckSum += (unsigned int)(Score & 0x3FF);
	CheckSum += (unsigned int)((Score >> 10) & 0x3FF);
	CheckSum += (unsigned int)(Time & 0xFF);
	CheckSum += (unsigned int)((Time >> 8) & 0xFF);
	CheckSum += (unsigned int)(Name[0]) + (unsigned int)(Name[1]) + (unsigned int)(Name[2]) + (unsigned int)(Name[3]);
	CheckSum &= 0x3FF;

	PASSWORD_CHUNK_HIGH = CheckSum & 0x3;
	PASSWORD_CHUNK_HIGH <<= 20;
	PASSWORD_CHUNK_HIGH |= Score & 0xFFFFF;
	PASSWORD_CHUNK_HIGH <<= 8;
	PASSWORD_CHUNK_HIGH |= (unsigned int)(Name[0]) & 0xFF;

	PASSWORD_CHUNK_MEDIUM = (unsigned int)(Name[3]) & 0xFF;
	PASSWORD_CHUNK_MEDIUM <<= 8;
	PASSWORD_CHUNK_MEDIUM |= (unsigned int)(Name[2]) & 0xFF;
	PASSWORD_CHUNK_MEDIUM <<= 8;
	PASSWORD_CHUNK_MEDIUM |= (unsigned int)(Name[1]) & 0xFF;
	PASSWORD_CHUNK_MEDIUM <<= 6;
	PASSWORD_CHUNK_MEDIUM |= (unsigned int)(Level) & 0x3F;

	PASSWORD_CHUNK_LOW = (CheckSum >> 2) & 0xFF;
	PASSWORD_CHUNK_LOW <<= 2;
	PASSWORD_CHUNK_LOW |= (unsigned int)(Speed) & 0x3;
	PASSWORD_CHUNK_LOW <<= 2;
	PASSWORD_CHUNK_LOW |= (unsigned int)(GameMode) & 0x3;
	PASSWORD_CHUNK_LOW <<= 2;
	PASSWORD_CHUNK_LOW |= ((unsigned int)(Level) >> 6) & 0x3;
	PASSWORD_CHUNK_LOW <<= 16;
	PASSWORD_CHUNK_LOW |= (unsigned int)(Time) & 0xFFFF;

	PASSWORD_CHUNK_HIGH ^= TableMaskHigh[CheckSum & 0x3];
	PASSWORD_CHUNK_MEDIUM ^= TableMaskMiddle[CheckSum & 0x3];
	PASSWORD_CHUNK_LOW ^= TableMaskLower[CheckSum & 0x3];

	unsigned int Constant = TableMaskFrameCountLower[SplitFrameCount[0]] ^ TableMaskFrameCountUpper[SplitFrameCount[1]];

	PASSWORD_CHUNK_HIGH ^= Constant;
	PASSWORD_CHUNK_MEDIUM ^= Constant;
	PASSWORD_CHUNK_LOW ^= Constant;

	retPASSWORD += PasswordCharacters[SplitFrameCount[0]];

	for (unsigned char i=0;i<6;i++) {
        IntermediatePassword[0] += PasswordCharacters[PASSWORD_CHUNK_HIGH & 0x1F];
        PASSWORD_CHUNK_HIGH >>= 5;

        IntermediatePassword[1] += PasswordCharacters[PASSWORD_CHUNK_MEDIUM & 0x1F];
        PASSWORD_CHUNK_MEDIUM >>= 5;

        IntermediatePassword[2] += PasswordCharacters[PASSWORD_CHUNK_LOW & 0x1F];
        PASSWORD_CHUNK_LOW >>= 5;
	}

	retPASSWORD += IntermediatePassword[0] + IntermediatePassword[1] + IntermediatePassword[2];

	retPASSWORD += PasswordCharacters[SplitFrameCount[1]];

	return retPASSWORD;
}

bool _DecodePassword(const char Password[], unsigned char& GameMode, unsigned char& Level, unsigned char& Speed, unsigned int& Score, unsigned short& Time, unsigned char Name[], unsigned int& FrameCount) {
    unsigned char SplitFrameCount[2];
    unsigned int Chunk[3] = {};

    unsigned char FrameMaskCounter;

    for (FrameMaskCounter=0;FrameMaskCounter<PasswordCharacters.size();FrameMaskCounter++)
        if (PasswordCharacters[FrameMaskCounter] == Password[0]) {
            SplitFrameCount[0] = FrameMaskCounter;
            break;
        }

    if (FrameMaskCounter == PasswordCharacters.size())
        return false;

    for (FrameMaskCounter=0;FrameMaskCounter<PasswordCharacters.size();FrameMaskCounter++)
        if (PasswordCharacters[FrameMaskCounter] == Password[19]) {
            SplitFrameCount[1] = FrameMaskCounter;
            break;
        }

    if (FrameMaskCounter == PasswordCharacters.size())
        return false;

    FrameCount = SplitFrameCount[0] | (SplitFrameCount[1] << 5);

    int n;

    // ###   Password   ###
    //
    //       20 char.
    //
    // V                  V
    // E5HQ3E80B03JA5316R1F
    //
    // ^                  ^
    //      FrameCount
    //
    //  ^^^^^^^^^^^^^^^^^^
    //      Data Chunk
    //
    //          ||
    //          VV
    //
    //  ^^^^^^
    //   High
    //
    //        ^^^^^^
    //        Medium
    //
    //              ^^^^^^
    //               Low

    n = -1;

    for (unsigned short i=1;i<=6;i++) {
        for (unsigned char j=0;j<PasswordCharacters.size();j++)
            if (PasswordCharacters[j] == Password[i]) {
                n = j;
                break;
            }

        if (n == -1)
            return false;

        PASSWORD_CHUNK_HIGH |= n << 25;
        if (i < 6)
            PASSWORD_CHUNK_HIGH >>= 5;
    }

    n = -1;

    for (unsigned short i=7;i<=12;i++) {
        for (unsigned char j=0;j<PasswordCharacters.size();j++)
            if (PasswordCharacters[j] == Password[i]) {
                n = j;
                break;
            }

        if (n == -1)
            return false;

        PASSWORD_CHUNK_MEDIUM |= n << 25;
        if (i < 12)
            PASSWORD_CHUNK_MEDIUM >>= 5;
    }

    n = -1;

    for (unsigned short i=13;i<=18;i++) {
        for (unsigned char j=0;j<PasswordCharacters.size();j++)
            if (PasswordCharacters[j] == Password[i]) {
                n = j;
                break;
            }

        if (n == -1)
            return false;

        PASSWORD_CHUNK_LOW |= n << 25;
        if (i < 18)
            PASSWORD_CHUNK_LOW >>= 5;
    }

    unsigned int Constant = TableMaskFrameCountLower[SplitFrameCount[0]] ^ TableMaskFrameCountUpper[SplitFrameCount[1]];

    PASSWORD_CHUNK_HIGH ^= Constant;
    PASSWORD_CHUNK_MEDIUM ^= Constant;
    PASSWORD_CHUNK_LOW ^= Constant;

	unsigned int CheckSum;

	// The algorithm is designed to make the last two bit of the checksum obtainable in cleartext.

	unsigned char CheckSumLastTwoBits = (PASSWORD_CHUNK_HIGH >> 28) & 0x3;

    PASSWORD_CHUNK_HIGH ^= TableMaskHigh[CheckSumLastTwoBits];
    PASSWORD_CHUNK_MEDIUM ^= TableMaskMiddle[CheckSumLastTwoBits];
    PASSWORD_CHUNK_LOW ^= TableMaskLower[CheckSumLastTwoBits];

    Time = PASSWORD_CHUNK_LOW & 0xFFFF;
    PASSWORD_CHUNK_LOW >>= 16;

    Level = PASSWORD_CHUNK_LOW & 0x3;
    PASSWORD_CHUNK_LOW >>= 2;

    GameMode = PASSWORD_CHUNK_LOW & 0x3;
    PASSWORD_CHUNK_LOW >>= 2;

    Speed = PASSWORD_CHUNK_LOW & 0x3;
    PASSWORD_CHUNK_LOW >>= 2;

    CheckSum = PASSWORD_CHUNK_LOW & 0xFF;

    Level = (Level << 6) | (PASSWORD_CHUNK_MEDIUM & 0x3F);
    PASSWORD_CHUNK_MEDIUM >>= 6;

    Name[1] = PASSWORD_CHUNK_MEDIUM & 0xFF;
    PASSWORD_CHUNK_MEDIUM >>= 8;

    Name[2] = PASSWORD_CHUNK_MEDIUM & 0xFF;
    PASSWORD_CHUNK_MEDIUM >>= 8;

    Name[3] = PASSWORD_CHUNK_MEDIUM & 0xFF;

    Name[0] = PASSWORD_CHUNK_HIGH & 0xFF;
    PASSWORD_CHUNK_HIGH >>= 8;

    Score = PASSWORD_CHUNK_HIGH & 0xFFFFF;
    PASSWORD_CHUNK_HIGH >>= 20;

    CheckSum = (CheckSum << 2) | (PASSWORD_CHUNK_HIGH & 0x3);

    CheckSum &= 0x3FF;

    unsigned int TestCheckSum = (unsigned int)(GameMode) + (unsigned int)(Level) + (unsigned int)(Speed);
    TestCheckSum += (unsigned int)(Score & 0x3FF);
    TestCheckSum += (unsigned int)((Score >> 10) & 0x3FF);
    TestCheckSum += (unsigned int)(Time & 0xFF);
    TestCheckSum += (unsigned int)((Time >> 8) & 0xFF);
    TestCheckSum += (unsigned int)(Name[0]) + (unsigned int)(Name[1]) + (unsigned int)(Name[2]) + (unsigned int)(Name[3]);
    TestCheckSum &= 0x3FF;

    // The code is valid if the embedded checksum equals the calculated one AND the data obtained is valid.

    if (TestCheckSum == CheckSum && (_CheckPasswordData(GameMode,Level,Speed,Score,Time,Name,FrameCount) == PasswordOK))
        return true;

	return false;
}
