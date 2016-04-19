#pragma once

#include "Functions.hpp"

namespace func
{
	/*	Checks for matches between all the elements of lhs and rhs and if none is found it pushes rhs to the back of lhs.
		@param lhs	Variable size container whose elements are all possible permutations of a given sum.
		@param rhs	Permutation to insert if it's place-independent different to every element of lhs.
		@param size	Length of rhs, and consequently, lhs[i].
		@return		Number of matches found.
	 */
	template <typename Type> usi UniquePush (std::vector<Type*> &lhs, const Type rhs[], const usi size)
	{
		usi tal = 0;								//Number of matches found.

		for (usi i = 0; i < lhs.size(); i++)
			if (PICompare(lhs[i], rhs, size))
			{
				lhs[i][size]+=1;					//If a match is found increase the match counter in the array by one.
				tal++;								//Increase by one the number of matches found every time one is... well, found.
			}

		if (tal == 0)
		{
			Type *res = new Type[size+1] {0};
			for (usi i = 0; i < size; i++)
				res[i] = rhs[i];					//Copy rhs to res.
			res[size] = 1;
			lhs.push_back(res);						//If no matches were found then insert the new permutation into lhs.
		}

		return tal;
	}
}