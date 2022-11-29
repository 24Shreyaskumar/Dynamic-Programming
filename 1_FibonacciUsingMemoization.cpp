#include <bits/stdc++.h>
#define vi vector<int>
#define ll long long
using namespace std;

ll fib(int n, vi &dp) {
    if (n <= 1) return n;
    if (dp[n] != -1) return dp[n];
    return dp[n] = fib(n-1, dp) + fib(n-2, dp);
}

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin>>n;
    vi dp(n+1, -1);

    cout<<fib(n, dp)<<"\n";
}