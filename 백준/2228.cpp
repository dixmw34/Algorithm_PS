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

int sum[101], dp[101][101];
bool visit[101][101];

int sol(int idx, int cnt) {
	if (cnt == 0)return 0;
	if (idx < 0)return -INF;
	if (visit[idx][cnt])return dp[idx][cnt];

	visit[idx][cnt] = true;

	dp[idx][cnt] = sol(idx - 1, cnt);

	for (int i = idx - 1; i >= 0; --i) {
		dp[idx][cnt] = max(dp[idx][cnt], sum[idx] - sum[i] + sol(i - 1, cnt - 1));
	}
	return dp[idx][cnt];
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	sum[0] = 0;
	int n, m, a;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a;
		sum[i] = a + sum[i - 1];
	}

	memset(visit, 0, sizeof(visit));

	cout << sol(n, m) << '\n';


	
	return 0;

}