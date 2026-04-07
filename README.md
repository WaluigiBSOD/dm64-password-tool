# Dr. Mario 64 Password Tool

A command-line tool written in C++ that allows to generate and decode [the passwords of Dr. Mario 64](https://tcrf.net/Dr._Mario_64#Passwords).

## Program

Both this program and [Dr. Mario 64 Password Decoder](https://github.com/WaluigiBSOD/dm64-password-decoder) were written using the original source code of the game that leaked in July 2020 as reference.

The original implementation of the password generation algorithm inside the source code of the game can be found at `bbgames.7z\bbgames.tar\d1\routefree\bbgames\depot\dm64\src\passwd.c`, for some reason the password decoding algorithm is absent but it can be easily obtained from the generation one.

Code documentation can be found [here](https://waluigibsod.github.io/dm64-password-decoder), generated with [Doxygen](https://github.com/doxygen/doxygen) from the source code and an additional file for the main page.

### How To Compile It

A handy [`CMakeLists.txt`](https://github.com/WaluigiBSOD/dm64-password-tool/blob/master/src/CMakeLists.txt) file is provided inside the [`src`](https://github.com/WaluigiBSOD/dm64-password-tool/tree/master/src) directory for easy compilation, overall the only particular requirement it needs is the ISO C++11 standard.

### Usage

Run the program without any argument or see the usage in [`PrintUsage.cpp`](https://github.com/WaluigiBSOD/dm64-password-tool/blob/master/src/PrintUsage.cpp).

## License

This source code is released under the GNU General Public License v 3.0 (see [`LICENSE`](https://github.com/WaluigiBSOD/dm64-password-tool/blob/master/LICENSE) in the root of the repository for a copy of the license and for more information).

### Disclaimer

This program may contain copyrighted material, the use of which may not have been specifically authorized by the copyright owner.
This material is available in an effort to research on the password system of the videogame "Dr. Mario 64", to provide a tool that allows to know about it more deeply than before.

This should constitute a ‘fair use’ of any such copyrighted material (referenced and provided for in section 107 of the US Copyright Law).

If you wish to use any copyrighted material from this program for purposes of your own that go beyond ‘fair use’, you must obtain expressed permission from the copyright owner.