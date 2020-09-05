#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<string>> relation) {
    int answer = 0;

    int n = relation.size(), m = relation[0].size(), v = m;
    vector<bool>visit(m, false);
    for (int i = 0; i < m; i++) {
        vector<string>a(n);
        for (int j = 0; j < n; j++) {
            a[j] = relation[j][i];
        }
        sort(a.begin(), a.end());
        if (unique(a.begin(), a.end()) == a.end()) {
            visit[i] = true;
            answer++;
            v--;
        }
    }
    int test = 2;
    vector<int>varr;
    vector<vector<int>>ans;
    for (int i = 0; i < m; i++) { if (!visit[i])varr.push_back(i); };
    while (v >= test) {
        vector<bool>arr(v, false);

        for (int i = v-1; i >=v-test; i--)arr[i] = true;

        do {
            vector<int>k;
            for (int i = 0; i < v; i++) {
                if (arr[i])k.push_back(varr[i]);
            }
            vector<vector<string>>a(n, vector<string>(test));
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < test; j++) {
                    a[i][j] = relation[i][k[j]];
                }
            }
            sort(a.begin(), a.end());
            if (unique(a.begin(), a.end()) == a.end()) {
                ans.push_back(k);
            }
        } while (next_permutation(arr.begin(), arr.end()));
        test++;
    }

    for (int i = 0; i < ans.size(); i++) {
        if (ans[i].size() == 2)answer++;
        else {
            bool check = true;
            for (int j = 0; j < i; j++) {
                if (ans[j].size() == ans[i].size())break;
                int num = 0;
                for (int k = 0; k < ans[j].size(); k++) {
                    vector<int>::iterator it = lower_bound(ans[i].begin(), ans[i].end(), ans[j][k]);
                    if (it != ans[i].end() && *it == ans[j][k])num++;
                }
                if (num == ans[j].size()) {
                    check = false;
                    break;
                }
            }
            if (check)answer++;
        }
    }

    return answer;
}
