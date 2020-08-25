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

	int t, n, m;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		int num = -1;
		vector<int>a(n);
		vector<int>b(m);
		set<int>s;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			s.insert(a[i]);
		}
		for (int i = 0; i < m; i++) {
			cin >> b[i];
		}
		for (int i = 0; i < m; i++) {
			if (s.find(b[i]) != s.end()) {
				num = b[i];
				break;
			}
		}
		if (num == -1)cout << "NO\n";
		else {
			cout << "YES\n";
			cout << 1 << ' ' << num << '\n';
		}
	}

	
	return 0;

}