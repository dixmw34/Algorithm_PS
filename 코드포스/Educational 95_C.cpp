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

int n;
vector<int>a;
vector<vector<int>>dp;

int sol(int idx, int p) {
	if (idx >= n)return 0;

	if (dp[p][idx] != INF)return dp[p][idx];
	if (idx == n - 1) {
		if (a[idx] && p)return dp[p][idx] = 1;
		else return dp[p][idx] = 0;
	}

	dp[p][idx] = min(sol(idx + 1, 1 - p) + a[idx] * p, sol(idx + 2, 1 - p) + a[idx] * p + a[idx + 1] * p);

	return dp[p][idx];
}


int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		a = vector<int>(n);
		for (int i = 0; i < n; ++i)cin >> a[i];

		dp = vector<vector<int>>(2, vector<int>(n, INF));

		cout << sol(0, 1) << '\n';
	}

	

	return 0;

}