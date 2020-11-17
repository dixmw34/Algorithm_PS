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

vector<vector<pair<int, double>>>l(10000);
bool visit[10000];
double cost[10000];

void dij() {
	priority_queue<pair<double, int>>pq;
	pq.push(make_pair(-1.0, 0));

	while (!pq.empty()) {
		double val = -pq.top().first; int now = pq.top().second; pq.pop();

		if (visit[now] && cost[now] < val)continue;

		for (int i = 0; i < l[now].size(); ++i) {
			int next = l[now][i].first;
			double new_val = val * l[now][i].second;
			if (!visit[next] || cost[next] > new_val) {
				cost[next] = new_val;
				visit[next] = true;
				pq.push(make_pair(-new_val, next));
			}
		}
	}
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int n, m, a, b;
		double c;
		cin >> n >> m;

		while (m--) {
			cin >> a >> b >> c;
			l[a].push_back(make_pair(b, c));
			l[b].push_back(make_pair(a, c));
		}

		memset(visit, 0, sizeof(visit));

		visit[0] = true; cost[0] = 1.0;

		dij();
		printf("%.10lf\n", cost[n - 1]);

		for (int i = 0; i < n; ++i)l[i].clear();
	}


	return 0;

}