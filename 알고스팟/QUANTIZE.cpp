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

int a[100], sum[101], square[101], dp[101][11], mindp[101][101];

int minimum(int start, int end) {
	int & result = mindp[start][end];
	if (result != -1)return result;
	int mid = (sum[end] - sum[start - 1]) / (end - start + 1);
	int left = square[end] - square[start - 1] + (-2)*mid*((sum[end] - sum[start - 1])) + (end - start + 1)*mid*mid;
	mid++;
	int right = square[end] - square[start - 1] + (-2)*mid*((sum[end] - sum[start - 1])) + (end - start + 1)*mid*mid;
	return result = min(left, right);
}

int sol(int end, int cnt) {

	if (end <= 0)
		return 0;
	if (cnt == 0)
		return INF;
	int& result = dp[end][cnt];
	if (result != -1)
		return result;
	result = INF;
	for (int i = 1; i <= end; ++i) {
		result = min(result, sol(i - 1, cnt - 1) + minimum(i, end));
	}
	return result;
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, s;
		cin >> n >> s;

		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		sort(a, a + n);

		memset(sum, 0, sizeof(sum));
		memset(square, 0, sizeof(square));
		memset(dp, -1, sizeof(dp));
		memset(mindp, -1, sizeof(mindp));
		for (int i = 1; i <= n; ++i) {
			sum[i] = a[i - 1] + sum[i - 1];
			square[i] = a[i - 1] * a[i - 1] + square[i - 1];
		}
		cout << sol(n, s) << '\n';
	}
	

	
	return 0;
}