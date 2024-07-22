#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <execution>
using namespace std;

void printArr(vector<string> ans){
    for (auto element : ans ){
        cout << "  " << element;
    }
    cout << endl;
}

vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
    map<int, string, greater<int> > m;
    int n = names.size();

    for (int i=0; i<n; i++){
        m.insert(make_pair(heights[i] , names[i]));
    }

    vector<string> ans;
    for (auto pair : m ){
        ans.push_back(pair.second);
    }

    return ans;
}

// space optimization
vector<string> sortPeopleOPT(vector<string>& names, vector<int>& heights) {
    std::vector<std::pair<std::string, int>> pairs{};
    for (std::size_t i = 0; i < names.size(); i++)
        pairs.push_back(std::make_pair(names[i], heights[i]));

    std::sort(std::execution::par_unseq, pairs.begin(), pairs.end(), [](const auto& a, const auto& b) -> bool
    {
        return a.second > b.second;
    });

    vector<string> ans;
    for (auto pair : pairs ){
        ans.push_back(pair.first);
    }

    return ans;
}



int main(){
    vector<string> names = {"Mary","John","Emma"};
    vector<int> heights = {500,900,1000};

    vector<string> ans = sortPeopleOPT(names, heights);
    printArr(ans);


    return 0;
}