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

int dx[] = { -1, 0, 1, 0, -1, -1, 1, 1 };
int dy[] = { 0, 1, 0, -1, -1, 1, -1, 1 };

//----------------------------------------------------

int par[100000], num[100000];
int find(int x) {
	if (x == par[x])return x;
	return par[x] = find(par[x]);
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	int n, m, x, y, k;
	cin >> n >> m;
	memset(num, 0, sizeof(num));
	for (int i = 0; i < n; ++i) {
		par[i] = i;
		num[i] = 1;
	}
	
	while (m--) {
		cin >> x >> y;
		x = find(x);
		y = find(y);
		if (x != y) {
			if (x > y)swap(x, y);
			par[y] = x;
			num[x] += num[y];
			num[y] = 0;
		}
	}

	cin >> x >> y >> k;

	int ans = num[find(x)];

	num[find(x)] = 0;
	num[find(y)] = 0;

	sort(num, num + 100000, greater<int>());

	for (int i = 0; i < k; ++i) {
		ans += num[i];
	}
	cout << ans << '\n';

	return 0;

}