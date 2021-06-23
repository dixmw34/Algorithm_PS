#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<vector<string>>user_case;
vector<vector<string>>ans_arr;
map<string, bool>m;

void dfs(vector<string>result){
    if(result.size() == user_case.size()){
        ans_arr.push_back(result);
        return;
    }
    int cnt = result.size();
    for(int i = 0; i<user_case[cnt].size(); ++i){
        if(!m[user_case[cnt][i]]){
            m[user_case[cnt][i]] = true;
            result.push_back(user_case[cnt][i]);
            dfs(result);
            result.pop_back();
            m[user_case[cnt][i]] = false;
        }
    }
    return;
}

int solution(vector<string> user_id, vector<string> banned_id) {

    user_case = vector<vector<string>>(banned_id.size());
    
    for(int i = 0; i<banned_id.size(); ++i){
        for(int j = 0; j<user_id.size(); ++j){
            if(banned_id[i].size()!=user_id[j].size())
                continue;
            int k = 0;
            for(; k<banned_id.size(); ++k){
                if(banned_id[i][k] != '*' && banned_id[i][k] != user_id[j][k])
                    break;
            }
            if(k == banned_id.size())
                user_case[i].push_back(user_id[j]);
        }
    }
    
    for(int i = 0; i<user_id.size(); ++i){
        m[user_id[i]] = false;
    }
    
    dfs({});
    
    for(int i = 0; i<ans_arr.size(); ++i){
        sort(ans_arr[i].begin(), ans_arr[i].end());
    }
    sort(ans_arr.begin(), ans_arr.end());
	ans_arr.erase(unique(ans_arr.begin(), ans_arr.end()), ans_arr.end());
	return ans_arr.size();

}

//소스코드 문제의 출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges