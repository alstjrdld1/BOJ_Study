#include <map>
#include <queue>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

map<int, vector<int>> graph;
bool visit[1001];
int connectedCount = 0;

int main()
{
	fastio;
	int N, M;
	cin >> N >> M;
	memset(visit, false, 1001);
	queue<int> myQ;

	for (int i = 0; i < N; i++)
	{
		graph[i + 1] = vector<int>();
	}

	for (int i = 0; i < M; i++)
	{
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 1; i <= N; i++)
	{
		if (visit[i]) continue;
		else
		{
			myQ.push(i);
			while (myQ.size() > 0)
			{
				int node = myQ.front();
				myQ.pop();
				visit[node] = true;

				for (int i = 0; i < graph[node].size(); i++)
				{
					if (visit[graph[node][i]]) continue;
					else
					{
						myQ.push(graph[node][i]);
						visit[graph[node][i]] = true;
					}
				}
			}
			connectedCount++;
		}
	}

	cout << connectedCount;

	return 0;
}