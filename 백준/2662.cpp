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
#include <string.h>
#include <iomanip>

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

int dp[301][21], a[301][21], r[301][21];

void f(int w, int n) {
	if (n == 0)return;
	f(w - r[w][n], n - 1);
	cout << r[w][n] << ' ';
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	memset(dp, 0, sizeof(dp));

	int w, n;
	cin >> w >> n;

	for (int i = 1; i <= w; ++i) {
		for (int j = 0; j <= n; ++j) {
			cin >> a[i][j];
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = w; j >= 1; --j) {
			for (int k = 0; k <= j; ++k) {
				if (dp[j][i] < dp[j - k][i - 1] + a[k][i]) {
					dp[j][i] = dp[j - k][i - 1] + a[k][i];
					r[j][i] = k;
				}
			}
		}
	}

	cout << dp[w][n] << '\n';
	f(w, n);
	cout << '\n';


	return 0;

}