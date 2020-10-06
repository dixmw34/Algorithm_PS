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

int dx[] = { -1, 0, 1, 0, -1, -1, 1, 1 };
int dy[] = { 0, 1, 0, -1, -1, 1, -1, 1 };

//----------------------------------------------------

int ax[] = { 0, -1, 1, 0, 0 };
int ay[] = { 0, 0, 0, -1, 1 };

int n, ans = INF, arr[10][10];
bool visit[10][10];

void dfs(int now, int cnt, int cost) {
	if (cnt == 3) {
		ans = min(ans, cost);
		return;
	}

	while (now < n*n) {
		int x = now / n, y = now % n;
		if (x == 0 || x == n - 1 || y == 0 || y == n - 1 || visit[x][y]) {
			++now;
			continue;
		}
		bool flag = true;
		for (int i = 0; i < 5; ++i) {
			if (visit[x + ax[i]][y + ay[i]])flag = false;
		}
		if (flag) {
			for (int i = 0; i < 5; ++i) {
				visit[x + ax[i]][y + ay[i]] = true;
				cost += arr[x + ax[i]][y + ay[i]];
			}
			dfs(now + 2, cnt + 1, cost);
			for (int i = 0; i < 5; ++i) {
				visit[x + ax[i]][y + ay[i]] = false;
				cost -= arr[x + ax[i]][y + ay[i]];
			}
		}
		++now;
	}
	if (now >= n * n)return;
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> arr[i][j];
		}
	}

	memset(visit, 0, sizeof(visit));

	dfs(n + 1, 0, 0);

	cout << ans << '\n';

	return 0;

}