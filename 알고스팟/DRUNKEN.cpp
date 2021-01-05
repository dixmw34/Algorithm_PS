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

	int n, m;
	cin >> n >> m;
	vector<pi>_time(n);
	for (int i = 0; i < n; ++i) {
		cin >> _time[i].first;
		_time[i].second = i;
	}
	vector<vector<int>>road(n, vector<int>(n, INF));
	vector<vector<int>>ans(n, vector<int>(n, INF));
	int a, b, c;
	while (m--) {
		cin >> a >> b >> c;
		a--, b--;
		road[a][b] = road[b][a] = ans[a][b] = ans[b][a] = c;
	}

	sort(_time.begin(), _time.end());
	for (int k = 0; k < n; ++k) {
		a = _time[k].second;
		int t = _time[k].first;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (i == j)continue;
				road[i][j] = min(road[i][j], road[i][a] + road[a][j]);
				ans[i][j] = min(ans[i][j], road[i][a] + road[a][j] + t);
			}
		}
	}

	int t;
	cin >> t;
	while (t--) {
		cin >> a >> b;
		if (a == b)cout << 0 << '\n';
		else cout << ans[a - 1][b - 1] << '\n';
	}
	


	return 0;
}