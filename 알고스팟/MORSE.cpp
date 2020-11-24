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

const ll Max = 987654321987654321;
ll dp[201][101];

ll sol(int n, int m) {
	if (dp[n][m] != -1)return dp[n][m];
	if (m == 0 || n == m)return dp[n][m] = 1;

	dp[n][m] = min(sol(n - 1, m - 1) + sol(n - 1, m), Max);

	return dp[n][m];
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	memset(dp, -1, sizeof(dp));

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		ll k;
		cin >> n >> m >> k;

		while (n + m) {
			if (n == 0) {
				cout << 'o';
				m--;
			}
			else if (m == 0) {
				cout << '-';
				n--;
			}
			else {
				if (k > sol(n + m - 1, n - 1)) {
					k -= sol(n + m - 1, n - 1);
					cout << 'o';
					m--;
				}
				else {
					cout << '-';
					n--;
				}
			}
		}
		cout << '\n';
	}

	return 0;
}