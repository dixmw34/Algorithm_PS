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

const ll mod = 1e9 + 7;

ll fac(ll num) {
	ll result = 1;
	for (ll i = 2; i <= num; i++) {
		result = (result*i) % mod;
	}
	return result;
}

ll ind(ll num) {
	ll result = 1;
	for (ll i = 1; i <= num; i++) {
		result = (result*2) % mod;
	}
	return result;
}



int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	ll result = fac(n) - ind(n - 1);

	if (result < 0)result += mod;

	cout << result << '\n';


	return 0;

}