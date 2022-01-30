#include <iostream>
#include <vector>
#include <forward_list>
#include <list>
#include <stack>

void main() {
	int n=10;
	// array
	int a[n];
	
	//vector similar to array 
	// #include <vector>
	vector<int> a(n); // reserve n element, value may be 0
		
		// using make_heap to sort
		//#include <algorithm>    
		a.push_back(1); // add 1 to n+1 element
		make_heap(a.begin(),a.end());
		sort_heap (a.begin(),a.end());
		
	
	//pair https://www.cplusplus.com/reference/utility/pair/?kw=pair
	// #include <utility> 
	pair<int,int> a,b;
	a = {2,2}; // c11 compiler
	b = std::make_pair(5,6371);
	cout << a.first << "  ha " << a.second;
	
	//tuple https://www.cplusplus.com/reference/tuple/
	// #include <tuple>
	tuple<int,""> b;
	b = std::make_tuple (100L,'Y')
	
	//linked list
	struct linker_list {
		int value;
		struct linker_list *next;
	}
	
		//forward_list https://www.cplusplus.com/reference/forward_list/forward_list/
		// #include <forward_list>
		forward_list<int> fw_list;
		fw_list.assign({ 1, 2, 3 });
		fw_list.push_front(1);
		fw_list.pop_front();
		auto it = fw_list.begin();
		it = fw_list.erase_after(it);              
		for ( auto it = fw_list.begin(); it != fw_list.end(); ++it )
			cout << ' ' << *it;
		
		
		//list  https://www.cplusplus.com/reference/list/list/
		// #include <list>
		list<int> lst = {1, 2, 3, 10};
		lst.push_front(11);
		lst.push_back(18);
		auto it = std::find(lst.begin(), lst.end(), 10);
		if (it != lst.end()) {
			lst.insert(it, 21);
		}
		for (int x : lst) {
			std::cout << x << '\n';  // 11,1,2,3,21,10,18
		}
	
	
	//stack  https://www.cplusplus.com/reference/stack/stack/
	// #include <stack>  LIFO
	stack<int> st;
	st.push(10);
	st.push(11);
	
	st.size();
	st.top();
	while(!st.empty()){
		count << st.pop(); // 11, 10
	}
	
	//queue  https://www.cplusplus.com/reference/queue/queue/
	//#include <queue> FIFO
	queue<int> que;
	que.push(10);
	que.push(11);
	
	que.front();
	while(!st.empty()){
		count << que.pop();  // 10, 11
	}
	
	//map https://www.cplusplus.com/reference/map/map/
	// #include <map>
	map<int, string> Students;

	Students.insert(std::make_pair<int, string>(200, "Alice"));

	Students.insert({201, "John"});

	cout << "Map size is: " << Students.size() << endl;

	cout << endl << "Default map Order is: " << endl;

	for (map<int, string>::iterator it = Students.begin(); it != Students.end(); ++it) {

		cout << (*it).first << ": " << (*it).second << endl;
	}
	
	map<int, std::string>::iterator it = my_map.find(200); //map.find key
	map.erase(it);
	
	//hash table
	struct hashtable {
		list<int> *table;
		int total;
		
		hashtable(int n){
			total = n;
			table = new list<int>[n];
		}
	}
	hashtable htb = hashtable(5);
	int num = 100;
	htb.table[num%5].push_back(num); // store num in hashtable


	//tree 
	struct tree {
		struct tree* left;
		struct tree* right;
		int value;
		
		tree(int n){
			value = n;
			right = null;
			left = null;
		}
		void insert(int n){
			struct tree *node = new struct tree(n);
			node.left = this->left;
			this->left = node;
		}
	}
		// sort tree
		// search tree
	
	//heap (heap tree) is an array that has speacial position
	// using make_heap
	//#include <algorithm>
	vector<int> ss(4);
	
	ss.push_back(2);
	ss.push_back(1);
	make_heap(ss.begin(),ss.end());
	// need to use sort_heap after make_heap or the result is error
	sort_heap(ss.begin(),ss.end()); 
	
	//graph
	//present by matrix
	int a[n][n];
	
}

//Sorting function
//quicksort
int partition(vector<int> &a, int p1, int p2) {
	int j = p2;
	int pos = p1;
	for(int i = p1; i < p2;i++){
		if(a[pos] < a[p2]){
			j--;
			int m = a[j];
			a[j] = a[pos];
			a[pos] = m;
		} else {
			pos++;
		}
	}
	int m = a[j];
	a[j] = a[p2];
	a[p2] = m;
	
	return j;
}
void quicksort(vector<int> &a, int p1, int p2){
	if(p1 >= p2)
		return;
	int i = partition(a,p1,p2);
	quicksort(a,p1,i-1);
	quicksort(a,i+1,p2);
}


//mergesort
void merge(vector<int> &a,int p0, int p1, int p2){
	vector<int> a1(a.begin()+p0,a.begin()+p1+1);
	vector<int> a2(a.begin()+p1+1,a.begin()+p2+1);
	int j = 0;
	int	k = 0;
	for(int i = p0; i <= p2; i++){
		if(j >= a1.size()){
			a[i] = a2[k];
			k++;
		} else if(k >= a2.size()){
			a[i]=a1[j];
			j++;
		} else{
			if(a1[j]>a2[k]){
				a[i]=a1[j];
				j++;
			} else {
				a[i] = a2[k];
				k++;
			}
		}
	}
}

void mergesort(vector<int> &a, int p0, int p1){
	if(p0 < p1){
		int mid = (p0+p1)/2;
		mergesort(a, p0, mid);
		mergesort(a, mid +1, p1);
		merge(a, p0, mid, p1);
	}
}


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
	for(int i = 0; i < a.size()-1; i++)
		for(int j= i+1; j< a.size(); j++) {
			if(a[i]<a[j]){
				int m = a[j];
				a[j]= a[i];
				a[i]= m;
			}
		}
}


//insertsort
void insertsort(int a[]){
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









