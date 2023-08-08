#include <iostream>
#include <stack>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main(){
    fastio;
    int N;
    cin >> N;

    stack<int> myStack;

    for(int i = 0; i < N; i++){
        int num;
        cin >> num;

        if(num == 1){
            int tmp;
            cin >> tmp;
            myStack.push(tmp);
        }
        else if(num == 2){
            if(myStack.empty()){
                cout << -1 << "\n";
            }
            else{
                cout << myStack.top() << "\n";
                myStack.pop();
            }
        }
        else if(num == 3){
            cout << myStack.size() << "\n";
        }
        else if(num == 4){
            if(myStack.empty()){
                cout << 1 << "\n";
            }
            else{
                cout << 0 << "\n";
            }
        }
        else if(num == 5){
            if(myStack.empty()){
                cout << -1 << "\n";
            }
            else{
                cout << myStack.top() << "\n";
            }
        }
    }

    return 0;
}