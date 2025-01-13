class Solution {
public:
    void sortColors(vector<int>& nums) {
        // Method 0: Not allowed to use in this question 
        // TC: O(N logN)
        // SC: O(logN)
        int n=nums.size();
        sort(nums.begin(), nums.end());

        // Method 1: Extreme Brute force 
        // MERGE SORT : DIVIDE AND CONQUER 
        // Use merge sort TC:O(N logN) SC:O(N)
        // Explanation: It divides the input array into two-parts, until the size of the input array is not '1'. In the return part, it will merge two sorted arrays a return a whole merged sorted array.
        

        // Method 2: Brute force approach TC:O(2N) SC:O(1) no extra space used, we are just modifying the given array
        int n=nums.size();
        int cnt0=0;
        int cnt1=0;
        int cnt2=0;
        for(int i=0; i<n; i++){
            if(nums[i]==0) cnt0++;
            else if(nums[i]==1) cnt1++;
            else cnt2++;
        }
        int i=0;
        while(cnt0!=0){
            nums[i]=0;
            cnt0--;
            i++;
        }
        while(cnt1!=0){
            nums[i]=1;
            cnt1--;
            i++;
        }
        while(cnt2!=0){
            nums[i]=2;
            cnt2--;
            i++;
        }
        
        // Method 3: Better solution TC:O(2N) SC:O(3)==O(1)
        unordered_map<int,int> mpp; // number, count
        int n = nums.size();
        for (int i=0; i<n; i++) {
            mpp[nums[i]]++;  // Automatically increments count or sets to 1 if not present
        }
        int i = 0; // Update the original array based on counts stored in mpp
        for (int count = 0; count < mpp[0]; count++){
            nums[i++]=0;
        }
        for (int count = 0; count < mpp[1]; count++){
            nums[i++]=1;
        }
        for (int count = 0; count < mpp[2]; count++){
            nums[i++]=2;
        }
        
        // Method 4: DUTCH NATIONAL FLAH ALGO - One Pass
        // Optimal Solution TC:O(N) SC:O(1)
        // Initially mid and low was at start and high was at end, so in worst time complexity mid would move by one and high would move by one on left
        // Thus iterating through the whole array - TC:O(N)
        int n=nums.size();
        int low=0, mid=0, high=n-1;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else if(nums[mid]==2){
                swap(nums[mid], nums[high]);
                high--;
            }
        }
        
    }
};