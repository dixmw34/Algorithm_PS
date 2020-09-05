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

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t, n, one, num;
	cin >> t;
	while (t--) {
		cin >> n;
		one = 0;
		vector<int>a(n);
		for (int i = 0; i < n; ++i)cin >> a[i];

		for (int i = 0; i < n; ++i) {
			if (a[i] == 1)one++;
			else {
				if (i % 2)cout << "Second\n";
				else cout << "First\n";
				break;
			}
		}
		if (one == n) {
			if(one%2)cout << "First\n";
			else cout << "Second\n";
		}

	}



	return 0;

}