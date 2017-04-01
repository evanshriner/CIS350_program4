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
	vector<vector<int>> includedBlocks;
	
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
		setBlockTypes();
		setCageConditions();
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

	void setBlockTypes()
	{
		char type;
		for (int i = 0; i < puzzleSize; i++)
		{
			for (int j = 0; j < puzzleSize; j++)
			{
				cin >> type;
				puzzle[i][j][1] = 0;
				puzzle[i][j][1] = (int)type - 97;
			}
		}
	}

	void setCageConditions()
	{
		for (int i = 0; i < numOfCages; i++)
		{
			CageCondition temp;
			cin >> temp.total >> temp.operation;
			cages.push_back(temp);
		}

		for (int i = 0; i < puzzleSize; i++)
		{
			for (int j = 0; j < puzzleSize; j++)
			{
				vector<int> temp;
				temp.push_back(i);
				temp.push_back(j);

				cages[puzzle[i][j][1]].includedBlocks.push_back(temp);
			}
		}
	}
};


int main()
{
	int size, cages;
	cin >> size >> cages;
	KenPuzzle p1(size, cages);

	// out put table
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << p1.puzzle[i][j][0] << " ";
		}
		cout << endl;
	}

	system("pause");
	return 0;
}


/*
input the two numbers
make the grid from pointer

put function inside init that takes the rest of the input
and makes the entire puzzle
*/