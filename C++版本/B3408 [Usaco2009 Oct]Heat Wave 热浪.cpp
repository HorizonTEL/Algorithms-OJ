// 感谢舍友史大佬倾情相助(^V^) 
#include<bits/stdc++.h>
using namespace std;

#define N 2501



void ShortestPath(int v0, int vnum, short cost[2502][2502], int *dp) {
	int v, w, i, j, k, m;
	bool final[2502] = {0};
	for (w = 1; w <= vnum; ++w) {
		dp[w] = cost[v0][w];
	}
	dp[v0] = 0;
	final[v0] = true;

	for (int i = 1; i < vnum; ++i) {
		int min = 0;
		v = v0;
		for (w = 1; w <= vnum; ++w) {
			if (!final[w] && dp[w] != -1) {
				if (!min) {
					v = w;
					min = dp[w];
				}
				if (dp[w] < min) {
					v = w;
					min = dp[w];
				}
			}
		}
		final[v] = true;
		for (w = 1; w <= vnum; ++w) {
			if (!final[w] && cost[v][w] != -1) {
				if (dp[w] == -1 || (min + cost[v][w] < dp[w])) {
					dp[w] = min + cost[v][w];
				}
			}
		}

	}
}

int main() {
	int n, m, s, t, i, j, dp[2502];
	cin >> n >> m >> s >> t;
	short cost[2502][2502];
	for(i = 1; i <= n; i++){
		for(j = 1; j <= n; j++)
			cost[i][j] = -1;
	}
	short v, w, c;
	for (int i = 0; i < m; ++i) {
		cin >> v >> w >> c;
		cost[v][w] = c;
		cost[w][v] = c;
	}

	ShortestPath(s, n, cost, dp);
	cout << dp[t] << endl;
	return 0;
}
