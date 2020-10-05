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

int dx[] = { -1, 0, 1, 0, -1, -1, 1, 1 };
int dy[] = { 0, 1, 0, -1, -1, 1, -1, 1 };

//----------------------------------------------------

ll a[100000];

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i)cin >> a[i];
		sort(a, a + n);
		ll ans = LLONG_MIN;
		int aa = n - 1, bb = n - 2, cc = n - 3, dd = n - 4, ee = n - 5;
		for (int i = 0; i < 5; ++i) {
			ans = max(ans, a[aa] * a[bb] * a[cc] * a[dd] * a[ee]);
			aa = (aa + 1) % n;
			bb = (bb + 1) % n;
			cc = (cc + 1) % n;
			dd = (dd + 1) % n;
			ee = (ee + 1) % n;
		}
		cout << ans << '\n';
	}

	

	return 0;

}