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

const ll Mod = 1000000007;

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	vector<ll>dp(101, 0);
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= 100; ++i) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % Mod;
	}

	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		cout << dp[n] << '\n';
	}

	return 0;

}