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

	int t, n;
	ll ans, max_num;
	cin >> t;
	while (t--) {
		cin >> n;
		ans = 0;
		vector<ll>arr(n);
		for (int i = n - 1; i >= 0; i--)cin >> arr[i];
		max_num = arr[0];
		ll num = 0;
		for (int i = 1; i < n; i++) {
			if (max_num > arr[i]) {
				num++;
				ans -= arr[i];
			}
			else {
				ans += num * max_num;
				num = 0;
				max_num = arr[i];
			}
		}
		ans += num * max_num;
		cout << ans << '\n';
	}

	return 0;

}