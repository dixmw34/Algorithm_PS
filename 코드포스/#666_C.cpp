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

	int n;
	cin >> n;
	vector<ll>a(n);

	for (int i = 0; i < n; i++)cin >> a[i];

	if (n == 1) {
		cout << "1 1\n" << -a[0] << '\n';
		cout << "1 1\n" << 0 << '\n';
		cout << "1 1\n" << 0 << '\n';
	}
	else {
		cout << "1 1\n" << -a[0] << '\n';
		a[0] = 0;
		cout << "2 " << n << "\n";

		for (int i = 1; i < n; i++) {
			cout << a[i] * (n - 1) << ' ';
			a[i] += a[i] * (n - 1);
		}
		cout << '\n';

		cout << "1 " << n << "\n";
		for (int i = 0; i < n; i++) {
			cout << -a[i] << ' ';
		}
		cout << '\n';
	}

	

	return 0;

}