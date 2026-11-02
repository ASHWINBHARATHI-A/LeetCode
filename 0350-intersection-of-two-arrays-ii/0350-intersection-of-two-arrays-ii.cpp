class Solution {
public:
    vector<int> intersect(vector<int>& a, vector<int>& b) {
       vector<int>ans;
      for(int i = 0; i < a.size(); i++) {
            for(int j = 0; j < b.size(); j++) {
                if(a[i] == b[j]) {
                    ans.push_back(a[i]);
                    b[j] = -1;
                    break;
                }
            }
        }
        return ans;
    }
};