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
using namespace std;

const int MOD = 1000000000;

int dp[101][10][1 << 10];

void fun(int now, int next, int n) {
	for (int i = 0; i < (1 << 10); ++i) {
		dp[n + 1][next][i | (1 << next)] = (dp[n + 1][next][i | (1 << next)] + dp[n][now][i]) % MOD;
	}
	return;
}

int main(void) {

	int n;
	cin >> n;

	memset(dp, 0, sizeof(dp));

	for (int i = 0; i < 10; ++i) {
		dp[1][i][1 << i] = 1;
	}

	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < 10; ++j) {
			if (j - 1 >= 0)fun(j, j - 1, i);
			if (j + 1 < 10)fun(j, j + 1, i);
		}		
	}

	int ans = 0;
	for (int i = 1; i < 10; ++i) {
		ans = (ans + dp[n][i][(1 << 10) - 1]) % MOD;
	}

	cout << ans << '\n';

	

	return 0;
}