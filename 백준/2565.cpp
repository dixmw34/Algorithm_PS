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

int dx[] = { -1, 0, 1, 0, -1, -1, 1, 1 };
int dy[] = { 0, 1, 0, -1, -1, 1, -1, 1 };

//----------------------------------------------------

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, a, b;
	vector<pi>arr;
	vector<int>ans;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		arr.push_back(pi(a, b));
	}

	sort(arr.begin(), arr.end());

	for (int i = 0; i < n; i++) {
		if (ans.empty() || ans.back() < arr[i].second)ans.push_back(arr[i].second);
		else {
			int idx = lower_bound(ans.begin(), ans.end(), arr[i].second) - ans.begin();
			ans[idx] = arr[i].second;
		}
	}

	cout << n - ans.size() << '\n';

	return 0;

}