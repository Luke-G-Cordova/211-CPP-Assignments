#include <iostream>
using namespace std;

int main(){
    int num;
    while(cin>>num){
        if(num%2!=0){
            cerr << "not all even" << endl;
            return 1;
        }
    }
    cout << "all even" << endl;
    return 0;
}