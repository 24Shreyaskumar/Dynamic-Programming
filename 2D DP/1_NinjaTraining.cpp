#include <bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vector<int>>
using namespace std;

int Training(int day, int memory, vvi v, vvi &dp) {
    if (day == 0) {
        int mx = 0;
        for (int i = 0; i < 3; i++) {
            if (i != memory) mx = max(mx, v[0][i]); 
        }
        return mx;
    }

    if (dp[day][memory] != -1) return dp[day][memory];

    int mx = 0;
    for (int i = 0; i < 3; i++) {
        if (i != memory) {
            int points = v[day][i] + Training(day-1, i, v, dp);
            mx = max(mx, points);
        }
    }

    return dp[day][memory] = mx;
}

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL); cout.tie(NULL);

    int t; cin>>t;

    while (t--) {
        int days;
        cin>>days;
        vvi v(days, vi(3)), dp(days, vi(4, -1));

        for (int i = 0; i < days; i++) {
            for (int j = 0; j < 3; j++) cin>>v[i][j];
        }

        cout<<Training(days-1, 3, v, dp)<<"\n";
    }

    return 0;
}