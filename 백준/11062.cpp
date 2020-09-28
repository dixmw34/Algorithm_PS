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
#include <string.h>
#include <iomanip>

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

int dp[1000][1000][2];
vector<int>a;

int sol(int left, int right, int name) {
	if (left == right) {
		if (name == 0)return dp[left][right][name] = a[left];
		else return dp[left][right][name] = 0;
	}
	if (dp[left][right][name] != -1)return dp[left][right][name];

	if (name == 0) {
		return dp[left][right][name] = max(a[left] + sol(left + 1, right, 1 - name), a[right] + sol(left, right - 1, 1 - name));
	}
	else {
		return dp[left][right][name] = min(sol(left + 1, right, 1 - name), sol(left, right - 1, 1 - name));
	}
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		a = vector<int>(n);
		for (int i = 0; i < n; ++i)cin >> a[i];
		memset(dp, -1, sizeof(dp));
		cout << sol(0, n - 1, 0) << '\n';
	}

	return 0;

}