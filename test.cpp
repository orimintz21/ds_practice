#include "UF.hpp"
#include <vector>


// using namespace my_union_find;
using std::vector;
using std::string;

int main(){
    vector<int> my_vec;
    for(int i=0; i<100; i++){
        my_vec.push_back(i);
    }
    UnionFind<int> uf(my_vec);

}