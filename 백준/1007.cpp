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

pi a[20];

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> a[i].first >> a[i].second;
		}
		double ans = INF;
		vector<bool>v(n, true);
		for (int i = 0; i < n / 2; ++i)
			v[i] = false;

		do {
			double x = 0, y = 0;
			for (int i = 0; i < n; ++i) {
				if (v[i]) {
					x += a[i].first, y += a[i].second;
				}
				else {
					x -= a[i].first, y -= a[i].second;
				}
			}
			ans = min(ans, sqrt(x*x + y * y));
		} while (next_permutation(v.begin(), v.end()));

		printf("%.10lf\n", ans);
	}

	return 0;
}