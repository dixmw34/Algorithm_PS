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

struct Pack
{
	string name;
	int volume;
	int value;
};

int dp[101][1001];
Pack p[101];

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		memset(dp, 0, sizeof(dp));

		int n, w;
		cin >> n >> w;
		for (int i = 1; i <= n; ++i) {
			cin >> p[i].name >> p[i].volume >> p[i].value;
			for (int j = w; j >= 0; --j) {
				if (j >= p[i].volume)dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - p[i].volume] + p[i].value);
				else dp[i][j] = dp[i - 1][j];
			}
		}

		cout << dp[n][w] << ' ';

		stack<string>s;
		for (int i = n; i > 0; --i) {
			if (w - p[i].volume >= 0 && dp[i][w] == dp[i - 1][w - p[i].volume] + p[i].value) {
				s.push(p[i].name);
				w -= p[i].volume;
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