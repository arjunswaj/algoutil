#include <iostream>
#include <string.h>
using namespace std;

// http://www.geeksforgeeks.org/dice-throw-problem/

// The main function that returns number of ways to get sum 'x'
// with 'n' dice and with 'm' faces.
int findWays(int m, int n, int x)
{
	cout << "Dice " << n << ", Faces " << m << ", Sum " << x << endl; 
    // Create a table to store results of subproblems.  One extra 
    // row and column are used for simpilicity (Number of dice
    // is directly used as row index and sum is directly used
    // as column index).  The entries in 0th row and 0th column
    // are never used.
    int table[n + 1][x + 1];
    memset(table, 0, sizeof(table)); // Initialize all entries as 0
 
    // Table entries for only one dice
    for (int j = 1; j <= m && j <= x; j++)
        table[1][j] = 1;
 
    // Fill rest of the entries in table using recursive relation
    // i: number of dice, j: sum

    /*
    F (i, j) = summation of
    for k = 1 to min (m, j)
		F (i - 1, j - k)
    */

    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= x; j++)
            for (int k = 1; k <= m && k < j; k++)
                table[i][j] += table[i-1][j-k];
 
    
    for (int i = 0; i <= n; i++)
    {
      for (int j = 0; j <= x; j++)
        cout << table[i][j] << " ";
      cout << endl;
    }    
    return table[n][x];
}


int main(int argc, char const *argv[])
{
	cout << findWays(16, 2, 15) << endl << endl;
    cout << findWays(12, 2, 35) << endl << endl;
    cout << findWays(16, 4, 85) << endl << endl;
    cout << findWays(14, 2, 55) << endl << endl;
    cout << findWays(14, 3, 55) << endl << endl;
 
    return 0;
}