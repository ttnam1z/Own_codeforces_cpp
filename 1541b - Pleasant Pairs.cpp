#include <iostream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;
struct t_pair{
    int v,i;
};
vector<t_pair> u;

vector<int> v;

void solve(vector<int> v, int len){
    
}

int main(){
    int n;
    int len;
    cin >> n;
    while(n--){
        cin >> len;
        v.resize(len);
        //vector<int> v;
        for(int val,i =0; i < len; i++){
            cin >> val;
            v[i] = val;
            //v.push_back(val);
        }
        int count = 0;
        for(int i = 0; i < len-1;i++){
            for (int j=v[i] - (i+1) % v[i] - 1; j<len;j += v[i] ){
                if ((i < j) && (1ll*v[i]*v[j]) == (i+j +2)){
                    count++;
                }
            }
        }
        cout << count << endl;
    }

    return 0;
}