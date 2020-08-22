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

int dx[] = { -1, 0, 1, 0, -1, -1, 1, 1 };
int dy[] = { 0, 1, 0, -1, -1, 1, -1, 1 };

//----------------------------------------------------

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	int a[3];
	int b[3];
	cin >> t;
	while (t--) {
		for (int i = 0; i < 3; i++)cin >> a[i];
		for (int i = 0; i < 3; i++)cin >> b[i];

		int ans = 0;

		if (b[2] > (a[0] + a[2])) {
			b[2] -= (a[0] + a[2]);
			a[0] = a[2] = 0;
			ans -= b[2] * 2;
		}
		else {
			if (b[2] > a[0]) {
				b[2] -= a[0];
				a[0] = 0;
				a[2] -= b[2];
				b[2] = 0;
				ans = 2 * min(a[2], b[1]);
			}
			else {
				ans = 2 * min(a[2], b[1]);
			}
		}

		cout << ans << '\n';
		
	}

	return 0;

}