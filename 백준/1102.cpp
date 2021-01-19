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

int dp[1 << 16];
int n, p, arr[16][16];

int sol(int now, int cnt) {
	int&ret = dp[now];
	if (ret != -1)return ret;
	ret = INF;

	if (cnt >= p) {
		return ret = 0;
	}
	for (int i = 0; i < n; ++i) {
		if (now&(1 << i)) {
			for (int k = 0; k < n; ++k) {
				if (now&(1<<k))continue;
				ret = min(ret, sol(now | (1 << k), cnt + 1) + arr[i][k]);
			}
		}
	}
	return ret;
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	memset(dp, -1, sizeof(dp));

	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> arr[i][j];
		}
	}
	int start = 0, cnt = 0;
	char ch;
	for (int i = 0; i < n; ++i) {
		cin >> ch;
		if (ch == 'Y') {
			start |= (1 << i);
			cnt++;
		}
	}
	cin >> p;
	int result = sol(start, cnt);
	if (result == INF) 
		cout << -1 << '\n';
	else
		cout << result << '\n';

	

	return 0;
}