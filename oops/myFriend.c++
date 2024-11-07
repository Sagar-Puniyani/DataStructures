#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Model
{
    private:
        string Name;
        int servings;
    
    public: 
        Model(string name, int serve) : Name(name), servings(serve){}

        friend bool compareServings(const Model &model1, const Model &model2);

        void display() const {
            cout << "Model name : " << Name << endl;
        }
};

bool compareServings(const Model &model1, const Model &model2){
    return model1.servings >= model2.servings;
}

int main(){

    Model userModel("authorized" , 44);
    Model viewModel("access" , 44);

    userModel.display();
    viewModel.display();

    if (compareServings(userModel, viewModel)){
        cout << "User has more servings" << endl;
    }
    else{
        cout << "View has more servings" << endl;
    }

    return 0;
}
