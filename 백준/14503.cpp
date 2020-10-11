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

const int Mod = 20091101;

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	int n, m, x, y, d;
	cin >> n >> m >> x >> y >> d;
	vector<vector<int>>arr(n, vector<int>(m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> arr[i][j];
		}
	}

	vector<vector<int>>visit(n, vector<int>(m, false));
	int ans = 0;
	while (1) {
		if (arr[x][y] == 0 && !visit[x][y]) {
			visit[x][y] = true;
			ans++;
		}
		bool flag = false;
		for (int i = 0; i < 4; ++i) {
			d = (d - 1 + 4) % 4;
			if (arr[x + dx[d]][y + dy[d]] == 0 && !visit[x + dx[d]][y + dy[d]]) {
				flag = true;
				break;

			}
		}
		if (flag) {
			x = x + dx[d], y = y + dy[d];
			continue;
		}
		int back = (d + 2) % 4;
		if (arr[x + dx[back]][y + dy[back]] == 1) {
			cout << ans << '\n';
			return 0;
		}
		x = x + dx[back], y = y + dy[back];
	}

	return 0;

}