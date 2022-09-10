#ifndef UF_HPP
#define UF_HPP
#include <vector>
#include <iostream>
#include <memory>
#include <exception>
// namespace my_union_find{
    using std::vector;
    template<class T>
    class Group;

    template<class T>
    class Element{
        public:
            const T _data;
            Element<T>* _parent;
            Group<T>* _group;

            Element(const T data): _data(data), _parent(nullptr), _group(nullptr) {}
            Element() : _data(), _parent(nullptr), _group(nullptr){} 
    };
    
    template<class T>
    class Group{
        public:
            Element<T>* _root;
            int _size;

            Group(Element<T>* root): _root(root), _size(1) {}
            Group(): _root(nullptr), _size(0) {}
            void Add(Element<T>& new_element){
                new_element._parent = this->_root;
                _size++;
            }
    };

    template<class T>
    class UnionFind {
        public:
            vector<Group<T>> _groups;
            vector<Element<T>> _elements;

            UnionFind(const vector<T> data){
                for (auto i : data){
                    _elements.push_back(i);
                    _groups.push_back(&(_elements.back()));
                    _elements.back()._group = &(_groups.back());
                }
            }

            Group<T>& Find(int loc) const {
                Element<T>* root = &_elements.at(loc);
                while(root->_parent != nullptr)
                {
                    root = root->_parent;
                }
                //sets the parents for all the elements in the rout
                Element<T>* element_ptr = & (_elements.at(loc));
                while (element_ptr != root)
                {
                    element_ptr->_parent = root;
                }
                
                return *(root->_group);
            }

            Group<T>& Union(Group<T>& group1, Group<T>& group2){
                if(&group1 == & group2){
                    throw std::invalid_argument();
                }
                if(group1._size <= group2._size)
                {
                    group2._root->_parent = group1._root;
                    group1._size += group2._size;
                    return group1;
                }
                else{
                    group1._root->_parent = group2._root;
                    group2._size += group1._size;
                    return group2;
                }
            }

            Group<T>& Union(int loc1, int loc2){
                return Union(Find(loc1), Find(loc2));
            }
    };
// }
    


#endif //UF_HPP