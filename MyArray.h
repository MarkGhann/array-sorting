#ifndef __MYARRAY_H__
#define __MYARRAY_H__

#include <cassert>
#include <ostream>

class MyArray final {
public:
    enum SortType {
         BUBBLE = 0,
    };

public:
    inline MyArray(size_t size = 10) {
        this->max = size;
        this->curr = 0;
        this->arr = new int64_t[size];
        for(size_t i = 0; i < this->max; i++) {
            this->arr[i] = 0;
        }
    }
    
    inline MyArray(const MyArray &array) {
        *this = array;
    }

    ~MyArray() {
        delete this->arr;
    }

public:
    MyArray& operator=(const MyArray& array) {
        this->UpdateArray(array.GetMax());
        for(size_t i = 0; i < array.GetSize(); i++) {
            this->arr[i] = array[i];
            this->curr++;
        }
        return *this;
    }

    int64_t& operator[] (size_t n) const {
        assert(n < this->curr);
        return this->arr[n];
    }

public:
    inline int8_t Add(int64_t v) {
        assert(this->arr != nullptr);
        if (this->curr >= this->max) {
            this->DoubleArray();
        }

        this->arr[this->curr] = v;
        this->curr++;

        return 0;
    }

    inline int8_t Replace(size_t n1, size_t n2) {
        assert(this->arr != nullptr);
        assert(n1 < this->curr && n2 < this->curr);

        int64_t tmp = this->arr[n1];
        this->arr[n1] = this->arr[n2];
        this->arr[n2] = tmp;

        return 0;
    }

    inline int64_t GetValue(size_t n) const {
        assert(this->arr != nullptr);
        assert(n < this->curr);
        return this->arr[n];
    }

    inline void Sort(SortType type) {
        switch(type) {
            case SortType::BUBBLE: {
                this->BubbleSort();
            } break;
        }
    }
    
    inline void Print(std::ostream &out) {
        out << "array:";
        for(size_t i = 0; i < this->curr; i++) {
            out << " ";
            out << this->arr[i];
        }
        out << "\n";
    }

    inline size_t GetSize() const {
        return this->curr;
    }

protected:
    inline size_t GetMax() const {
        return this->max;
    }

private:
    inline void UpdateArray(size_t size) {
        delete this->arr;
        this->max = size;
        this->curr = 0;
        this->arr = new int64_t[size];
        for(size_t i = 0; i < this->max; i++) {
            this->arr[i] = 0;
        }
    }

    inline void DoubleArray() {
        int64_t *new_arr = new int64_t[this->max<<2];
        for(size_t i = 0; i < this->max; i++) {
            new_arr[i] = this->arr[i];
        }
        delete this->arr;
        this->arr = new_arr;
        this->max *= 2;
    }

    void BubbleSort();

private:
    int64_t *arr = nullptr;
    size_t max;
    size_t curr;
};

#endif // __MYARRAY_H__