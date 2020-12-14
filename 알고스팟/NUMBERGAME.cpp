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

int a[50], dp[50][50][2];
bool visit[50][50][2];

int sol(int left, int right, int name) {
	if (left > right)return 0;
	if (visit[left][right][name])return dp[left][right][name];
	visit[left][right][name] = true;
	int &ret = dp[left][right][name];

	if (name == 0) {
		if (left == right) {
			ret = a[left];
		}
		else {
			ret = max(max(a[left] + sol(left + 1, right, 1 - name), a[right] + sol(left, right - 1, 1 - name)), max(sol(left + 2, right, 1 - name), sol(left, right - 2, 1 - name)));
		}
	}
	else {
		if (left == right) {
			ret = -a[left];
		}
		else {
			ret = min(min(-a[left] + sol(left + 1, right, 1 - name), -a[right] + sol(left, right - 1, 1 - name)), min(sol(left + 2, right, 1 - name), sol(left, right - 2, 1 - name)));
		}
	}

	return ret;
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		memset(visit, 0, sizeof(visit));
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i)cin >> a[i];
		cout << sol(0, n - 1, 0) << '\n';
	}

	return 0;
}