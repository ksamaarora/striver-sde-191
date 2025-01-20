class Solution {
public:
    void merge(vector<int>& nums, int low, int mid, int high){
        int left=low;
        int right=mid+1;
        vector<int> temp;

        while(left<=mid && right<=high){ // Merging two halves
            if(nums[left]<=nums[right]) {
                temp.push_back(nums[left]);
                left++;
            }
            else{
                temp.push_back(nums[right]);
                right++;
            }
        }
        while(left<=mid){  // Adding remaining elements from left half (if any)
            temp.push_back(nums[left]);
            left++;
        }
        while(right<=high){ // Adding remaining elements from right half (if any)
            temp.push_back(nums[right]);
            right++;
        }
        // Copy sorted elements back to the original array
        for(int i = 0; i < temp.size(); i++){
            nums[low + i] = temp[i];
        }
    }

    void ms(vector<int>& nums, int low, int high){
        if(low==high) return;
        int mid=(low+high)/2;
        ms(nums,low,mid);
        ms(nums,mid+1,high);
        merge(nums,low,mid,high);
    }

    void sortColors(vector<int>& nums) {
        // Method 1: Extreme Brute force 
        // MERGE SORT : DIVIDE AND CONQUER 
        // Use merge sort TC:O(N logN) SC:O(N)
        // Explanation: It divides the input array into two-parts, until the size of the input array is not '1'. In the return part, it will merge two sorted arrays a return a whole merged sorted array.
        int n=nums.size();
        ms(nums,0,n-1);
    }
};