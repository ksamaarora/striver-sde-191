### **237. Delete Node in a Linked List**  
**Difficulty:** Medium  
**Topics:** Linked List  

---

#### **Problem Description:**
You are given a singly linked list `head` and a reference to a node `node` in it. Your task is to delete the given `node` from the linked list. 

**Key Notes:**
1. You will not be given access to the `head` of the linked list.
2. All the values in the linked list are unique.
3. It is guaranteed that the node to be deleted is **not the last node** in the list.

By deleting the node, we mean:
- The value of the given node should no longer exist in the linked list.
- The number of nodes in the linked list should decrease by one.
- The order of the nodes before and after the given node should remain the same.

---

#### **Custom Testing:**
- For the input, you will provide the entire linked list (`head`) and the `node` to be deleted. 
- The function will modify the linked list directly, and the output will be the linked list after the deletion.

---

#### **Example 1:**

**Input:**  
`head = [4,5,1,9], node = 5`  
**Output:**  
`[4,1,9]`  

**Explanation:**  
You are given the second node with value `5`. After deleting this node, the linked list becomes `4 -> 1 -> 9`.

---

#### **Example 2:**

**Input:**  
`head = [4,5,1,9], node = 1`  
**Output:**  
`[4,5,9]`  

**Explanation:**  
You are given the third node with value `1`. After deleting this node, the linked list becomes `4 -> 5 -> 9`.

---

#### **Constraints:**
- The number of nodes in the linked list is in the range `[2, 1000]`.
- `-1000 <= Node.val <= 1000`.
- All values in the linked list are unique.
- The node to be deleted is guaranteed to be in the list and is **not the tail node**.

---

#### **Additional Notes:**
- You do not have to handle memory deallocation for the node explicitly. 
- Focus on updating the linked list structure correctly.

---