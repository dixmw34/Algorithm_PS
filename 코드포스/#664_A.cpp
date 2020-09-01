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

int dx[] = { -1, 1, 0, 0, -1, -1, 1, 1 };
int dy[] = { 0, 0, -1, 1, -1, 1, -1, 1 };

//----------------------------------------------------

bool test(vector<ll>a) {
	int odd = 0;
	int even = 0;

	for (int i = 0; i < 4; i++) {
		if (a[i] % 2)odd++;
		else even++;
	}
	if (even >= 3)return true;
	else return false;

}


int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	ll t, a, b, c, d;

	cin >> t;
	while (t--) {
		cin >> a >> b >> c >> d;

		bool check = test({ a, b, c, d });
		if (!check && a > 0 && b > 0 && c > 0) {
			check = test({ a-1, b-1, c-1, d+3 });
		}

		if (check)cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
	

}