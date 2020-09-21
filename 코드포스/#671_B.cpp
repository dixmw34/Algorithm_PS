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

	vector<ll>arr(1, 1);
	ll n = 1;
	while (arr.size() < 30) {
		n = 2 * n + 1;
		arr.push_back(n*(n + 1) / 2);
	}
	int t;
	ll x;
	cin >> t;
	while (t--) {
		cin >> x;
		int ans = 0;
		for (; ans < 30; ++ans) {
			if (x < arr[ans])break;
			else x -= arr[ans];
		}
		cout << ans << '\n';
	}

	return 0;

}