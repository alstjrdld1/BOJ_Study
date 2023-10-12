#include <queue>
#include <utility>
#include <iostream>
using namespace std;

int N, M;
char** campus;
bool** visit;
queue<pair<int, int>> q;

int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };

bool isIn(int r, int c)
{
	if (r < 0 || r >= N || c < 0 || c >= M) return false;
	return true;
}

int main()
{
	int people = 0;
	cin >> N >> M;
	
	campus = new char* [N];
	visit = new bool* [N];
	for (int i = 0; i < N; i++)
	{
		campus[i] = new char[M];
		visit[i] = new bool[M];
		for (int j = 0; j < M; j++)
		{
			cin >> campus[i][j];
			visit[i][j] = false;
			if (campus[i][j] == 'I')
			{
				q.push(pair<int, int>(i, j));
				visit[i][j] = true;
			}
		}
	}

	while (!q.empty())
	{
		pair<int, int> front = q.front();
		int r = front.first;
		int c = front.second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			if (isIn(r + dr[i], c + dc[i]))
			{
				if (visit[r + dr[i]][c + dc[i]] || campus[r+dr[i]][c+dc[i]] == 'X') continue;
				else
				{
					q.push(pair<int, int>(r + dr[i], c + dc[i]));
					visit[r + dr[i]][c + dc[i]] = true;
					if (campus[r + dr[i]][c + dc[i]] == 'P')
					{
						people++;
					}
				}
			}
		}
	}

	if (people == 0)
	{
		cout << "TT";
	}
	else
	{
		cout << people;
	}

	return 0;
}