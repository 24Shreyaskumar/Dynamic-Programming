#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
using namespace std;

ll FJ_memo(int stairs, vi &energy, vi &dp) {
    if (stairs == 0) return 0;
    if (dp[stairs] != -1) return dp[stairs];

    int left = FJ_memo(stairs-1, energy, dp) + abs(energy[stairs] - energy[stairs-1]);
    int right = INT_MAX;
    if (stairs > 1) right = FJ_memo(stairs-2, energy, dp) + abs(energy[stairs] - energy[stairs-2]);

    dp[stairs] = min(left, right);
    return dp[stairs];
}

ll FJ_tab(int stairs, vi energy, vi &dp) {
    dp[0] = 0;
    for (int i = 1; i < stairs; i++) {
        int f = dp[i-1] + abs(energy[i] - energy[i-1]);
        int s = INT_MAX;
        if (i > 1) s = dp[i-2] + abs(energy[i] - energy[i-2]);
        dp[i] = min(f, s);
    }

    return dp[stairs-1];
}

ll FJ_noSpace(int stairs, vi energy) {
    int prev = 0, prev2 = 0, curi;
    for (int i = 1; i < stairs; i++) {
        int f = prev + abs(energy[i] - energy[i-1]);
        int s = INT_MAX;
        if (i > 1) s = prev2 + abs(energy[i] - energy[i-2]);
        curi = min(f, s);
        prev2 = prev;
        prev = curi;
    }

    return prev;
}

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL); cout.tie(NULL);

    int stairs; cin>>stairs;
    vi energy, dp(stairs+1, -1);
    for (int i = 0; i < stairs; i++) {
        int x; cin>>x;
        energy.push_back(x);
    }

    cout<<"Memoization : "<<FJ_memo(stairs - 1, energy, dp)<<"\n";
    cout<<"Tabulation : "<<FJ_tab(stairs, energy, dp)<<"\n";
    cout<<"No Extra Space : "<<FJ_noSpace(stairs, energy)<<"\n";

    return 0;
}