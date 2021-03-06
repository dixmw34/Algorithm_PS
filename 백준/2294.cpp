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

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, k, a;
	cin >> n >> k;
	vector<int>dp(k + 1, INF);
	dp[0] = 0;

	while (n--) {
		cin >> a;
		for (int i = a; i <= k; ++i) {
			dp[i] = min(dp[i], dp[i - a] + 1);
		}
	}

	if (dp[k] == INF)cout << -1 << '\n';
	else cout << dp[k] << '\n';


	
	return 0;

}