#include <iostream>
using namespace std;

int blue = 0;
int white = 0;

int** grid;

void splitColorPaper(int row, int col, int n)
{
    if(n == 1)
    {
        if(grid[row][col] == 1) blue++;
        else white++;
    }
    else
    {
        int sum = 0;
        for(int i = row; i < row + n; i++)
        {
            for(int j = col; j < col + n; j++)
            {
                sum += grid[i][j];
            }
        }
        
        if(sum == 0) white++;
        else if(sum == n*n) blue++;
        else 
        {
            splitColorPaper(row, col, n/2);
            splitColorPaper(row + n/2, col, n/2);
            splitColorPaper(row, col + n/2, n/2);
            splitColorPaper(row + n/2, col + n/2, n/2);
        }
    }
}

int main()
{
    int N; 
    cin >> N;

    grid = new int*[N];
    for(int i = 0; i < N; i++)
    {
        grid[i] = new int[N];
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> grid[i][j];
        }
    }

    splitColorPaper(0, 0, N);

    cout << white << "\n" << blue;

    return 0;
}