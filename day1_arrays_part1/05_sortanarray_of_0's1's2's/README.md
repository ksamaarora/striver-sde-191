### **LeetCode Problem 75: Sort Colors (Medium)**

#### **Problem Statement:**
You are given an array `nums` with `n` objects colored **red**, **white**, or **blue**. Sort them **in-place** so that objects of the same color are adjacent, with the colors in the order:  
- **Red** (0)  
- **White** (1)  
- **Blue** (2)  

We will use the integers:  
- `0` → Red  
- `1` → White  
- `2` → Blue  

You must solve this problem **without using the library's sort function**.

---

### **Example 1:**
```plaintext
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
```

### **Example 2:**
```plaintext
Input: nums = [2,0,1]
Output: [0,1,2]
```

---

### **Constraints:**
- `n == nums.length`  
- `1 <= n <= 300`  
- `nums[i]` is either `0`, `1`, or `2`.  

---

### **Follow-Up:**
**Can you come up with a one-pass algorithm using only constant extra space?**
