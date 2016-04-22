#pragma once
#include "Functions.hpp"

namespace func
{
	/*Compares 2 arrays of arbitrary size.
	*/
	template <typename Type> bool PICompare(const Type lhs[], const Type rhs[], const usi size)
	{
		usi tal = 0;
		Type	*slhs,
				*srhs;

		slhs = nQSort(lhs, size);				//Creates sorted versions of lhs and rhs.
		srhs = nQSort(rhs, size);

		for (usi i = 0; i < size; i++)		//Iterates through the sorted arrays and..
			if (slhs[i] == srhs[i])			//If a match is found at the ith place...
				tal++;						//tal is increased.

		delete[] slhs;
		delete[] srhs;
		
		if (tal < size)						//If the number of matches is less to the number of elements...
			return false;					//The arrays are different.					
		else								//Otherwise...
			return true;					//They are the same.
	}
}