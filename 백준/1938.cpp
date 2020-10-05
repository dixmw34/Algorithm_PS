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
	int d = 0;
};

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	int n;
	char ch;
	cin >> n;
	vector<vector<vector<int>>>arr(n, vector<vector<int>>(n, vector<int>(2, INF)));
	vector<vector<bool>>check(n, vector<bool>(n, false));
	vector<pi>start;
	vector<pi>end;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> ch;
			if (ch == '1')check[i][j] = true;
			else if (ch == 'B') {
				start.push_back(pi(i, j));
			}
			else if (ch == 'E') {
				end.push_back(pi(i, j));
			}
		}
	}
	int dir = 0;
	if (start[0].first != start[1].first)dir = 1;
	queue<Point>q;
	q.push(Point{ start[1].first, start[1].second, dir });
	arr[start[1].first][start[1].second][dir] = 0;
	if (end[0].first != end[1].first)dir = 1;
	else dir = 0;
	while (!q.empty()) {
		Point p = q.front(); q.pop();
		if (p.x == end[1].first && p.y == end[1].second && p.d == dir) {
			cout << arr[p.x][p.y][p.d] << '\n';
			return 0;
		}
		if (p.d == 0) {
			//up
			if (p.x - 1 >= 0 && !check[p.x - 1][p.y - 1] && !check[p.x - 1][p.y] && !check[p.x - 1][p.y + 1] && arr[p.x - 1][p.y][p.d] == INF) {
				arr[p.x - 1][p.y][p.d] = arr[p.x][p.y][p.d] + 1;
				q.push(Point{ p.x - 1, p.y, p.d });
			}
			//down
			if (p.x + 1 < n && !check[p.x + 1][p.y - 1] && !check[p.x + 1][p.y] && !check[p.x + 1][p.y + 1] && arr[p.x + 1][p.y][p.d] == INF) {
				arr[p.x + 1][p.y][p.d] = arr[p.x][p.y][p.d] + 1;
				q.push(Point{ p.x + 1, p.y, p.d });
			}
			//left
			if (p.y - 2 >= 0 && !check[p.x][p.y - 2] && arr[p.x][p.y - 1][p.d] == INF) {
				arr[p.x][p.y - 1][p.d] = arr[p.x][p.y][p.d] + 1;
				q.push(Point{ p.x, p.y - 1, p.d });
			}
			//right
			if (p.y + 2 < n && !check[p.x][p.y + 2] && arr[p.x][p.y + 1][p.d] == INF) {
				arr[p.x][p.y + 1][p.d] = arr[p.x][p.y][p.d] + 1;
				q.push(Point{ p.x, p.y + 1, p.d });
			}
		}
		else {
			//up
			if (p.x - 2 >= 0 && !check[p.x - 2][p.y] && arr[p.x - 1][p.y][p.d] == INF) {
				arr[p.x - 1][p.y][p.d] = arr[p.x][p.y][p.d] + 1;
				q.push(Point{ p.x - 1, p.y, p.d });
			}
			//down
			if (p.x + 2 < n && !check[p.x + 2][p.y] && arr[p.x + 1][p.y][p.d] == INF) {
				arr[p.x + 1][p.y][p.d] = arr[p.x][p.y][p.d] + 1;
				q.push(Point{ p.x + 1, p.y, p.d });
			}
			//left
			if (p.y - 1 >= 0 && !check[p.x - 1][p.y - 1] && !check[p.x][p.y-1] && !check[p.x + 1][p.y - 1] && arr[p.x][p.y - 1][p.d] == INF) {
				arr[p.x][p.y - 1][p.d] = arr[p.x][p.y][p.d] + 1;
				q.push(Point{ p.x, p.y - 1, p.d });
			}
			//right
			if (p.y + 1 < n && !check[p.x - 1][p.y + 1] && !check[p.x][p.y + 1] && !check[p.x + 1][p.y + 1] && arr[p.x][p.y + 1][p.d] == INF) {
				arr[p.x][p.y + 1][p.d] = arr[p.x][p.y][p.d] + 1;
				q.push(Point{ p.x, p.y + 1, p.d });
			}
		}
		bool flag = true;
		for (int i = 0; i < 8; ++i) {
			if (p.x + dx[i] < 0 || p.x + dx[i] >= n || p.y + dy[i] < 0 || p.y + dy[i] >= n || check[p.x + dx[i]][p.y + dy[i]]) {
				flag = false;
				break;
			}
		}
		if (flag && arr[p.x][p.y][1 - p.d] == INF) {
			arr[p.x][p.y][1 - p.d] = arr[p.x][p.y][p.d] + 1;
			q.push(Point{ p.x, p.y, 1 - p.d });
		}
	}

	cout << 0 << '\n';

	return 0;

}