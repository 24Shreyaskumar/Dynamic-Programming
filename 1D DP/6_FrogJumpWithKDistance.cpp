#include <bits/stdc++.h>
#define vi vector<int>
#define ll long long 
using namespace std;

ll FJK_memo(int stairs, int k, vi energy, vi &dp) {
    if (stairs == 0) return 0;
    if (dp[stairs] != -1) return dp[stairs];
    
    for (int i = 1; i <= k; i++) {
        int minSteps = INT_MAX;
        if (stairs - i >= 0) {
            int jumps = FJK_memo(stairs - i, k, energy, dp) + abs(energy[stairs] - energy[stairs-i]);
            minSteps = min(minSteps, jumps);
        }
        dp[stairs] = minSteps;
    }

    return dp[stairs];
}

ll FJK_tab(int stairs, int k, vi energy, vi dp) {
    dp[0] = 0;
    for (int i = 1; i < stairs; i++) {
        int minSteps = INT_MAX;
        for (int j = 1; j <= k; j++) {
            if (i - j >= 0) {
                int jumps = dp[i-j] + abs(energy[i] - energy[i-j]);
                minSteps = min(minSteps, jumps);
            }

            dp[i] = minSteps;
        }
    }

    return dp[stairs - 1];
}

// ll FJK_noSpace(int stairs, int k, vi energy) {
    
// }

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL); cout.tie(NULL);

    int stairs, k;
    cin>>stairs>>k;
    vi energy(stairs), dp(stairs+1, -1);
    for (int i = 0; i < stairs; i++) cin>>energy[i];

    cout<<"Memoization : "<<FJK_memo(stairs-1, k, energy, dp)<<"\n";
    cout<<"Tabulation : "<<FJK_tab(stairs, k, energy, dp);
    //cout<<"No extra space : "<<FJK_noSpace(stairs, k, energy);
}