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

int cx[] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int cy[] = { -1, 1, -2, 2, -2, 2, -1, 1 };

bool visit[300][300];

struct Point
{
	int x;
	int y;
	int time;
};

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int l, x, y, a, b;
		cin >> l >> x >> y >> a >> b;

		memset(visit, 0, sizeof(visit));
		queue<Point>q;
		q.push(Point{ x, y, 0 });
		visit[x][y] = true;

		while (!q.empty()) {
			Point p = q.front(); q.pop();
			if (p.x == a && p.y == b) {
				cout << p.time << '\n';
				break;
			}
			for (int i = 0; i < 8; ++i) {
				if (p.x + cx[i] >= 0 && p.x + cx[i] < l && p.y + cy[i] >= 0 && p.y + cy[i] < l && !visit[p.x + cx[i]][p.y + cy[i]]) {
					visit[p.x + cx[i]][p.y + cy[i]] = true;
					q.push(Point{ p.x + cx[i], p.y + cy[i] , p.time + 1 });
				}
			}
		}
	}

	
	return 0;

}