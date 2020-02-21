template <class T>
SparseVector<T>::SparseVector() {
    v.clear();
    r = Roaring();
}

// Warning:
// Worst case performance is O(N).
// It is recommended to insert items in order of ascending indices.
template <class T>
void SparseVector<T>::insert(size_t i, const T &elem) {
    size_t idx;
    if (r.contains(i)) {
        idx = r.rank(i);
        v[i] = elem;
    } else {
        r.add(i);
        idx = r.rank(i);
        if (v.size() < idx) v.resize(idx);
        v.emplace(v.begin() + idx, elem);
    }
}

// Warning:
// Worst case performance is O(N).
// It is recommended to remove items in order of descending indices.
template <class T>
T SparseVector<T>::remove(size_t i) {
    T t;
    if (r.contains(i)) {
        size_t idx = r.rank(i);
        t = v[idx];
        r.remove(i);
        v.erase(v.begin()+idx);
    }
    return t;
}

template <class T>
void getElements(std::vector<std::pair<size_t, T> > &elems) {
    
}

// Returns a new T if element is not in the sparse vector
template <class T>
T SparseVector<T>::get(size_t i) const {
    if (r.contains(i)) {
        return v[r.rank(i)];
    }
    return T();
}

// Returns def if element is not in the sparse vector
template <class T>
T SparseVector<T>::get(size_t i, const T &def) const {
    if (r.contains(i)) {
        return v[r.rank(i)];
    }
    return def;
}

template <class T>
bool SparseVector<T>::contains(size_t i) const {
    return r.contains(i);
}

template <class T>
bool SparseVector<T>::isEmpty() const {
    return r.isEmpty();
}

template <class T>
T& SparseVector<T>::operator[] (size_t i) {
    if (r.contains(i)) {
        return v[r.rank(i)];
    }
    throw std::invalid_argument("Index not present in SparseVector.");
}

template <class T>
const T& SparseVector<T>::operator[] (size_t i) const {
    if (r.contains(i)) {
        return v[r.rank(i)];
    }
    throw std::invalid_argument("Index not present in SparseVector.");
}
