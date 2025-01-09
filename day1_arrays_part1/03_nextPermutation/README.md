**LeetCode Problem 31: Next Permutation**

**Difficulty:** Medium  

A **permutation** of an array of integers is an arrangement of its elements into a sequence or linear order.

For example, for `arr = [1,2,3]`, all permutations are:  
`[1,2,3]`, `[1,3,2]`, `[2,1,3]`, `[2,3,1]`, `[3,1,2]`, `[3,2,1]`.  

The **next permutation** of an array is the next lexicographically greater permutation of its elements. If no such permutation exists, the array must be rearranged into the smallest possible order (i.e., sorted in ascending order).

### Examples:
- The next permutation of `[1,2,3]` is `[1,3,2]`.  
- The next permutation of `[2,3,1]` is `[3,1,2]`.  
- The next permutation of `[3,2,1]` is `[1,2,3]` because it’s the highest permutation possible.  

### **Task:**  
Given an array of integers `nums`, modify the array **in place** to find the next permutation.  
- **In place:** The solution must use only constant extra memory.  

---

### **Example 1:**
**Input:** `nums = [1,2,3]`  
**Output:** `[1,3,2]`  

### **Example 2:**
**Input:** `nums = [3,2,1]`  
**Output:** `[1,2,3]`  

### **Example 3:**
**Input:** `nums = [1,1,5]`  
**Output:** `[1,5,1]`  

---

### **Constraints:**
- `1 <= nums.length <= 100`  
- `0 <= nums[i] <= 100`  