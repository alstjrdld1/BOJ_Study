#include <iostream>
#include <queue>
#include <utility>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXVAL 9999999

int** grid;
int** visit;
int** dist;

int n, m;
int target[2];
int dr[4] = { 0, 0, 1, -1 };
int dc[4] = { 1, -1, 0, 0 };

bool isIn(int r, int c)
{
	if (r < 0 || r >= n || c < 0 || c >= m) return false;
	return true;
}

void solve()
{
	// BFS
	queue<pair<int, int>> bfs;
	bfs.push(pair<int, int>(target[0], target[1]));
	visit[target[0]][target[1]] = 1;
	dist[target[0]][target[1]] = 0;

	while (bfs.size() > 0) {
		pair<int, int> front = bfs.front();
		int r = front.first;
		int c = front.second;
		bfs.pop();

		for (int i = 0; i < 4; i++)
		{
			if (isIn(r + dr[i], c + dc[i])) // out of range check
			{
				if (grid[r + dr[i]][c + dc[i]] == 1 && visit[r + dr[i]][c + dc[i]] == 0)
				{
					if (dist[r + dr[i]][c + dc[i]] > dist[r][c] + 1)
					{
						dist[r + dr[i]][c + dc[i]] = dist[r][c] + 1;
					}
					bfs.push(pair<int, int>(r + dr[i], c + dc[i]));
					visit[r + dr[i]][c + dc[i]] = 1;
				}
				else if (grid[r + dr[i]][c + dc[i]] == 0)
				{
					dist[r + dr[i]][c + dc[i]] = 0;
				}
			}
		}
	}
}

int main()
{
	fastio;
	cin >> n >> m;

	grid = new int* [n];
	dist = new int* [n];
	visit = new int* [n];
	for (int i = 0; i < n; i++)
	{
		grid[i] = new int[m];
		dist[i] = new int[m];
		visit[i] = new int[m];
		for (int j = 0; j < m; j++)
		{
			cin >> grid[i][j];
			dist[i][j] = MAXVAL;
			if (grid[i][j] == 2)
			{
				target[0] = i;
				target[1] = j;
			}
			else if(grid[i][j] == 0)
			{
				dist[i][j] = 0;
			}
			visit[i][j] = 0;
		}
	}

	solve();

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (dist[i][j] == MAXVAL) cout << -1 << " ";
			else cout << dist[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}