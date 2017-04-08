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
private:

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

	bool puzzleCompleted(int &row, int &col)
	{
		for (row = 0; row < puzzleSize; row++)
		{
			for (col = 0; col < puzzleSize; col++)
			{
				if (puzzle[row][col][0] == 0)
					return false;
			}
		}
		return true;
	}

	bool numberWorks(int i, int row, int col)
	{
		// check if number works with row and col
		checkPlacement(i, row, col);

		// check if number works with cage
		checkCage(i, row, col);

	}

	bool checkPlacement(int i, int row, int col)
	{
		// check if  i is valid in row

		//check if i is valid in column
	}

	bool checkCage(int i, int row, int col)
	{
		// check if current cage members work with i
	}

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

	bool solvePuzzle()
	{
		int row, col;

		if (puzzleCompleted(row,col))
		{
			return true;
		}

		for (int i = 1; i <= puzzleSize; i++)
		{
			if (numberWorks(i, row, col))
			{
				puzzle[row][col][0] = i;

				if (solvePuzzle())
				{
					return true;
				}
				else
				{
					puzzle[row][col][0] = 0;
				}
			}
		}
		return false;
	}
	
};


int main()
{
	int size, cages;
	cin >> size >> cages;
	KenPuzzle p1(size, cages);

	// out put table
	if (p1.solvePuzzle())
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				cout << p1.puzzle[i][j][0] << " ";
			}
			cout << endl;
		}
	}
	else
	{
		cout << "no solution";
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