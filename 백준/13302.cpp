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

int dp[101][35];
int N;
vector<bool>check(101, false);

int sol(int day, int cupon) {
	
	if (day > N)return 0;

	if (dp[day][cupon])return dp[day][cupon];

	dp[day][cupon] = INF;

	if (check[day])dp[day][cupon] = min(dp[day][cupon], sol(day + 1, cupon));
	else {
		if (cupon >= 3)dp[day][cupon] = min(dp[day][cupon], sol(day + 1, cupon - 3));

		dp[day][cupon] = min(dp[day][cupon], sol(day + 1, cupon) + 10000);

		dp[day][cupon] = min(dp[day][cupon], sol(day + 3, cupon + 1) + 25000);

		dp[day][cupon] = min(dp[day][cupon], sol(day + 5, cupon + 2) + 37000);
	}

	return dp[day][cupon];

}


int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int M, num;

	cin >> N >> M;

	while (M--) {
		cin >> num;
		check[num] = true;
	}

	cout << sol(1, 0) << '\n';

	return 0;
	

}