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

int dp[100001][3];
const int MOD = 9901;

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	memset(dp, 0, sizeof(dp));
	dp[1][0] = dp[1][1] = dp[1][2] = 1;

	int n;
	cin >> n;
	for (int i = 2; i <= n; ++i) {
		dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % MOD;
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % MOD;
		dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
	}

	cout << (dp[n][0] + dp[n][1] + dp[n][2]) % MOD << '\n';


	return 0;
}