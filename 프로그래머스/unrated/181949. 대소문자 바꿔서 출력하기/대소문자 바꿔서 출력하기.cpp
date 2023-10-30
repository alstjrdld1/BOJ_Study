#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str;
    cin >> str;
    for(int i = 0; i < str.size(); i++)
    {
        if (str[i] < 96) // 대문자 
        {
            cout << char(32+str[i]);
        }
        else if(str[i] >96) // 소문자
        {
            cout << char(str[i] - 32);
        }
    }
    return 0;
}