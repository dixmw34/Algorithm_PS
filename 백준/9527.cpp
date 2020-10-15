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

ll dp[55];

ll sol(ll num) {
	ll test = 0;
	int i = 0;
	while (test < num) {
		test = (test + 1) * 2 - 1;
		++i;
	}

	if (test == num) {
		return dp[i];
	}
	else {
		return dp[i - 1] + (num - (test + 1) / 2 + 1) + sol(num - (test + 1) / 2);
	}
}


int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	memset(dp, 0, sizeof(dp));
	ll test = 1;
	for (int i = 1; i < 55; ++i) {
		dp[i] = dp[i - 1] * 2 + test;
		test *= 2;
	}

	ll a, b;
	cin >> a >> b;
	cout << sol(b) - sol(a - 1) << '\n';

	return 0;

}