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

const ll Min = -100000000000;

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, s, e, m, a, b;
	ll c;
	cin >> n >> s >> e >> m;

	vector<ll>cost(n, Min);
	vector<ll>city(n);
	vector<vector<pair<int, ll>>>l(n);
	vector<vector<int>>back(n);

	while (m--) {
		cin >> a >> b >> c;
		l[a].push_back(make_pair(b, c));
		back[b].push_back(a);
	}
	for (int i = 0; i < n; ++i)cin >> city[i];

	bool is_cycle = false;
	vector<bool>arrived(n, false);
	queue<int>q;
	q.push(e); arrived[e] = true;
	while (!q.empty()) {
		int now = q.front(); q.pop();
		for (int i = 0; i < back[now].size(); ++i) {
			int next = back[now][i];
			if (!arrived[next]) {
				arrived[next] = true;
				q.push(next);
			}
		}
	}

	cost[s] = city[s];

	for (int k = 0; k <= n; ++k) {
		for (int i = 0; i < n; ++i) {
			if (cost[i] == Min)continue;
			for (int j = 0; j < l[i].size(); ++j) {
				int next = l[i][j].first;
				ll new_val = cost[i] - l[i][j].second + city[next];
				if (new_val > cost[next]) {
					cost[next] = new_val;
					if (k == n && arrived[next])is_cycle = true;
				}
			}
		}
	}

	if (is_cycle) {
		cout << "Gee\n";
	}
	else {
		if (cost[e] == Min)cout << "gg\n";
		else cout << cost[e] << '\n';
	}


	return 0;
}