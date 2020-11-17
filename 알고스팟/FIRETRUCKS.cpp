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

int visit[1001];
vector<vector<pi>>l(1001);

void bfs(int start) {
	visit[start] = 0;
	priority_queue<pi>pq;
	pq.push(pi(0, start));
	while (!pq.empty()) {
		int now = pq.top().second, cost = -pq.top().first; pq.pop();
		if (visit[now] < cost)continue;
		for (int i = 0; i < l[now].size(); ++i) {
			int next = l[now][i].first, new_val = cost + l[now][i].second;
			if (visit[next] == -1 || visit[next] > new_val) {
				visit[next] = new_val;
				pq.push(pi(-new_val, next));
			}
		}
	}
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int v, e, n, m, a, b, c, start;
		cin >> v >> e >> n >> m;
		while (e--) {
			cin >> a >> b >> c;
			l[a].push_back(pi(b, c));
			l[b].push_back(pi(a, c));
		}

		vector<int>fire(n);
		for (int i = 0; i < n; ++i)cin >> fire[i];

		cin >> start; m--;
		while (m--) {
			cin >> a;
			l[start].push_back(pi(a, 0));
		}

		memset(visit, -1, sizeof(visit));

		bfs(start);

		int result = 0;
		for (int i = 0; i < n; ++i)result += visit[fire[i]];
		cout << result << '\n';

		for (int i = 1; i <= v; ++i)l[i].clear();
	}


	
	return 0;

}