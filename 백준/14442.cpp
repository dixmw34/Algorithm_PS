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

struct Point
{
	int x;
	int y;
	int wall = 0;
};

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	int n, m, k;
	char ch;
	cin >> n >> m >> k;
	vector<vector<vector<int>>>arr(n, vector<vector<int>>(m, vector<int>(k + 1, INF)));
	vector<vector<bool>>check(n, vector<bool>(m, false));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> ch;
			if (ch == '1')check[i][j] = true;
		}
	}
	queue<Point>q;
	q.push(Point{ 0, 0, 0 });
	arr[0][0][0] = 1;
	while (!q.empty()) {
		Point p = q.front(); q.pop();
		if (p.x == n - 1 && p.y == m - 1) {
			cout << arr[p.x][p.y][p.wall] << '\n';
			return 0;
		}
		for (int i = 0; i < 4; ++i) {
			if (p.x + dx[i] >= 0 && p.x + dx[i] < n && p.y + dy[i] >= 0 && p.y + dy[i] < m) {
				if (check[p.x + dx[i]][p.y + dy[i]]) {
					if (p.wall + 1 <= k && arr[p.x + dx[i]][p.y + dy[i]][p.wall + 1] == INF) {
						arr[p.x + dx[i]][p.y + dy[i]][p.wall + 1] = arr[p.x][p.y][p.wall] + 1;
						q.push(Point{ p.x + dx[i], p.y + dy[i], p.wall + 1 });
					}
				}
				else {
					if (arr[p.x + dx[i]][p.y + dy[i]][p.wall] == INF) {
						arr[p.x + dx[i]][p.y + dy[i]][p.wall] = arr[p.x][p.y][p.wall] + 1;
						q.push(Point{ p.x + dx[i], p.y + dy[i], p.wall });
					}
				}
			}
		}
	}

	cout << -1 << '\n';

	return 0;

}