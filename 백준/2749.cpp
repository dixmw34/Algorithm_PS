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

int dx[] = { -1, 0, 1, 0, -1, -1, 1, 1 };
int dy[] = { 0, 1, 0, -1, -1, 1, -1, 1 };

//----------------------------------------------------

const ll re = 1500000;
const int Mod = 1000000;

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	ll num;
	cin >> num;
	num %= re;
	if (num == 0) {
		cout << 0 << '\n';
		return 0;
	}
	ll i = 1;
	int one = 0, two = 1;
	while (i<num) {
		int r = two;
		two = (one + two) % Mod;
		one = r;
		++i;
	}
	cout << two << '\n';

	


	return 0;

}