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

mt19937_64 random_engine;

signed main() {

    int n, m, k; cin >> n >> m >> k;

    vector<vector<int>> hopes;

    REP(n) {
        vector<int> candidates(m);
        iota(ALL(candidates), 0);
        shuffle(ALL(candidates), random_engine);

        hopes.emplace_back(candidates);
    }

    print(n, m);
    ITR(hope, hopes) print(hope);
    cout << flush;

    vector<int> results(k); input >> results;

    ll score = 0;

    ITR(hope, hopes) {
        REP(j, k) {
            if(count(ALL(hope), results[j])) {
                int rank = m - (find(ALL(hope), results[j]) - hope.begin());
                debug(rank);
                score += 1 << rank;
            }
        }
    }

    print(score);

    return 0;
}
