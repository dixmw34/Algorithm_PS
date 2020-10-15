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

int a[100000], cache[100000][2];

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)cin >> a[i];

	cache[0][0] = a[0], cache[0][1] = -INF;

	int ans = a[0];

	for (int i = 1; i < n; ++i) {
		cache[i][0] = max(cache[i - 1][0] + a[i], a[i]);
		cache[i][1] = max(cache[i - 1][1] + a[i], cache[i - 1][0]);
		ans = max(ans, max(cache[i][0], cache[i][1]));
	}

	cout << ans << '\n';
	

	return 0;

}