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

const int Mod = 1000000003;
int dp[1001][501];

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	memset(dp, 0, sizeof(dp));

	int n, k;
	cin >> n >> k;

	if (k > (n + 1) / 2) {
		cout << 0 << '\n';
		return 0;
	}

	for (int i = 1; i < n; ++i) {
		dp[i][0] = 1;
		dp[i][1] = i;
		for (int j = 2; j <= (i + 1) / 2; ++j) {
			dp[i][j] = (dp[i - 1][j] + dp[i - 2][j - 1]) % Mod;
		}
	}

	cout << (dp[n - 2][k] + (dp[n - 3][k - 1] * 2) % Mod) % Mod;
	
	return 0;

}