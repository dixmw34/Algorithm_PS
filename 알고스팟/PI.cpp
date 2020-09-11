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

int sol(string a) {
	int n = a.size();
	bool flag = true;
	for (int i = 1; i < n; i++) {
		if (a[i] != a[0]) {
			flag = false;
			break;
		}
	}
	if (flag)return 1;
	flag = true;
	for (int i = 2; i < n; i++) {
		if (a[i]-a[i-1] != a[1]-a[0]) {
			flag = false;
			break;
		}
	}
	if (flag) {
		if (abs(a[1] - a[0]) == 1)return 2;
		else return 5;
	}
	flag = true;
	for (int i = 2; i < n; i++) {
		if (a[i] != a[i - 2]) {
			flag = false;
			break;
		}
	}
	if (flag)return 4;

	return 10;
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	int t;
	string a;
	cin >> t;
	while (t--) {
		cin >> a;
		int n = a.size();
		vector<int>dp(n+1, INF);
		dp[0] = 0;
		for (int i = 2; i < n; ++i) {
			for (int k = 2; k <= 4; ++k) {
				if (i - k < 0)break;
				int num = sol(a.substr(i - k, k + 1));
				dp[i+1] = min(dp[i+1], dp[i - k] + num);
			}
		}
		cout << dp[n] << '\n';
	}

	return 0;

}