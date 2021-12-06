#pragma once

// will hold locations for the characters and the special tiles//

struct Location
{
    explicit Location(int row, int col) : row(row), col(col) {}

    int row;
    int col;
};