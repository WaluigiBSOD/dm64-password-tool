# Dr. Mario 64 Password Tool
# Copyright (C) 2020-present WaluigiBSOD (waluigibsod.github.io)
#
# This file is part of Dr. Mario 64 Password Tool.
#
# Dr. Mario 64 Password Tool is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# Dr. Mario 64 Password Tool is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program. If not, see <https://www.gnu.org/licenses/>.

# Minimum required CMake version

cmake_minimum_required(VERSION 3.10.0 FATAL_ERROR)

# Program version

set(RELEASE_SERVICE_VERSION_MAJOR "1")
set(RELEASE_SERVICE_VERSION_MINOR "0")
set(RELEASE_SERVICE_VERSION_MICRO "1")
set(RELEASE_SERVICE_VERSION "${RELEASE_SERVICE_VERSION_MAJOR}.${RELEASE_SERVICE_VERSION_MINOR}.${RELEASE_SERVICE_VERSION_MICRO}")

# Project name

project(dm64-password-tool VERSION ${RELEASE_SERVICE_VERSION})

# Project requires at least the C++11 standard

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Adding source files to build the main executable

add_executable(dm64-password-tool CheckCommandLineArguments.cpp CheckCommandLineArguments.h CheckRawData.cpp CheckRawData.h Constants.cpp Constants.h main.cpp PasswordDecode.cpp PasswordDecode.h PasswordGenerate.cpp PasswordGenerate.h PasswordShow.cpp PasswordShow.h PlayerName.cpp PlayerName.h PrintError.cpp PrintError.h PrintUsage.cpp PrintUsage.h Random.cpp Random.h StringFunctions.cpp StringFunctions.h)