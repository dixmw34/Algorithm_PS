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

int n, m;

struct plane
{
	int end;
	int cost;
	int time;
};

vector<vector<plane>>arr;
vector<vector<int>>visit;

void dij(int start) {
	visit = vector<vector<int>>(n + 1, vector<int>(m + 1, INF));
	visit[start][0] = 0;
	queue<plane>q;
	q.push(plane{ start, 0, 0 });

	while (!q.empty()) {
		int now = q.front().end, cost = q.front().cost, time = q.front().time; q.pop();

		if (visit[now][cost] < time)continue;

		for (int i = 0; i < arr[now].size(); i++) {
			int next = arr[now][i].end, add_time = arr[now][i].time, add_cost = arr[now][i].cost;
			if (cost + add_cost > m)continue;
			if (visit[next][cost + add_cost] > time+add_time) {
				visit[next][cost + add_cost] = time + add_time;
				q.push(plane{next, cost + add_cost , time + add_time });
			}
		}
	}
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t, k, a, b, c, d;
	cin >> t;
	while (t--) {
		cin >> n >> m >> k;
		arr = vector<vector<plane>>(n + 1);
		while (k--) {
			cin >> a >> b >> c >> d;
			arr[a].push_back(plane{ b, c, d });
		}
		dij(1);


		int ans = INF;
		for (int i = 0; i <= m; i++) {
			ans = min(ans, visit[n][i]);
		}
		if (ans == INF)cout << "Poor KCM\n";
		else cout << ans << '\n';
	}

	return 0;

}