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

int n,ALL;
int road[16][16];
vector<vector<int>>dp(16, vector<int>(1 << 16, -1));

int dfs(int now, int visit) {
	if (visit == ALL) {
		if (road[now][0])return road[now][0];
		else return INF;
	}

	if (dp[now][visit] != -1)return dp[now][visit];
	dp[now][visit] = INF;

	for (int i = 0; i < n; i++) {
		if (road[now][i]!=0 && ((visit & (1 << i)) != (1 << i))) {
			dp[now][visit] = min(dp[now][visit], road[now][i] + dfs(i, visit | (1 << i)));
		}
	}
	return dp[now][visit];
}


int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> road[i][j];
		}
	}

	ALL = (1 << n) - 1;

	cout << dfs(0, 1) << '\n';



	return 0;
	

}