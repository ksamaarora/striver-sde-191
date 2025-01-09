### **Method 1: Brute Force Approach (Pseudocode)**

**Time Complexity:** \(O(n^2 \times m)\)  
**Space Complexity:** \(O(1)\)

```plaintext
function countPrefixSuffixPairs(words):
    n = size of words
    count = 0

    for i from 0 to n-1:
        for j from i+1 to n-1:
            word1 = words[i]
            word2 = words[j]

            if length(word1) > length(word2):
                continue

            # Check if word1 is a prefix and suffix of word2
            if word2 starts with word1 AND word2 ends with word1:
                count += 1

    return count
```

---

### **Method 2: Trie-Based Approach (Pseudocode)**

**Time Complexity:** \(O(n^2 \times m)\)  
**Space Complexity:** \(O(n \times m)\)  

**Trie Node Definition:**
```plaintext
class Node:
    links = array of size 26 initialized to NULL

    function contains(char):
        return links[char - 'a'] != NULL

    function put(char, node):
        links[char - 'a'] = node

    function next(char):
        return links[char - 'a']
```

**Trie Definition:**
```plaintext
class Trie:
    root = new Node()

    function insert(word):
        node = root
        for each char in word:
            if node does not contain char:
                node.put(char, new Node())
            node = node.next(char)

    function startsWith(prefix):
        node = root
        for each char in prefix:
            if node does not contain char:
                return false
            node = node.next(char)
        return true
```

**Main Function Using Trie:**
```plaintext
function countPrefixSuffixPairs(words):
    n = size of words
    count = 0

    for i from 0 to n-1:
        prefixTrie = new Trie()
        suffixTrie = new Trie()

        # Insert current word in both tries
        prefixTrie.insert(words[i])

        reversedWord = reverse(words[i])
        suffixTrie.insert(reversedWord)

        for j from 0 to i-1:
            if length(words[j]) > length(words[i]):
                continue

            prefixWord = words[j]
            reversedPrefixWord = reverse(words[j])

            # Check both prefix and suffix condition using the Trie
            if prefixTrie.startsWith(prefixWord) AND suffixTrie.startsWith(reversedPrefixWord):
                count += 1

    return count
```

---

### **Key Differences:**
- **Brute Force:** Directly compares strings using `find()` and `rfind()` functions.  
- **Trie-Based:** Uses a trie data structure to check prefixes and suffixes efficiently.  
