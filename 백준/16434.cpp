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

struct Room
{
	int t;
	ll a;
	ll h;

};

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	int n;
	ll atk;
	cin >> n >> atk;

	vector<Room>arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i].t >> arr[i].a >> arr[i].h;
	}

	ll left = 1, right = LLONG_MAX, ans;
	while (left <= right) {
		ll mid = (left + right) / 2;
		ll test_h = mid, test_a = atk;

		for (int i = 0; i < n; ++i) {
			if (arr[i].t == 1) {
				test_h -= ((arr[i].h - 1) / test_a) * arr[i].a;
				if (test_h <= 0)break;
			}
			else {
				test_a += arr[i].a;
				test_h = min(test_h + arr[i].h, mid);
			}
		}

		if (test_h > 0) {
			ans = mid;
			right = mid - 1;
		}
		else left = mid + 1;

	}

	cout << ans << '\n';

	return 0;

}