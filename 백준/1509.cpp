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

vector<int>dp(2500, INF);
string s;

int sol(int n) {
	if (n < 0)
		return 0;
	if (dp[n] != INF)
		return dp[n];
	
	dp[n] = n + 1;
	for (int i = 0; i <= n; ++i) {
		bool flag = true;
		int l = i, r = n;
		while (l < r) {
			if (s[l] != s[r]) {
				flag = false;
				break;
			}
			l++; r--;
		}
		if (flag) {
			dp[n] = min(dp[n], sol(i - 1) + 1);
		}
	}
	return dp[n];
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> s;
	cout << sol(s.size() - 1) << '\n';

	return 0;
}