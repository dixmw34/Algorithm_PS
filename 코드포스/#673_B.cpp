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

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int n, k, test = 0, a;
		cin >> n >> k;
		vector<int>ans(n, 0);
		if (k % 2) {
			for (int i = 0; i < n; ++i) {
				cin >> a;
				if (a <= k / 2)ans[i] = 0;
				else ans[i] = 1;
			}
		}
		else {
			for (int i = 0; i < n; ++i) {
				cin >> a;
				if (a < k / 2)ans[i] = 0;
				else if (a == k / 2) {
					ans[i] = test;
					test = 1 - test;
				}
				else ans[i] = 1;
			}
		}

		for (int i = 0; i < n; ++i) {
			cout << ans[i] << ' ';
		}
		cout << '\n';
		
	}

	return 0;

}