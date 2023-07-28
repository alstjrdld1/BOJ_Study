#include <iostream>
#include <cstring>
#include <queue>
#include <utility>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define INF 9999999
int distances[1001];
int costs[1001];
int graph[1001][1001];
int N, M, X, maxVal;

void dijkstra(int start){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    distances[start] = 0;
    pq.push({0, start});

    while(!pq.empty()){
        int curNode = pq.top().second;
        int curDist = pq.top().first;
        pq.pop();

        for(int i = 1 ; i <= N; i++){
            if(graph[curNode][i] == INF) continue;

            int nxtNode = i;
            int nxtDist = curDist + graph[curNode][i];

            if(nxtDist < distances[nxtNode]){
                distances[nxtNode] = nxtDist;
                pq.push({ nxtDist, nxtNode });
            }
        }
    }

    for(int i = 1; i <= N; i++){
        graph[start][i] = distances[i];
    }
}

int main(){
    fastio;
    memset(graph, INF, sizeof(int) * 1001 * 1001);
    memset(costs, 0, sizeof(int) * 1001);
    cin >> N >> M >> X;
    maxVal = 0;
    for(int i = 0; i < M; i++){
        int s, e, t;
        cin >> s >> e >> t;
        graph[s][e] = t;
    }

    for(int i = 1; i <= N; i++){
        memset(distances, INF, sizeof(int) * 1001);
        dijkstra(i);
    }

    for(int i = 1; i <= N; i++){
        costs[i] = graph[i][X] + graph[X][i];
        if(costs[i] > maxVal){
            maxVal = costs[i];
        }
    }
    
    cout << maxVal;

    return 0;
}