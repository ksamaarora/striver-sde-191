// Method 1: Brute force solution 
// NOTE: THIS SOLUTION DOESNT WORK AS IN TEST CASE SOME MATRIX ELEMENT HAS VALUE = -1 AS WELL SO THAT CAUSES CONFUSION AND THUS WRONG ANSWER
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

// Method 2: Better
// TC: O(n*m + n*m)
// SC:O(n) + O(m)
class Solution {
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
