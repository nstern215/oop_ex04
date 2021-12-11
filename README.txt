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

4.
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


5.
Board.h\cpp
BoardItem.h\cpp
Controller.h\cpp
Matrix.h\cpp
MatrixItem.h\cpp
Menu.h\cpp
MenuItem.h\cpp
Square.h\cpp

8.
Matrix use a 2D vector of MatrixItem pointer to store the data.
We use polymorphism to store MenuItem and BoardItem in this vector

7. 

8.
