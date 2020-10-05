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

vector<string>a;
int n, k;

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	cin >> n >> k;

	a = vector<string>(n);
	for (int i = 0; i < n; ++i)cin >> a[i];

	if (k < 5) {
		cout << 0 << '\n';
		return 0;
	}
	if (k == 26) {
		cout << n << '\n';
		return 0;
	}

	vector<bool>v(26, false);
	for (int i = 1; i <= k - 5; ++i) {
		v[26 - i] = true;
	}
	int ans = 0;
	do {
		if (v[0] || v['c' - 'a'] || v['i' - 'a'] || v['n' - 'a'] || v['t' - 'a'])continue;
		int test = 0;
		for (int i = 0; i < n; ++i) {
			bool flag = true;
			for (int j = 0; j < a[i].size(); ++j) {
				if (a[i][j] == 'a' || a[i][j] == 'c' || a[i][j] == 'i' || a[i][j] == 'n' || a[i][j] == 't')continue;
				else if (!v[a[i][j] - 'a']) {
					flag = false;
					break;
				}
			}
			if (flag)test++;
		}
		ans = max(ans, test);

	} while (next_permutation(v.begin(), v.end()));

	cout << ans << '\n';


	return 0;

}