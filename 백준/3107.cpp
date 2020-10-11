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

int dx[] = { -1, 0, 1, 0, -1, -1, 1, 1 };
int dy[] = { 0, 1, 0, -1, -1, 1, -1, 1 };

//----------------------------------------------------

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	string s;
	cin >> s;
	s += ':';
	vector<string>ans(1);
	int idx = 0, rule = -1;

	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == ':') {
			if (ans[idx].size() == 0)rule = idx;
			while (ans[idx].size() < 4)ans[idx] = "0" + ans[idx];
			idx++;
			ans.push_back({});
		}
		else ans[idx] = ans[idx] + s[i];
	}
	while (idx < 8) {
		ans.insert(ans.begin() + rule, "0000");
		idx++;
	}
	for (int i = 0; i < 8; ++i) {
		cout << ans[i];
		if (i != 7)cout << ':';
	}
	cout << '\n';

	return 0;

}