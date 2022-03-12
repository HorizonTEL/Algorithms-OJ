#include<bits/stdc++.h>
using namespace std;

#define  INFINITY 65535

void ShortestPath(int graph[1100][1100], int *D, int vex, int start){
	int i, j, k, m;
	bool final[1100] = {0};
	for(i = 1; i <= vex; i++){
		if(i == start){
			final[i] = true;
			D[i] = 0;	// start 到i的最短路径 
			continue;
		}
		D[i] = graph[start][i]; 
	}
	for(i = 1; i <= vex; i++){
		if(i == start)
			continue;
		m = INFINITY;
		for(j = 1; j <= vex; j++){
			if(!final[j] && D[j] < m){
				m = D[j];
				k = j;
			}
		}
		final[k] = 1;
		for(j = 1; j <= vex; j++){
			if(!final[j] && m + graph[k][j] < D[j])
				D[j] = m + graph[k][j];
		}
	}
}

void ShortestPath1(int graph[1100][1100], int *D, int vex, int end){
	int i, j, k, m;
	bool final[1100] = {0};
	for(i = 1; i <= vex; i++){
		if(i == end){
			final[i] = true;
			D[i] = 0;	// i 到end的最短路径 
			continue;
		}
		D[i] = graph[i][end]; 
	}
	for(i = 1; i <= vex; i++){
		if(i == end)
			continue;
		m = INFINITY;
		for(j = 1; j <= vex; j++){
			if(!final[j] && D[j] < m){
				m = D[j];
				k = j;
			}
		}
		final[k] = 1;
		for(j = 1; j <= vex; j++){
			if(!final[j] && m + graph[j][k] < D[j])
				D[j] = m + graph[j][k];
		}
	}
}

int main(){
	int n, m, x;
	while(cin>>n>>m>>x){
		int graph[1100][1100], i, j, k, p, t;
		for(i = 1; i <= n; i++){
			for(j = 1; j <= n; j++)
				graph[i][j] = INFINITY;
		}
		for(i = 0; i < m; i++){
			cin>>p>>t;
			cin>>graph[p][t];
		}
		int re[1100] = {0}, D[1100] = {0}, D1[1100] = {0}, re0 = 0;
		ShortestPath(graph, D, n, x);
		ShortestPath1(graph, D1, n, x);
		for(i = 1; i <= n; i++){
			if(i == x)
				continue;
			// int D1[1100] = {0};
			// ShortestPath(graph, D1, n, i);
			re0 = max(re0, D[i] + D1[i]);
		}
		cout<<re0<<endl;
	}
	return 0;
}
