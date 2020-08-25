#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;

    map<string, int>m;
    map<string, int>::iterator it;
    vector<int>v;

    for (int i = 0; i < clothes.size(); i++) {
        string a = clothes[i][0], b = clothes[i][1];
        it = m.find(b);
        if (it == m.end()) {
            m.insert(make_pair(b, v.size()));
            v.push_back(1);
        }
        else {
            v[it->second]++;
        }
    }

    for (int i = 0; i < v.size(); i++) {
        answer *= (v[i]+1);
    }

    return answer-1;
}

bool cmp(vector<string>a, vector<string>b) {
	if (a[1] == b[1])return a[0] < b[0];
	else return a[1] < b[1];
}

int solution2(vector<vector<string>> clothes) {
	int answer = 1;

	sort(clothes.begin(), clothes.end(), cmp);

	string s = "";
	int num = 0;

	for (int i = 0; i < clothes.size(); i++) {
		if (s == clothes[i][1]) {
			num++;
		}
		else {
			answer *= (num + 1);
			num = 1;
			s = clothes[i][1];
		}
	}
	answer *= (num + 1);

	return answer-1;
}
