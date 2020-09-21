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

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		
		int n;
		ll k;

		cin >> n >> k;

		ll left = 0, right = 0, ans;

		vector<ll>L(n), M(n), G(n);
		for (int i = 0; i < n; ++i) {
			cin >> L[i];
			right = max(right, L[i]);
			cin >> M[i];
			M[i] = L[i] - M[i];
			cin >> G[i];
		}

		

		while (left <= right) {
			ll mid = (left + right) / 2;
			ll test = 0;

			for (int i = 0; i < n; ++i) {
				if (mid < M[i])continue;
				else if (M[i] <= mid && L[i] > mid)test += (mid - M[i]) / G[i] + 1;
				else test += (L[i] - M[i]) / G[i] + 1;
			}

			if (test >= k) {
				ans = mid;
				right = mid - 1;
			}
			else left = mid + 1;
		}
		cout << ans << '\n';
	}
	

	return 0;

}