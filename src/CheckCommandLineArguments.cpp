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

/// @file      CheckCommandLineArguments.cpp
///
/// @brief     Functions that validate command-line arguments, as strings.
///
/// @author    WaluigiBSOD
/// @copyright GPL-3.0 License

#include <cstring>

#include "Constants.h"

#include "PlayerName.h"

#include "PrintError.h"

#include "StringFunctions.h"

/// Checks if the game mode entered as a command-line argument is valid or not, as a string.
///
/// @param[in] CommandLineArgument Command-line argument to check.
///
/// @return    **True** if the game mode entered as a command-line argument is valid as a string, **false** if not.
///
/// @author    WaluigiBSOD
/// @copyright GPL-3.0 License

bool _ValidateCommandLineGameMode(char* CommandLineArgument) {
    // String length

    if (strlen(CommandLineArgument) != 1)
        return false;

    // Decimal digits only

    if (!_OnlyDigits(CommandLineArgument))
        return false;

    return true;
}

/// Checks if the level entered as a command-line argument is valid or not, as a string.
///
/// @param[in] CommandLineArgument Command-line argument to check.
///
/// @return    **True** if the level entered as a command-line argument is valid as a string, **false** if not.
///
/// @author    WaluigiBSOD
/// @copyright GPL-3.0 License

bool _ValidateCommandLineLevel(char* CommandLineArgument) {
    // String length

    if (strlen(CommandLineArgument) > 2)
        return false;

    // Decimal digits only

    if (!_OnlyDigits(CommandLineArgument))
        return false;

    return true;
}

/// Checks if the speed entered as a command-line argument is valid or not, as a string.
///
/// @param[in] CommandLineArgument Command-line argument to check.
///
/// @return    **True** if the speed entered as a command-line argument is valid as a string, **false** if not.
///
/// @author    WaluigiBSOD
/// @copyright GPL-3.0 License

bool _ValidateCommandLineSpeed(char* CommandLineArgument) {
    // String length

    if (strlen(CommandLineArgument) > 1)
        return false;

    // Decimal digits only

    if (!_OnlyDigits(CommandLineArgument))
        return false;

    return true;
}

/// Checks if the score entered as a command-line argument is valid or not, as a string.
///
/// @param[in] CommandLineArgument Command-line argument to check.
/// @param[in] InGameInformation   Specifies if the score to be validated comes directly from the game's screen (**true**) or is entered as internal data (**false**).
///
/// @return    **True** if the score entered as a command-line argument is valid as a string, **false** if not.
///
/// @author    WaluigiBSOD
/// @copyright GPL-3.0 License

bool _ValidateCommandLineScore(char* CommandLineArgument, bool InGameInformation) {
    // String length

    if (InGameInformation && strlen(CommandLineArgument) > 7)
        return false;
    else if (!InGameInformation && strlen(CommandLineArgument) > 6)
        return false;

    // Decimal digits only

    if (!_OnlyDigits(CommandLineArgument))
        return false;

    // Trailing zero (only when inputting in-game information)

    if (InGameInformation && CommandLineArgument[strlen(CommandLineArgument) - 1] != '0')
        return false;

    return true;
}

/// Checks if the time entered as a command-line argument is valid or not, as a string.
///
/// @param[in] CommandLineArgument Command-line argument to check.
/// @param[in] InGameInformation   Specifies if the time to be validated comes directly from the game's screen (**true**) or is entered as internal data (**false**).
///
/// @return    **True** if the time entered as a command-line argument is valid as a string, **false** if not.
///
/// @author    WaluigiBSOD
/// @copyright GPL-3.0 License

bool _ValidateCommandLineTime(char* CommandLineArgument, bool InGameInformation) {
    // String length

    if (InGameInformation && strlen(CommandLineArgument) != 5)
        return false;
    else if (!InGameInformation && strlen(CommandLineArgument) > 5)
        return false;

    // Decimal digits only

    if (InGameInformation && (!_OnlyDigits(CommandLineArgument,0,1) || !_OnlyDigits(CommandLineArgument,3,4)))
        return false;
    else if (!InGameInformation && !_OnlyDigits(CommandLineArgument))
        return false;

    // Colon (only when inputting in-game information)

    if (InGameInformation && CommandLineArgument[2] != ':')
        return false;

    return true;
}

/// Checks if the player name entered as a command-line argument is valid or not, as a string.
///
/// @param[in] CommandLineArgument Command-line argument to check.
///
/// @return    **True** if the player name entered as a command-line argument is valid as a string, **false** if not.
///
/// @author    WaluigiBSOD
/// @copyright GPL-3.0 License

bool _ValidateCommandLinePlayerName(char* CommandLineArgument) {
    // String length

    if (strlen(CommandLineArgument) != 4)
        return false;

    // Characters

    if (_ConvertASCIICharacterToInternal(CommandLineArgument[0]) == ConversionAsciiToInternalError)
        return false;

    if (_ConvertASCIICharacterToInternal(CommandLineArgument[1]) == ConversionAsciiToInternalError)
        return false;

    if (_ConvertASCIICharacterToInternal(CommandLineArgument[2]) == ConversionAsciiToInternalError)
        return false;

    if (_ConvertASCIICharacterToInternal(CommandLineArgument[3]) == ConversionAsciiToInternalError)
        return false;

    return true;
}

/// Checks if the frame count entered as a command-line argument is valid or not, as a string.
///
/// @param[in] CommandLineArgument Command-line argument to check.
///
/// @return    **True** if the frame count entered as a command-line argument is valid as a string, **false** if not.
///
/// @author    WaluigiBSOD
/// @copyright GPL-3.0 License

bool _ValidateCommandLineFrameCount(char* CommandLineArgument) {
    // String length

    if (strlen(CommandLineArgument) > 4)
        return false;

    // Decimal digits only

    if (!_OnlyDigits(CommandLineArgument))
        return false;

    return true;
}

/// Checks if all the entered command-line arguments are valid or not, as a string.
///
/// @param[in] CommandLineArgumentsArray All the command-line arguments to check.
/// @param[in] InGameInformation         Specifies if the data to be validated comes directly from the game's screen (**true**) or is entered as internal data (**false**).
///
/// @return    **True** if the entered command-line arguments are valid as a string, **false** if not.
///
/// @author    WaluigiBSOD
/// @copyright GPL-3.0 License

unsigned char _CheckCommandLineArguments(char** CommandLineArgumentsArray, bool InGameInformation = false) {
    if (!_ValidateCommandLineGameMode(CommandLineArgumentsArray[1]))
        return _PrintErrorMessage("Entered game mode",ArgumentInvalidGameMode);

    if (!_ValidateCommandLineLevel(CommandLineArgumentsArray[2]))
        return _PrintErrorMessage("Entered level",ArgumentInvalidLevel);

    if (!_ValidateCommandLineSpeed(CommandLineArgumentsArray[3]))
        return _PrintErrorMessage("Entered speed",ArgumentInvalidSpeed);

    if (!_ValidateCommandLineScore(CommandLineArgumentsArray[4],InGameInformation))
        return _PrintErrorMessage("Entered score",ArgumentInvalidScore);

    if (!_ValidateCommandLineTime(CommandLineArgumentsArray[5],InGameInformation))
        return _PrintErrorMessage("Entered time",ArgumentInvalidTime);

    if (!_ValidateCommandLinePlayerName(CommandLineArgumentsArray[6]))
        return _PrintErrorMessage("Entered player name",ArgumentInvalidPlayerName);

    if (!InGameInformation && !_ValidateCommandLineFrameCount(CommandLineArgumentsArray[7]))
        return _PrintErrorMessage("Entered frame count",ArgumentInvalidFrameCount);

    return PasswordOK;
}
