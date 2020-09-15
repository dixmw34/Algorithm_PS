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

ll h[20000];

ll sol(int start, int end) {
	if (start == end)return h[start];

	int mid = (start + end) / 2;

	ll ans = max(sol(start, mid), sol(mid + 1, end));

	ll test = min(h[mid], h[mid + 1]);
	ans = max(ans, test * 2);

	int lo = mid - 1, hi = mid + 2;

	while (lo >= start || hi <= end) {
		if (lo == start - 1) {
			test = min(test, h[hi]);
			ans = max(ans, test*(hi - lo));
			++hi;
		}
		else if (hi == end + 1) {
			test = min(test, h[lo]);
			ans = max(ans, test*(hi - lo));
			--lo;
		}
		else if (h[lo] >= h[hi]) {
			test = min(test, h[lo]);
			ans = max(ans, test*(hi - lo));
			--lo;
		}
		else {
			test = min(test, h[hi]);
			ans = max(ans, test*(hi - lo));
			++hi;
		}
	}
	return ans;
}


int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; ++i)cin >> h[i];

		cout << sol(0, n - 1) << '\n';
	}

	

	return 0;

}