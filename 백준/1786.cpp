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

vector<int>makeTable(string p) {
	int n = p.size(), j = 0;
	vector<int>table(n, 0);
	for (int i = 1; i < n; ++i) {
		while (j > 0 && p[i] != p[j]) {
			j = table[j - 1];
		}
		if (p[i] == p[j]) {
			table[i] = ++j;
		}
	}
	return table;
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	string a, b;
	getline(cin, a);
	cin.clear();
	getline(cin, b);
	cin.clear();

	vector<int>table = makeTable(b);
	vector<int>ans;

	int n = a.size(), m = b.size(), j = 0;
	for (int i = 0; i < n; ++i) {
		while (j > 0 && a[i] != b[j]) {
			j = table[j - 1];
		}
		if (a[i] == b[j]) {
			++j;
			if (j == m) {
				ans.push_back(i - m + 2);
				j = table[j - 1];
			}
		}
	}

	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i] << ' ';
	}
	cout << '\n';

	return 0;

}