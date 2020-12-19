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

int dp[59050];

int check(string s) {
	int num = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == 'o') {
			num += pow(3, i);
		}
		else if (s[i] == 'x') {
			num += pow(3, i) * 2;
		}
	}
	return num;
}

bool isFinished(string board, char turn) {
	if (turn == board[0] && turn == board[1] && turn == board[2])return true;
	if (turn == board[3] && turn == board[4] && turn == board[5])return true;
	if (turn == board[6] && turn == board[7] && turn == board[8])return true;
	if (turn == board[0] && turn == board[3] && turn == board[6])return true;
	if (turn == board[1] && turn == board[4] && turn == board[7])return true;
	if (turn == board[2] && turn == board[5] && turn == board[8])return true;
	if (turn == board[0] && turn == board[4] && turn == board[8])return true;
	if (turn == board[2] && turn == board[4] && turn == board[6])return true;
	return false;
}

int sol(string s, char ch) {
	int num = check(s);
	if (dp[num] != -2)return -dp[num];

	int result = -2;
	char op = (ch == 'o' ? 'x' : 'o');

	if (isFinished(s, op)) {
		dp[num] = -1;
		return 1;
	}

	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '.') {
			string a = s;
			a[i] = ch;
			result = max(result, sol(a, op));
		}
	}

	if (result == -2)result = 0;

	dp[num] = result;
	return -result;
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	for (int i = 0; i < 59050; ++i) {
		dp[i] = -2;
	}

	int t;
	cin >> t;
	while (t--) {
		string s1, s2, s3, s;
		cin >> s1 >> s2 >> s3;
		s = s1 + s2 + s3;

		int name = 0;
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] == 'x')name++;
			else if (s[i] == 'o')name--;
		}
		char ch, op;
		if (name == 0) {
			ch = 'x', op = 'o';
		}
		else {
			ch = 'o', op = 'x';
		}
		int result = sol(s, ch);
		if (result == 0) {
			cout << "TIE\n";
		}
		else if (result == 1) {
			cout << op << '\n';
		}
		else
			cout << ch << '\n';

	}

	
	return 0;
}