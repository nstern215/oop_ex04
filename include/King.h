#pragma once

#include "MatrixItem.h"
#include <cstdbool>

class King : public MatrixItem {

public:

	King();
	King(const MatrixItem&);

	bool kingAtThron();

private:

	bool m_thron = false;
	bool m_boarded = false;

};