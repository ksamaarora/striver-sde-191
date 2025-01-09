Note: In interview 3 types of problems can be asked

- Given Row and Column, tell the element at that place 
- Print any nth row of the pascal triangle
- Print the entire pascal triangle 

Q1) Given R and C tell element at that place 

Formula:
(R-1)C(C-1)

Note: nCn=n!/(r! x (n-r)!)
e.g. 4C2 = 4!/(2! * 2!)

// Method 1: Brute Force
Find each value in the formula by running loops of factorial calculation and then calculate
```c++
// TC: O(n)+ O(r) + O(n-r)
// SC: O(1)
// NOTE: Very inefficient - dont do this 
```

Method 2:

[img](/day1_arrays_part1/02_pascalsTriangle/Screenshot%202025-01-09%20at%205.52.54 PM.png)

10 also goes 3 places and 3 goes 3 places .. make sure u divide 10 by 1, 9 by 2 and 8 by 3

```c++
// Method 2: Better Solution
// TC: O(r)
// SC: O(1)
int ncr(int n, int r){
    long long res=1; // Take largest data type to prevent overflow 
    for(int i=0; i<r; i++){
        res=res*(n-i);
        res=res/(i+1);
    }
    return res;
}
```

Q2) Print any nth row of the pascal triangle

Observation: Nth row will have n elements

Formula:
(R-1)C(C-1)

[img](/day1_arrays_part1/02_pascalsTriangle/Screenshot%202025-01-09%20at%206.31.39 PM.png)

Observation: Formula 
ans x (row-col)/col

```c++
// TC:O(N)
// SC:O(1)
long long ans=1;
for(int i=0; i<n; i++){
    ans=ans*(n-i);
    ans=ans/i;
    cout<<ans;
}
```

Q3) Print the entire pascal triangle 

Return ans in a list 
[img](/day1_arrays_part1/02_pascalsTriangle/Screenshot%202025-01-09%20at%206.37.44 PM.png)

```c++
class Solution {
public:
    vector<int> generateRow(int row) {
        long long ans = 1;
        vector<int> ansRow;
        ansRow.push_back(1);  // The first element is always 1
        for (int col = 1; col < row; col++) {
            ans = ans * (row - col);
            ans = ans / col;
            ansRow.push_back(ans);
        }
        return ansRow;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for (int i = 1; i <= numRows; i++) {
            ans.push_back(generateRow(i));  // Generate row 'i' which has i elements
        }
        return ans;
    }
};
```