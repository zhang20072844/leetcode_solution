/************************************************************************
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.


A partially filled sudoku which is valid.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
************************************************************************/


#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	bool isValidSudoku(vector<vector<char> > &board) {
		int row[9] = {0};
		int col[9] = {0};
		int cur[9] = {0};
		for (int i = 0; i < board.size(); ++ i)
		{
			for (int j = 0; j < board[i].size(); ++ j)
			{
				if (board[i][j] == '.')
				{
					continue;
				}
				int num = board[i][j] - '0';
				if (col[j] & (1 << num))
				{
					return false;
				}
				else
				{
					col[j] |= (1 << num);
				}

				if (row[i] & (1 << num))
				{
					return false;
				}
				else
				{
					row[i] |= (1 << num);
				}

				int index = (i/3)*3 + j/3;
				if (cur[index] & (1 << num))
				{
					return false;
				}
				else
				{
					cur[index] |= (1 << num);
				}
			}
		}
		return true;
	}
};
int main()
{

	ListNode *a = new ListNode(2);
	ListNode *b = NULL;
	Solution solution;
	solution.getIntersectionNode(a,b);
	return 0;
}