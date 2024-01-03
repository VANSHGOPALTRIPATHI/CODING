/*PROBLEM STATEMENT=>
You have been given a 9x9 2d integer matrix 'MAT' representing a Sudoku puzzle. The empty cells of the Sudoku are filled with zeros, and the rest of the cells are filled with integers from 1 to 9. Your task is to fill all the empty cells such that the final matrix represents a Sudoku solution.

Note:
A Sudoku solution must satisfy all the following conditions-
1. Each of the digits 1-9 must occur exactly once in each row.
2. Each of the digits 1-9 must occur exactly once in each column.
3. Each of the digits 1-9 must occur exactly once in each of the 9, 3x3 sub-grids of the grid.

You can also assume that there will be only one sudoku solution for the given matrix.

    TIME COMPLEXITY->9^m
    SPACE COMPLEXITY->O(1);


*/
#include <bits/stdc++.h>
bool issafe(int row, int col, vector<vector<int>> &board, int value)
{
    for (int i = 0; i < board.size(); i++)
    {
        // row check->
        if (board[row][i] == value)
        {
            return false;
        }
        // col check->
        if (board[col][i] == value)
        {
            return false;
        }
        // 3*3 mtrix check
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == value)
        {
            return false;
        }
    }
    return true;
}

bool solve(vector<vector<int>> &board)
{
    int n = board.size();
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (board[row][col] == 0)
            {
                for (int val = 1; val <= 9; val++)
                {
                    if (issafe(row, col, board, val))
                    {
                        board[row][col] = val;
                        // recursive call
                        bool aageposssible = solve(board);
                        if (aageposssible)
                        {
                            return true;
                        }
                        else
                        {
                            // backtrak
                            board[row][col] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<int>> &sudoku)
{
    // Write your code here
    // No need to print the final sudoku
    // Just fill the values in the given matrix
    solve(sudoku);
}