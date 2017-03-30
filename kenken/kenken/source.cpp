/*
hello
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct cageCondition
{
	char operation;
	int total;
};

class kenPuzzle
{
public:
	int puzzleSize;
	int numOfCages;
	int*** puzzle;
	vector<cageCondition> cages;

	kenPuzzle(int p, int n)
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
	}
};


int main()
{

}


/*
input the two numbers
make the grid from pointer
*/