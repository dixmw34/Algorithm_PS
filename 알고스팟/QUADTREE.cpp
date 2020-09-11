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

string s;
int idx = 0;

string sol() {
	if (s[idx] == 'x') {
		++idx;
		string a = sol();
		string b = sol();
		string c = sol();
		string d = sol();
		
		return "x" + c + d + a + b;
	}
	else return string(1, s[idx++]);
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		cin >> s;
		idx = 0;
		cout << sol() << '\n';
	}

	return 0;

}