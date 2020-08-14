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

	int n, ans = 0;
	cin >> n;
	vector<int>arr(n);
	vector<int>dp;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		if (dp.empty() || dp.back() < arr[i])dp.push_back(arr[i]);
		else {
			int idx = lower_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();
			dp[idx] = arr[i];
		}
	}


	cout << dp.size() << '\n';

	return 0;
	

}