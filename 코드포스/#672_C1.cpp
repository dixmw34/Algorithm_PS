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

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);


	int t;
	cin >> t;
	while (t--) {
		int n, q;
		cin >> n >> q;
		vector<int>a(n+1);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		a[n] = 0;
		int mx = a[0], mn = INF;
		ll ans = 0;
		for (int i = 1; i <= n; ++i) {
			if (a[i - 1] < a[i]) {
				if (a[i - 1] == mn) {
					ans += (ll)(mx - mn);
					mx = a[i];
				}
				mx = max(mx, a[i]);
			}
			else {
				if (a[i - 1] == mx) {
					mn = a[i];
				}
				mn = min(mn, a[i]);
			}
		}
		ans +=(ll)(mx - mn);
		cout << ans << '\n';
	}



	return 0;

}