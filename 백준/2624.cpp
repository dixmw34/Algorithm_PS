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

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T, k, p, n;

	cin >> T >> k;

	vector<int>dp(T + 1, 0);
	dp[0] = 1;

	while (k--) {
		cin >> p >> n;
		for (int i = T; i >= p; i--) {
			for (int j = p * n; j >= p; j -= p) {
				if (i - j < 0)continue;
				dp[i] += dp[i - j];
			}
		}
	}

	cout << dp[T] << '\n';


	return 0;
	

}