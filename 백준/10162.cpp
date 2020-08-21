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

	int n, a = 60 * 5, b = 60, c = 10;
	cin >> n;

	if (n%c != 0) {
		cout << -1 << '\n';
	}
	else {
		cout << n / a << ' ';
		n %= a;
		cout << n / b << ' ';
		n %= b;
		cout << n / c << '\n';
	}


	return 0;

}