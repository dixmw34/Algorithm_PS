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

char change(char ch) {
	if (ch == '0')return '1';
	else return '0';
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	int t, n;
	string a, b;
	cin >> t;
	while (t--) {
		cin >> n >> a >> b;
		vector<int>v;
		for (int i = n - 1; i >= 1; --i) {
			if (a[i] == b[i])continue;
			else {
				if (a[0] == b[i]) {
					v.push_back(1); v.push_back(i + 1);
					for (int k = 1; k <= i; ++k) {
						a[k] = change(a[k]);
					}
					reverse(a.begin(), a.begin() + i + 1);
				}
				else {
					v.push_back(i + 1);
					for (int k = 0; k <= i; ++k) {
						a[k] = change(a[k]);
					}
					reverse(a.begin(), a.begin() + i + 1);
				}
			}
		}
		if (a[0] != b[0]) {
			v.push_back(1);
			a[0] = change(a[0]);
		}
		cout << v.size() << ' ';
		for (int i = 0; i < v.size(); ++i)cout << v[i] << ' ';
		cout << '\n';
	}

	return 0;

}