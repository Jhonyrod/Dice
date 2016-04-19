// Dice.cpp : Defines the entry point for the console application.

/*	This program asks for a number of dice and their number of sides.
	Given those parameters it calculates the relative probability of throwing a certain number
	(which is limited by the parameters themselves).
	It also calculates the probability of each unique permutation, for example, using three D6s
	and throwing a 5: the probability of {3,1,1} and {2,2,1}.

	TODO:	Output to a file.
	TODO:	use command line arguments instead of cin.
	TODO:	Restrict size of arguments to avoid excessive memory usage (measured 500MB with 6 by 6)
	TODO:	Improve memory efficiency.																*/

//#define NO_VC															//Uncomment to enable compatibility with other compilers.
#include "Functions.hpp"

using namespace std;

typedef unsigned short int usi;
typedef unsigned short int cnt;

#ifndef NO_VC
int _tmain (int argc, _TCHAR* argv[])
#else
int main (int argc, char* argv)
#endif
{
	unsigned		cal = 0,											//Counts the total permutations.
					cun = 0;											//Counts the total unique permutations.
	usi				ndice = 0,											//Will hold the number of dice.
					sides = 0;											//Will hold the number of sides of each dice.

	vector<usi*>	*All,												//Will hold all the permutations.
					*Uni;												//Will hold the unique permutation array.

	cout << "Enter the number of dice, followed by their number of faces...\n";
	do
	{
		cin >> ndice >> sides;
		if (ndice*sides == 0)
			cout << "\nCome again?...\n";
	} while (ndice*sides == 0);

	All = new vector<usi*>[ndice*(sides - 1) + 1];						//Allocates memory for All and Uni.
	Uni = new vector<usi*>[ndice*(sides - 1) + 1];

	func::Fill(All, Uni, sides, ndice, new vector<usi>);

	for (cnt i = 0; i <= ndice*(sides - 1); i++)						//Run through all the possible sums.
	{
		cal += All[i].size();
		cun += Uni[i].size();

		cout << "\nThere's a total of "			<< All[i].size()	<<
				"\tways to sum "				<< i + ndice		<<	//i+ndice is there in order to show the correct sum from the dice as, for simplistic reasons, the "dice" in this code only run from 0 to sides.
				",\thowever, there are only "	<< Uni[i].size()	<<
				"\tunique ways, which are:\n";

		for (cnt j = 0; j<Uni[i].size(); j++)							//Run trough all possible permutatios
		{
			cout << '{';
			for (cnt k = 0; k<ndice; k++)								//Run through all dice in each permutation (although more than 3 dice is not allowed yet).
			{
				cout << Uni[i][j][k] + 1;								//Same as i+ndice.
				if (k<(ndice - 1))										//So that the last element isn't followed by a comma.
					cout << ',';
			}
			cout << "} :\t" << Uni[i][j][ndice] << "\ttimes.\n";
		}																//Displays all the unique permutations in human readable form. 
	}

	cout << "\nGiving us " << cal << " total permutations or " << cun << " unique permutations." << endl;

	return 0;
}