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

int dx[] = { 0, 0, -1, 1, -1, -1, 1, 1 };
int dy[] = { 1, -1, 0, 0, -1, 1, -1, 1 };

//----------------------------------------------------

vector<map<string, int>>m(9);

void start() {
	for (int k = 1; k <= 8; ++k) {
		string a = "";
		for (int i = 1; i <= k; ++i)a += to_string(i);
		queue<string>q;
		q.push(a);
		m[k][a] = 0;
		while (!q.empty()) {
			a = q.front(); q.pop();
			int cost = m[k][a];
			for (int i = 0; i < k; ++i) {
				for (int j = i + 1; j <= k; ++j) {
					string b = a;
					reverse(b.begin() + i, b.begin() + j);
					if (m[k].find(b) == m[k].end()) {
						m[k][b] = cost + 1;
						q.push(b);
					}
				}
			}
		}
	}
}


int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	start();

	//cout << "----------\n";

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<pi>a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i].first;
			a[i].second = i + 1;
		}
		sort(a.begin(), a.end());
		string s = "";
		for (int i = 0; i < n; ++i) {
			s += to_string(a[i].second);
		}
		cout << m[n][s] << '\n';
	}


	
	return 0;

}