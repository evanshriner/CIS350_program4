/*
hello
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// http://www.geeksforgeeks.org/backtracking-set-7-suduku/
struct CageCondition
{
	char operation;
	int total;
};

class KenPuzzle
{
public:
	int puzzleSize;
	int numOfCages;
	int*** puzzle;
	vector<CageCondition> cages;

	KenPuzzle(int p, int n)
	{
		puzzleSize = p;
		numOfCages = n;

		puzzle = initPuzzle();
	}

	int*** initPuzzle()
	{
		int*** temp;
		temp = new int**[puzzleSize];
		for (int i = 0; i < puzzleSize; i++)
		{
			temp[i] = new int*[puzzleSize];
			for (int j = 0; j < puzzleSize; j++)
			{
				temp[i][j] = new int[2];
			}
		}

		for (int i = 0; i < puzzleSize; i++)
		{
			for (int j = 0; j < puzzleSize; j++)
			{
				temp[i][j][0] = 0; // unassigned value
			}
		}

		return temp;
	}

	
};


int main()
{
	int size, cages;
	cin >> size >> cages;
	KenPuzzle p1(size, cages);

}


/*
input the two numbers
make the grid from pointer
*/