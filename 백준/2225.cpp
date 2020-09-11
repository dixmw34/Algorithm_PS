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

const ll Mod = 1000000000;

vector<vector<ll>>dp(201, vector<ll>(201, 0));

ll sol(int n, int k) {
	if (dp[n][k])return dp[n][k];

	if (k == 1)return dp[n][k] = 1;

	for (int i = 0; i <= n; ++i) {
		dp[n][k] = (dp[n][k] + sol(i, k - 1)) % Mod;
	}
	return dp[n][k];
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	int n, k;
	cin >> n >> k;
	cout << sol(n, k) << '\n';
	

	return 0;

}