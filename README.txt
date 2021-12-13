1.
ex04 board editor

2.
Netanel Stern, ID 206342255
Daniel Yosef, ID 322017518

3.
In this made an interface to create a new level board for the gmae "Game of Throne"
You can edit an existing board or create a new one.

To edit an existing one, rename the file to "Board.txt" and place it in the folder of the program.
If you want to create a new board, you will be ask to enter the size of the board in the terminal window.
The new board will save as "Board.txt" in the same folder as the running program

4. Design
we have two main base objects:
Matrix that represent a visual matrix and data
Matrix item represent the data element in the matrix.

Board and Menu derived from Matrix and represent the Menu that store the different options for the board
and Board the represent the board.

MenuItem and BoardItem derived from MatrixItem and represent an element of the menu or the board

Square is an object that taking care of the graphical section and print to the screen the relevant graphics elements.

Controller is the object that manage the editing process. When the menu clicked it update the controller about the selected
command (add, delete, save etc.) or about the selected item to add to the board.
When the board cliecked it ask the controller for the selected item to add to the board. In case of delete mode, an empty item
will be added to the board.


5. Files
Board.h\cpp
BoardItem.h\cpp
Controller.h\cpp
Matrix.h\cpp
MatrixItem.h\cpp
Menu.h\cpp
MenuItem.h\cpp
Square.h\cpp

6. Data Strucutres
Matrix use a 2D vector of MatrixItem pointer to store the data.
We use polymorphism to store MenuItem and BoardItem in this vector

7. Algorithms

8. Bugs

9. Comments: Board file format
the level represent by a txt file that contains how the board should be. for an empty cube use underscore ('_').
after the board add a single dash ('-')
for each teleport pair add a single row with the pair coordinates seperate by space
row col pairRow pairCol

!!include all players in the level board!!

by default, the levels folder is "Resources". when the project runs from the "out\build\x64-Debug" folder,
(created by Visual Studio after build), the game will take the Resources folder.
Another option is a parameter: run command: ex02.exe <path>

A level fomat for example:
___==M=!__X**
_K__=#=__T_*@
____X____====
W============
-
0 10 2 4