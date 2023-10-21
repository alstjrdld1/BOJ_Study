#include <queue>
#include <string>
#include <utility>
#include <iostream>
using namespace std;

#define MAXDIST 10001

int N,M;
int** grid;
bool** visitMap;
int** distanceFromStart;

bool isIn(int r, int c);

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int main()
{
    cin >> N >> M;

    grid = new int* [N];
    visitMap = new bool* [N];
    distanceFromStart = new int* [N];

    for(int i = 0; i< N; i++)
    {
        grid[i] = new int[M];
        visitMap[i] = new bool[M];
        distanceFromStart[i] = new int[M];

        string row;
        cin >> row;
        
        for(int j = 0; j < row.size(); j++)
        {
            grid[i][j] = row[j] - 48;
            visitMap[i][j] = false;
            distanceFromStart[i][j] = MAXDIST;
        }
    }

    queue<pair<int, int>> q;
    q.push(pair<int, int>(0, 0));
    distanceFromStart[0][0] = 1;

    while(!q.empty())
    {
        pair<int, int> front = q.front();
        int r = front.first;
        int c = front.second;
        visitMap[r][c] = true;
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            if(isIn(r + dr[i], c + dc[i]))
            {
                if(!visitMap[r+dr[i]][c+dc[i]] && (grid[r + dr[i]][c + dc[i]] == 1))
                {   
                    q.push(pair<int, int>(r+dr[i], c + dc[i]));
                    visitMap[r + dr[i]][c+dc[i]] = true;
                    if(distanceFromStart[r][c] + 1 < distanceFromStart[r + dr[i]][c + dc[i]])
                    {
                        distanceFromStart[r + dr[i]][c + dc[i]] = distanceFromStart[r][c] + 1;
                    }
                }
            }
        }
    }

    cout << distanceFromStart[N-1][M-1];

    return 0;
}

bool isIn(int r, int c)
{
    if(r >= N || r < 0 || c < 0 || c >= M) return false;
    return true;
}