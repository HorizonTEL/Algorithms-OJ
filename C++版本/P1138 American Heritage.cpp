#include<bits/stdc++.h>
#include<string>
using namespace std;

void post(string in, string pre, int root, int start, int end){
	if(start > end)
		return;
	int i = start;
	// �ҵ���������ĸ��ڵ����ڵ�λ�� 
	while(i < end && in[i] != pre[root])
		i++;
	post(in, pre, root+1, start, i-1);	// ���������� 
	post(in, pre, root+1+i-start, i+1, end);	// ���������� 
	cout<<pre[root];
}

int main(){
	string in, pre;
	while(cin>>in>>pre){
		post(in, pre, 0, 0, in.length()-1);
		cout<<endl;
	}
	return 0;
}
