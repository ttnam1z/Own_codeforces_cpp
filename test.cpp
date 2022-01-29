#include <iostream>
#include <map>
#include <vector>
#include <list>
#include <algorithm>    

using namespace std;
pair<string,int> a;

//bublesort
void bublesort(vector<int> &a){
	bool swap;
	for (int i =0; i< a.size(); i++){
		swap = false;
		for( int j = 0; j <a.size()-1; j++){
			if (a[j] < a[j+1]){
				int m = a[j];
				a[j]= a[j+1];
				a[j+1]= m;
				swap = true;
			}
		}
		if(!swap)
			break;
	}
}


//selectionsort
void selectionsort(vector<int> &a){
	for(int i = 0; i < a.size()-1;i++){
		for(int j = i+1; j < a.size(); j++){
			if(a[i] < a[j]){
				int m = a[j];
				a[j]= a[i];
				a[i]= m;
			}
		}
	}
}

void insertsort(vector<int> &a){
	int val;
	for(int i = 1; i < a.size();i++) {
		val = a[i];
		int j = i;
		while(j > 0 && val>a[j-1]){
			a[j]=a[j-1];
			j--;
		}
		a[j] = val;
	}
}


int main() {
	struct tree {
		struct tree* left;
		struct tree* right;
		int value;
		
		tree(int n){
			value = n;
			right = NULL;
			left = NULL;
		}
		void insert(int n){
			struct tree *node = new struct tree(n);
			node->left = this->left;
			this->left = node;
		}
	};
	int n = 100;
	int aa[n][n];
	vector<int> ss(4);
	
	ss.push_back(2);
	ss.push_back(1);
	ss.push_back(5);
	
	for(int i = 0; i<ss.size(); i++){
		cout << ss[i] << " ";
	}
	cout << "\n";
	
	insertsort(ss);
	
	//make_heap(ss.begin(),ss.end());
	//sort_heap(ss.begin(),ss.end());
	for(int i = 0; i<ss.size(); i++){
		cout << ss[i] << " ";
	}
	cout << "\n";
	
	vector<int> *s;
	
	s = new vector<int>[3];
	s[0].push_back(1);
	s[1].push_back(3);
	s[2].push_back(2);
	
	cout << s[0][0] << " " << s[1][0] << s[2][0]<<"\n";
	
	list<int> *l;  //pointer to array of list
	l = new list<int>[4]; 
	
	a = {"heho",1};
	cout << a.first << "  ha " << a.second;
	
	map<string,int> lst;
	lst.insert({"hs",1});
	lst.insert(make_pair("hh",2));
	for(auto it = lst.begin(); it != lst.end(); it++)
	{
		cout << (*it).first << " " << (*it).second << "\n";
		
	}
	return 0;
}
