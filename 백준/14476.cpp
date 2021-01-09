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
#include <cassert>

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

int num[1000000], _left[1000000], _right[1000000];

int gcd(int a, int b) {
	if (a*b == 0)return max(a, b);
	while (a%b) {
		int r = a % b;
		a = b;
		b = r;
	}
	return b;
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> num[i];
	_left[0] = num[0];
	for (int i = 1; i < n; ++i) {
		_left[i] = gcd(num[i], _left[i - 1]);
	}
	_right[n - 1] = num[n - 1];
	for (int i = n - 2; i >= 0; --i) {
		_right[i] = gcd(num[i], _right[i + 1]);
	}

	pi ans = pi(-1, -1);
	for (int i = 0; i < n; ++i) {
		int left = 0, right = 0;
		if (i != 0)left = _left[i - 1];
		if (i != n - 1)right = _right[i + 1];
		int test = gcd(left, right);
		if (num[i] % test != 0 && ans.first < test) {
			ans = pi(test, num[i]);
		}
	}
	if (ans.first != -1) {
		cout << ans.first << ' ' << ans.second << '\n';
	}
	else
		cout << -1 << '\n';




	return 0;
}