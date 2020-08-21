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

#define INF 987654321

using namespace std;

typedef pair<int, int> pi;
typedef pair<int, pair<int, int>>ppi;
typedef unsigned int ui;
typedef long long ll;

int dx[] = { -1, 0, 1, 0, -1, -1, 1, 1 };
int dy[] = { 0, 1, 0, -1, -1, 1, -1, 1 };

//----------------------------------------------------

int n, k, l;

int arr[101];
int time[200];
vector<vector<int>>dp;

int sol(int now, int t) {
	if (now == n)return true;

	if (dp[t][now] != -1)return dp[t][now];

	dp[t][now] = 0;

	if (arr[now + 1] + time[t] <= l)dp[t][now] = sol(now + 1, (t + 1) % (2 * k));
	if (arr[now] + time[t] <= l)dp[t][now] = max(dp[t][now], sol(now, (t + 1) % (2 * k)));

	return dp[t][now];

}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;

	cin >> t;
	while (t--) {
		cin >> n >> k >> l;
		dp = vector<vector<int>>(2 * k, vector<int>(n+1, -1));
		arr[0] = -100;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
		}
		for (int i = 0; i < 2 * k; i++) {
			if (i <= k)time[i] = i;
			else {
				time[i] = time[i - 1] - 1;
			}
		}
		if (sol(0, 1))cout << "YES\n";
		else cout << "NO\n";
		dp.clear();
	}

	return 0;

}