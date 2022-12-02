#include <bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vector<int>>
using namespace std;

int Training_memo(int day, int memory, vvi v, vvi &dp) {
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
            int points = v[day][i] + Training_memo(day-1, i, v, dp);
            mx = max(mx, points);
        }
    }

    return dp[day][memory] = mx;
}

int Training_tab(int days, int memory, vvi v, vvi &dp) {
    int mx = 0;
    dp[0][0] = max(v[0][1], v[0][2]);
    dp[0][1] = max(v[0][0], v[0][2]);
    dp[0][2] = max(v[0][0], v[0][1]);
    dp[0][3] = max(v[0][0], max(v[0][1], v[0][2]));

    for (int i = 1; i < days; i++) {
        for (int memory = 0; memory <= 3; memory++) {
            dp[i][memory] = 0;

            for (int j = 0; j < 3; j++) {
                if (j != memory) {
                    int points = v[i][j] + dp[i-1][j];
                    dp[i][memory] = max(dp[i][memory], points);
                }
            }
        }
    }

    return dp[days-1][3];
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

        cout<<"Memoization : "<<Training_memo(days-1, 3, v, dp)<<"\n";
        cout<<"Tabulation : "<<Training_tab(days-1, 3, v, dp)<<"\n";
    }

    return 0;
}