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

int dx[] = { -1, 1, 0, 0, -1, -1, 1, 1 };
int dy[] = { 0, 0, -1, 1, -1, 1, -1, 1 };

//----------------------------------------------------

vector<vector<pi>>road;
vector<vector<pi>>back;
vector<int>time;
vector<int>inDegree;

void bfs(int start, int end) {
	queue<int>q;
	q.push(start);
	time[start] = 0;

	while (!q.empty()) {
		int now = q.front(); q.pop();
		if (now == end)return;

		for (int i = 0; i < road[now].size(); i++) {
			int next = road[now][i].first, cost = road[now][i].second;
			time[next] = max(time[next], time[now] + cost);
			if (--inDegree[next] == 0)q.push(next);
		}
	}
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M, a, b, cost, start, end;
	cin >> N >> M;

	road = vector<vector<pi>>(N + 1);
	back = vector<vector<pi>>(N + 1);
	time = vector<int>(N + 1, 0);
	inDegree = vector<int>(N + 1, 0);

	while (M--) {
		cin >> a >> b >> cost;
		road[a].push_back(pi(b, cost));
		inDegree[b]++;

		back[b].push_back(pi(a, cost));
	}

	cin >> start >> end;

	bfs(start, end);

	cout << time[end] << '\n';

	queue<int>q;
	vector<bool>visit(N + 1, false);
	q.push(end);
	int ans = 0;

	while (!q.empty()) {
		int now = q.front(); q.pop();
		if (now == start)break;

		for (int i = 0; i < back[now].size(); i++) {
			int pre = back[now][i].first, cost = back[now][i].second;
			if (time[pre] + cost == time[now]) {
				ans++;
				if (!visit[pre]) {
					visit[pre] = true;
					q.push(pre);
				}
			}
		}
	}

	cout << ans << '\n';

	return 0;
	

}