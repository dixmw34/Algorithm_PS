#include <string>
#include <vector>

using namespace std;

vector<vector<int>>arr;
vector<bool>visit(12, false);
int n, ans = 0;

bool check(int _x, int _y) {
    int x = _x, y = _y;
    while (1) {
        if (--x < 0 || --y < 0)
            break;
        if (arr[x][y])
            return false;
    }
    x = _x, y = _y;
    while (1) {
        if (--x < 0 || ++y >= n)
            break;
        if (arr[x][y])
            return false;
    }
    return true;
}

void func(int x) {
    if (x == n) {
        ans++;
        return;
    }
    for (int y = 0; y < n; ++y) {
        if (!visit[y] && check(x, y)) {
            arr[x][y] = 1;
            visit[y] = true;
            func(x + 1);
            arr[x][y] = 0;
            visit[y] = false;
        }
    }

}

int solution(int _n) {
    n = _n;
    arr = vector<vector<int>>(n, vector<int>(n, 0));

    func(0);

    return ans;
}