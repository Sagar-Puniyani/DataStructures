#include <iostream>
using namespace std;

class String {

    public:
    char* data;

    // Default constructor
    String() {
        data = nullptr;
    }

    // Parameterized constructor
    String(const char* str) {
        int length = strlen(str);
        data = new char[length + 1];
        strcpy(data, str);
    }

    // Copy constructor
    String(const String& other) {
        int length = strlen(other.data);
        data = new char[length + 1];
        strcpy(data, other.data);
    }

    // Move constructor
    String(String&& other) noexcept {
        data = other.data;
        other.data = nullptr;
    }

    // Destructor
    ~String() {
        delete[] data;
    }

    // Copy assignment operator
    String& operator=(const String& other) {
        if (this != &other) {
            delete[] data;
            int length = strlen(other.data);
            data = new char[length + 1];
            strcpy(data, other.data);
        }
        return *this;
    }

    // Move assignment operator
    String& operator=(String&& other) noexcept {
        if (this != &other) {
            delete[] data;
            data = other.data;
            other.data = nullptr;
        }
        return *this;
    }

    // Getter method
    const char* getData() const {
        return data;
    }
    
};


int main(){


    return 0;
}