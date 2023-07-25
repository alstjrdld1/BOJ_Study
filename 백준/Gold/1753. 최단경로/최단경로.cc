#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <cstring>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define INF 9999999

int V, E;

int distances[20001];
vector<pair<int, int>> graph[20001];

// 시작 위치와 정점의 개수, 인접 행렬을 받아
// 최소 거리 행렬을 반환함
void dijkstra(int start)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;  // 우선순위 큐 선언

	distances[start] = 0;  // 시작 노드 거리를 0으로 함
	pq.push({ 0, start });  // 우선순위 큐에 넣기

	while (!pq.empty())
	{
		int cur_dist = pq.top().first; // 큐에서 꺼내 방문하고 있는 정점의 거리
		int cur_node = pq.top().second;  // 정점의 인덱스(번호)
		pq.pop();

		for (int i = 0; i < graph[cur_node].size(); i++)
		{
			if (graph[cur_node][i].second == INF) continue;

			int nxt_node = graph[cur_node][i].first;  // 인접 정점 번호
			int nxt_dist = cur_dist + graph[cur_node][i].second;  // 인접 정점까지 거리

			if (nxt_dist < distances[nxt_node])  // 지금 계산한 것이 기존 거리값보다 작다면
			{
				distances[nxt_node] = nxt_dist;  // 거리값 업데이트
				pq.push({ nxt_dist, nxt_node });  // 우선순위 큐에 넣기
			}
		}
	}
}

int main() {
	fastio;

	cin >> V >> E;
	for (int i = 0; i <= V; i++) {
		distances[i] = INF;
	}

	int start;
	cin >> start;

	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;

		graph[u].push_back({ v, w });
	}

	dijkstra(start);

	for (int i = 1; i <= V; i++) {
		if (i == start) {
			cout << 0 << "\n";
			continue;
		}
		int result = distances[i];

		if (result == INF) {
			cout << "INF" << "\n";
		}
		else {
			cout << result << "\n";
		}
	}

	return 0;
}