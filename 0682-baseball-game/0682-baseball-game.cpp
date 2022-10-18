class Solution {
public:
    int calPoints(vector<string>& operations) {
        int ans = 0;
        stack<int> st;
        
        for(auto s: operations) {
            if(s == "+") {
                int s1 = st.top(); st.pop();
                int s2 = st.top(); st.pop();
                st.push(s2);
                st.push(s1);
                st.push(s1 + s2);
            } else if(s == "D") {
                int s1 = st.top();
                st.push(s1 * 2);
            } else if (s == "C") {
                st.pop();
            } else {
                st.push(stoi(s));
            }
        }
        
        while(st.size()) {
            cout << st.top() << endl;
            ans += st.top();
            st.pop();
        }
        
        return ans;
    }
};