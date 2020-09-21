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

vector<vector<int>>arr(21);

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	int n, k;
	string s;
	cin >> n >> k;

	for (int i = 0; i < n; ++i) {
		cin >> s;
		arr[s.size()].push_back(i);
	}

	ll ans = 0;

	for (int i = 2; i <= 20; ++i) {
		for (int j = 0; j < arr[i].size(); ++j) {
			int idx = upper_bound(arr[i].begin(), arr[i].end(), arr[i][j] + k) - arr[i].begin();
			ans += (ll)(idx - j - 1);
		}
	}

	cout << ans << '\n';


	return 0;

}