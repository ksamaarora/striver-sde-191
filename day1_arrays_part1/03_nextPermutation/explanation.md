arr[]=[3,2,1]

1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1

3 factorial possible ways = 3! = 6

have to write them in dictionary order
sorted order

find next permutation after given array num 

if given is 3 2 1 then u will fall back to the first num and return ans=[1 2 3]

Method 1: Brute Force
find all permutations 
sort them 
then do linear search to find num given in question
return the next nnumber (next index num) to the given num for ans



