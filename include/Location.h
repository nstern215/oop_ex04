#pragma once

struct Location
{
	unsigned int m_row;
	unsigned int m_col;
};

bool operator==(const Location& a, const Location& b);
