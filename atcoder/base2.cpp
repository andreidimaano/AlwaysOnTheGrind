#include <iostream>

using namespace std;

int main() {
    unsigned long long ans = 0;

    for(int i = 0; i < 64; i++) {
        unsigned long long a = 0;
        cin >> a;
        ans += a << i;
    }

    cout << ans;
     
    return 0;
    
}