class Solution {
public:
 int lowerBound(vector<int>& nums, int target){
    int left = 0;
    int right = nums.size();
    while(left<right){
        int mid = left+ (right-left) /2;
        if(nums[mid]<target)
            left = mid +1;
        
        else 
            right = mid;
        
    }
    return left;
}
int upperBound(vector<int>& nums, int target){
    int left = 0;
    int right = nums.size();
    while(left<right){
        int mid = left+(right-left)/2;
        if(nums[mid]<=target)
         left = mid + 1;
        else
         right = mid;
    }
    return left;
}
vector<int>searchRange(vector<int>& nums ,int target){
    int first = lowerBound(nums ,target);
    int last = upperBound(nums ,target)- 1;
    if(first>=nums.size()|| nums[first]!= target)
     return {-1 , -1};
     return{first ,last};

}
        
        
    
};