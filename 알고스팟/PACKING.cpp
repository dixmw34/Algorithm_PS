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

int dp[101][1001], r[101][1001];
string name[101];
pi p[101];

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		memset(dp, 0, sizeof(dp));

		int n, w, a, b;
		cin >> n >> w;
		for (int i = 1; i <= n; ++i) {
			cin >> name[i] >> a >> b;
			p[i] = pi(a, b);
			for (int k = 0; k <= w; ++k) {
				dp[i][k] = dp[i - 1][k];
				if (k - a >= 0 && dp[i][k] < dp[i - 1][k - a] + b) {
					dp[i][k] = dp[i - 1][k - a] + b;
					r[i][k] = i;
				}
			}
		}
		cout << dp[n][w] << ' ';

		stack<string>s;
		for (int i = n; i >= 1; --i) {
			if (w - p[i].first >= 0 && dp[i][w] == dp[i - 1][w - p[i].first] + p[i].second) {
				s.push(name[i]);
				w -= p[i].first;
				if (w == 0)break;
			}
		}
		cout << s.size() << '\n';
		while (!s.empty()) {
			cout << s.top() << '\n';
			s.pop();
		}

	}
	
	return 0;

}