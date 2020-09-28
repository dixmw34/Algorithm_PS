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

int gcd(int a, int b) {
	while (a%b) {
		int r = a % b;
		a = b;
		b = r;
	}
	return b;
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int>r(n);
		cin >> r[0];
		int num = r[0];
		for (int i = 1; i < n; ++i) {
			cin >> r[i];
			num = gcd(num, r[i]);
		}
		int mx = 0;
		vector<int>p(n);
		for (int i = 0; i < n; ++i) {
			cin >> p[i];
			mx = max(mx, (p[i] - r[i] + (r[i]/num) - 1) / (r[i] / num));
		}
		for (int i = 0; i < n; ++i) {
			cout << mx * (r[i] / num) + r[i] - p[i] << ' ';
		}
		cout << '\n';
	}

	return 0;

}