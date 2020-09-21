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

int ask(int a, int b) {
	int c;
	cout << "? " << a + 1 << ' ' << b + 1 << endl;
	cin >> c;
	return c;
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	int n;
	cin >> n;

	vector<int>ans(n);

	int mx = 0;

	for (int i = 1; i < n; ++i) {
		int a = ask(i, mx);
		int b = ask(mx, i);

		if (a > b) {
			ans[i] = a;
		}
		else {
			ans[mx] = b;
			mx = i;
		}
	}
	ans[mx] = n;
	cout << "! ";
	for (int i = 0; i < n; ++i) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
	


	return 0;

}