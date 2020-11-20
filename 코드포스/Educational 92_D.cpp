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

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		ll n, k;
		pair<ll, ll> p[2];
		ll ans = 0;
		cin >> n >> k;
		cin >> p[0].first >> p[0].second >> p[1].first >> p[1].second;

		if (p[0].first > p[1].first)swap(p[0], p[1]);

		if (p[0].second < p[1].first) {
			for (int i = 0; i < n; ++i) {
				ans += (p[1].first - p[0].second);
				ll test = (p[1].second - p[0].first);
				if (test >= k) {
					ans += k;
					k = 0;
					break;
				}
				else {
					ans += (p[1].second - p[0].first);
					k -= (p[1].second - p[0].first);
					if (k > (p[1].second - p[0].first) && (p[1].second - p[0].first) * 2 < (p[1].second - p[0].first) + (p[1].first - p[0].second)) {
						ans += 2 * k;
						k = 0;
						break;
					}
					else if (k <= (p[1].second - p[0].first) && k * 2 < (p[1].first - p[0].second) + k) {
						ans += 2 * k;
						k = 0;
						break;
					}
				}
			}
			if (k > 0)ans += 2 * k;
		}
		else if (p[0].second < p[1].second) {
			ll test = (-p[1].first + p[0].second)*n;
			if (test < k) {
				if ((p[1].second - p[0].first)*n < k) {
					ans = (p[1].first - p[0].first + p[1].second - p[0].second)*n;
					k -= (p[1].second - p[0].first)*n;
					ans += 2 * k;
				}
				else
					ans = k - test;
			}
		}
		else {
			ll test = (p[1].second - p[1].first)*n;
			if (test < k) {
				if ((p[0].second - p[0].first)*n < k) {
					ans = (p[1].first - p[0].first - p[1].second + p[0].second)*n;
					k -= (p[0].second - p[0].first)*n;
					ans += 2 * k;
				}
				else
					ans = k - test;
			}
		}

		cout << ans << '\n';

	}
	
	
	return 0;

}
