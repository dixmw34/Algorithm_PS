#include <string>
#include <vector>

using namespace std;

bool test(string a) {
    int num = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == '(')num++;
        else {
            if (num == 0)return false;
            num--;
        }
    }
    return true;
}

string solution(string p) {
    string answer = "";
    string u = "", v = "";
    int num = 0;

    for (int i = 0; i < p.size(); i++) {
        if (p[i] == '(')num++;
        else num--;
        u += p[i];
        if (num == 0) {
            if (test(u)) {
                answer += u;
                u = "";
            }
            else {
                answer += '(';
                v = solution(p.substr(i + 1, p.size() - i));
                answer += v;
                answer += ')';
                for (int j = 1; j < u.size() - 1; j++) {
                    if (u[j] == '(')answer += ')';
                    else answer += '(';
                }
                return answer;
            }
        }
    }
    return answer;
}