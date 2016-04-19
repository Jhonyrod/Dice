#pragma once
#include "Functions.hpp"

namespace func
{
	/*Compares 2 arrays of arbitrary size.
	*/
	template <typename Type> bool PICompare (const Type lhs[], const Type rhs[], const usi size)
	{
		bool res = false;
		Type	*slhs = nQSort(lhs, size),
				*srhs = nQSort(rhs, size);

		for (usi i = 0; i < size; i++)
			if (slhs[i] == srhs[i])
			{
				res = true;
				break;
			}

		delete[] slhs, srhs;

		return res;
	}
}