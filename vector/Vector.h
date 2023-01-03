#include <stddef.h>
#include <stdexcept>
#include <memory>
#include <string>

template <typename T> class Vector {

public:
    /**************************************************************************
     *************************  START: CONSTRUCTORS  *************************
    **************************************************************************/
    
    /**
     * WHAT: default constructor
     * NOTE: capacity will be initialized to 4 by default.
    **/
    Vector() : capacity(4), size(0) {
        data = std::make_unique<T[]>(4);
    }

    /**
     * WHAT: reserve constructor
     * NOTE: _capacity * sizeof(T) bytes will be allocated (tight memory mgmt)
    **/
    Vector(size_t _capacity) : capacity(_capacity), size(0) {
        data = std::make_unique<T[]>(capacity);
    }

    /**
     * WHAT: reserve + initialize constructor
     * NOTE: _capacity * sizeof(T) bytes will be allocated and initialized
    **/
    Vector(size_t _capacity, const T& init) : capacity(_capacity), size(_capacity) {
        data = std::make_unique<T[]>(capacity);
        for (size_t i = 0; i < size; ++i) {
            data[i] = init;
        }
    };

    /**
     * WHAT: copy constructor
    **/
    Vector(const Vector<T>& other) : capacity(other.capacity), size(other.size) {
        data = std::make_unique<T[]>(*(other.data.get()));
    };

    /**************************************************************************
     *************************   END: CONSTRUCTORS   *************************
    **************************************************************************/

    T& operator[] (size_t index) {
        if (index < 0 || index >= size)
            throw std::out_of_range("\n\t out of bounds access: index " + std::to_string(index));
        
        return data[index];
    }

private:
    size_t capacity;
    size_t size;
    std::unique_ptr<T[]> data;
};
