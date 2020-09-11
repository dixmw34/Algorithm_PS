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
#include <climits>

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

int n;

vector<vector<pi>>arr;
vector<vector<pi>>back;
vector<int>visit;

void dij(int start) {
	visit = vector<int>(n + 1, INF);
	visit[start] = 0;
	priority_queue<pi>pq;
	pq.push(pi(0, start));

	while (!pq.empty()) {
		int cost = -pq.top().first, now = pq.top().second; pq.pop();

		if (visit[now] < cost)continue;

		for (int i = 0; i < arr[now].size(); i++) {
			int next = arr[now][i].first, new_val = visit[now] + arr[now][i].second;
			if (visit[next] > new_val) {
				visit[next] = new_val;
				pq.push(pi(-new_val, next));
			}
		}

	}


}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int e, a, b, c, ans = INF;

	cin >> n >> e;
	arr = vector<vector<pi>>(n + 1);
	back = vector<vector<pi>>(n + 1);
	while (e--) {
		cin >> a >> b >> c;
		arr[a].push_back(pi(b, c));
		back[b].push_back(pi(a, c));
	}

	for (int i = 1; i < n; i++) {
		dij(i);
		for (int j = 0; j < back[i].size(); j++) {
			int pre = back[i][j].first, cost = back[i][j].second;
			ans = min(ans, visit[pre] + cost);
		}
	}

	if (ans == INF)cout << "-1\n";
	else cout << ans << '\n';

	return 0;

}