#include<bits/stdc++.h>
#include<set>
using namespace std;

typedef struct cookie{
	long long int chang;
	long long int kuan; 
	friend bool operator < (const cookie& n1, const cookie& n2)
    {
        return n1.kuan < n2.kuan;
    }
}cookie;

int main(){
	long long int n, m, i, j, x, y;
	cookie temp;
	while(cin>>n>>m){
		multiset<cookie> c;
		long long int re = 0;
		for(i = 0; i < n; i++){
			cin>>x>>y;
			temp.chang = max(x, y);
			temp.kuan = min(x, y);
			c.insert(temp);
		}
		while(m && !c.empty()){
			multiset<cookie>::iterator iter = --c.end();
			re += (*iter).kuan * (*iter).kuan;
			temp.chang = max((*iter).kuan, (*iter).chang - (*iter).kuan);
			temp.kuan = min((*iter).kuan, (*iter).chang - (*iter).kuan);
			c.erase(--c.end());
			m--;
			if(temp.kuan)
				c.insert(temp);
		}
		cout<<re<<endl;
	}
	return 0;
}
