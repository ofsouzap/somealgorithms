#include "general_algorithms.h"

using namespace general_algorithms;

vector<int>* lcs_aux(vector<int>* xs, int xend, vector<int>* ys, int yend)
{

	if (xend < 0 || yend < 0)
	{
		return new vector<int>(0);
	}
	else if (xs->at(xend) == ys->at(yend))
	{
		vector<int>* rec_res = lcs_aux(xs, xend - 1, ys, yend - 1);
		rec_res->push_back(xs->at(xend));
		return rec_res;
	}
	else
	{

		vector<int>* rec_res_l = lcs_aux(xs, xend - 1, ys, yend);

		vector<int>* rec_res_r = lcs_aux(xs, xend, ys, yend - 1);
		
		if (rec_res_l->size() > rec_res_r->size())
		{
			delete rec_res_r;
			return rec_res_l;
		}
		else
		{
			delete rec_res_l;
			return rec_res_r;
		}

	}

}

vector<int>* general_algorithms::longest_common_subsequence(vector<int>* xs, vector<int>* ys)
{
	return lcs_aux(xs, xs->size() - 1, ys, ys->size() - 1);
}