#include "Fill.hpp"

void func::Fill(std::unique_ptr<std::vector<usi*>[]> &All,
				std::unique_ptr<std::vector<usi*>[]> &Uni,
				const usi step,
				const usi depth,
				std::unique_ptr<std::vector<usi>> &iarr)
{
	if (depth == 0)											//If at the end of the chain...
	{
		unsigned	cnt   = 0;								//Will hold the sum of all the elements of iarr.
		usi			*perm = new usi[iarr->size()];			//Create a new array with space for each element of iarr.
		for (usi i = 0; i < iarr->size(); i++)				//Iterate through iarr.
			cnt += perm[i] = iarr->at(iarr->size() - i - 1);//Copy the ith element of iarr to the ith element of perm and sum it to cnt.
		All[cnt].push_back(perm);							//Push the new permutation to the corresponding index.
		UniquePush(Uni[cnt], All[cnt].back(), iarr->size());
	}
	else
		for (usi i = 0; i<step; i++)
		{
			iarr->push_back(i);								//Push the current index to iarr...
			Fill(All, Uni, step, depth - 1, iarr);			//And continue iterating.
			iarr->pop_back();								//Once done pop the last index from iarr.
		}
}

void func::Fill(std::unique_ptr<std::vector<usi*>[]> &All,
				std::unique_ptr<std::vector<usi*>[]> &Uni,
				const usi step,
				const usi depth)
{
	Fill(All, Uni, step, depth, std::make_unique<std::vector<usi>>());
}