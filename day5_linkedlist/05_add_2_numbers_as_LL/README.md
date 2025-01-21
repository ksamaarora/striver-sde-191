## 2. Add Two Numbers

**Difficulty**: Medium  
**Topics**: Linked Lists, Math, Simulation  

### Problem Statement:
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each node contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except for the number 0 itself.

---

### Example 1:
**Input**:  
`l1 = [2,4,3]`  
`l2 = [5,6,4]`  

**Output**:  
`[7,0,8]`  

**Explanation**:  
The numbers represented are 342 and 465. Their sum is 807, represented as `[7,0,8]`.

---

### Example 2:
**Input**:  
`l1 = [0]`  
`l2 = [0]`  

**Output**:  
`[0]`

---

### Example 3:
**Input**:  
`l1 = [9,9,9,9,9,9,9]`  
`l2 = [9,9,9,9]`  

**Output**:  
`[8,9,9,9,0,0,0,1]`  

**Explanation**:  
The numbers represented are 9999999 and 9999. Their sum is 10009998, represented as `[8,9,9,9,0,0,0,1]`.

---

### Constraints:
- The number of nodes in each linked list is in the range `[1, 100]`.
- `0 <= Node.val <= 9`
- The linked lists represent numbers without leading zeros.

---

**Accepted Submissions**: 5.3M  
**Total Submissions**: 11.8M  
**Acceptance Rate**: 45.0%  