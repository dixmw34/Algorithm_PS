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

const ll Max = 2000000000;

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		ll n, m, z;

		cin >> n >> m;
		z = (m*100 / n) + 1;
		
		if (((m + Max)*100 / (n + Max)) < z) {
			cout << -1 << '\n';
			continue;
		}

		ll left = 0, right = Max, ans;
		while (left <= right) {
			ll mid = (left + right) / 2;
			ll test = ((m + mid)*100) / (n + mid);
			if (test < z) {
				left = mid + 1;
			}
			else {
				ans = mid;
				right = mid - 1;
			}
		}
		cout << ans << '\n';

	}

	return 0;

}