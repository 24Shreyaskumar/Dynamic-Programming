#include <bits/stdc++.h>
#define vi vector<int>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin>>n;
    vi dp(n+1);
    dp[0] = 0; dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    cout<<dp[n]<<"\n";
    return 0;
}