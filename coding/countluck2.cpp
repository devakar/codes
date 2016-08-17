#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <stack>
#include <queue>
#include <cmath>
#include <map>
#include <sstream>
#include <functional>
#include <numeric>

#define mp make_pair
#define pb push_back
#define x first
#define y second

using namespace std;

long long toint(string s) { istringstream in(s); long long x; in>>x; return x; }
template<class T> string tostring(T x) { ostringstream out; out<<x; return out.str();}

int n, m, ret, k;
vector<string> v;
vector< pair<int, int> > walked;
vector< pair<int, int> > dads;
pair<int, int> target, source;
char dx[] = {0, 1, 0, -1};
char dy[] = {1, 0, -1, 0};

void dfs(pair<int, int>dad, pair<int, int>child) {
    if (child == target) {
        for (int i = 0; i < walked.size(); i++) {
            int cnt = 0;
            for (int j = 0; j < 4; j++) {
                if (walked[i].x+dx[j] >= 0 && walked[i].x+dx[j] < n &&
                        walked[i].y+dy[j] >= 0 && walked[i].y+dy[j] < m &&
                        v[walked[i].x+dx[j]][walked[i].y+dy[j]] == '.' &&
                        mp(walked[i].x+dx[j], walked[i].y+dy[j]) != dads[i]) {
                    cnt++;
                }
            }
            if (cnt >= 2) {
                ret++;
            }
        }
        return;
    } else {
        walked.pb(child);
        dads.pb(dad);
        for (int i = 0; i < 4; i++) {
            pair<int, int>u = mp(child.x+dx[i], child.y+dy[i]);
            if (u.x >= 0 && u.x < n &&
                    u.y >= 0 && u.y < m &&
                    v[u.x][u.y] == '.' &&
                    u != dad) {
                dfs(child, u);
                walked.pop_back();
                dads.pop_back();
            }
        }
    }
}

int main(int argc, char *argv[]) {
    int tcase;
    cin>>tcase;
    for (int iter=0;iter<tcase; iter++) {
        scanf("%d%d", &n, &m);
        walked.clear();
        v.clear();
        for (int i = 0; i < n; i++) {
            string tt;
            cin>>tt;
            v.pb(tt);
            for (int j = 0; j < m; j++) {
                if (v[i][j] == '*') {
                    target = mp(i, j);
                    v[i][j] = '.';
                }
                if (v[i][j] == 'M') {
                    source = mp(i, j);
                    v[i][j] = '.';
                }
            }
        }
        cin>>k;
        ret = 0;
        dfs(mp(-1, -1), source);
        printf("%s\n", ret==k?"Impressed":"Oops!");
    }
    return 0;
}