#include<bits/stdc++.h>
using namespace std;

typedef struct Node{
	int value;
	int number;
	struct Node *lchild;
	struct Node *rchild;
}BiTree;

void insert(BiTree *&T, int x){
	BiTree *s = (BiTree *) malloc(sizeof(BiTree));
    s -> value = x;
    s -> lchild = NULL;
    s -> rchild = NULL;
    s -> number = 1;
    BiTree *p = T;
    if(!p){
    	cout<<endl;
    	T = s;
	}
	else{
		while(p != NULL){
			if(x > p -> value){
				cout<<"->";
				if(p -> rchild == NULL){
					p -> rchild = s;
					cout<<endl;
					break;
				}
				p = p -> rchild;
			}
			else if(x < p -> value){
				cout<<"<-";
				if(p -> lchild == NULL){
					p -> lchild = s;
					cout<<endl;
					break;
				}
				p = p -> lchild;
			}
			else{
				p->number += 1;
				cout<<endl;
				break;
			}
		}
	}
}

void find(BiTree *T, int x){
	BiTree *p = T;
	if(!p)
		cout<<endl<<0<<endl;
	else{
		if(p->value == x){
			cout<<endl;
			cout<<p->number<<endl;
		}
		else{
			while(p){
				if(p->value > x){
					cout<<"<-";
					p = p->lchild;
				}
				else if(p->value < x){
					cout<<"->";
					p = p->rchild;
				}
				else{
					cout<<endl<<p->number<<endl;
					break;
				}
			}
			if(!p){
				cout<<endl<<0<<endl;
			}
		}
	}
}

int main(){
	BiTree *T = NULL;
	int n, i, x, opt;
	cin>>n;
	for(i  = 0; i < n; i++){
		cin>>opt>>x;
		if(opt == 1)
			insert(T, x);
		else
			find(T, x);
	}

