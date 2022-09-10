#ifndef UF_HPP
#define UF_HPP
#include <vector>
#include <iostream>
#include <memory>

namespace my_union_find{
    using std::shared_ptr;
    template<class T>
    class Group;

    template<class T>
    class Element{
        public:
            shared_ptr<T> _data;
            Element* _perent;
            Group* _group;

            Element(shared_ptr<T> data, Group* group): _data(data), _perent(nullptr), Group*(group){}
            virtual ~Element = default;
    };
    
    template<class T>
    class Group{
        public:
            Element* _root;
            int _size;

            Group(Element* root): _root(root), _size(1) {}
            virtual ~Group = default;

    };

    template<class T>
    class UnionFind {
        public:
            vector<T> groups();
            vector<T> elements();
    };
}
    


#endif //UF_HPP