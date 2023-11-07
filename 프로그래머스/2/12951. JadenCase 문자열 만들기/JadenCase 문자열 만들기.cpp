#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    bool largeFlag = true;
    int smallCapGap = 'a' - 'A';
    
    for(int i = 0; i < s.size(); i++)
    {
        if((s[i] - '0' >= 0) && (s[i] - '0' <= 9)) // number 
        {
            answer += s[i];
            if(largeFlag) 
            {
                largeFlag = false;
            }
        }
        
        else if((s[i] - 'a' >= 0) && (s[i] - 'a' <= 'z'-'a')) // smaller case 
        {
            if(largeFlag)
            {
                answer += (s[i] - smallCapGap);
                largeFlag = false;
            }
            else if(!largeFlag)
            {
                answer += s[i];
            }
        }
        
        else if((s[i] - 'A' >= 0) && (s[i] - 'A' <= 'Z'-'A')) // Capital
        {
            if(largeFlag)
            {
                answer += s[i];
                largeFlag = false;
            }
            else if(!largeFlag)
            {
                answer += (s[i] + smallCapGap);
            }
        }
        else if(s[i] == ' ')
        {
            largeFlag = true;
            answer += s[i];            
        }
    }
    
    return answer;
}