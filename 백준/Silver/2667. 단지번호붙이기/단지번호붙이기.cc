#include <queue>
#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <algorithm>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int N;
int** grid;
bool** visitMap;

int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };

bool isIn(int r, int c);

int main()
{
	fastio;
	cin >> N;

	grid = new int* [N];
	visitMap = new bool* [N];

	vector<int> houseNum;

	for (int i = 0; i < N; i++)
	{
		grid[i] = new int[N];
		visitMap[i] = new bool[N];
		string row;
		cin >> row;
		for (int j = 0; j < N; j++)
		{
			grid[i][j] = row[j] - 48;
			visitMap[i][j] = false;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visitMap[i][j] == true || grid[i][j] == 0) continue;
			queue<pair<int, int>> q;
			q.push(pair<int, int>(i, j));
			int danjiCount = 1;

			while (!q.empty())
			{
				pair<int, int> front = q.front();
				int r = front.first;
				int c = front.second;
				q.pop();
				visitMap[r][c] = true;
				
				for (int k = 0; k < 4; k++)
				{
					if (isIn(r + dr[k], c + dc[k]))
					{
						if (grid[r + dr[k]][c + dc[k]] == 1 && visitMap[r+dr[k]][c+dc[k]] != true)
						{
							q.push(pair<int, int>(r + dr[k], c + dc[k]));
							danjiCount++;
							visitMap[r + dr[k]][c + dc[k]] = true;
						}
					}
				}
			}
			houseNum.push_back(danjiCount);
		}
	}

	cout << houseNum.size() << "\n";

	sort(houseNum.begin(), houseNum.end());

	for (int i = 0; i < houseNum.size(); i++)
	{
		cout << houseNum[i] << "\n";
	}

	return 0;
}

bool isIn(int r, int c)
{
	if (r >= N || r < 0 || c < 0 || c >= N) return false;
	return true;
}