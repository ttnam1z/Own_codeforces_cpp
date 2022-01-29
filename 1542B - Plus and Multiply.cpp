#include <iostream>
#include <vector>

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        long long n,a,b = 0;
        cin >> n;
        cin >> a;
        cin >> b;

        if(a == 1){
            if(((n-a)%b)==0){
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
            continue;
        }

        int match = 0;
        long long pow=1;
        while(true){
            if(((n-pow) % b) ==0){match=1;break;}
            pow *=a;
            if(n < pow) break;
        }
        if(match == 0){
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }

    }

    return 0;
}