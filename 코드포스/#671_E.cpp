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

bool prime(int num) {
	if (num < 2)return false;
	for (int i = 2; i <= sqrt(num); ++i) {
		if (num%i == 0)return false;
	}
	return true;
}

ll a[100000];

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int>a;
		map<int, bool>m;
		for (int i = 2; i <= sqrt(n); ++i) {
			if (n%i == 0) {
				a.push_back(i);
				if (i*i != n)a.push_back(n/i);
				m[i] = m[n / i] = true;
			}
		}
		if (a.size() == 2 && prime(a[0]) && prime(a[1])) {
			cout << a[0] << ' ' << a[1] << ' ' << n << '\n' << 1 << '\n';
			continue;
		}
		sort(a.begin(), a.end());

		int start = n / a[0];
		vector<vector<int>>ans;
		for (int i = 0; i < a.size(); ++i) {
			if (prime(a[i])) {
				ans.push_back({ start*a[i], a[i] });
				m[a[i]] = m[start*a[i]] = false;
				start = a[i];
			}
		}
		for (int i = 0; i < a.size(); ++i) {
			if (!m[a[i]])continue;
			for (int j = 0; j < ans.size(); ++j) {
				if (a[i] % ans[j][1] == 0) {
					ans[j].push_back(a[i]);
					break;
				}
			}
		}

		for (int i = 0; i < ans.size(); ++i) {
			for (int j = 0; j < ans[i].size(); ++j) {
				cout << ans[i][j] << ' ';
			}
		}
		cout << '\n' << 0 << '\n';
		m.clear();
	}

	

	return 0;

}