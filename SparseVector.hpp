#include <vector>
#include <bifrost/roaring.hh>

template <class T>
class SparseVector {
    public:
        SparseVector();
        void insert(size_t i, const T &elem);
        T remove(size_t i);
        T get(size_t i) const;
        T get(size_t i, const T& def) const;
        bool contains(size_t i) const;
        bool isEmpty() const;

        T& operator[] (size_t i);
        const T& operator[] (size_t i) const;

    private:
        Roaring r;
        std::vector<T> v;
};

#include "SparseVector.tcc"
