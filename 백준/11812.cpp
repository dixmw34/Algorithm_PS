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

vector<bool>check(33554433, false);

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	ll n, x, y;
	int k, Q;

	cin >> n >> k >> Q;

	while (Q--) {
		cin >> x >> y;

		if (k == 1) {
			cout << abs(x - y) << '\n';
			continue;
		}

		ll test = 0;
		int depth_x = 0, depth_y = 0;
		for (int i = 0; i < 50; ++i) {
			test += pow(k, i);
			if (test >= x) {
				depth_x = i;
				break;
			}
		}

		test = 0;
		for (int i = 0; i < 50; ++i) {
			test += pow(k, i);
			if (test >= y) {
				depth_y = i;
				break;
			}
		}

		if (x > y)swap(x, y);
		int num = abs(depth_y - depth_x);
		while (num--) {
			y = ((y - 2) / k) + 1;
		}
		while (x != y) {
			x = ((x - 2) / k) + 1;
			y = ((y - 2) / k) + 1;
		}

		test = 0;
		for (int i = 0; i < 50; ++i) {
			test += pow(k, i);
			if (test >= x) {
				cout << depth_x + depth_y - 2 * i << '\n';
				break;
			}
		}
		
	}


	return 0;

}