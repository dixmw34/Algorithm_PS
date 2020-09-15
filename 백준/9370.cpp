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
const int Max = 8000000;
vector<vector<pi>>arr;

vector<int>visit_s;
vector<int>visit_g;
vector<int>visit_h;

void dji(int s, int g, int h) {

	visit_s = vector<int>(n + 1, Max);
	visit_s[s] = 0;
	priority_queue<pi>pq;
	pq.push(pi(0, s));
	while (!pq.empty()) {
		int now = pq.top().second, dis = -pq.top().first; pq.pop();
		if (visit_s[now] < dis)continue;

		for (int i = 0; i < arr[now].size(); ++i) {
			int next = arr[now][i].first, new_val = dis + arr[now][i].second;
			if (visit_s[next] > new_val) {
				visit_s[next] = new_val;
				pq.push(pi(-new_val, next));
			}
		}
	}

	visit_g = vector<int>(n + 1, Max);
	visit_g[g] = 0;
	pq.push(pi(0, g));
	while (!pq.empty()) {
		int now = pq.top().second, dis = -pq.top().first; pq.pop();
		if (visit_g[now] < dis)continue;

		for (int i = 0; i < arr[now].size(); ++i) {
			int next = arr[now][i].first, new_val = dis + arr[now][i].second;
			if (visit_g[next] > new_val) {
				visit_g[next] = new_val;
				pq.push(pi(-new_val, next));
			}
		}
	}

	visit_h = vector<int>(n + 1, Max);
	visit_h[h] = 0;
	pq.push(pi(0, h));
	while (!pq.empty()) {
		int now = pq.top().second, dis = -pq.top().first; pq.pop();
		if (visit_h[now] < dis)continue;

		for (int i = 0; i < arr[now].size(); ++i) {
			int next = arr[now][i].first, new_val = dis + arr[now][i].second;
			if (visit_h[next] > new_val) {
				visit_h[next] = new_val;
				pq.push(pi(-new_val, next));
			}
		}
	}
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	int cnt, m, t, s, g, h, a, b, d, dis;

	cin >> cnt;
	while (cnt--) {
		dis = INF;

		cin >> n >> m >> t >> s >> g >> h;

		arr = vector<vector<pi>>(n + 1);

		while (m--) {
			cin >> a >> b >> d;
			arr[a].push_back(pi(b, d));
			arr[b].push_back(pi(a, d));
			if ((a == g && b == h) || (a == h && b == g))dis = min(dis, d);
		}

		dji(s, g, h);

		priority_queue<int>pq;
		while (t--) {
			cin >> a;

			if (a == g || a == h) {
				if ((visit_s[a] == visit_s[g] + dis) || (visit_s[a] == visit_s[h] + dis))pq.push(-a);
			}
			else {
				if ((visit_s[a] == visit_s[g] + dis + visit_h[a]) || (visit_s[a] == visit_s[h] + dis + visit_g[a]))pq.push(-a);
			}
			
		}

		while (!pq.empty()) {
			cout << -pq.top() << ' ';
			pq.pop();
		}
		cout << '\n';




	}

	return 0;

}