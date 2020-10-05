#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <map>
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


int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	int n, k, a;
	cin >> n >> k;
	vector<int>dp(k + 1, INF);
	dp[0] = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a;
		for (int j = k / a; j >= 1; --j) {
			for (int x = k; x - j * a >= 0; --x) {
				dp[x] = min(dp[x], dp[x - j * a] + j);
			}
		}
	}

	if (dp[k] == INF)cout << -1 << '\n';
	else cout << dp[k] << '\n';

	return 0;

}