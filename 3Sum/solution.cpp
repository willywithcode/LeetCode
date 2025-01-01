class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result = {};
        set<vector<int>> set;
        sort(nums.begin(), nums.end());
        for(int i = 0 ; i < nums.size(); i ++) {
            int target = -nums[i];
            size_t left = i + 1, right = nums.size() - 1;

            while (left < right) {
                int sum = nums[left] + nums[right];

                if (sum == target) {
                    set.insert({nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1]) ++left;
                    while (left < right && nums[right] == nums[right - 1]) --right;

                    ++left;
                    --right;
                } else if (sum < target) {
                    ++left; 
                } else {
                    --right;
                }
            }
        }
        for(auto it : set) {
            result.push_back(it);
        }
        return result;
    }
};