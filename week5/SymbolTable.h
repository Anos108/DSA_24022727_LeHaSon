#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H
#include <iostream>
#include <vector>


using namespace std;

template<class Key, class Value>
class SymbolTable {
private:
    vector<Key> keys;
    vector<Value> value;

    int rank_inprivate(const Key &key) const;

public:
    Key min();

    Key max();

    Key floor(Key& key);

    Key ceiling(Key& key);

    int rank(Key &key);

    Key select(int k);

    void deleteMin();

    void deleteMax();

    int size(Key lo, Key hi);

    vector<Key> keys_print();

    vector<Key> keys_printFromLoToHi(Key lo, Key hi);
};





#endif
