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

int dp[101][102];

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		memset(dp, 0, sizeof(dp));

		int n;
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= i; ++j) {
				cin >> dp[i][j];
				int Max = max(dp[i - 1][j - 1], dp[i - 1][j]);
				dp[i][j] += Max;
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; ++i) {
			ans = max(ans, dp[n][i]);
		}
		cout << ans << '\n';
	}
	
	return 0;

}