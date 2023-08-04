#include <iostream>
#include <cstring>
#include <utility>
#include <queue>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define INF 9999999
int distances[801];
int graph[801][801];
int N, E;

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
    memset(graph, INF, sizeof(int) * 801 * 801);
    cin >> N >> E;

    for(int i = 0; i < E; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a][b] = c;
        graph[b][a] = c;
    }

    int v1, v2;
    cin >> v1 >> v2;

    memset(distances, INF, sizeof(int) * 801);
    dijkstra(1);
    memset(distances, INF, sizeof(int) * 801);
    dijkstra(v1);
    memset(distances, INF, sizeof(int) * 801);
    dijkstra(v2);

    int minLength = graph[1][v1] + graph[v1][v2] + graph[v2][N];
    int tmp = graph[1][v2] + graph[v2][v1] + graph[v1][N];
    
    if(minLength > tmp){
        minLength = tmp;
    }

    if(minLength >= INF){
        minLength = -1;
    }

    cout << minLength << "\n";

    return 0;
}