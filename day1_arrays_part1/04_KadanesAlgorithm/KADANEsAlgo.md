maxi=INT_MIN
sum=0;


arr[]=[-2,-3,4,-1,-2,1,5,-3]

as before u will iterate over the array one by one .. keeping a track of the maxi BUT the difference is 

say if u are at -2 
sum=-2+0;
maxi = max(INT_MIN,-2) = -2 // maxi=max(maxi,sum)

then u move to -3 
sum=-2-3=-5
maxi==max(-2,-5)= -2
thus there is no use of adding to a negativ sum .. thus whenever sum<0, we update sum to 0 and continue the loop

```cpp
for(int i=0; i<n; i++){
    sum+=nums[i];
    maxi=max(maxi,sum);
    if(sum<0) sum=0;
}
```

Note: To avoid INT Overflow error keep long long instead of int 

If in question it was given that if the maxi<0 at the end, return an empty subarray 
So u would do before returning the ans u would use a if case 
if(maxi<0){
    nums.clear();
    // return {}; // returns an empty vector directly 
}

### Follow Up Question
#### Can u print any of those subarrays that will give u the maximum sum 
```cpp
// STRIVER METHOD 
// TC: O(N) SC:O(1)
int sum=0;
int n=nums.size();
int maxi=INT_MIN;
int start, ansStart, ansEnd;
for(int i=0; i<n; i++){
    if(sum==0) start=i; // start will always be when sum is zero 
    sum+=nums[i];
    if(sum>maxi){
        maxi=sum;
        ansStart=start;
        ansEnd=i;
    }
    if(sum<0) {
        sum=0;
        ans.clear();
    }
}
return maxi;
```

```cpp
// Tracking Subaaray (not that good)
// TC: O(N) SC:O(N) in worst case 
int sum=0;
int n=nums.size();
int maxi=INT_MIN;
vector<int> ans, temp;  // `temp` keeps track of the current subarray
for(int i=0; i<n; i++){
    sum+=nums[i];
    temp.push_back(nums[i]);
    
    if(sum>maxi){
        maxi=sum;
        ans = temp;  // Store the subarray giving maximum sum
    }

    if(sum<0) {
        sum=0;
        temp.clear();  // Reset the subarray when sum goes negative
    }
}
return maxi;
```

