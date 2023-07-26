#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;

int distances[100003];
int n, k; 
int changes[] = {0, -1, 1};

#define INF 9999999

void dijkstra(int start){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;

    distances[start] = 0; // my distance is 0
    pq.push({0, start}); // put into priority queue

    while(!pq.empty()){
        int curNode = pq.top().second;
        int curDist = pq.top().first;
        pq.pop();

        for(int i = 0; i < 3; i++){
            int nxtNode;

            // decide next node 
            if(changes[i] == 0) nxtNode = 2 * curNode; // 2 times jump exception
            else nxtNode = curNode + changes[i]; 

            // zero case exception
            if(curNode == 0 && nxtNode == 0){
                continue;
            }
            
            // calculate distance
            int nxtDist = abs(changes[i]) + curDist; // move nearby costs 1 

            if(nxtNode >= 0 && (nxtNode <= n + 2 || nxtNode <= k + 2)){ // constrain from 0 to bigger number
                if(nxtDist < distances[nxtNode]){ // if distance is smaller
                    distances[nxtNode] = nxtDist; // change
                    pq.push({ nxtDist, nxtNode});
                }
            }
        }
    }
}

int main(){

    cin >> n >> k;
    memset(distances, INF, sizeof(int) * 100003);
 
    dijkstra(n);

    cout << distances[k];

    return 0;
}