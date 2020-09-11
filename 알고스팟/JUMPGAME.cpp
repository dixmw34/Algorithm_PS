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

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int cnt, n;
	cin >> cnt;
	while (cnt--) {
		cin >> n;
		int a[100][100] = { 0, };

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];
			}
		}
		int dp[100][100] = { 0, };
		dp[0][0] = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i + a[i][j] < n)dp[i + a[i][j]][j] += dp[i][j];
				if (j + a[i][j] < n)dp[i][j + a[i][j]] += dp[i][j];
			}
		}

		if (dp[n - 1][n - 1] == 0)cout << "NO\n";
		else cout << "YES\n";
	}
	

	return 0;

}