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

ll dp[201][101];

ll sol(int n, int m) {
	if (dp[n][m] != -1)return dp[n][m];

	if (m == 0 || n == m)return dp[n][m] = 1LL;

	else return dp[n][m] = min((ll)INT_MAX, sol(n - 1, m - 1) + sol(n - 1, m));
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
		int l = n + m;
		while (l--) {
			if (n == 0) {
				cout << 'o';
			}
			else if (m == 0) {
				cout << '-';
			}
			else {
				ll test = sol(n + m - 1, m);
				if (test < k) {
					cout << 'o';
					m--;
					k -= test;
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