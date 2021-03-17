#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int>par(200000), num(200000, 1);

int find(int x) {
    if (x == par[x])
        return x;
    else
        return par[x] = find(par[x]);
}

int merge(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b)
        return num[a];
    if (a > b)swap(a, b);
    num[a] += num[b];
    num[b] = 0;
    par[b] = a;

    return num[a];
}

int solution(vector<int> stones, int k) {

    map<int, vector<int>>m;
    for (int i = 0; i < stones.size(); ++i) {
        m[stones[i]].push_back(i);
        par[i] = i;
    }

    if (k == 1) {
        return m.begin()->first;
    }

    vector<bool>zero(stones.size(), false);

    for (auto x : m) {
        for (int i = 0; i < x.second.size(); ++i) {
            zero[x.second[i]] = true;
            if (x.second[i] > 0 && zero[x.second[i] - 1]) {
                int result = merge(x.second[i] - 1, x.second[i]);
                if (result >= k)
                    return x.first;
            }
            if (x.second[i] < stones.size() - 1 && zero[x.second[i] + 1]) {
                int result = merge(x.second[i] + 1, x.second[i]);
                if (result >= k)
                    return x.first;
            }
        }

    }

    return 0;
}