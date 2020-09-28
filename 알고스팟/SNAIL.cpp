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

int n, m;

vector<vector<double>>dp;

double sol(int day, int len) {
	if (len >= n)return 1.0;
	else if (day >= m)return 0.0;

	if (dp[day][len] >= 0.0)return dp[day][len];
	
	return dp[day][len] = sol(day + 1, len + 2)*0.75 + sol(day + 1, len + 1)*0.25;
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		dp = vector<vector<double>>(m, vector<double>(n, -1.0));
		printf("%.10lf\n", sol(0, 0));
	}

	return 0;

}