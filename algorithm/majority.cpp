/*
 * @uni_kakurenbo
 * https://github.com/uni-kakurenbo/competitive-programming-workspace
 *
 * CC0 1.0  http://creativecommons.org/publicdomain/zero/1.0/deed.ja
 */
/* #language C++ GCC */
/* #region template */
#include <bits/stdc++.h>
using namespace std;

#include "template.hpp"
/* #endregion */

signed main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> hopes(n, vector<int>(m));
    input >> hopes;

    debug(hopes);

    map<int,int> cnt;
    REP(i, n) ++cnt[hopes[i][0]];

    print(max_element(ALL(cnt), [](auto& a, auto& b) { return a.second < b.second; })->first);

}
