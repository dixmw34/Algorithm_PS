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
#include <cassert>

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

bool arr[50][50][(1 << 7) - 1];

struct Point
{
	int x;
	int y;
	int state;
	int time;
};

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	memset(arr, 0, sizeof(arr));

	int n, m;
	cin >> n >> m;
	vector<vector<char>>map(n, vector<char>(m));
	pi start;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> map[i][j];
			if (map[i][j] == '0') {
				start = pi(i, j);
			}

		}
	}
	queue<Point>q;
	q.push(Point{ start.first, start.second, 0, 0 });
	while (!q.empty()) {
		Point now = q.front(); q.pop();
		if (map[now.x][now.y] == '1') {
			cout << now.time << '\n';
			return 0;
		}
		for (int i = 0; i < 4; ++i) {
			int x = now.x + dx[i], y = now.y + dy[i];
			if (x >= 0 && x < n && y >= 0 && y < m) {
				if (map[x][y] == '#') {
					continue;
				}
				else if (map[x][y] >= 'A' && map[x][y] <= 'F') {
					int lock = (1 << (map[x][y] - 'A'));
					if ((lock&now.state) == lock && !arr[x][y][now.state]) {
						arr[x][y][now.state] = true;
						q.push(Point{ x, y, now.state, now.time + 1 });
					}
				}
				else if (map[x][y] >= 'a' && map[x][y] <= 'f') {
					int new_state = now.state | (1 << (map[x][y] - 'a'));
					if (!arr[x][y][now.state] && !arr[x][y][new_state]) {
						arr[x][y][now.state] = true;
						arr[x][y][new_state] = true;
						q.push(Point{ x, y, new_state, now.time + 1 });
					}
				}
				else {
					if (!arr[x][y][now.state]) {
						arr[x][y][now.state] = true;
						q.push(Point{ x, y, now.state, now.time + 1 });
					}
				}
			}
		}
	}

	cout << -1 << '\n';

	return 0;
}