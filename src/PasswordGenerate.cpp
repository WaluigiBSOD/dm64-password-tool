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

/// @file      PasswordGenerate.cpp
///
/// @brief     Functions that generate a password given its raw data in input.
///
/// @author    WaluigiBSOD
/// @copyright GPL-3.0 License

#include "Constants.h"

#include "Random.h"

/// Generates a password given the parameters in input.
///
/// Data must be validated before calling this function as it can also be used to generate passwords containing invalid data, however expected data from each parameter is illustrated below.
///
/// @param[in] GameMode   Desired game mode (0 - Classic, 1 - Score Attack, 2 - Marathon).
/// @param[in] Level      Desired virus/game level (if the game mode is "Classic" it contains the virus level, otherwise 0 - Easy, 1 - Normal, 2 - Hard).
/// @param[in] Speed      Desired speed (0 - Low, 1 - Medium, 2 - High).
/// @param[in] Score      Desired score (final score without the last digit as it's always 0, assuming a score from 0 to 9999990, this parameter can assume values from from 0 to 999999).
/// @param[in] Time       Desired time (time when the game ended, expressed in tenths of second ranging from 0 to 59999, it represents the in-game time from 0'00.0 to 99'59.9 including tenths of a second not shown in-game).
/// @param[in] PlayerName Desired player name (name of the player, 4 letters and it uses a special in-game encoding even for symbols).
/// @param[in] FrameCount Desired frame count (total amount of frames passed since the game started modulo 1024, used to add randomness in the password).
///
/// @return    A 20 characters password encoding all this information (e.g. 2TL8A8WYDP5M5J80BT0P from https://tcrf.net/File:DrMario64-password.png).
///
/// @author    WaluigiBSOD
/// @copyright GPL-3.0 License

string _GeneratePassword(unsigned char GameMode, unsigned char Level, unsigned char Speed, unsigned int Score, unsigned short Time, unsigned char PlayerName[], unsigned short FrameCount) {
    string retPASSWORD = "";

    unsigned char SplitFrameCount[2];
    unsigned short Checksum;
    unsigned int PasswordChunk[3];

    string IntermediatePassword[3] = {
        "",
        "",
        ""
    };

    unsigned int ObfuscationConstant;

    // Obfuscation Constant

	SplitFrameCount[0] = FrameCount & 0x1F;
	SplitFrameCount[1] = (FrameCount >> 5) & 0x1F;

	ObfuscationConstant = TableMaskFrameCountX[SplitFrameCount[0]] ^ TableMaskFrameCountY[SplitFrameCount[1]];

	// Checksum

    Checksum = GameMode;
    Checksum += Level;
    Checksum += Speed;
    Checksum += Score & 0x3FF;
    Checksum += (Score >> 10) & 0x3FF;
    Checksum += Time & 0xFF;
    Checksum += (Time >> 8) & 0xFF;
    Checksum += PlayerName[0];
    Checksum += PlayerName[1];
    Checksum += PlayerName[2];
    Checksum += PlayerName[3];
    Checksum &= 0x3FF;

    // Password Chunk X

	PasswordChunk[0] = Checksum & 0x3;
	PasswordChunk[0] <<= 20;
	PasswordChunk[0] |= Score & 0xFFFFF;
	PasswordChunk[0] <<= 8;
	PasswordChunk[0] |= PlayerName[0] & 0xFF;

	// Password Chunk Y

	PasswordChunk[1] = PlayerName[3] & 0xFF;
	PasswordChunk[1] <<= 8;
	PasswordChunk[1] |= PlayerName[2] & 0xFF;
	PasswordChunk[1] <<= 8;
	PasswordChunk[1] |= PlayerName[1] & 0xFF;
	PasswordChunk[1] <<= 6;
	PasswordChunk[1] |= Level & 0x3F;

	// Password Chunk Z

	PasswordChunk[2] = (Checksum >> 2) & 0xFF;
	PasswordChunk[2] <<= 2;
	PasswordChunk[2] |= Speed & 0x3;
	PasswordChunk[2] <<= 2;
	PasswordChunk[2] |= GameMode & 0x3;
	PasswordChunk[2] <<= 2;
	PasswordChunk[2] |= (Level >> 6) & 0x3;
	PasswordChunk[2] <<= 16;
	PasswordChunk[2] |= Time & 0xFFFF;

	// Obfuscation

	PasswordChunk[0] ^= TableMaskPasswordChunkX[Checksum & 0x3] ^ ObfuscationConstant;
	PasswordChunk[1] ^= TableMaskPasswordChunkY[Checksum & 0x3] ^ ObfuscationConstant;
	PasswordChunk[2] ^= TableMaskPasswordChunkZ[Checksum & 0x3] ^ ObfuscationConstant;

	// Conversion

	unsigned char i;
	unsigned char j;

	for (i=0;i<6;i++)
        for (j=0;j<3;j++) {
            IntermediatePassword[j] += PasswordCharacters[PasswordChunk[j] & 0x1F];

            PasswordChunk[j] >>= 5;
        }

    retPASSWORD += PasswordCharacters[SplitFrameCount[0]];

	retPASSWORD += IntermediatePassword[0];
	retPASSWORD += IntermediatePassword[1];
	retPASSWORD += IntermediatePassword[2];

	retPASSWORD += PasswordCharacters[SplitFrameCount[1]];

	return retPASSWORD;
}

/// Generates a random password.
///
/// @return    A 20 characters password encoding random valid data.
///
/// @author    WaluigiBSOD
/// @copyright GPL-3.0 License

string _GenerateRandomPassword() {
    unsigned char GameMode = GameModes[GameModePRNG(MersenneTwister)];

    unsigned char Level;

    if (GameMode == GameModeClassic)
        Level = VirusLevelPRNG(MersenneTwister);
    else
        Level = GameLevel[GameLevelPRNG(MersenneTwister)];

    unsigned char Speed = GameSpeed[SpeedPRNG(MersenneTwister)];

    unsigned int Score = ScorePRNG(MersenneTwister);

    unsigned short Time = TimePRNG(MersenneTwister);

    unsigned char PlayerName[4];

    for (unsigned char i=0;i<4;i++)
        PlayerName[i] = InternalToASCIICharactersTable[RandomPlayerNameInternalCharacter(MersenneTwister)];

    unsigned short FrameCount = FrameCountPRNG(MersenneTwister);

    return _GeneratePassword(GameMode,Level,Speed,Score,Time,PlayerName,FrameCount);
}
