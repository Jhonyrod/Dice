// Dice.cpp : Defines the entry point for the console application.

#include "Functions.hpp"

using namespace std;

typedef unsigned short int usi;
typedef unsigned short int cnt;

int _tmain(int argc, _TCHAR* argv[])
{
	usi cal = 0,														//Counts the total permutations.
		cun = 0;														//Counts the total unique permutations.
	/*const*/usi	ndice = 3,											//Will hold the number of dice.
					sides = 6;											//Will hold the number of sides of each dice.

	vector<usi*>	*All,												//Will hold all the permutations.
					*Uni;												//Will hold the unique permutation array.
	//vector <usi*>	All[ndice*(sides - 1) + 1],
	//				Uni[ndice*(sides - 1) + 1];

	cout	<< "Enter the number of dice, followed by their number of faces" << endl;
	cin		>> ndice >> sides;

	All = new vector<usi*>[ndice*(sides - 1) + 1] {nullptr};			//Allocates memory for All and Uni.
	Uni = new vector<usi*>[ndice*(sides - 1) + 1] {nullptr};

	func::Fill(All, Uni, sides, ndice, new vector<usi>);

	for (cnt i = 0; i <= ndice*(sides - 1); i++)						//Run through all the possible sums.
	{
		cal += All[i].size();
		cun += Uni[i].size();

		cout << "\nThere's a total of "			<< All[i].size()	<<
				"\tways to sum "				<< i + ndice		<<	//i+ndice is there in order to show the correct sum from the dice as, for simplistic reasons, the "dice" in this code only run from 0 to sides.
				",\thowever, there are only "	<< Uni[i].size()	<<
				" unique ways, which are:\n";

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

	cout << "\nGiving us " << cal << " total permutations or " << cun << " unique permutations.";

	return 0;
}