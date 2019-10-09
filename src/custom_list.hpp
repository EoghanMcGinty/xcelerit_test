#pragma once
#include <cstdlib>
#include <vector>
#include <stdexcept>
#include <unordered_map>
#include <string>


/** A list that can be indexed by int (position) and a string key 
 * 
 * The template parameter T can be arbitrary types. The requirements are
 * the same as for standard containers, i.e. they must be copyable and
 * default-constructable. 
 * 
 * It can be assumed that elements are never deleted - the only supported
 * operations are adding elements and accessing them by a string key or 
 * their index.
 **/
template <class T>
class CustomList
{
public:
    
    /** Check if list is empty */
    bool empty() const { return data_.empty(); }

    /** Return the length of the list */
    size_t size() const { return data_.size(); }

    /** Retrieve an element by its string-valued key.
     * 
     * @param key String-valued key into the list
     * @throw std::out_of_range if key is not in list
     */
    const T& get_by_key(const std::string& key) const {        
        int index = key_map_.at(key);
        return data_.at(index);        
    }

    /** Retrieve an element by its integer index 
     * 
     * @param i Integer index into the list. 0 < i < size()-1
     * @throw std::out_of_range if index is not in the list.
     */
    const T& get_by_index(int i) const  {       
        return data_.at(i);        
    }

    /** Add new value at the end, with the given key.
     * 
     * Note: no uniqueness checks are performed - if the same key 
     * is used for multiple elements, only the first match will be
     * retrieved later.
     * 
     * @param key string-valued key for later retrieval.
     * @param value The element to insert
     */
    void push_back(const std::string& key, const T& value) {
        data_.push_back(value);
        key_map_.insert({key, size() - 1});
    }

private:
    std::vector<T> data_;
    std::unordered_map<std::string, int> key_map_;
};
