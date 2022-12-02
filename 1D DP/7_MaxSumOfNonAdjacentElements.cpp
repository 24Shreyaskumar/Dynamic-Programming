#include <bits/stdc++.h>
#define vi vector<int>
#define ll long long
using namespace std;

ll Sol_mem0(int n, vi v, vi &dp) {
    if (n == 0) return v[0];
    if (n < 0) return 0;
    if (dp[n] != -1) return dp[n];

    int pick = v[n] + Sol_mem0(n-2, v, dp);
    int dontPick = 0 + Sol_mem0(n-1, v, dp);

    return dp[n] = max(pick, dontPick);
}

ll Sol_tab(int n, vi v, vi dp) {
    dp[0] = v[0];
    
    for (int i = 1; i < n; i++) {
        int pick = v[i];
        if (i > 1) pick += dp[i-2];
        int dontPick = 0 + dp[i-1];

        dp[i] = max(pick, dontPick);
    }

    return dp[n-1];
}

ll Sol_so(int n, vi v) {
    int prev = v[0], prev2 = 0, curi;
    for (int i = 1; i < n; i++) {
        int pick = v[i];
        if (i > 1) pick += prev2;
        int dontPick = 0 + prev;

        curi = max(pick, dontPick);
        prev2 = prev;
        prev = curi;
    }

    return prev;
}

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin>>n;
    vi v(n), dp(n+1, -1);
    for (int i = 0; i < n; i++) cin>>v[i];

    cout<<"Memoization : "<<Sol_mem0(n, v, dp)<<"\n";
    cout<<"Tabulation : "<<Sol_tab(n, v, dp)<<"\n";
    cout<<"Space Optimised : "<<Sol_so(n, v)<<"\n";

    return 0;
}