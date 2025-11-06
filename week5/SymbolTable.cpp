#include "SymbolTable.h"
#include <iostream>
#include <vector>

template<class Key, class Value>
int SymbolTable<Key, Value>::rank_inprivate(const Key &key) const {
    int lo = 0;
    int hi = keys.size() - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (key < keys[mid]) {
            hi = mid - 1;
        } else if (key > keys[mid]) {
            lo = mid + 1;
        } else {
            return mid;
        }
    }
    return lo;
}

template<class Key, class Value>
Key SymbolTable<Key, Value>::min() {
    return keys.front();
}

template<class Key, class Value>
Key SymbolTable<Key, Value>::max() {
    return keys.back();
}

template<class Key, class Value>
Key SymbolTable<Key, Value>::floor(Key &key) {
    int i = rank_inprivate(key);
    if (i < keys.size() && keys[i] == key) return keys[i];
    return keys[i - 1];
}

template<class Key, class Value>
Key SymbolTable<Key, Value>::ceiling(Key &key) {
    int i = rank_inprivate(key);
    if (i < keys.size()) return keys[i];
    return keys[i];
}

template<class Key, class Value>
int SymbolTable<Key, Value>::rank(Key &key) {
    return rank_inprivate(key);
}

template<class Key, class Value>
Key SymbolTable<Key, Value>::select(int k) {
    return keys[k];
}

template<class Key, class Value>
void SymbolTable<Key, Value>::deleteMin() {
    keys.erase(keys.begin());
    value.erase(value.begin());
}

template<class Key, class Value>
void SymbolTable<Key, Value>::deleteMax() {
    keys.erase(keys.back());
    value.erase(value.back());
}

template<class Key, class Value>
int SymbolTable<Key, Value>::size(Key lo, Key hi) {
    int i = rank_inprivate(lo);
    int j = rank_inprivate(hi);
    if (j < keys.size() && keys[j] == hi) j++;
    return j - i;
}

template<class Key, class Value>
vector<Key> SymbolTable<Key, Value>::keys_print() {
    return keys;
}

template<class Key, class Value>
vector<Key> SymbolTable<Key, Value>::keys_printFromLoToHi(Key lo, Key hi) {
    vector<Key> res;
    if (lo > hi) return res;
    int i = rank_inprivate(lo);
    int j = rank_inprivate(hi);
    for (int k = i; k <= j; k++) {
        res.push_back(keys[k]);
    }
    return res;
}
