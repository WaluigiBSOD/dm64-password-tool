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

/// @file      PasswordDecode.cpp
///
/// @brief     Function that decodes a password given in input.
///
/// @author    WaluigiBSOD
/// @copyright GPL-3.0 License

#include "Constants.h"

/// Decodes the password given in input.
///
/// More information on valid in-game data that can be found in the documentation of _GeneratePassword().
///
/// @param[in]  Password   The password to decode.
/// @param[out] GameMode   Decoded game mode.
/// @param[out] Level      Decoded virus/game level.
/// @param[out] Speed      Decoded speed.
/// @param[out] Score      Decoded score.
/// @param[out] Time       Decoded time.
/// @param[out] PlayerName Decoded player name.
/// @param[out] FrameCount Decoded frame count.
///
/// @return     **True** if the decoded checksum matches the embedded one, otherwise **false**.
///
/// @author     WaluigiBSOD
/// @copyright  GPL-3.0 License

bool _DecodePassword(const char Password[], unsigned char& GameMode, unsigned char& Level, unsigned char& Speed, unsigned int& Score, unsigned short& Time, unsigned char PlayerName[], unsigned short& FrameCount) {
    unsigned char SplitFrameCount[2] = {
        0xFF,
        0xFF
    };

    unsigned int ObfuscationConstant;

    unsigned int PasswordChunk[3] = {
        0x00000000,
        0x00000000,
        0x00000000
    };

    unsigned short Checksum;
    unsigned short TestChecksum;

    int n;

    unsigned char i;
    unsigned char j;
    unsigned char k;

    // Frame Count (modulo 1024)

    for (i=0;i<PasswordCharacters.size() && (SplitFrameCount[0] >= PasswordCharacters.size() || SplitFrameCount[1] >= PasswordCharacters.size());i++) {
        if (PasswordCharacters[i] == Password[0])
            SplitFrameCount[0] = i;

        if (PasswordCharacters[i] == Password[19])
            SplitFrameCount[1] = i;
    }

    if (SplitFrameCount[0] >= PasswordCharacters.size() || SplitFrameCount[1] >= PasswordCharacters.size())
        return false;

    FrameCount = SplitFrameCount[0] | (SplitFrameCount[1] << 5);

    // Obfuscation Constant

    ObfuscationConstant = TableMaskFrameCountX[SplitFrameCount[0]] ^ TableMaskFrameCountY[SplitFrameCount[1]];

    // ###   Password   ###
    //
    //    20 characters
    //
    // V                  V
    // E5HQ3E80B03JA5316R1F
    //
    // ^                  ^
    // X                  Y
    //      FrameCount
    //
    //  ^^^^^^^^^^^^^^^^^^
    //     Data Chunks
    //
    //          ||
    //          VV
    //
    //  ^^^^^^
    //    X
    //
    //        ^^^^^^
    //          Y
    //
    //              ^^^^^^
    //                Z

    for (i=0;i<3;i++) {
        n = -1;

        for (j=(6 * i) + 1;j<=6 * (i + 1);j++) {
            for (k=0;k<PasswordCharacters.size();k++)
                if (PasswordCharacters[k] == Password[j]) {
                    n = k;

                    break;
                }

            if (n == -1)
                return false;

            PasswordChunk[i] |= n << 25;

            if (j < 6 * (i + 1))
                PasswordChunk[i] >>= 5;
        }

        PasswordChunk[i] ^= ObfuscationConstant;
    }

	// The algorithm is designed to make the last two bit of the checksum obtainable in cleartext so they can be used to de-obfuscate the password.

	// Checksum (1/2)

	Checksum = (PasswordChunk[0] >> 28) & 0x3;

    PasswordChunk[0] ^= TableMaskPasswordChunkX[Checksum];
    PasswordChunk[1] ^= TableMaskPasswordChunkY[Checksum];
    PasswordChunk[2] ^= TableMaskPasswordChunkZ[Checksum];

    // Time

    Time = PasswordChunk[2] & 0xFFFF;
    PasswordChunk[2] >>= 16;

    // Level (1/2)

    Level = PasswordChunk[2] & 0x3;
    PasswordChunk[2] >>= 2;

    // Game Mode

    GameMode = PasswordChunk[2] & 0x3;
    PasswordChunk[2] >>= 2;

    // Speed

    Speed = PasswordChunk[2] & 0x3;
    PasswordChunk[2] >>= 2;

    // Checksum (2/2)

    Checksum = ((PasswordChunk[2] & 0xFF) << 2) | Checksum;

    // Level (2/2)

    Level = (Level << 6) | (PasswordChunk[1] & 0x3F);
    PasswordChunk[1] >>= 6;

    // Player Name

    PlayerName[1] = PasswordChunk[1] & 0xFF;
    PasswordChunk[1] >>= 8;

    PlayerName[2] = PasswordChunk[1] & 0xFF;
    PasswordChunk[1] >>= 8;

    PlayerName[3] = PasswordChunk[1] & 0xFF;

    PlayerName[0] = PasswordChunk[0] & 0xFF;
    PasswordChunk[0] >>= 8;

    // Score

    Score = PasswordChunk[0] & 0xFFFFF;

    // Test Checksum

    TestChecksum = GameMode;
    TestChecksum += Level;
    TestChecksum += Speed;
    TestChecksum += Score & 0x3FF;
    TestChecksum += (Score >> 10) & 0x3FF;
    TestChecksum += Time & 0xFF;
    TestChecksum += (Time >> 8) & 0xFF;
    TestChecksum += PlayerName[0];
    TestChecksum += PlayerName[1];
    TestChecksum += PlayerName[2];
    TestChecksum += PlayerName[3];
    TestChecksum &= 0x3FF;

    // The password is valid if the embedded checksum equals the calculated one (data obtained is validated later).

    if (TestChecksum == Checksum)
        return true;

	return false;
}
