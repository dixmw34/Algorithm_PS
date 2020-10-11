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

struct Photo {
	int t;
	int x;
	int y;
};

int r, n;
Photo arr[100001];

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	cin >> r >> n;
	arr[0] = Photo{ 0, 1, 1 };
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i].t >> arr[i].x >> arr[i].y;
	}

	vector<pi>ans(1, pi(0, n));
	int ans_size = 1, result;

	for (int k = n - 1; k >= 0; --k) {
		int dp = 0;
		for (int b = ans_size - 1; b >= 0; --b) {
			int i = ans[b].second;
			if (abs(arr[k].x - arr[i].x) + abs(arr[k].y - arr[i].y) <= arr[i].t - arr[k].t) {
				dp = ans[b].first + 1;
				break;
			}
		}
		int idx = lower_bound(ans.begin(), ans.end(), pi(dp, k)) - ans.begin();
		ans.insert(ans.begin() + idx, pi(dp, k));
		ans_size++;
		if (k == 0)result = dp;
	}

	cout << result << '\n';
	

	return 0;

}