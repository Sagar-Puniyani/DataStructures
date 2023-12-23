#ifndef VECTOR_H 
#define VECTOR_H 

const int default_vector_size = 5;
template <typename T > 
class vector {

    private:
        size_t size_;
        size_t capacity_;
        T* elements;

    public:
    vector(){
        size_ = 0;
        capacity_ = default_vector_size;
        elements = new T[default_vector_size];
    }
    vector(int n ,const T  &value ){
        this->size_ = n;
        this->capacity_ = 2*n;
        elements = new T[capacity_];
        for ( int i=0 ; i<n ; i++){
            elements[i] = value;
        }
    }
    vector(const vector& v0 ){
        this->size_ = v0.size_;
        this->capacity_ = v0.capacity_;
        elements = new T[capacity_];

        for (size_t i=0 ; i<v0.size_ ; i++) {
            elements[i] = v0.elememts[i];
        }
    }
    ~vector(){
        delete[] elements;
    }

    public:
    size_t  size() const {
        return size_;
    }

    size_t capacity() const {
        return capacity_;
    }

    bool Isempty() const {
        return size_==0;
    }


// v[i] = x, this is writing operation 
    T& operator [](int index){
        return elements[index];
    }
// x = v[i], this is reading operation 
    const T& operator [](int index) const {
        return elements[index];
        
    }

// v = w 
    vector& operator = (const vector &object ) {
        if ( size_ < object.size_){
            delete[] elements;
            capacity_ = 2 * size_;
            elements = new T[capacity_];
        }
        for ( size_t i = 0 ; i<object.size_ ; i++){
            elements[i] = object.elements[i];
        }
        size_ = object.size_;
        return *this;
    }

// implementation of the push opeartion 
    void push_back(const T &object ){
        if ( size_ == capacity_ ) {
            T* newarray = new T[2 * capacity_];
            for (size_t i=0 ; i < size_ ; i++){
                newarray[i] = elements[i];
            }
            delete[] elements;
            elements = newarray;
            capacity_ *= 2;
        }
        elements[size_] = object;
        size_++;
    }

    void pop_back() {
        if (size_ > 0 ){
            size_--;
        }
    }

    void Erase(int index ){
        for (size_t i = index ; i < size_ ; i++){
            elements[i] = elements[i+1];
        }
        size_--;
    }

    void insert(int index , T& value ){

    }

    void clear(){
        size_ = 0;
        capacity_ = default_vector_size;
        delete[] elements;
    }
};


#endif 