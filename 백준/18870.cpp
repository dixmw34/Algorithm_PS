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

map<int, int>m;
int a[1000000];

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (m.find(a[i]) == m.end()) {
			m[a[i]] = 0;
		}
	}
	int idx = 0;
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
		it->second = idx++;
	}
	for (int i = 0; i < n; ++i) {
		cout << m[a[i]] << ' ';
	}
	cout << '\n';
	

	return 0;
}