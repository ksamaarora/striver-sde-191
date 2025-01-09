**Set Matrix Zeros**

**Problem Statement:**
Given an `n x m` matrix, set the entire row and column to zero for each zero present in the matrix. Note that while changing elements to zero, the newly marked zeros should not be considered for marking other rows and columns.

---

### **Brute Force Solution:**
**Approach:**
- Traverse through each row and column. If a zero is encountered, mark the entire row and column as zero.
- To avoid confusion between newly marked zeros and original zeros, mark the row and column with `-1` instead of zero initially.
- Finally, iterate through the matrix again and convert all `-1` elements to `0`.

```c++
// Method 1: Brute force solution 
// TC:O((n*m)*(n+m)) + O(n*m) = cube power 
// SC: O(1)

class Solution {
public:

    void setRow(vector<vector<int>>& matrix, int i){
        int col_size=matrix[0].size();
        for(int j=0; j<col_size; j++){
            if(matrix[i][j] != 0) { 
                matrix[i][j] = -1; // Only mark non-zero elements to avoid conflict
            }
        }
    }

    void setCol(vector<vector<int>>& matrix, int j){
        int row_size=matrix.size();
        for(int i=0; i<row_size; i++){
            if(matrix[i][j] != 0) { 
                matrix[i][j] = -1; // Only mark non-zero elements to avoid conflict
            }
        }
    }

    void setZeroes(vector<vector<int>>& matrix) { 
        int row_size=matrix.size();
        int col_size=matrix[0].size();

        for(int i=0; i<row_size; i++){
            for(int j=0; j<col_size; j++){
                if(matrix[i][j]==0){
                    setRow(matrix, i);
                    setCol(matrix, j);
                }
                else{
                    continue;
                }
            }
        }

        for(int i=0; i<row_size; i++){
            for(int j=0; j<col_size; j++){
                if(matrix[i][j]==-1){
                    matrix[i][j]=0;
                }
                else{
                    continue;
                }
            }
        }
    }
};

```

---

### **Better Solution:**
**Approach:**
- Use separate arrays to track rows and columns that need to be zeroed.
- Traverse the matrix and mark the respective row and column when a zero is encountered.
- Update the matrix using these marked arrays.


Brute force we were traversing across the entire matrix 
Better solution would be - 

If an entire column has a minimum of one xero 
or 
if an entire row has min of one zero
then, we would mark that row or col 

Thus we will keep a track of all the marked rows and col, 
thus create an extra col array and extra row array and marke all of them as zero intially 

[img](/day1_arrays_part1/01_setMatrixZeros/Screenshot%202025-01-08%20at%208.44.40 PM.png)

Thus after marking all the rows and columns, change all the 1's to 0's 

```c++
// Method 2: Better
// TC: O(n*m + n*m)
// SC:O(n) + O(m)
public:
    void setZeroes(vector<vector<int>>& matrix) { 
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> col(m, 0); // Vector for column tracking
        vector<int> row(n, 0); // Vector for row tracking
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]==0){
                    row[i]=1;
                    col[j]=1;
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(col[j]==1 || row[i]==1){
                    matrix[i][j]=0;
                }
            }
        }
    }
};
```
---

### **Optimal Solution:**
**Approach:**
- Use the first row and column as markers instead of separate arrays.
- Check the first row and column for zeros initially.
- Use the first row and column for marking, then update the matrix based on these markers.

The minimum TC required to traverse a matrix is O(n^2)
Thus for optimal solution we optimize the SC

To optimise we need to do everything in the matrix itslef rather than keeping an extra row and column
Now col[0] is row[n]
and row[0] is col[m]
since first element overlaps in row and column, we keep the first element track like this 

[img](/day1_arrays_part1/01_setMatrixZeros/Screenshot%202025-01-09%20at%203.35.36 PM.png)

```c++
// Method 3: Optimal Solution (In-Place)
// TC: O(n*m)
// SC: O(1)
#include <vector>
#include <limits.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row_size = matrix.size();
        int col_size = matrix[0].size();
        
        bool firstRowZero = false, firstColZero = false;
        
        // Step 1: Check if the first row needs to be zeroed
        for (int j = 0; j < col_size; j++) {
            if (matrix[0][j] == 0) {
                firstRowZero = true;
                break;
            }
        }

        // Step 2: Check if the first column needs to be zeroed
        for (int i = 0; i < row_size; i++) {
            if (matrix[i][0] == 0) {
                firstColZero = true;
                break;
            }
        }

        // Step 3: Use the first row and column as markers
        for (int i = 1; i < row_size; i++) {
            for (int j = 1; j < col_size; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Step 4: Zero out cells based on markers (ignoring the first row and col for now)
        for (int i = 1; i < row_size; i++) {
            for (int j = 1; j < col_size; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Step 5: Zero out the first row if needed
        if (firstRowZero) {
            for (int j = 0; j < col_size; j++) {
                matrix[0][j] = 0;
            }
        }

        // Step 6: Zero out the first column if needed
        if (firstColZero) {
            for (int i = 0; i < row_size; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};
```