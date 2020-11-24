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

int n, m;
int dp[101][101];
ll a[101], b[101];

int sol(int left, int right) {
	if (left > n || right > m)return 0;
	if (dp[left][right] != -1)return dp[left][right];

	dp[left][right] = 0;

	ll Max = max(a[left], b[right]);

	for (int i = left + 1; i <= n; ++i) {
		if (a[i] > Max)dp[left][right] = max(dp[left][right], 1 + sol(i, right));
	}

	for (int i = right + 1; i <= m; ++i) {
		if (b[i] > Max)dp[left][right] = max(dp[left][right], 1 + sol(left, i));
	}

	return dp[left][right];

}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		a[0] = b[0] = LLONG_MIN;
		for (int i = 1; i <= n; ++i)cin >> a[i];
		for (int i = 1; i <= m; ++i)cin >> b[i];

		memset(dp, -1, sizeof(dp));

		cout << sol(0, 0) << '\n';

	}

	return 0;
}