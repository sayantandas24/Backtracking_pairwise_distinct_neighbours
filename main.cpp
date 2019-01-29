#include<bits/stdc++.h>
using namespace std;
int grid[20][20]; // defining a grid globally

/* function that takes cell indices, row and column
  of the grid and fill it */
bool fillGrid(int i, int j, int row, int col, int max_N)
{
  // all the cells of the grid are filled
  if (i >= row)
  {
      return true;
  }
  /*  # # # # #
      # # U # #
      # L X R _
      _ _ D _ _
      _ _ _ _ _   */
  
  // consider the integers 1 to max_neighbous 
  // for the position X
  for (int num = 1; num <= max_N; num++)
  {
      int ifValid = 0;  // valid positions counter  

      // number distinct to the right neighbour of U
      if(((i > 0 && j < col - 1) && num != grid[i-1][j+1]) 
        // right neighbour of U out of index
        || ( i < 1 || j > col - 2))  
      {
          ifValid ++;
      }
      
      // number distinct to the upper neighbour of U
      if (( i > 1 && num != grid[i-2][j]) ||
        // upper neighbour of U out of index
          i < 2)
      {
          ifValid ++;
      }

      // number distinct to the left neighbour of U
      if ((( i > 0 && j > 0) && num != grid[i-1][j-1]) 
        // left neighbour of U out of index
        || ( i < 1 || j < 1))
      {
          ifValid ++;
      }

      // number distinct to the left neighbour of L
      if (( j > 1 && num != grid[i][j-2]) || 
        // left neighbour of L out of index
          j < 2)
      {
          ifValid ++;
      }
      
      if (ifValid == 4) // the number is valid for 
                        // all the mentioned potsitions
      {
          grid[i][j] = num; // fill the cell

          // fill the next column of the row
          if ( j < col - 1)
          {
              // valid!
              if( fillGrid( i, j+1, row, col, max_N))
                  return true;
              grid[i][j] = 0; // not valid! 
          }
          // fill the 1st column of the next row
          else
          {
              // valid!
              if( fillGrid( i+1, 0, row, col, max_N))
                  return true;
              grid[i][j] = 0; // not valid!
          }
      }
  }
  return false; // Backtracking
}

/* function to find the number of maximum possible
  neighbours*/ 
int FindMaxNeighbour(int row, int col)
{
    // grid contains 1 element
    if (row * col == 1)
        return 1;

    // one lined grid
    else if (row == 1 || col == 1)
    {
        // grid contains 2 elements
        if(row * col == 2)
            return 1;
        // more than 2 elements
        else
            return 2;
    }

    // two lined grid
    else if (row == 2 || col == 2)
    {
        // grid of size 2 * 2
        if (row * col == 4)
            return 2;
        // contains more than 4 elements
        else
            return 3;
    }

    // atleast one cell has 4 neighbours
    else
        return 4;
}

/* function to print the grid*/
void printGrid(int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            cout << grid[i][j] << " ";
        cout << endl;
    }
}

/* Driver Program to test above functions */
int main()
{
    // declaring row and column size
    int row = 5, col = 7;

    // maximum possible neighbours of the grid[row][col] 
    int max_neighbours = FindMaxNeighbour(row, col);
    
    if (fillGrid(0, 0, row, col, max_neighbours))
        printGrid( row, col);
    else
        cout << "No solution" << endl;
    return 0;
}