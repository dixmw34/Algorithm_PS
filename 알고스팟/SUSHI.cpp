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

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, m, a, b;
		cin >> n >> m;
		m /= 100;
		vector<int>dp(m + 1, 0);
		for (int i = 0; i < n; ++i) {
			cin >> a >> b;
			a /= 100;
			for (int k = a; k <= m; ++k) {
				dp[k] = max(dp[k], dp[k - a] + b);
			}
		}
		cout << dp[m] << '\n';
	}

	return 0;
}