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

string s;
int n;

int cal(int a, int b, char op) {
	if (op == '+')return a + b;
	else if (op == '-')return a - b;
	else if (op == '*')return a * b;
}

int sol(int idx, int result) {

	char op = s[idx];

	if (idx >= n)return result;
	if (idx + 2 >= n)return cal(result, s[idx + 1] - '0', op);
	else {
		return max(sol(idx + 2, cal(result, s[idx + 1] - '0', op)), sol(idx + 4, cal(result, cal(s[idx + 1] - '0', s[idx + 3] - '0', s[idx + 2]), op)));
	}
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	cin >> n >> s;
	s = "+" + s;

	cout << sol(0, 0) << '\n';
	



	return 0;

}