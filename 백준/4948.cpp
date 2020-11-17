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

vector<int>prime;
bool is_prime[300001];
int Max = 300000;

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	memset(is_prime, 1, sizeof(is_prime));
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i <= Max; ++i) {
		if (!is_prime[i])continue;
		prime.push_back(i);
		for (int j = 2; i*j <= Max; ++j)is_prime[i*j] = false;
	}

	int n;
	while (cin >> n && n != 0) {
		int ans = upper_bound(prime.begin(), prime.end(), 2 * n) - lower_bound(prime.begin(), prime.end(), n + 1);
		cout << ans << '\n';
	}

	return 0;

}