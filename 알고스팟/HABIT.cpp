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
#include<cassert>

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

int sol(string a, string b) {
	int i = 0, n = min(a.size(), b.size());
	while (i < n) {
		if (a[i] != b[i])
			break;
		i++;
	}
	return i;
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int k;
		string s;
		cin >> k >> s;
		vector<string>arr;
		for (int i = 0; i < s.size(); ++i) {
			arr.push_back(s.substr(i, s.size() - i));
		}
		sort(arr.begin(), arr.end());
		int ans = 0;
		for (int i = 0; i + k <= arr.size(); ++i) {
			ans = max(ans, sol(arr[i], arr[i + k - 1]));
		}
		cout << ans << '\n';
	}

	return 0;
}