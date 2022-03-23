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
			a[i] = 0;		// ��¼�ߵĸ��� 
			b[i] = 1;		// ��¼��ĸ��� 
		}
		while(m--){
			cin>>i>>j;
			int u = find_root(i);
			int v = find_root(j);
			if(u == v)
				a[u]++;		// ��u�������ڵ�
			else{
				parent[v] = u;	// ����ͨ����ͨ��������¼���ڵ� 
				a[u] = a[u] + a[v] + 1;
				b[u] = b[u] + b[v]; 
			}
		}
		int re = 0;
		for(i = 1; i <= n; i++){
			// iΪ���ڵ㲢�ұ������ڵ�������¼�� 
			if(i == parent[i] && a[i] > b[i])
				re += a[i] - b[i];
		}
		cout<<"Case #"<<x<<": "<<re<<endl;
	}
	return 0;
}
