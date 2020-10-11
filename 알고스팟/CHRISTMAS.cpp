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

const int Mod = 20091101;

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	int c;
	cin >> c;
	while (c--) {

		int n, k, num;
		cin >> n >> k;
		vector<int>a(n + 1);
		a[0] = 0;
		for (int i = 1; i <= n; ++i) {
			cin >> num;
			a[i] = (a[i - 1] + num) % k;
		}

		vector<pi>ans(k, pi(0, 0));//first:개수, second:위치
		ans[0].first = 1;
		int ans_cnt = 0, ans_max = 0, end = -1;
		for (int i = 1; i <= n; ++i) {
			if (ans[a[i]].first > 0) {
				ans_cnt = (ans_cnt + ans[a[i]].first) % Mod;
				if (end <= ans[a[i]].second) {
					end = i;
					ans_max++;
				}
			}
			ans[a[i]].first++;
			ans[a[i]].second = i;
		}
		cout << ans_cnt << ' ' << ans_max << '\n';
		
	}

	return 0;

}