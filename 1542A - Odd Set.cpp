#include <iostream>
#include <vector>

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        vector<int> v(2*n);
        for(int val,i=0; i < 2*n;i++){
            cin >> val;
            v[i] = val;
        }

        int cnt=0;
        for(int i=0; i < 2*n; i++){
            if(v[i]%2 == 1){cnt++;}
        }

        if(cnt == n){
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}