#include<bits/stdc++.h>
#include<queue>
using namespace std;
int n, m;
int rd[1005];
int f[1005];
vector<int> a[1005];

int bfs(){
	int ans = 0;
	queue<int> q;
	for(int i = 1; i <= n; i++){
		f[i] = 0;
		if(!rd[i] && a[i].size()){
			q.push(i);
			f[i] = 1;
		}
	}
	while(!q.empty()){
		int top = q.front();
		q.pop();
		if(!a[top].size())
			ans = f[top];
		for(int i = 0; i < a[top].size(); i++){
			int v = a[top][i];
            f[v] = max(f[v], f[top] + 1);
			rd[v]--;
			if(!rd[v])
				q.push(v);
		}
	}
	return ans;
}

int main(){
	while(cin >> n >> m){
		for(int i = 1; i <= n; i++)
			rd[i] = 0;
		for(int i = 1; i <= m; i++){
			int u, v;
			cin >> u >> v;
			rd[v]++;
			a[u].push_back(v);
		}
		cout << bfs() << endl;
		for(int i = 1; i <= n; i++)
			a[i].clear();		
	}	
}
