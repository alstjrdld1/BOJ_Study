#include <queue>
#include <utility>
#include <iostream>
using namespace std;

int N, M;
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };
int** grid;
bool** visit;
queue<pair<int,int>> q;
int day = 0;
int visitCount = 0;
int invalidCount = 0;

bool isIn(int r, int c)
{
	if (r < 0 || r >= N || c < 0 || c >= M) return false;
	return true;
}

int main()
{
	cin >> M >> N;
	grid = new int* [N];
	visit = new bool* [N];

	for (int i = 0; i < N; i++)
	{
		grid[i] = new int[M];
		visit[i] = new bool[M];
		for (int j = 0; j < M; j++)
		{
			cin >> grid[i][j];
			if (grid[i][j] == 1)
			{
				q.push(pair<int, int>(i, j));
				visit[i][j] = true;
				visitCount++;
			}
			else if (grid[i][j] == -1)
			{
				invalidCount++;
				visit[i][j] = false;
			}
			else
			{
				visit[i][j] = false;
			}
		}
	}

	while (!q.empty())
	{
		day++;
		int qSize = q.size();
		for (int i = 0; i < qSize; i++)
		{
			pair<int, int> front = q.front();
			q.pop();
			int r = front.first;
			int c = front.second;

			for (int n = 0; n < 4; n++)
			{
				if (isIn(r + dr[n], c + dc[n]))
				{
					if (visit[r + dr[n]][c + dc[n]] || grid[r + dr[n]][c + dc[n]] == -1) continue;
					else
					{
						q.push(pair<int, int>(r + dr[n], c + dc[n]));
						visit[r + dr[n]][c + dc[n]] = true;
						visitCount++;
					}
				}
			}
		}
	}

	if (visitCount != ((N * M) - invalidCount) )
	{
		cout << -1;
	}
	else
	{
		cout << day - 1;
	}

	return 0;
}