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

int test[13], fac[5] = { 1, 16, 256, 4096, 65536 };
bool visit[16];
vector<string>ans;

int cal(vector<int>a) {
	int result = 0;
	for (int i = 0; i < a.size(); ++i) {
		result += fac[i]*a[i];
	}
	return result;
}

bool check(int num) {
	vector<bool>v(16, false);
	if (num / fac[4] != 1)return false;
	num %= fac[4];
	if (num / fac[3] != test[2])return false;
	num %= fac[3];
	for (int i = 2; i >= 0; --i) {
		if (visit[num / fac[i]] || v[num / fac[i]])return false;
		v[num / fac[i]] = true;
		num %= fac[i];
	}
	return true;
}

void dfs(int cnt) {
	if (cnt == 5) {
		int list = cal({ test[2], 1, test[1], test[0] });
		int filo = cal({ test[4], test[0], test[1], test[3] });
		int stack = list + filo;
		if (check(stack)) {
			string s = "";
			for (int i = 3; i >= 0; --i) {
				int num = list / fac[i];
				if (num < 10)s+=to_string(num);
				else s += (char)(num - 10 + 'a');
				list -= num * fac[i];
			}
			s+= " + ";
			for (int i = 3; i >= 0; --i) {
				int num = filo / fac[i];
				if (num < 10)s += to_string(num);
				else s += (char)(num - 10 + 'a');
				filo -= num * fac[i];
			}
			s+= " = ";
			for (int i = 4; i >= 0; --i) {
				int num = stack / fac[i];
				if (num < 10)s += to_string(num);
				else s += (char)(num - 10 + 'a');
				stack -= num * fac[i];
			}
			cout << s << '\n';
		}
		return;
	}

	for (int i = 0; i < 16; ++i) {
		if (i == 0 && (cnt == 0 || cnt == 3))continue;
		if (i == 1)continue;
		if (!visit[i]) {
			test[cnt] = i;
			visit[i] = true;
			dfs(cnt + 1);
			visit[i] = false;
		}
	}
	return;
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	memset(visit, 0, sizeof(visit));
	visit[1] = true;
	dfs(0);
	

	return 0;

}