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

int par[500];

int find(int x) {
	if (par[x] == x)return x;
	return par[x] = find(par[x]);
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, m, a, b;
		cin >> n >> m;
		vector<pi>p(n);
		for (int i = 0; i < n; ++i)cin >> p[i].first;
		for (int i = 0; i < n; ++i) {
			cin >> p[i].second;
			par[i] = i;
		}
		while (m--) {
			cin >> a >> b;
			a = find(a); b = find(b);
			par[a] = par[b] = min(a, b);
		}
		priority_queue<ppi>pq;
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				a = find(i); b = find(j);
				if (a != b) {
					int l = pow(p[i].first - p[j].first, 2) + pow(p[i].second - p[j].second, 2);
					pq.push(ppi(-l, pi(i, j)));
				}
			}
		}
		double ans = 0.0;
		while (!pq.empty()) {
			double l = -pq.top().first;
			a = pq.top().second.first, b = pq.top().second.second; pq.pop();
			a = find(a); b = find(b);
			if (a != b) {
				par[a] = par[b] = min(a, b);
				ans += sqrt(l);
			}
		}

		printf("%.10lf\n", ans);

	}


	return 0;

}