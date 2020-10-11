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

int n, par[100001][20], depth[100001];
vector<vector<int>>child(100001);

void dfs(int now, int anc) {
	par[now][0] = anc;
	depth[now] = depth[anc] + 1;
	for (int i = 0; i < child[now].size(); ++i) {
		dfs(child[now][i], now);
	}
}

void set_par() {
	for (int i = 1; i < 20; ++i) {
		for (int j = 0; j < n; ++j) {
			par[j][i] = par[par[j][i - 1]][i - 1];
		}
	}
}

int find(int x, int y) {
	if (depth[x] > depth[y])swap(x, y);
	for (int i = 19; i >= 0; --i) {
		if (depth[y] - depth[x] >= (1 << i))y = par[y][i];
	}
	if (x == y)return x;
	for (int i = 19; i >= 0; --i) {
		if (par[x][i] != par[y][i]) {
			x = par[x][i]; y = par[y][i];
		}
	}
	return par[x][0];
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	int c;
	cin >> c;
	while (c--) {
		int q, a, b;
		cin >> n >> q;
		depth[0] = -1;
		for (int i = 1; i < n; ++i) {
			cin >> a;
			child[a].push_back(i);
		}

		dfs(0, 0);
		set_par();

		while (q--) {
			cin >> a >> b;
			cout << depth[a] + depth[b] - depth[find(a, b)] * 2 << '\n';
		}
		for (int i = 0; i < n; ++i)child[i].clear();
	}

	return 0;

}