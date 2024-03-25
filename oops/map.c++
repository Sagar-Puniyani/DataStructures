#include <iostream>
#include <unordered_map>
#include <vector>

int main(){

    std:: vector<int> arr = {10 , 20 , 30 , 40 };

    for (  std::vector<int> :: iterator item = arr.begin() ; item != arr.end() ; item++ ){
        void * ptr = &(*item);
        std::cout << ptr << " -" << std::endl;

        std::cout << static_cast<void*>(&(*item)) << " " << std::endl;
    }

    std::cout << "arr.begin: " << static_cast<void*>(&(*arr.begin())) << std::endl;




    // use of map 
    std::cout << "==================Use of MAP===================" << std :: endl;
    using Map = std::unordered_map <std::string , int >;

    std :: unordered_map <std:: string , int > map;
    map["c++" ] = 2;
    map["sagar"] = 10;

    for ( Map :: iterator iterator = map.begin() ; iterator != map.end() ; ++iterator  ){
        auto& key = (*iterator).first;
        auto& value  = (*iterator).second;

    std :: cout << key << " = " << value << std :: endl;

    }
    
    std:: cout << std :: endl;

    for ( auto KeyValuePair : map ){
        auto& key = (KeyValuePair).first;
        auto& value  = (KeyValuePair).second;

    std :: cout << key << " = " << value << std :: endl;
    }

    std:: cout << std :: endl;

    for ( auto [key , value ] : map ){
    std :: cout << key << " = " << value << std :: endl;
    }




    return 0;
}