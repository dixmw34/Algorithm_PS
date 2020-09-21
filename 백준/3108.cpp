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

vector<vector<int>>arr(2001, vector<int>(2001, 0));
int ans = 0;

void bfs(int a, int b) {
	++ans;
	arr[a][b] = -arr[a][b];
	queue<pi>q;
	q.push(pi(a, b));
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second; q.pop();
		if (x == 1000 && y == 1000)--ans;
		for (int i = 0; i < 4; ++i) {
			if (x + dx[i] >= 0 && x + dx[i] <= 2000 && y + dy[i] >= 0 && y + dy[i] <= 2000 && arr[x + dx[i]][y + dy[i]] == 1) {
				arr[x + dx[i]][y + dy[i]] = -1;
				q.push(pi(x + dx[i], y + dy[i]));
			}
		}
	}
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	int n, x1, y1, x2, y2;
	cin >> n;

	while (n--) {
		cin >> x1 >> y1 >> x2 >> y2;

		if (x1 > x2)swap(x1, x2);
		if (y1 > y2)swap(y1, y1);

		x1 = x1 * 2 + 1000;
		x2 = x2 * 2 + 1000;
		y1 = y1 * 2 + 1000;
		y2 = y2 * 2 + 1000;

		for (int i = x1; i <= x2; ++i) {
			arr[i][y1] = arr[i][y2] = 1;
		}
		for (int i = y1; i <= y2; ++i) {
			arr[x1][i] = arr[x2][i] = 1;
		}
	}

	for (int i = 0; i <= 2000; ++i) {
		for (int j = 0; j <= 2000; ++j) {
			if (arr[i][j] == 1)bfs(i, j);
		}
	}

	cout << ans << '\n';

	return 0;

}