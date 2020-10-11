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

const int snake = 10000;

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	int n, k, x, y, l, t;
	cin >> n >> k;
	vector<vector<int>>arr(n, vector<int>(n, 0));
	while (k--) {
		cin >> x >> y;
		arr[x - 1][y - 1] += 1;
	}
	queue<pair<int, char>>q;
	char ch;
	cin >> l;
	while (l--) {
		cin >> t >> ch;
		q.push(make_pair(t, ch));
	}

	int time = 0, d = 1;
	x = 0, y = 0;
	queue<pi>tail;
	tail.push(pi(0, 0));
	while (1) {
		if (!q.empty() && q.front().first == time) {
			if (q.front().second == 'L')d = (d - 1 + 4) % 4;
			else d = (d + 1) % 4;
			q.pop();
		}
		if (x + dx[d] < 0 || x + dx[d] >= n || y + dy[d] < 0 || y + dy[d] >= n || arr[x + dx[d]][y + dy[d]] / snake == 1) {
			cout << time + 1 << '\n';
			return 0;
		}
		time++;
		x += dx[d]; y += dy[d];
		tail.push(pi(x, y));
		if (arr[x][y]) {
			arr[x][y] = snake;
			continue;
		}
		else {
			arr[x][y] = snake;
			arr[tail.front().first][tail.front().second] %= snake;
			tail.pop();
		}
	}

	return 0;

}