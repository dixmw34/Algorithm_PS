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

int dx[] = { -1, 1, 0, 0, -1, -1, 1, 1 };
int dy[] = { 0, 0, -1, 1, -1, 1, -1, 1 };

//----------------------------------------------------

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int>arr(n);
		for (int i = n-1; i >= 0; i--)cin >> arr[i];

		ll ans = 0;

		for (int i = 0; i < n-1; i++) {
			if (arr[i] < arr[i + 1]) {
				ans += (ll)(arr[i + 1] - arr[i]);
			}
		}
		cout << ans << '\n';
	}

	return 0;
	

}