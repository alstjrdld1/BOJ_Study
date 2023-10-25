#include <queue>
#include <vector>
#include <iostream>
using namespace std;

typedef struct ThreePair
{
	int first;
	int second;
	int third;
} ThreePair;

int M, N, H;
vector<vector<vector<int>>> tomatoBox; // tomatoBox[H][M][N]
vector<vector<vector<bool>>> visit;

int dm[4] = {-1, 1, 0, 0};
int dn[4] = {0, 0, -1, 1};
int dh[2] = { -1, 1 };

bool isIn(int h, int m, int n)
{
	if (h < 0 || h >= H || m < 0 || m >= M || n < 0 || n >= N) return false;
	return true;
}

int main()
{
	bool allRipen = true;
	cin >> N >> M >> H;

	queue<ThreePair> q;

	for (int h = 0; h < H; h++)
	{
		vector<vector<int>> hthBox;
		vector<vector<bool>> hthVisit;
		for (int m = 0; m < M; m++)
		{
			vector<int> row;
			vector<bool> visitRow;

			for (int n = 0; n < N; n++)
			{
				int tomatoStatus;
				cin >> tomatoStatus;
				row.push_back(tomatoStatus);
				visitRow.push_back(false);

				if (tomatoStatus == 0) allRipen = false;
				else if (tomatoStatus == 1)
				{
					q.push(ThreePair({ h, m, n }));
					visitRow[n] = true;
				}
			}
			hthBox.push_back(row);
			hthVisit.push_back(visitRow);
		}
		tomatoBox.push_back(hthBox);
		visit.push_back(hthVisit);
	}

	int day = 0;
	while (q.size() > 0)
	{
		int qSize = q.size();
		for (int qs = 0; qs < qSize; qs++)
		{
			ThreePair front = q.front();
			int h = front.first;
			int m = front.second;
			int n = front.third;
			q.pop();

			for (int i = 0; i < 4; i++) // M, N neighbor
			{
				if (isIn(h, m + dm[i], n + dn[i]))
				{
					if (visit[h][m + dm[i]][n + dn[i]] || tomatoBox[h][m + dm[i]][n + dn[i]] == -1) continue;
				
					tomatoBox[h][m + dm[i]][n + dn[i]] = 1;
					visit[h][m + dm[i]][n + dn[i]] = true;
					q.push(ThreePair({ h, m + dm[i], n + dn[i] }));
				}
			}

			for (int i = 0; i < 2; i++) // h neighbor
			{
				if (isIn(h + dh[i], m, n))
				{
					if (visit[h + dh[i]][m][n] || tomatoBox[h + dh[i]][m][n] == -1) continue;

					tomatoBox[h + dh[i]][m][n] = 1;
					visit[h + dh[i]][m][n] = true;
					q.push(ThreePair({ h + dh[i], m, n}));
				}
			}
		}

		/*
		for (int h1 = 0; h1 < H; h1++)
		{
			for (int m1 = 0; m1 < M; m1++)
			{

				for (int n1 = 0; n1 < N; n1++)
				{
					cout << visit[h1][m1][n1] << " ";
				}
				cout << "\n";
			}
			cout << "\n";
		}
		cout << "==================================" << "\n";
		*/
		day++;
	}

	if (allRipen)
	{
		cout << 0;
		return 0;
	}

	for (int h1 = 0; h1 < H; h1++)
	{
		for (int m1 = 0; m1 < M; m1++)
		{
			for (int n1 = 0; n1 < N; n1++)
			{
				if (tomatoBox[h1][m1][n1] == -1) continue; 
				if (!visit[h1][m1][n1])
				{
					cout << -1; 
					return 0;
				}
			}
		}
	}

	cout << day-1;

	return 0;
}