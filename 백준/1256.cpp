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

vector<vector<int>>dp(201, vector<int>(201, -1));
const int Max = 1000000001;

int sol(int n, int m) {
	if (dp[n][m] != -1)return dp[n][m];
	if (m == 0 || n == m)return 1;

	dp[n][m] = sol(n - 1, m - 1) + sol(n - 1, m);
	if (dp[n][m] > Max)dp[n][m] = Max;
	return dp[n][m];
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	int n, m, k;
	string ans = "";
	cin >> n >> m >> k;
	if (sol(n + m, n) < k) {
		cout << -1 << '\n';
		return 0;
	}

	int l = n + m;
	for (int i = 0; i < l; ++i) {
		if (n == 0) {
			ans += 'z';
		}
		else if (m == 0) {
			ans += 'a';
		}
		else {
			int num = sol(n + m - 1, m);
			if (num < k) {
				ans += 'z';
				k -= num;
				m--;
			}
			else {
				ans += 'a';
				n--;
			}
		}
	}

	cout << ans << '\n';

	return 0;

}