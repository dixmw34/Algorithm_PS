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

int dp[2][101][20];

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	memset(dp, 0, sizeof(dp));

	string s;
	cin >> s;
	string arr[2];
	cin >> arr[0] >> arr[1];

	for (int k = s.size() - 1; k >= 0; --k) {
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < arr[0].size(); ++j) {
				if (arr[i][j] == s[k]) {
					if(k == s.size()-1)
						dp[i][j][k] = 1;
					else {
						for (int t = j + 1; t < arr[0].size(); ++t) {
							dp[i][j][k] += dp[(i + 1) % 2][t][k + 1];
						}
					}
				}
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < arr[0].size(); ++j) {
			ans += dp[i][j][0];
		}
	}
	cout << ans << '\n';
	


	return 0;
}