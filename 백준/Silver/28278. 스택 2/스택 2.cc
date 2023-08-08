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

        switch(num){
            case 1: 
                int tmp;
                cin >> tmp;
                myStack.push(tmp);
                break;
            case 2:
                if(myStack.empty()){
                    cout << -1 << "\n";
                }
                else{
                    cout << myStack.top() << "\n";
                    myStack.pop();
                }
                break;
            case 3:
                cout << myStack.size() << "\n";
                break;
            case 4:
                if(myStack.empty()){
                    cout << 1 << "\n";
                }
                else{
                    cout << 0 << "\n";
                }
                break;
            case 5:
                if(myStack.empty()){
                    cout << -1 << "\n";
                }
                else{
                    cout << myStack.top() << "\n";
                }
                break;
        }
    }

    return 0;
}