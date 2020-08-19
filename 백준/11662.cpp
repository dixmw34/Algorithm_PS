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

double getdistance(double x1, double y1, double x2, double y2) {
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	double ax, ay, bx, by, cx, cy, dx, dy, ans = 100000.0;
	int N = 1000000;

	cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;

	double Mx = (bx - ax) / (double)(N), My = (by - ay) / (double)(N);
	double Gx = (dx - cx) / (double)(N), Gy = (dy - cy) / (double)(N);

	for (int i = 0; i <= N; i++) {
		ans = min(ans, getdistance(ax, ay, cx, cy));
		ax += Mx; ay += My; cx += Gx; cy += Gy;
	}
	
	printf("%.10lf\n", ans);

	return 0;

}