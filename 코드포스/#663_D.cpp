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

vector<vector<int>>arr;
vector<vector<int>>dp;
bool ok[8][8];
int bitcnt[8] = { 0, 1, 1, 2, 1, 2, 2, 3 };
int n, m;

int sol2() {

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if ((bitcnt[i] + bitcnt[j]) % 2)ok[i][j] = true;
			else ok[i][j] = false;
		}
	}

	dp = vector<vector<int>>(m, vector<int>(4, 0));
	int num = arr[0][0] + arr[1][0] * 2;
	for (int i = 0; i < 4; i++) {
		dp[0][i] = bitcnt[(num^i)];
	}
	for (int k = 1; k < m; k++) {
		num = arr[0][k] + arr[1][k] * 2;
		for (int i = 0; i < 4; i++) {
			dp[k][i] = INF;
			for (int j = 0; j < 4; j++) {
				if (ok[i][j])dp[k][i] = min(dp[k][i], dp[k - 1][j] + bitcnt[num^i]);
			}
		}
	}
	int ans = INF;
	for (int i = 0; i < 4; i++) {
		ans = min(ans, dp[m - 1][i]);
	}
	return ans;
}
int sol3() {

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (((bitcnt[i % 4] + bitcnt[j % 4]) % 2) && ((bitcnt[i / 2] + bitcnt[j / 2]) % 2))ok[i][j] = true;
			else ok[i][j] = false;
		}
	}

	dp = vector<vector<int>>(m, vector<int>(8, 0));
	int num = arr[0][0] + arr[1][0] * 2 + arr[2][0] * 4;
	for (int i = 0; i < 8; i++) {
		dp[0][i] = bitcnt[(num^i)];
	}
	for (int k = 1; k < m; k++) {
		num = arr[0][k] + arr[1][k] * 2 + arr[2][k] * 4;
		for (int i = 0; i < 8; i++) {
			dp[k][i] = INF;
			for (int j = 0; j < 8; j++) {
				if (ok[i][j])dp[k][i] = min(dp[k][i], dp[k - 1][j] + bitcnt[num^i]);
			}
		}
	}
	int ans = INF;
	for (int i = 0; i < 8; i++) {
		ans = min(ans, dp[m - 1][i]);
	}
	return ans;
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	char ch;

	cin >> n >> m;
	if (n <= m) {
		arr = vector<vector<int>>(n, vector<int>(m));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> ch;
				arr[i][j] = ch - '0';
			}
		}
	}
	else {
		arr = vector<vector<int>>(m, vector<int>(n));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> ch;
				arr[j][i] = ch - '0';
			}
		}
		swap(n, m);
	}

	if (n > 3)cout << -1 << '\n';
	else if (n == 1)cout << 0 << '\n';
	else if (n == 2) {
		cout << sol2() << '\n';
	}
	else {
		cout << sol3() << '\n';
	}
	


	return 0;

}