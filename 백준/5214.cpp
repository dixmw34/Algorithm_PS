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

vector<vector<int>>arr;
vector<int>visit;

void bfs(int n) {
	queue<int>q;
	q.push(0);
	while (!q.empty()) {
		int now = q.front(); q.pop();
		if (now == n - 1)return;

		for (int i = 0; i < arr[now].size(); ++i) {
			if (visit[arr[now][i]] == INF) {
				visit[arr[now][i]] = visit[now] + 1;
				q.push(arr[now][i]);
			}
		}
	}

}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	int n, k, m, a;
	cin >> n >> k >> m;

	arr = vector<vector<int>>(n + m);

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < k; ++j) {
			cin >> a;
			arr[a - 1].push_back(n + i);
			arr[n + i].push_back(a - 1);
		}
	}

	visit = vector<int>(n + m, INF);
	visit[0] = 1;

	bfs(n);

	if (visit[n - 1] == INF)cout << -1 << '\n';
	else cout << visit[n - 1] / 2 + 1 << '\n';


	return 0;

}