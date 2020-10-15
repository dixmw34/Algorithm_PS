#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <map>
#include <unordered_map>
#include <set>
#include <climits>
#include <string.h>
#include <iomanip>

#define INF 987654321

using namespace std;

typedef pair<int, int> pi;
typedef pair<int, pair<int, int>>ppi;
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;

int dx[] = { 0, 0, -1, 1, -1, -1, 1, 1 };
int dy[] = { 1, -1, 0, 0, -1, 1, -1, 1 };

//----------------------------------------------------

map<string, string>dic;
map<string, int>show;

void insert(string s, int cnt) {
	for (int i = 1; i <= s.size(); ++i) {
		string test = dic[s.substr(0, i)];
		if (show[test] < cnt) {
			dic[s.substr(0, i)] = s;
		}
		else if (show[test] == cnt) {
			dic[s.substr(0, i)] = min(test, s);
		}
	}
}

int sol(string s) {
	for (int i = 1; i < s.size(); ++i) {
		map<string, string>::iterator it = dic.find(s.substr(0, i));
		if (it == dic.end()) {
			break;
		}
		if (it->second == s) {
			return i + 1;
		}
	}
	return s.size();
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	int c;
	cin >> c;
	while (c--) {
		int n, m, cnt;
		string s, total;
		cin >> n >> m;
		while (n--) {
			cin >> s >> cnt;
			insert(s, cnt);
			show[s] = cnt;
		}
		int ans = 0;
		s = "";
		cin.ignore();
		getline(cin, total, '\n');
		for (int k = 0; k < total.size(); ++k) {
			if (total[k] != ' ')s += total[k];
			else {
				ans++;
				if (s != "") {
					ans += sol(s);
					s = "";
				}
			}
		}
		if (s != "") {
			ans += sol(s);
		}

		cout << ans << '\n';
		dic.clear();
		show.clear();
	}
	

	return 0;

}