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

int a[50];

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int n, plus = 0, minus = 0;
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			if (a[i] > 0)plus += a[i];
			else if (a[i] < 0)minus -= a[i];
		}
		if (plus == minus) {
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		sort(a, a + n);
		if (plus > minus) reverse(a, a + n);
		for (int i = 0; i < n; ++i)cout << a[i] << ' ';
		cout << '\n';
	}

	

	return 0;

}