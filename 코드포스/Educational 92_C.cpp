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
	cin.tie(NULL); cout.tie(NULL);

	int t;
	string s;
	cin >> t;
	while (t--) {
		cin >> s;
		int ans = s.size() - 2, mx = 0, num = 0, n = s.size();
		//cout << n << '\n';
		vector<vector<int>>arr(10);
		for (int i = 0; i < n; i++) {
			arr[s[i] - '0'].push_back(i);
			mx = max(mx, (int)arr[s[i] - '0'].size());
		}
		mx = max(mx, num);
		//cout << mx << '\n';
		ans = min(ans, n - mx);

		for (int i = 0; i <= 9; i++) {
			for (int j = 0; j <= 9; j++) {
				if (i == j || arr[i].empty() || arr[j].empty())continue;
				num = 0;
				int x = 0, y = 0;
				while (x < arr[i].size() && y < arr[j].size()) {
					if (arr[i][x] < arr[j][y]) {
						num += 2;
						while (x < arr[i].size() && arr[j][y] > arr[i][x])x++;
					}
					y++;
				}
				//cout << i << ' ' << j << " : " << n - num << '\n';
				ans = min(ans, n - num);
			}
		}

		cout << ans << '\n';

	}



	return 0;

}