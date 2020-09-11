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

vector<vector<int>>dp;
vector<int>a;

int sol(int left, int right) {
	if (left == right)return 0;
	if (dp[left][right] != -1)return dp[left][right];

	dp[left][right] = INF;
	for (int k = left; k < right; k++) {
		dp[left][right] = min(dp[left][right], sol(left, k) + sol(k + 1, right) + a[right + 1] - a[left]);
	}

	return dp[left][right];
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		a = vector<int>(n + 1, 0);
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			a[i] += a[i - 1];
		}
		dp = vector<vector<int>>(n, vector<int>(n, -1));
		cout << sol(0, n - 1) << '\n';
	}

	

	return 0;

}