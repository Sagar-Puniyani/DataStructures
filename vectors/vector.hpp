#ifndef VECTOR_H 
#define VECTOR_H 

template <typename T > 
class vector {

    private:
        int size;
        int capacity;
        T* items;

    public:

    vector();
    vector(int n ,const T  &value );
    vector(const vector& v0 );
    ~vector();

    int size() const {

    }

    int capacity() const {

    }

    bool Isempty() const {

    }

// implementation of the push opeartion 
    void push_back(T &object ){

    }


    T& operator [](int index);
    const T& operator [](int index) const ;

};


#endif 