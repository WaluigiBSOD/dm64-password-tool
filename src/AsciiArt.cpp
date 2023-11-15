// Dr. Mario 64 Password Generator/Decoder Tool
// Copyright (C) 2020-present WaluigiBSOD (waluigibsod.github.io)
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

#include "StringFunctions.h"

extern const string AsciiArtBlueVirus =
_CenterString("   ......              ") +
_CenterString("  .******.      ..  .. ") +
_CenterString(" .*...***.   ...#...##.") +
_CenterString(" ......***. .**.######.") +
_CenterString("     ...**..****.####. ") +
_CenterString("     ...*****....####. ") +
_CenterString("      ...***......###..") +
_CenterString("     ....**....***..##.") +
_CenterString("    .*...**......**... ") +
_CenterString("   .*...#..#......**.  ") +
_CenterString("   .*...#..#......***. ") +
_CenterString("  .***...**......****. ") +
_CenterString("  .******************. ") +
_CenterString("  .*.***********...**. ") +
_CenterString("  .*....###........**. ") +
_CenterString(" ..**...###........*.  ") +
_CenterString(".##.*.............**.  ") +
_CenterString(".###.*...........**.   ") +
_CenterString(".##.*.*........**..    ") +
_CenterString(" ....*.**....***.      ") +
_CenterString("  .##.#..*****....     ") +
_CenterString(" .#####. .....#.##.    ") +
_CenterString(" .......     .#####.   ") +
_CenterString("             .......   ")
;

extern const string AsciiArtRedVirus =
_CenterString("       .\?.              ") +
_CenterString("      .\?\?.   ..         ") +
_CenterString("      .#\?\?...#.         ") +
_CenterString("      .##\?.\?\?\?..        ") +
_CenterString("      ..\?\?\?\?\?\?\?\?.. .    ") +
_CenterString("     .\?\?\?......\?\?\?.#... ") +
_CenterString("    .\?\?.......#..\?\?..\?\?.") +
_CenterString("   .\?\?..........#.\?.\?\?. ") +
_CenterString("   .\?\?....\?\?\?\?\?....\?\?#. ") +
_CenterString("   .\?\?\?..\?....\?\?...\?... ") +
_CenterString("  .\?\?\?\?\?\?\?.....\?....\?.  ") +
_CenterString("  .\?\?....\?\?\?....\?...\?.. ") +
_CenterString("  .\?...##..\?\?\?..\?...\?.  ") +
_CenterString(" ..\?...##....\?\?\?\?\?.\?\?#. ") +
_CenterString(".#.\?..........##.\?\?\?..#.") +
_CenterString("...\?\?.........##....###.") +
_CenterString(".#..\?\?.....#.......#.#. ") +
_CenterString(".##..\?\?...##.#......##. ") +
_CenterString(".##. .\?\?\?.##.##...\?...  ") +
_CenterString(" ..   ....#####.\?\?.\?.   ") +
_CenterString("      .\?\?..###........  ") +
_CenterString("    ...\?..\?...  .#####. ") +
_CenterString("   .#####.\?.    ....... ") +
_CenterString("   ........             ")
;

extern const string AsciiArtYellowVirus =
_CenterString("          .    .        ") +
_CenterString("    ..   .*.  .*.   ..  ") +
_CenterString("    .#.  .**..**.  .#.  ") +
_CenterString("     .#..#..##..#..#.   ") +
_CenterString("      .############.    ") +
_CenterString("       .##########.     ") +
_CenterString("      .####....####...  ") +
_CenterString("     .###..*..*..##.**. ") +
_CenterString("  .. .##...*..*....*.**.") +
_CenterString("  .#.*......##.....*.**.") +
_CenterString("   .#.###.######.##.**. ") +
_CenterString("    .###############... ") +
_CenterString("   .##################. ") +
_CenterString("   .##################. ") +
_CenterString(".. .####..........####. ") +
_CenterString(".*. .##.##########.##.  ") +
_CenterString(".**.#..############..   ") +
_CenterString(".**...*............     ") +
_CenterString(".****.****.   ..#..     ") +
_CenterString(" .**. .**.    .*.**.    ") +
_CenterString("  ..   ..     .*****.   ") +
_CenterString("              .......   ")
;

extern const string AsciiArtViruses[3] = {AsciiArtBlueVirus,AsciiArtRedVirus,AsciiArtYellowVirus};

extern const string AsciiArtBlueVirusLaughing =
_CenterString("       .. .... ..       ") +
_CenterString("     ..**.****.**..     ") +
_CenterString("  ...*****.**.*****...  ") +
_CenterString(" .***......**......***. ") +
_CenterString(" .*........**........*. ") +
_CenterString("  ..*..............*..  ") +
_CenterString("  .**.....#..#.....**.  ") +
_CenterString("  .**.....#**#.....**.  ") +
_CenterString("  ..**..********..**..  ") +
_CenterString("  .*****..####..*****.  ") +
_CenterString(" .*.**....####....**.*. ") +
_CenterString(" ...*..............*... ") +
_CenterString(".##..................##.") +
_CenterString(".###.*............*.###.") +
_CenterString(".##..**..........**..##.") +
_CenterString(" ..  ..**......**..  .. ") +
_CenterString("     ..*.******.*..     ") +
_CenterString("    .##.#......#.##.    ") +
_CenterString("   .#####.    .#####.   ") +
_CenterString("   .......    .......   ")
;

extern const string AsciiArtRedVirusLaughing =
_CenterString("    .              .    ") +
_CenterString("   .\?.  .      .  .\?.   ") +
_CenterString("   .\?\?..#......#..\?\?.   ") +
_CenterString("   .#\?\?..\?\?\?\?\?\?..\?\?#.   ") +
_CenterString("   .#\?.\?\?\?\?\?\?\?\?\?\?.\?#.   ") +
_CenterString("    ..\?\?........\?\?..    ") +
_CenterString("    .\?...##..##...\?.    ") +
_CenterString("    .\?............\?.    ") +
_CenterString("   .\?\?....\?\?\?\?....\?\?.   ") +
_CenterString("   .\?\?\?..\?\?..\?\?..\?\?\?.   ") +
_CenterString("  .\?\?..\?\?\?....\?\?\?..\?\?.  ") +
_CenterString("  .\?....\?\?\?\?\?\?\?\?....\?.  ") +
_CenterString(" .#\?...##.\?\?\?\?\?.#...\?#. ") +
_CenterString(".#.\?...##.......#...\?.#.") +
_CenterString("...\?................\?...") +
_CenterString(".#.\?................\?.#.") +
_CenterString(".##\?................\?##.") +
_CenterString(".##.\?......##......\?.##.") +
_CenterString(" ....\?\?\?\?\?\?\?\?\?\?\?\?\?\?.... ") +
_CenterString("     ....\?\?\?\?\?\?....     ") +
_CenterString("    ...\?........\?...    ") +
_CenterString("   .#####. .\?..#####.   ") +
_CenterString("   ....... ..........   ")
;

extern const string AsciiArtYellowVirusLaughing =
_CenterString("         .    .         ") +
_CenterString("    ..  .*....*.  ..    ") +
_CenterString("    .#..#######...#.    ") +
_CenterString("     ..##########..     ") +
_CenterString("     .####....####.     ") +
_CenterString("    .###.**..**.###.    ") +
_CenterString("    .##....##....##.    ") +
_CenterString("     ...#######....     ") +
_CenterString("  .. .############. ..  ") +
_CenterString("  .#.##..######..##.#.  ") +
_CenterString("   .##.*..####..*.##.   ") +
_CenterString("   .#..*........*..#.   ") +
_CenterString("  ..#..*..*..*..*..#..  ") +
_CenterString(" .**.#.*..*..*..*.#.**. ") +
_CenterString(".**..#....*..*....#..**.") +
_CenterString(".**.*.##........##.*.**.") +
_CenterString(" .**. ..########.. .**. ") +
_CenterString("  ..  .#.######.#.  ..  ") +
_CenterString("     ..#...... .#..     ") +
_CenterString("    .**.*.    .*.**.    ") +
_CenterString("   .*****.    .*****.   ") +
_CenterString("   .......    .......   ")
;

extern const string AsciiArtVirusesLaughing[3] = {AsciiArtBlueVirusLaughing,AsciiArtRedVirusLaughing,AsciiArtYellowVirusLaughing};

extern const string AsciiArtDrMarioWatching =
_CenterString("     ###              ") +
_CenterString("    ##.## ****        ") +
_CenterString("    ##### ******      ") +
_CenterString("     ###.########     ") +
_CenterString("        **********    ") +
_CenterString("    ***#*...******    ") +
_CenterString("     ##*####.#****    ") +
_CenterString("     #.#.#####***##   ") +
_CenterString("     #.#.#####**####  ") +
_CenterString("   ##########***#.##  ") +
_CenterString("  ###############.##  ") +
_CenterString("  #######**####*####  ") +
_CenterString("   #####*****###*##*  ") +
_CenterString("    ********####****  ") +
_CenterString("    ******######***   ") +
_CenterString("     ##..######       ") +
_CenterString("      ######...##     ") +
_CenterString("    #.......##..###   ") +
_CenterString("  ###..##..##.*.####  ") +
_CenterString(" ####.*.#.###.*.####  ") +
_CenterString(" #.##.*.#.#..*.###### ") +
_CenterString("##.##.**.##.**.##.### ") +
_CenterString("#.####.*.#.**..##.### ") +
_CenterString("#.####.*.#.*..##.#####") +
_CenterString("..####.**.**.###.#####") +
_CenterString("#.#####.*#*.####......") +
_CenterString("##....#..#.##...######") +
_CenterString("##.####.###.###.#.####") +
_CenterString("#..####.....####.#### ") +
_CenterString(" #  ###.#########..   ") +
_CenterString("    ###.###########   ") +
_CenterString("     ..............   ") +
_CenterString("     #####..#####     ") +
_CenterString("     #####..#####     ") +
_CenterString(" *** #####..###..***  ") +
_CenterString("*#***..........***#** ") +
_CenterString("**********..********* ") +
_CenterString(" *********..********  ")
;

extern const string AsciiArtDrMarioGameOver =
_CenterString("               **###**              ") +
_CenterString("             ***###*#***            ") +
_CenterString("             ***#####***            ") +
_CenterString("            ####.###.####           ") +
_CenterString("            *****...*****           ") +
_CenterString("           **##*.#*#.*##**          ") +
_CenterString("          ##*#..#####..#*##         ") +
_CenterString("         ###*####.#.####*###        ") +
_CenterString("         #*#**###.#.###**#*#        ") +
_CenterString("         ##*#############*##        ") +
_CenterString("          #*#############*#         ") +
_CenterString("           ###**#####**###          ") +
_CenterString("           #*****###*****#          ") +
_CenterString("           ##***********##          ") +
_CenterString("     ##     #############     ##    ") +
_CenterString("     #    ##..####.####..#     #    ") +
_CenterString("   ### # ####...#####...#### # ###  ") +
_CenterString(" ##### ######.*......*.#######  ####") +
_CenterString("##    #######.*.#.#..*.#########   #") +
_CenterString("     #####.##.**.#..**.##.#####     ") +
_CenterString("      ####.###.*.#.**.####.###      ") +
_CenterString("       ##.####.*.#.*..####.         ") +
_CenterString("         #####.**.**.######         ") +
_CenterString("         ######.*#*.#######         ") +
_CenterString("         .....#..#.##.....#         ") +
_CenterString("         ######.###.#######         ") +
_CenterString("         ######.....#######         ") +
_CenterString("          #####.##########          ") +
_CenterString("          #####.##########          ") +
_CenterString("          ................          ") +
_CenterString("            #####  #####            ") +
_CenterString("            #####  #####            ") +
_CenterString("        *** #####  ###..***         ") +
_CenterString("       *#***.....  ...***#**        ") +
_CenterString("       **********  *********        ") +
_CenterString("        *********  ********         ")
;

extern const string AsciiArtDrMario[2] = {AsciiArtDrMarioWatching,AsciiArtDrMarioGameOver};
