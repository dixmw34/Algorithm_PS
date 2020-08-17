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

int dx[] = { -1, 1, 0, 0, -1, -1, 1, 1 };
int dy[] = { 0, 0, -1, 1, -1, 1, -1, 1 };

//----------------------------------------------------

const int MIN = -1e9 - 1;

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int>arr(n);
		deque<int>dq;
		for (int i = 0; i < n; i++) cin >> arr[i];

		sort(arr.begin(), arr.end());

		for (int i = 0; i < n; i++) {
			if (i % 2)dq.push_back(arr[i]);
			else dq.push_front(arr[i]);
		}

		int ans = abs(dq.front() - dq.back());

		for (int i = 0; i < n-1; i++) {
			ans = max(ans, abs(dq[i + 1] - dq[i]));
		}

		cout << ans << '\n';

	}

	return 0;

}