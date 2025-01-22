# Hash Table
- [ ] Done?
## Theory
**A hash table** is a data structure that allows for efficient storage and retrieval of data in close to *O(1)* time. It is widely used to implement associative arrays, where elements are stored as key-value pairs.

The basic idea of ​​a hash table is to use a hash function that transforms a key into an index to access the array where the values ​​are stored.

**Where is it used?**:

- Associative arrays and containers
- Caching
- Databases
- Compilers (symbol tables)
- Distributed computing systems
- Cryptography
- Memory management systems
- Game engines
- Big Data

# Explanation
**Methods**:
- insert - insert a new key-value pair
- search - return a bool indicating whether the pair exists in the table
- remove - remove a pair
- print - print the table
- size - return the size of the table
___
```cpp
void insert(const K& key, const V& value) {
    size_t index = hash(key);
    for (auto& pair : table[index]) {
        if (pair.first == key) {
            pair.second = value;
            return;
        }
    }
    table[index].emplace_back(key, value);
}
```
If the key already exists, the value is updated.

### Example

The initial state of the table is empty.

Insert the following pairs: `(1, "Alice")`, `(6, "Bob")`, `(3, "Eve")`.

- For key 1:
- Hash: 1 % 5 = 1.
- Search in `table[1]` (list at index 1) — the list is empty.
- Add the pair `(1, "Alice")` to `table[1]`.

- For key 6:
- Hash: 6 % 5 = 1.
- Search in `table[1]` — it already contains `(1, "Alice")`.
- Since the keys are different, add the pair `(6, "Bob")` to `table[1]` (the collision is resolved via the chain).

- For key 3:
- Hash: 3 % 5 = 3.
- List `table[3]` is empty. Add pair `(3, "Eve")`.

Table result:
```
Index 0:
Index 1: (1, Alice) (6, Bob)
Index 2:
Index 3: (3, Eve)
Index 4:
```
**P. s.** Each table cell (index) is represented by a container of type `std::list`. If no elements were added to a specific cell, then this list remains empty, but this does not mean that "empty" indices (0, 2, 4) are absent altogether - they are there, they just contain empty lists.
___
```cpp
bool search(const K& key, V& value) const {
    size_t index = hash(key);
    for (const auto& pair : table[index]) {
        if (pair.first == key) {
            value = pair.second;
            return true;
        }
    }
    return false;
}
```
First, we calculate the index using the hash function and go through all the pairs in the list by index. If a pair is found, `true` is returned, otherwise `false`.
### Example
Hash-table:
```
Index 0:
Index 1: (1, Alice) (6, Bob)
Index 2:
Index 3: (3, Eve)
Index 4:
```
Find the value for key 1.

- Input data:

    - Key to search for: 1.
    - Hash table already contains data.
    - Hash function:
    ```cpp
    size_t hash(const int& key) const {
        return key % table_size; // table_size = 5
    }
    ```

- Calculate hash:

    - Hash for key 1:

    - `size_t index = hash(1); // 1 % 5 = 1`

    - Get index 1.

- Search the list at index 1:

    - Look at `table[1]`:

    - `table[1]`: `[(1, "Alice"), (6, "Bob")]`

    - Start traversing the list elements:
        - First pair: `(1, "Alice")`.
        - Key matches (1 == 1).
            - Store the value of `"Alice"` in `value`.
            - Return `true` (search successful).

- Search result:

    - The method returns `true`.
    - The value of key 1: `"Alice"`.
___
```cpp
bool remove(const K& key) {
    size_t index = hash(key);
    auto& list = table[index];
    for (auto it = list.begin(); it != list.end(); ++it) {
        if (it->first == key) {
            list.erase(it); // Remove pair
            return true;
        }
    }
    return false;
}
```
We calculate the index by key, get a list by index and go through all the elements from the resulting list. Then we check the keys for matching `key` (`it->first` stores the key of the element we are checking at the moment). If the keys match, we delete this pair and return 'true'.
### Example
1. Step 1:
    The method calculates the index of the table cell for the given key using the hash function:

    `size_t index = hash(key);`

    This allows us to find in which cell the list of (key, value) pairs is located.

2. Step 2:
    Get a reference to the list of pairs located in the cell with the found index:

    `auto& list = table[index];`

    Now we have access to the list of all elements with this index.

3. Step 3:
    Go through the list using an iterator:

    `for (auto it = list.begin(); it != list.end(); ++it)`

    Go through all the (key, value) pairs in this cell.

4. Step 4:
    Compare the key of the current pair with the passed key:

    `if (it->first == key)`

    If the key matches, then we have found the element that needs to be removed.

5. Step 5:
    Remove the found element from the list:

    `list.erase(it);`

    The erase method removes the pair by the iterator `it`.

6. Step 6:
    After successful deletion, return `true` to indicate that the element was found and removed.

Step 7:
    If the key is not found in the list, return `false`.