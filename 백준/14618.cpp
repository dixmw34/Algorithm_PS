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

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, m, start, k;

	cin >> n >> m >> start >> k;

	vector<char>home(n + 1, '!');

	int a, b, c;

	for (int i = 0; i < k; ++i) {
		cin >> a;
		home[a] = 'A';
	}
	for (int i = 0; i < k; ++i) {
		cin >> a;
		home[a] = 'B';
	}

	vector<vector<pi>>l(n + 1);

	while (m--) {
		cin >> a >> b >> c;
		l[a].push_back(pi(b, c));
		l[b].push_back(pi(a, c));
	}

	vector<int>visit(n + 1, INF);
	int ans = INF;
	priority_queue<pi>pq;
	visit[start] = 0;
	pq.push(pi(0, start));

	while (!pq.empty()) {
		int cost = -pq.top().first, now = pq.top().second; pq.pop();
		if (visit[now] < cost)continue;
		for (int i = 0; i < l[now].size(); ++i) {
			int next = l[now][i].first, new_val = cost + l[now][i].second;
			if (visit[next] > new_val) {
				visit[next] = new_val;
				pq.push(pi(-new_val, next));
				if ((home[next] != '!') && (ans == INF || visit[ans] > new_val || (visit[ans] == new_val && home[ans] == 'B'))) {
					ans = next;
				}
			}
		}
	}

	if (ans == INF) {
		cout << -1 << '\n';
	}
	else {
		cout << home[ans] << '\n' << visit[ans] << '\n';
	}
	

	return 0;
}