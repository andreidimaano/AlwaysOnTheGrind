#include <iostream>
#include <string>

using namespace std;

int main () {
    string s;
    int n;

    cin >> n >> s;

    for(int i = 0; i < n; i++){
        cout << s[i] << s[i];
    }
    cout << endl;

    return 0;
}