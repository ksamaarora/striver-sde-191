Maximise the profit 

Buying has to be done before the selling

7 1 5 3 6 4

If you are selling on ith day, you buy on the minimum price from the first day to the (i-1)th day

thus pick each number from i=1 till end and compare it with the prev elements to find the min, in order to maximise the profit = num-prevelement

do this repeatedly for all the elements till the for loop gets over and return the maximum profit

### **Explanation (C++ Code for Best Time to Buy and Sell Stock)**

This code uses **Dynamic Programming (DP)** to maximize the profit by tracking the minimum price seen so far and the maximum profit possible.

---

### **Key Variables:**
- `mini`: Keeps track of the minimum price seen so far (for buying).
- `maxProfit`: Stores the maximum profit possible at each step.
- `n`: Size of the prices array.

---

### **Steps (Line by Line Explanation):**
1. **Initialization:**
   ```cpp
   int n=prices.size();
   int mini=prices[0];
   int maxProfit=0;
   ```
   - `mini` is initialized with the first price.  
   - `maxProfit` starts at 0 as no transaction has occurred yet.

2. **Loop through Prices:**
   ```cpp
   for(int i=1; i<n; i++){
   ```
   - Loop starts from the second day (`i=1`).

3. **Calculate Current Profit if Sold Today:**
   ```cpp
   int cost = prices[i] - mini;
   ```
   - `cost` calculates the profit if the stock is sold on the current day after buying at `mini`.

4. **Update Maximum Profit:**
   ```cpp
   maxProfit = max(maxProfit, cost);
   ```
   - Update `maxProfit` if the current profit (`cost`) is greater than the previous `maxProfit`.

5. **Update Minimum Price:**
   ```cpp
   mini = min(mini, prices[i]);
   ```
   - Update `mini` if the current price is lower than the previous `mini`.

6. **Return Result:**
   ```cpp
   return maxProfit;
   ```
   - Return the maximum profit calculated.

---

### **Example Walkthrough (prices = [7, 1, 5, 3, 6, 4]):**
- **Day 1:** mini = 7, maxProfit = 0  
- **Day 2:** mini = 1, maxProfit = 0  
- **Day 3:** cost = 5 - 1 = 4, maxProfit = 4  
- **Day 4:** cost = 3 - 1 = 2, maxProfit = 4  
- **Day 5:** cost = 6 - 1 = 5, maxProfit = 5  
- **Day 6:** cost = 4 - 1 = 3, maxProfit = 5  

**Final Output:** `maxProfit = 5`

---

### **Time and Space Complexity:**
- **Time Complexity:** `O(n)` → Linear scan of the array once.  
- **Space Complexity:** `O(1)` → Only a few variables are used for tracking, no extra data structures.  

✅ **Efficient and Optimal Solution.**