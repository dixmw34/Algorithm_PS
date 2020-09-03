#include <string>
#include <vector>
#include <map>

using namespace std;

typedef long long ll;

map<ll, ll>par;

ll find(ll x) {
    if (par[x] == 0)return x;
    else return par[x] = find(par[x]);
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;

    for (int i = 0; i < room_number.size(); i++) {
        ll room = find(room_number[i]);
        answer.push_back(room);
        par[room] = room + 1;
    }

    return answer;
}