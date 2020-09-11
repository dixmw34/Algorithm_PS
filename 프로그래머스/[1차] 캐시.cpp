#include <string>
#include <vector>
#include <deque>
#include <map>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    int n = cities.size();
    map<string, int>m;

    if (cacheSize == 0)return n * 5;

    for (int i = 0; i < n; i++) {
        string a = cities[i];
        for (int k = 0; k < a.size(); k++) {
            if (a[k] <= 'Z')a[k] += ('a' - 'A');
        }
        if (m.size() < cacheSize) {
            if (m.find(a) == m.end()) {
                answer += 5;
                m.insert(make_pair(a, i));
            }
            else {
                answer += 1;
                m.find(a)->second = i;
            }
        }
        else {
            if (m.find(a) == m.end()) {
                int num = i;
                string b;
                for (auto x : m) {
                    if (x.second < num) {
                        num = x.second;
                        b = x.first;
                    }
                }
                m.erase(m.find(b));
                answer += 5;
                m.insert(make_pair(a, i));
            }
            else {
                answer += 1;
                m.find(a)->second = i;
            }
        }
    }


    return answer;
}