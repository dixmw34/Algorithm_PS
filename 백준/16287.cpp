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
#include <cassert>

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



int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int w, n;
	cin >> w >> n;
	vector<int>arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	vector<vector<int>>dp(w);
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (arr[i] + arr[j] < w) {
				dp[arr[i] + arr[j]].push_back(arr[i]);
			}
		}
	}

	for (int k = 2; k <= w / 2; ++k) {
		if (dp[k].empty() || dp[w - k].empty())
			continue;
		for (int i = 0; i < dp[k].size(); ++i) {
			int a = dp[k][i], b = k - a;
			for (int j = 0; j < dp[w - k].size(); ++j) {
				int c = dp[w - k][j], d = w - k - c;
				if (a != c && a != d && b != c && b != d) {
					cout << "YES\n";
					return 0;
				}
			}
		}

	}

	cout << "NO\n";

	return 0;
}