# Dr. Mario 64 Password Generator/Decoder Tool
A command-line tool written in C++ that allows to generate and decode [the passwords of Dr. Mario 64](https://tcrf.net/Dr._Mario_64#Passwords).
## License
This source code is released under the GNU General Public License v 3.0 (see LICENSE in the root of the repository for a copy of the license and for more information).
### Disclaimer
This program may contain copyrighted material, the use of which may not have been specifically authorized by the copyright owner.
This material is available in an effort to research on the password system of the videogame "Dr. Mario 64", to provide a tool that allows to know about it more deeply than before and to make the tool better from a graphical point of view.

This should constitute a ‘fair use’ of any such copyrighted material (referenced and provided for in section 107 of the US Copyright Law).

If you wish to use any copyrighted material from this program for purposes of your own that go beyond ‘fair use’, you must obtain expressed permission from the copyright owner.
## How to compile
1. Clone the repository into a folder.
2. Compile all the `.cpp` files into object code and link them to make an executable.
   You must use the ISO C++ 2011 standard to compile them (it needs the `<chrono>` and `<random>` libraries).
## Usage
See the usage in `PrintUsage.cpp`.
## Testing
It was tested on Windows 10 by compiling it with Min-GW and using the US version of the game.
To test it more, I added an automatic test routine on startup that I plan to remove in future releases (no telemetry involved).