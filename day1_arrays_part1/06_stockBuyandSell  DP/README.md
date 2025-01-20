**Problem:** Best Time to Buy and Sell Stock  

**Difficulty:** Easy  
**Topics:** Arrays, Dynamic Programming  

---

**Description:**  
You are given an array `prices` where `prices[i]` represents the price of a stock on the `i-th` day.  

Your task is to maximize your profit by choosing:  
- A single day to **buy** one stock.  
- A different day in the future to **sell** that stock.  

Return the **maximum profit** you can achieve from this transaction. If no profit can be made, return `0`.  

---

**Example 1:**  
**Input:** `prices = [7,1,5,3,6,4]`  
**Output:** `5`  
**Explanation:**  
- Buy on day 2 (price = 1)  
- Sell on day 5 (price = 6)  
- Profit = `6 - 1 = 5`  

**Example 2:**  
**Input:** `prices = [7,6,4,3,1]`  
**Output:** `0`  
**Explanation:**  
- No profitable transaction can be made.  

---

**Constraints:**  
- `1 <= prices.length <= 10^5`  
- `0 <= prices[i] <= 10^4`  

---

**Note:**  
- You must buy before you sell.  
- Only **one transaction** is allowed.  