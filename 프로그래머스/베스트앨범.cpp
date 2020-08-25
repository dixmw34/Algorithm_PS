#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

typedef pair<int, int> pi;

bool cmp(pair<int, string>a, pair<int, string>b) {
    return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    vector<pair<int, string>>gen; //sort예정, (재생횟수, 장르이름)
    vector<vector<pi>>music(100); //장르별로 구분 (재생횟수, index)
    map<string, int>m; //장르이름, index
    map<string, int>::iterator it;

    int n = genres.size();

    for (int i = 0; i < n; i++) {
        it = m.find(genres[i]);
        if (it == m.end()) {
            int idx = m.size();
            gen.push_back(make_pair(plays[i], genres[i]));
            m.insert(make_pair(genres[i], idx));
            music[idx].push_back(pi(-plays[i], i));
        }
        else {
            int idx = it->second;
            gen[idx].first += plays[i];
            music[idx].push_back(pi(-plays[i], i));
        }
    }

    sort(gen.begin(), gen.end(), cmp);

    for (int i = 0; i < gen.size(); i++) {
        it = m.find(gen[i].second);
        int idx = it->second;
        sort(music[idx].begin(), music[idx].end());

        int test = 0;

        for (int k = 0; k < min((int)music[idx].size(), 2); k++) {
            answer.push_back(music[idx][k].second);
        }
    }



    return answer;
}