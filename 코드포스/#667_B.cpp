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
	cin.tie(NULL); cout.tie(NULL);

	int t;
	ll a, b, x, y, n;
	cin >> t;
	while (t--) {
		cin >> a >> b >> x >> y >> n;
		ll ra = max(x, a - n);
		ll rn = n - (a - ra);
		ll rb = max(y, b - rn);
		ll ans = ra * rb;
		
		rb = max(y, b - n);
		n -= b - rb;
		a = max(x, a - n);
		ans = min(ans, rb*a);

		cout << ans << '\n';
	}



	return 0;

}