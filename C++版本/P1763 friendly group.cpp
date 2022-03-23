#include<bits/stdc++.h>
using namespace std;

int parent[300010], a[300010], b[300010];

int find_root(int x){
	if(x == parent[x])
		return x;
	return parent[x] = find_root(parent[x]);
}

int main(){
	int t, n, m, i, j, x;
	cin>>t;
	for(x = 1; x <= t; x++){
		cin>>n>>m;
		for(i = 1; i <= n; i++){
			parent[i] = i;
			a[i] = 0;		// 记录边的个数 
			b[i] = 1;		// 记录点的个数 
		}
		while(m--){
			cin>>i>>j;
			int u = find_root(i);
			int v = find_root(j);
			if(u == v)
				a[u]++;		// 将u当做根节点
			else{
				parent[v] = u;	// 可连通的连通起来，记录根节点 
				a[u] = a[u] + a[v] + 1;
				b[u] = b[u] + b[v]; 
			}
		}
		int re = 0;
		for(i = 1; i <= n; i++){
			// i为根节点并且边数大于点数，记录下 
			if(i == parent[i] && a[i] > b[i])
				re += a[i] - b[i];
		}
		cout<<"Case #"<<x<<": "<<re<<endl;
	}
	return 0;
}
