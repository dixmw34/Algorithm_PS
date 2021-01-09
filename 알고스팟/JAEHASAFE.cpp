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

vector<int>maketable(string a) {
	int n = a.size();
	vector<int>table(n, 0);
	int j = 0;
	for (int i = 1; i < n; ++i) {
		while (a[i] != a[j] && j > 0) {
			j = table[j - 1];
		}
		if (a[i] == a[j]) {
			table[i] = ++j;
		}
	}
	return table;
}

int sol(string a, string b) {
	int n = a.size(), m = b.size();
	vector<int>table = maketable(b);
	int j = 0;
	for (int i = 0; i < n; ++i) {
		while (a[i] != b[j] && j > 0) {
			j = table[j - 1];
		}
		if (a[i] == b[j]) {
			j++;
			if (j == m) {
				return i - m + 1;
			}
		}
	}
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, ans = 0;
		cin >> n;
		vector<string>arr(n + 1);
		for (int i = 0; i <= n; ++i)
			cin >> arr[i];
		for (int i = 0; i < n; ++i) {
			if (i % 2 == 1) {
				ans += sol(arr[i] + arr[i], arr[i + 1]);
			}
			else {
				ans += sol(arr[i + 1] + arr[i + 1], arr[i]);
			}
		}
		cout << ans << '\n';
	}
	

	return 0;
}