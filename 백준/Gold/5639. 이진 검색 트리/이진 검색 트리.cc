#include <iostream>
#include <vector>
using namespace std;

vector<int> tree;

void printPostOrder(int curIdx, int maxIdx){
    if(curIdx >= tree.size()){
        return;
    }
    
    int curNumber = tree[curIdx];
    int bigIdx = maxIdx;
    
    for(int i = curIdx; i<maxIdx; i++){
        if(curNumber < tree[i]){
            bigIdx = i;
            break;
        }
    }

    // cout << curNumber << " " << curIdx << " " << bigIdx << " " << maxIdx << "\n";

    if(tree[curIdx + 1] < curNumber){
        printPostOrder(curIdx + 1, bigIdx); // left
    }

    if(bigIdx != maxIdx){
        printPostOrder(bigIdx, maxIdx); // right
    }

    cout << curNumber << "\n";
}

int main(){

    while(!cin.eof()){
        int key;
        cin >> key;
        tree.push_back(key);
    }

    printPostOrder(0, tree.size());
    
    return 0;
}