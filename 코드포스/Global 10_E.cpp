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

ll a[25][25];

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, q;
	ll num;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i % 2 == 0)a[i][j] = 0;
			else a[i][j] = (1LL << (i + j + 2));
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}
	cout.flush();
	cin >> q;
	while (q--) {
		cin >> num;

		stack<pi>s;
		int x = n - 1, y = n - 1;

		while (1) {
			s.push(pi(x, y));
			num -= a[x][y];
			if (num == 0)break;

			if (y == 0) {
				x--;
			}
			else {
				if (a[x - 1][y] != 0) {
					if (a[x - 1][y] <= num)x--;
					else y--;
				}
				else {
					if (a[x][y - 1] <= num)y--;
					else x--;
				}
			}
		}
		while (x) {
			x--;
			s.push(pi(x, y));
		}
		while (y) {
			y--;
			s.push(pi(x, y));
		}

		while (!s.empty()) {
			cout << s.top().first + 1 << ' ' << s.top().second + 1 << '\n';
			s.pop();
		}
		cout.flush();

	}


	return 0;

}