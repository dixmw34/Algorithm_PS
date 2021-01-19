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

int n, c[1 << 24];

int setdisc(int now, int hi, int idx) {
	return (now& ~(3 << (hi * 2))) | (idx << (hi * 2));
}

int getdisc(int now, int hi) {
	return (now >> (hi * 2)) & 3;
}

int sol(int start, int end) {
	if (start == end)
		return 0;
	memset(c, 0, sizeof(c));
	c[start] = 1, c[end] = -1;
	queue<int>q;
	q.push(start); q.push(end);
	while (!q.empty()) {
		int now = q.front(); q.pop();
		vector<int>top(4, -1);
		for (int i = n - 1; i >= 0; --i) {
			top[getdisc(now, i)] = i;
		}

		for (int i = 0; i < 4; ++i) {
			if (top[i] == -1)continue;
			for (int j = 0; j < 4; ++j) {
				if (i == j)continue;
				if (top[j] == -1 || top[i] < top[j]) {
					int next = setdisc(now, top[i], j);
					if (c[next] == 0) {
						c[next] = c[now] + (c[now] > 0 ? 1 : -1);
						q.push(next);
					}
					else if (c[now] * c[next] < 0) {
						return abs(c[now]) + abs(c[next]) - 1;
					}
				}
			}
		}
	}
	return -1;
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		int start = 0, end = 0;
		for (int i = 0; i < 4; ++i) {
			int k, a;
			cin >> k;
			while (k--) {
				cin >> a;
				start = setdisc(start, a - 1, i);
				end = setdisc(end, a - 1, 3);
			}
		}
		cout << sol(start, end) << '\n';
	}


	

	

	return 0;
}