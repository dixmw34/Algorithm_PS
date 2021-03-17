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

int sol(int a, int b) {
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

	int a1, b1, a2, b2;
	cin >> a1 >> b1 >> a2 >> b2;

	int ans_b = b1 * b2, ans_a = a1 * b2 + a2 * b1;

	int num = sol(ans_a, ans_b);

	cout << ans_a / num << ' ' << ans_b / num << '\n';

	return 0;
}