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
	cin.tie(NULL); std::cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		
		int n, x, test = 0;
		cin >> n >> x;
		vector<int>a(n);
		int sum = 0;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			if (a[i] == x)test++;
			sum += a[i];
		}

		sort(a.begin(), a.end());
		if (a[0] == x && a[n - 1] == x)cout << 0 << '\n';
		else if (x*n == sum || test)cout << 1 << '\n';
		else cout << 2 << '\n';

	}
	

	return 0;

}