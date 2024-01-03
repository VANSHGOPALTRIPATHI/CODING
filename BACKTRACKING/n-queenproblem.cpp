
/*           PROBLEM STATEMENT->>>>
The N Queens puzzle is the problem of placing N chess queens on an N * N chessboard such that no two queens attack each other.

Given an integer ‘N’, print all distinct solutions to the ‘N’ queen puzzle.

Two queens on the same chessboard can attack each other if any of the below condition satisfies:
1. They share a row.
2. They share a column.
3. They share a diagonal.
*/
#include <bits/stdc++.h>
void addsolution(vector<vector<int>> &ans, vector<vector<int>> &board, int n)
{
    vector<int> temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}
bool issafe(int row, int col, vector<vector<int>> &board, int n)
{
    int x = row;
    int y = col;

    // check for same row
    while (y >= 0)
    {
        if (board[x][y] == 1)
        {
            return false;
            y--;
        }
    }
        x = row;
        y = col;
        // check for diagonal->
        while (x >= 0 && y >= 0)
        {
            if (board[x][y] == 1)
            {
                return false;
                y--;
                x--;
            }
        }

        
        x = row;
        y = col;

        while (x < n && y >= 0)
        {
            if (board[x][y] == 1)
            {
                return false;
                y--;
                x++;
            }
        }
        return true;
    }

void solve(int col, vector<vector<int>> &ans, vector<vector<int>> &board, int n)
{
    if (col == n)
    {
        addsolution(ans, board, n);
        return;
    }
    for (int row = 0; row < n; row++)
    {
        if (issafe(row, col, board, n))
        {
            // placing is posiible
            board[row][col] = 1;
            solve(col + 1, ans, board, n);
            // backtraking
            board[row][col] = 0;
        }
    }
}

vector<vector<int>> nQueens(int n)
{
    // Write your code here

    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<int>> ans;

    solve(0, ans, board, n);

    return ans;
}
