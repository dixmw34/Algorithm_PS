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
vector<int>visit;
vector<int>d;

int dij(int start, int end) {
	priority_queue<pi, vector<pi>, greater<pi>>pq;
	pq.push(pi(0, start));
	visit[start] = 0;

	while (!pq.empty()) {
		int now = pq.top().second, cost = pq.top().first; pq.pop();
		if (now == end)return cost;
		if (visit[now] < cost)continue;

		for (int i = 0; i < road[now].size(); i++) {
			int next = road[now][i].first;
			int new_val = cost + road[now][i].second;
			if (visit[next] > new_val) {
				visit[next] = new_val;
				pq.push(pi(new_val, next));
				d[next] = now;
			}
		}
	}

}


int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m, a, b, cost, start, end;
	stack<int>s;

	cin >> n >> m;

	road = vector<vector<pi>>(n + 1);
	d = vector<int>(n + 1, -1);
	visit = vector<int>(n + 1, INF);

	while (m--) {
		cin >> a >> b >> cost;
		road[a].push_back(pi(b, cost));
	}

	cin >> start >> end;

	cout << dij(start, end) << '\n';

	for (int i = end; i != -1; i = d[i]) {
		s.push(i);
	}

	cout << s.size() << '\n';

	while (!s.empty()) {
		cout << s.top() << ' ';
		s.pop();
	}
	cout << '\n';


	return 0;
	

}