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

int dp[101][101], n;
vector<vector<pi>>tree(101);
bool visit[101];

void sol(int now, int par, int cnt) {
	if (tree[now].size() == 0) {
		dp[par][now] += cnt;
		return;
	}
	else {
		if (visit[now])return;
		visit[now] = true;
		for (int i = 0; i < tree[now].size(); ++i) {
			pi p = tree[now][i];
			sol(p.first, now, p.second);
			if (!visit[p.first])continue;
			for (int k = 1; k < n; ++k) {
				dp[now][k] += dp[p.first][k] * p.second;
			}
		}
	}
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int m, x, y, k;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		cin >> x >> y >> k;
		tree[x].push_back(pi(y, k));
	}
	memset(visit, 0, sizeof(visit));
	sol(n, -1, 1);
	for (int i = 1; i < n; ++i) {
		if (dp[n][i]) {
			cout << i << ' ' << dp[n][i] << '\n';
		}
	}
	

	return 0;
}