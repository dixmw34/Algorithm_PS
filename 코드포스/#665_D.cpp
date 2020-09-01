#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <map>
#include <set>

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

const ll MOD = 1e9 + 7;

vector<vector<int>>link(100000);
vector<ll>e;
ll n;

ll dfs(int now, int anc) {
	ll x = 0;
	for (int i = 0; i < link[now].size(); i++) {
		int next = link[now][i];
		if (next == anc)continue;
		ll y = dfs(next, now);
		e.push_back(y*(n - y));
		x += y;
	}
	return x + 1;
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t, m, a, b;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i < n; i++) {
			cin >> a >> b;
			a--; b--;
			link[a].push_back(b);
			link[b].push_back(a);
		}

		cin >> m;
		vector<ll>p(m);
		for (int i = 0; i < m; i++) cin >> p[i];

		dfs(0, -1);

		if (e.size() > p.size()) {
			while (e.size() > p.size())p.push_back(1);
		}

		sort(e.begin(), e.end());
		sort(p.begin(), p.end());

		if (e.size() < p.size()) {
			for (int i = e.size(); i < p.size(); i++) {
				p[e.size() - 1] = (p[e.size() - 1] * p[i]) % MOD;
			}
		}
		ll ans = 0;
		for (int i = 0; i < e.size(); i++) {
			ans = (ans + ((e[i] * p[i]) % MOD)) % MOD;
		}
		cout << ans << '\n';
		for (int i = 0; i < n; i++)link[i].clear();
		e.clear();
	}


	return 0;

}