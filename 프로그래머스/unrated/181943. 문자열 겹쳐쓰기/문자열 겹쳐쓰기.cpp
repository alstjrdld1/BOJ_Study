#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string overwrite_string, int s) {
    string answer = "";
    answer += my_string.substr(0, s) + overwrite_string;
    int owsLen = overwrite_string.length();
    if(my_string.length() > (s + owsLen))
    {
        answer += my_string.substr(s+owsLen, my_string.length());
    }
    
    return answer;
}