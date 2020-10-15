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

int a[100000], cache[100000][6];

int sol(int idx, int cnt, int left) {
	if (idx < 0)return -INF;
	if (cnt == 0)return 0;
	if (cache[idx][left] != -1)return cache[idx][left];

	cache[idx][left] = a[idx] + sol(idx + 1, cnt-1, left);
	if (left && idx > 0)cache[idx][left] = max(cache[idx][left], sol(idx - 1, cnt-1, left-1) + a[idx]);

	return cache[idx][left];
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	int t;

	cin >> t;
	while (t--) {
		int n, k, z;
		cin >> n >> k >> z;
		for (int i = 0; i < n; ++i) cin >> a[i];

		memset(cache, -1, sizeof(cache));

		cout << sol(1, k, z) + a[0] << '\n';
	}

	return 0;

}