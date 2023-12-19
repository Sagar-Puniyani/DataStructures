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
    vector(const vector& v1 );

// implementation of the push opeartion 
    void push_back(T &object ){

    }

};


#endif 