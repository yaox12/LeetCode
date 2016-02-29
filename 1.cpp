class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> origin(nums.begin(), nums.end());
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i ++)
            for (int j = i + 1; j < nums.size(); j ++) {
                int temp = nums[i] + nums[j];
                if (temp < target)  continue;
                if (temp == target)
                    return get_index(origin, nums[i], nums[j]);
                if (temp > target)  break;
            }
    }
private:
    vector<int> get_index(vector<int>& origin, int a, int b) {
        vector<int> ans;
        for (int i = 0; i < origin.size(); i ++) 
            if (origin[i] == a || origin[i] == b)
                ans.push_back(i + 1);
        return ans;
    }
};