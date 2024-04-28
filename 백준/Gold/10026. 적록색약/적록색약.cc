#include <queue>
#include <cstring>
#include <utility>
#include <iostream>
using namespace std;

char grid[100][100];
char redgreengrid[100][100];
bool visit[100][100] = { false };

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int N;

bool isIn(int x, int y)
{
	if (x >= N || x < 0 || y >= N || y < 0) return false;
	return true;
}

int main()
{
	cin >> N;

	queue<pair<int, int>> bfs;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> grid[i][j];
			redgreengrid[i][j] = grid[i][j];
			if (redgreengrid[i][j] == 'G')
			{
				redgreengrid[i][j] = 'R';
			}
		}
	}

	int area = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visit[i][j]) continue;
			char firstLetter = grid[i][j];
			bfs.push(pair<int, int>(i,j));
			visit[i][j] = true;

			while (bfs.size() > 0)
			{
				pair<int, int> front = bfs.front();
				bfs.pop();
				int x = front.first;
				int y = front.second;

				for (int d = 0; d < 4; d++)
				{
					if (isIn(x + dx[d], y + dy[d]))
					{
						if (!visit[x + dx[d]][y + dy[d]])
						{
							if (grid[x + dx[d]][y + dy[d]] == firstLetter)
							{
								bfs.push(pair<int, int>(x + dx[d], y + dy[d]));
								visit[x + dx[d]][y + dy[d]] = true;
							}
						}
					}
				}
			}
			area++;
		}
	}

	memset(visit, 0, 100 * 100);
	queue<pair<int, int>> rgBfs;
	int redGreenArea = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visit[i][j]) continue;
			char firstLetter = redgreengrid[i][j];
			rgBfs.push(pair<int, int>(i, j));
			visit[i][j] = true;

			while (rgBfs.size() > 0)
			{
				pair<int, int> front = rgBfs.front();
				rgBfs.pop();
				int x = front.first;
				int y = front.second;

				for (int d = 0; d < 4; d++)
				{
					if (isIn(x + dx[d], y + dy[d]))
					{
						if (!visit[x + dx[d]][y + dy[d]])
						{
							if (redgreengrid[x + dx[d]][y + dy[d]] == firstLetter)
							{
								rgBfs.push(pair<int, int>(x + dx[d], y + dy[d]));
								visit[x + dx[d]][y + dy[d]] = true;
							}
						}
					}
				}
			}
			redGreenArea++;
		}
	}
	
	cout << area << " " << redGreenArea;
	return 0;
}