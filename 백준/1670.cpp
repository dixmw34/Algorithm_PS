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

ll const Mod = 987654321;

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	ll dp[10001];
	dp[0] = dp[2] = 1;
	int n;
	cin >> n;
	for (int i = 4; i <= n; i += 2) {
		dp[i] = 0;
		for (int k = 0; k < i; k += 2) {
			dp[i] = (dp[i] + dp[k] * dp[i - k - 2]) % Mod;
		}
	}
	cout << dp[n] << '\n';

	return 0;
}