class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> set;
        
        for(auto s: emails) {
            int i = 0;
            bool plusExists = false;
            string localName = "";
            while(s[i] != '@'){
                if(s[i] == '+') {
                    plusExists = true;
                } else if(!plusExists && s[i] != '.') {
                    localName += s[i];
                }
                i++;
            }
            
            // i = index of '@'
            string email = localName + s.substr(i, s.size() - 1);
            set.insert(email);
        }
        
        return set.size();
    }
};