/*

Map:
• Associative container that stores key-value pairs.
• Allows efficient retrieval and modification of values based on keys.
• Keys are unique within the map.

Member Functions:
• begin(): Returns an iterator pointing to the first element (key-value pair) in the map.
• end(): Returns an iterator pointing to the past-the-end element in the map.
• empty(): Checks if the map is empty (i.e., whether its size is 0).
• size(): Returns the number of key-value pairs currently in the map.
• operator[](const Key& key): Accesses the value associated with the key, inserting a new element if the key does not exist.
• at(const Key& key): Accesses the value associated with the key, throwing an exception if the key is not found.
• insert(const std::pair<Key, Value>& value) or insert(iterator hint, const std::pair<Key, Value>& value): Inserts a new key-value
pair into the map; with a hint, it can potentially improve insertion efficiency.
• erase(const Key& key) or erase(iterator position) or erase(iterator first, iterator last): Removes one or more elements from the
map specified by key or position.
• clear(): Removes all key-value pairs from the map, which are destroyed, and leaves it with a size of 0.
• find(const Key& key): Returns an iterator to the element with the given key, or end() if the key is not found.
• count(const Key& key): Returns the number of elements with the specified key (1 or 0 since std::map does not allow
duplicate keys)

*/

#include<iostream>
#include<map>
#include<unordered_map>

using namespace std;

int main(){
    
    unordered_map<string,string> table;

    // insertion
    table["in"] = 'India';
    table.insert(make_pair("en","England"));

    pair<string,string> pair;

    pair.first = "br";
    pair.second = "brazil";

    table.insert(pair);

    return 0;
}