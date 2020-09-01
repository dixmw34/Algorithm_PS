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
typedef unsigned long long ull;

int dx[] = { -1, 0, 1, 0, -1, -1, 1, 1 };
int dy[] = { 0, 1, 0, -1, -1, 1, -1, 1 };

//----------------------------------------------------

int len(int num) {
	int l = 0;
	while (num) {
		num /= 10;
		l++;
	}
	return l;
}
int sol(int num) {
	int r = 0;
	while (num) {
		r += num % 10;
		num /= 10;
	}
	return r;
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, l;
	cin >> n;
	l = len(n);

	for (int i = max(0, n - 9 * l); i <= min(1000000, n + 9 * l); i++) {
		int a = i + sol(i);
		if (a == n) {
			cout << i << '\n';
			return 0;
		}
	}

	cout << 0 << '\n';

	return 0;

}