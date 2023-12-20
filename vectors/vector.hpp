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

        for (int i=0 ; i<v0.size_ ; i++) {
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

    }

// implementation of the push opeartion 
    void push_back(const T &object ){
        if ( size_ == capacity_ ) {
            T* newarray = new T[2 * capacity_];
            for (int i=0 ; i < size_ ; i++){
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

    }

    void Erase(int index ){

    }

    void insert(int index , T& value ){

    }

    void clear(){

    }
};


#endif 