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

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	map<string, int>m1;
	map<int, string>m2;

	int n, q;
	string s;
	cin >> n >> q;
	for (int i = 0; i < n; ++i) {
		cin >> s;
		m1.insert(make_pair(s, i));
		m2.insert(make_pair(i, s));
	}
	while (q--) {
		cin >> s;
		if (s[0] >= 'A' && s[0] <= 'Z') {
			cout << m1[s] + 1 << '\n';
		}
		else {
			int num = stoi(s);
			cout << m2[num-1] << '\n';
		}
	}
	

	
	return 0;

}