#include "Fill.hpp"

void func::Fill(std::vector<usi*> All[], std::vector<usi*> Uni[], const usi step, const usi depth, std::vector<usi>* iarr)
{
	if (depth == 0)
	{
		usi cnt = 0,
			*perm = new usi[iarr->size()];
		for (usi i = 0; i < iarr->size(); i++)
			cnt += perm[i] = iarr->at(iarr->size() - i - 1);
		All[cnt].push_back(perm);
		UniquePush(Uni[cnt], All[cnt].back(), iarr->size());
	}
	else
		for (usi i = 0; i<step; i++)
		{
			iarr->push_back(i);
			Fill(All, Uni, step, depth - 1, iarr);
			iarr->pop_back();
		}
}