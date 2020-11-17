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

int a[52][52];

void bfs(int x, int y) {
	a[x][y] = 0;
	queue<pi>q;
	q.push(pi(x, y));
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second; q.pop();
		for (int i = 0; i < 4; ++i) {
			if (a[x + dx[i]][y + dy[i]] == 1) {
				a[x + dx[i]][y + dy[i]] = 0;
				q.push(pi(x + dx[i], y + dy[i]));
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
		int m, n, k, x, y;
		cin >> m >> n >> k;
		memset(a, 0, sizeof(a));
		while (k--) {
			cin >> x >> y;
			a[x + 1][y + 1] = 1;
		}
		int ans = 0;
		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (a[i][j] == 1) {
					ans++;
					bfs(i, j);
				}
			}
		}
		cout << ans << '\n';
	}
	

	return 0;

}