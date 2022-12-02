//variation of fibonacci

/*
Problem Statement : 

You have been given a number of stairs. Initially, you are at the 0th stair and you need to reach the Nth stair. Each time you can either clime one stair or two stairs. You are supposed to return the number of distinct ways in which you can climb from the 0th stair to Nth stair.
*/


#include <bits/stdc++.h>
#define vi vector<int>
#define ll long long 
using namespace std;

ll CS_memo(int stairs, vi &dp) {
    if (stairs <= 1) return 1;
    if (dp[stairs] != -1) return dp[stairs];
    return dp[stairs] = CS_memo(stairs - 1, dp) + CS_memo(stairs-2, dp);
}

ll CS_tab(int stairs, vi dp) {
    dp[0] = 1; dp[1] = 1;
    for (int i = 2; i <= stairs; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[stairs];
}

ll CS_noSpace(int stairs) {
    int prev = 1, prev2 = 1, curi;

    for (int i = 2; i <= stairs; i++) {
        curi = prev + prev2;
        prev2 = prev;
        prev = curi;
    }

    return prev;
}

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL); cout.tie(NULL);

    int stairs; cin>>stairs;
    vi dp(stairs+1, -1);
    cout<<"Memoization : "<<CS_memo(stairs, dp)<<"\n";
    cout<<"Tabulation : "<<CS_tab(stairs, dp)<<"\n";
    cout<<"No Extra Space : "<<CS_noSpace(stairs)<<'\n';


    return 0;
}