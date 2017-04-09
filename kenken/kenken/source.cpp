/*
hello
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

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

	bool checkPlacement(int num, int row, int col)
	{
		// check if  i is valid in row
		for (int i = 0; i < puzzleSize; i++)
		{
			if (num == puzzle[row][i][0])
				return false;
		}

		//check if i is valid in column
		for (int i = 0; i < puzzleSize; i++)
		{
			if (num == puzzle[i][col][0])
				return false;
		}

		return true;
	}

	bool checkCage(int num, int row, int col)
	{
		CageCondition* temp = &cages[puzzle[row][col][1]]; // for easier readability
		vector<int> numbersInCage; // copy of current included blocks array
		for (int i = 0; i < temp->includedBlocks.size(); i++)
		{
			if (temp->includedBlocks[i][0] == row && temp->includedBlocks[i][1] == col)
			{
				numbersInCage.push_back(puzzle[temp->includedBlocks[i][0]][temp->includedBlocks[i][1]][0]);
			}
			else if (puzzle[temp->includedBlocks[i][0]][temp->includedBlocks[i][1]][0] == 0)
			{
				return true;
			}
			else
			{
				numbersInCage.push_back(puzzle[temp->includedBlocks[i][0]][temp->includedBlocks[i][1]][0]);
			}
		}

		switch (temp->operation)
		{
			int totalAmt;
			case 'x':
				totalAmt = 1;
				for (int i = 0; i < numbersInCage.size(); i++)
				{
					if (temp->includedBlocks[i][0] == row && temp->includedBlocks[i][1] == col)
					{
						if ((totalAmt *= num) > temp->total)
							return false;
					}
					else if ((totalAmt *= numbersInCage[i]) > temp->total)
						return false;

				}
				if (totalAmt == temp->total)
					return true;
				else
					return false;
			case '/':
				if (temp->includedBlocks[0][0] == row && temp->includedBlocks[0][1] == col)
				{
						if (numbersInCage[1] / num != temp->total && num / numbersInCage[1] != temp->total)
							return false;
				}
				else
				{
						if (numbersInCage[0] / num != temp->total && num / numbersInCage[0] != temp->total)
							return false;
				}
				return true;
			case '+':
				totalAmt = 0;
				for (int i = 0; i < numbersInCage.size(); i++)
				{
					if (temp->includedBlocks[i][0] == row && temp->includedBlocks[i][1] == col)
					{
						if ((totalAmt += num) > temp->total)
							return false;
					}
					else if ((totalAmt += numbersInCage[i]) > temp->total)
							return false;
				}
				if (totalAmt == temp->total)
					return true;
				else
					return false;
			case '-':
				
				if (temp->includedBlocks[0][0] == row && temp->includedBlocks[0][1] == col)
				{
					 if (abs(numbersInCage[1] - num) != temp->total)
						return false;
				}
				else
				{
					if (abs(numbersInCage[0] - num) != temp->total)
						return false;
				}
				return true;
			default:
				return false;
		}
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
			if (checkCage(i, row, col) && checkPlacement(i, row, col))
			{
				puzzle[row][col][0] = i;
				//printPuzzle();

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

	void printPuzzle()
	{
		for (int i = 0; i < puzzleSize; i++)
		{
			for (int j = 0; j < puzzleSize; j++)
			{
				cout << puzzle[i][j][0] << " ";
			}
			cout << endl;
		}
	}
	
};


int main()
{
	int size, cages;
	cin >> size >> cages;
	KenPuzzle p1(size, cages);

	if (p1.solvePuzzle())
	{
		p1.printPuzzle();
	}
	else
	{
		cout << "no solution";
	}
	//system("pause");
	return 0;
}


