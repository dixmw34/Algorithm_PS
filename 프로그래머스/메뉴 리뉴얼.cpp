#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) {
	vector<string> answer;
	vector<int>cnt(11, 0);

	map<string, int>m;

	for (int i = 0; i < orders.size(); ++i) {
		string s = orders[i];
        sort(s.begin(), s.end());
		for (int j = 0; j < course.size(); ++j) {
			if (s.size() < course[j])
				break;
			vector<bool>v(s.size(), true);
			for (int k = 0; k < course[j]; ++k)v[k] = false;
			do {
				string a = "";
				for (int k = 0; k < v.size(); ++k) {
					if (!v[k])a += s[k];
				}
				map<string, int>::iterator it = m.find(a);
				if (it == m.end()) {
					m[a] = 1;
				}
				else{
					it->second++;
					cnt[a.size()] = max(cnt[a.size()], it->second);
				}
			} while (next_permutation(v.begin(), v.end()));
		}
	}

	for (auto x : m) {
		if (cnt[x.first.size()] == x.second && x.second >= 2) {
			answer.push_back(x.first);
		}
	}

	sort(answer.begin(), answer.end());
	return answer;
}