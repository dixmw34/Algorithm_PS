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

ll dp[101][101];
const ll mod = 10000000;

ll sol(int block, int last) {
	ll& ret = dp[block][last];
	if (ret != -1)return ret;
	if (block == last)
		return ret = 1;
	ret = 0;
	for (int i = 1; i <= block - last; ++i) {
		ret = (ret + (i + last - 1)*sol(block - last, i)) % mod;
	}
	return ret;
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	memset(dp, -1, sizeof(dp));

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int ans = 0;
		for (int i = 1; i <= n; ++i) {
			ans = (ans + sol(n, i)) % mod;
		}
		cout << ans << '\n';
	}

	

	return 0;
}