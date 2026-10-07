#include <bits/stdc++.h>
using namespace std;

// pehli baar degital design fsm worth it lga bhai

int main() {
    string s{""};
    cin>>s;
    int state{};

    for(char c : s) {
        if(state == 0) {
            if (c == '1') state = 1;
            else { 
                cout<<"NO"<<endl;
                return 0;
            }
        }
        else if(state == 1) {
            if(c == '1') state = 1;
            else if(c == '4') state = 2;
            else {
                cout<<"NO"<<endl;
                return 0;
            }
        }
        else if(state == 2) {
            if (c == '1') state = 1;
            else if (c == '4') state = 3;
            else {
                cout<<"NO"<<endl;
                return 0;
            }
        }
        else {
            if (c == '1') state = 1;
            else {
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }

    cout<<"YES"<<endl;
    return 0;
}
