#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string sol(int num) {
    if (num < 10) {
        return to_string(num);
    }
    else {
        if (num == 10)return "A";
        else if (num == 11)return "B";
        else if (num == 12)return "C";
        else if (num == 13)return "D";
        else if (num == 14)return "E";
        else if (num == 15)return "F";
    }
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    string a = "0";

    int num = 1;
    for (int i = 0; i < t; i++) {
        int idx = i * m + p;
        while (a.size() < idx) {
            int k = num;
            string b = "";
            while (k) {
                b += sol(k%n);
                k /= n;
            }
            num++;
            reverse(b.begin(), b.end());
            a += b;
        }
        answer += a[idx-1];
    }

    return answer;
}