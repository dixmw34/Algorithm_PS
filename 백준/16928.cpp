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

bool visit[101];
map<int, int>_map;

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	memset(visit, false, sizeof(visit));

	int n, m, x, y;

	cin >> n >> m;

	n += m;
	while (n--) {
		cin >> x >> y;
		_map[x] = y;
	}

	queue<pi>q;
	q.push(pi(1, 0));
	visit[1] = true;
	while (!q.empty()) {
		pi now = q.front(); q.pop();
		for (int i = 1; i <= 6; ++i) {
			int next = now.first + i;
			if (_map.find(next) != _map.end())next = _map[next];
			if (!visit[next]) {
				visit[next] = true;
				if (next == 100) {
					cout << now.second + 1 << '\n';
					return 0;
				}
				q.push(pi(next, now.second + 1));
			}
		}
	}


	return 0;
}