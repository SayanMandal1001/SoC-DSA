class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        priority_queue<int> q;
        int n = nums.size();
        for(int i=0; i<min(n,k); i++){
            q.push(nums[i]);
        }
        ans.push_back(q.top());
        priority_queue<int> remove;
        for(int i=k; i<n; i++){
            remove.push(nums[i-k]);
            while(remove.size()!=0 && remove.top()==q.top()){
                remove.pop();
                q.pop();
            }
            q.push(nums[i]);
            ans.push_back(q.top());
        }
        return ans;
    }
};