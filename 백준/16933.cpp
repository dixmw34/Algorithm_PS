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

bool v[1002][1002][11];
int a[1002][1002];

struct Point
{
	int x;
	int y;
	int time;
	int wall;
};

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, m, k;
	char ch;
	cin >> n >> m >> k;
	memset(a, -1, sizeof(a));
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> ch;
			a[i][j] = ch - '0';
		}
	}
	memset(v, 0, sizeof(v));
	queue<Point>q;
	q.push(Point{ 1, 1, 1, k });
	v[1][1][k] = true;

	while (!q.empty()) {
		Point p = q.front(); q.pop();
		if (p.x == n && p.y == m) {
			cout << p.time << '\n';
			return 0;
		}

		for (int i = 0; i < 4; ++i) {
			int _x = p.x + dx[i], _y = p.y + dy[i];
			if (a[_x][_y] == 0) {
				if (v[_x][_y][p.wall])
					continue;
				v[_x][_y][p.wall] = true;
				q.push(Point{ _x, _y, p.time + 1, p.wall });
			}
			else if (a[_x][_y] == 1) {
				if (p.wall == 0)
					continue;
				if (p.time % 2 == 0) {
					if (v[_x][_y][p.wall - 1])
						continue;
					q.push(Point{ p.x, p.y, p.time + 1, p.wall });
				}
				else {
					if (v[_x][_y][p.wall-1])
						continue;
					v[_x][_y][p.wall - 1] = true;
					q.push(Point{ _x, _y, p.time + 1, p.wall - 1 });
				}
			}
		}
	}

	cout << -1 << '\n';

	return 0;
}