typedef pair<double, vector<int>> disCord;
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<disCord, vector<disCord>, greater<disCord>> pq;

        for(auto point: points) {
            double distance = sqrt((point[0] * point[0] + point[1] * point[1])); 
            pq.push({distance,point});
        }

        vector<vector<int>> ans;
        while(k--) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};