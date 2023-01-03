#include <stddef.h>
#include <stdexcept>
#include <memory>
#include <string>

using std::make_unique;

template <typename T> class Vector {

public:
    /**************************************************************************
     *************************  START: CONSTRUCTORS  *************************
    **************************************************************************/
    
    /**
     * WHAT: default constructor
     * NOTE: _capacity will be initialized to 4 by default.
    **/
    Vector() : _capacity(4), _size(0), _data(make_unique<T[]>(4)) {}

    /**
     * WHAT: reserve constructor
     * NOTE: _capacity * sizeof(T) bytes will be allocated (tight memory mgmt)
    **/
    Vector(size_t _capacity): _capacity(_capacity), 
                              _size(0),
                              _data(make_unique<T[]>(_capacity)) {}

    /**
     * WHAT: reserve + initialize constructor
     * NOTE: _capacity * sizeof(T) bytes will be allocated and initialized
    **/
    Vector(size_t _capacity, const T& init): _capacity(_capacity),
                                             _size(_capacity),
                                             _data(make_unique<T[]>(_capacity))
    {
        for (size_t i = 0; i < _size; ++i) {
            _data[i] = init;
        }
    };

    /**
     * WHAT: copy constructor
    **/
    Vector(const Vector<T>& other): _capacity(other._capacity),
                                    _size(other._size),
                                    _data(
                                        make_unique<T[]>(*(other._data.get()))
                                    )
    {}

    /**
     * WHAT: move constructor
    **/
    Vector(Vector<T> && other): _capacity(other._capacity), 
                                _size(other._size),
                                _data(std::move(other._data)) 
    {
        other._size = 0;
        other._capacity = 0;
    }

    Vector(std::initializer_list<T> init): _capacity(init.size()), 
                                           _size(init.size()),
                                           _data(make_unique<T[]>(_capacity))
    {
        int idx = 0;
        for (auto itr = init.begin(); itr != init.end(); ++itr) {
            _data[idx++] = *itr;
        }
    } 

    /**************************************************************************
     *************************   END: CONSTRUCTORS   *************************
    **************************************************************************/

    T& operator[] (size_t index) {
        if (index < 0 || index >= _size)
            throw std::out_of_range("\n\t out of bounds access: index " + std::to_string(index));
        
        return _data[index];
    }

    size_t size() { return _size; }

    size_t capacity() { return _capacity; }

    bool empty() { return _size == 0; }

private:
    size_t _capacity;
    size_t _size;
    std::unique_ptr<T[]> _data;
};
