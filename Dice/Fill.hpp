#pragma once

#include "Functions.hpp"

namespace func
{
	/*	Itarates through 'depth' for cycles in order to fill 'All' and 'Uni' with the correct values.
		@param All	An array of vectors of arrays.
					First index is the sum of all the elements of the innermost array.
					Second index is the nth permutation that sums the first index.
					Third index is the permutation itself.
					Fourth index is the nth value of the aforementioned permutation.
		@param Uni	Same as 'All', but it only holds unique permutations.
					It also holds a counter of how many equal permutations 'All' had, as the last value 
					of each permutation.
		@param step	The highest value to consider at each element of the permutations.
		@param depthThe number of elements of each permutation.
		@param iarr	Holds the history of all the indexes that the function has already looped through.
	*/
	void Fill (std::vector<usi*> All[], std::vector<usi*> Uni[], const usi step, const usi depth, std::vector<unsigned int> *iarr);
}
