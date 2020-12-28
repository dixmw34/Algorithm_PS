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

vector<int>sq;

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	for (int i = 1; i <= 223; ++i) {
		sq.push_back(i*i);
	}

	int dp[50001];
	memset(dp, 0, sizeof(dp));
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		dp[i] = i;
		for (int k = 0; sq[k] <= i; ++k) {
			dp[i] = min(dp[i], 1 + dp[i - sq[k]]);
		}
	}
	cout << dp[n] << '\n';

	

	return 0;
}