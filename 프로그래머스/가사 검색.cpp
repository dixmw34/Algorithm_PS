#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> words, vector<string> queries) {


    int n = queries.size(), m = words.size();
    vector<pair<string, int>>left;
    vector<pair<string, int>>right;

    for (int i = 0; i < n; i++) {
        if (queries[i][0] == '?') {
            reverse(queries[i].begin(), queries[i].end());
            right.push_back(make_pair(queries[i], i));
        }
        else left.push_back(make_pair(queries[i], i));
    }

    sort(words.begin(), words.end());
    vector<string>rw(m);
    for (int i = 0; i < m; i++) {
        rw[i] = words[i];
        reverse(rw[i].begin(), rw[i].end());
    }
    sort(rw.begin(), rw.end());
    vector<int> answer(n, 0);
    sort(left.begin(), left.end());
    for (int i = 0; i < left.size(); i++) {
        if (i - 1 >= 0 && left[i].first == left[i - 1].first) {
            answer[left[i].second] = answer[left[i - 1].second];
            continue;
        }
        int size = 0, ans = 0;
        while (1) {
            if (left[i].first[size] == '?')break;
            size++;
        }
        string a = left[i].first.substr(0, size);
        int idx = lower_bound(words.begin(), words.end(), a) - words.begin();
        while (idx < m) {
            if (words[idx].substr(0, size) == a) {
                if (left[i].first.size() == words[idx].size())ans++;
                idx++;
            }
            else break;
        }
        answer[left[i].second] = ans;
    }
    sort(right.begin(), right.end());
    for (int i = 0; i < right.size(); i++) {
        if (i - 1 >= 0 && right[i].first == right[i - 1].first) {
            answer[right[i].second] = answer[right[i - 1].second];
            continue;
        }
        int size = 0, ans = 0;
        while (1) {
            if (right[i].first[size] == '?')break;
            size++;
        }
        string a = right[i].first.substr(0, size);
        int idx = lower_bound(rw.begin(), rw.end(), a) - rw.begin();
        while (idx < m) {
            if (rw[idx].substr(0, size) == a) {
                if (right[i].first.size() == rw[idx].size())ans++;
                idx++;
            }
            else break;
        }
        answer[right[i].second] = ans;
    }

    return answer;
}