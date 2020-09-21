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

bool cmp(pi a, pi b) {
	if (a.second == b.second)return a.first > b.first;
	else return a.second < b.second;
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	int t, n, m, a, b;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		vector<bool>book(n + 1, false);
		vector<pi>arr(m);
		for (int i = 0; i < m; ++i) {
			cin >> arr[i].first >> arr[i].second;
		}
		sort(arr.begin(), arr.end(), cmp);
		int ans = 0;
		for (int i = 0; i < m; ++i) {
			for (int j = arr[i].first; j <= arr[i].second; ++j) {
				if (!book[j]) {
					book[j] = true;
					ans++;
					break;
				}
			}
		}
		cout << ans << '\n';
	}


	return 0;

}