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

int dx[] = { -1, 1, 0, 0, -1, -1, 1, 1 };
int dy[] = { 0, 0, -1, 1, -1, 1, -1, 1 };

//----------------------------------------------------

const int MAX = 1000001;
const int MOD = 1000000007;

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	vector<long long>dp(MAX, 0);
	vector<long long>sub(MAX, 0);
	dp[0] = 1;
	dp[1] = 2;
	dp[2] = 7;

	for (int i = 3; i <= N; i++) {
		if (i >= 3) {
			sub[i] = (sub[i - 1] + dp[i - 3] * 2) % MOD;
		}
		dp[i] = (dp[i - 2] * 3 + dp[i - 1] * 2 + sub[i]) % MOD;

	}

	cout << dp[N] << '\n';


	return 0;


}