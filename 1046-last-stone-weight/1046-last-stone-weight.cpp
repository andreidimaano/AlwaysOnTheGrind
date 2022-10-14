class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        
        for(auto stone: stones) {
            pq.push(stone);
        }
        
        while(pq.size() > 1) {
            int s1 = pq.top(); pq.pop();
            int s2 = pq.top(); pq.pop();
            
            if(s1 < s2) {
                s2 = s2 - s1;
                pq.push(s2);
            }  else if (s2 < s1) {
                s1 = s1 - s2;
                pq.push(s1);
            }
        }
        
        return (pq.size() == 1) ? pq.top() : 0;
    }
};