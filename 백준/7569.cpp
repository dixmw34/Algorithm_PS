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

int tx[] = { -1, 1, 0, 0, 0, 0 };
int ty[] = { 0, 0, -1, 1, 0, 0 };
int tz[] = { 0, 0, 0, 0, -1, 1 };

int arr[102][102][102];

struct Point
{
	int x;
	int y;
	int z;
	int time;
};

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	memset(arr, -1, sizeof(arr));

	int a, b, c, test = 0, ans = 0;
	cin >> b >> a >> c;
	queue<Point>q;

	for (int k = 1; k <= c; ++k) {
		for (int i = 1; i <= a; ++i) {
			for (int j = 1; j <= b; ++j) {
				cin >> arr[i][j][k];
				if (arr[i][j][k] == 1) {
					q.push(Point{ i, j, k, 0 });
				}
				else if (arr[i][j][k] == 0)test++;
			}
		}
	}

	while (!q.empty()) {
		Point p = q.front(); q.pop();
		ans = p.time;
		for (int i = 0; i < 6; ++i) {
			if (arr[p.x + tx[i]][p.y + ty[i]][p.z + tz[i]] == 0) {
				test--;
				arr[p.x + tx[i]][p.y + ty[i]][p.z + tz[i]] = 1;
				q.push(Point{ p.x + tx[i], p.y + ty[i], p.z + tz[i], p.time + 1 });
			}
		}
	}

	if (test == 0)cout << ans << '\n';
	else cout << -1 << '\n';

	
	return 0;

}