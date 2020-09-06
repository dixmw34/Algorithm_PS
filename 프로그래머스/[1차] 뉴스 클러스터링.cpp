#include <string>
#include <map>
#include <algorithm>

using namespace std;

bool test(char ch) {
    if (ch >= 'a'&& ch <= 'z')return true;
    else return false;
}

int solution(string str1, string str2) {
    int answer = 0;
    map<string, int>m1;
    map<string, int>m2;
    for (int i = 0; i < str1.size(); i++) {
        if (str1[i] >= 'A'&& str1[i] <= 'Z')str1[i] += ('a' - 'A');
    }
    for (int i = 0; i < str2.size(); i++) {
        if (str2[i] >= 'A'&& str2[i] <= 'Z')str2[i] += ('a' - 'A');
    }

    for (int i = 0; i < str1.size()-1; i++) {
        if (test(str1[i]) && test(str1[i + 1])) {
            m1[str1.substr(i, 2)]++;
        }
    }
    for (int i = 0; i < str2.size() - 1; i++) {
        if (test(str2[i]) && test(str2[i + 1])) {
            m2[str2.substr(i, 2)]++;
        }
    }

    int Min = 0, Max = 0;

    for (auto x : m1) {
        Min += min(m1[x.first], m2[x.first]);
        Max += max(m1[x.first], m2[x.first]);
    }
    for (auto y : m2) {
        if (m1[y.first] == 0)Max += y.second;
    }

    if (Max == 0)return 65536;
    return 65536*Min/Max;
}