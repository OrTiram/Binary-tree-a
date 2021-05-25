#pragma once
#include <iostream>
#include <stack>
#include <sstream>
#include <fstream>
#include <string>
#include <stdexcept>

namespace ariel
{

template<typename T>
    class BinaryTree
    {

            struct TreeNode
            {
                    T data;
                    TreeNode *left;
                    TreeNode *right;

                    TreeNode(T val){
                        data = val;
                        this->left = nullptr;
                        this->right = nullptr;
                    
                    }
            };

      private:
        TreeNode *root ;

      public:
        BinaryTree<T>(){}
        ~BinaryTree(){}
        BinaryTree<T> add_root(const T& rootIn){return *this;}
        BinaryTree<T> add_left(const T& rootIn,const T& leftIn){return *this;}
        BinaryTree<T> add_right(const T& rootIn,const T& rightIn){return *this;}

            class iterator
            {
                private:
                   std::stack<TreeNode*> st;
                   TreeNode* point_to_current_node;

                public:
                    iterator(TreeNode* ptr = nullptr)
                    {
                        point_to_current_node = ptr;
                    }

                    T& operator*() const
                    {
                        return point_to_current_node->data;
                    }

                    T* operator->() const 
                    {
                        return &(point_to_current_node->data);
                        }

                    iterator& operator++(){return *this;}
                    const iterator operator++(int){return *this;}
                    bool operator==(const iterator& other) const {return point_to_current_node == other.point_to_current_node;}
                    bool operator!=(const iterator& other) const {return point_to_current_node != other.point_to_current_node;}
      
          };

          
                    iterator begin_preorder(){return iterator(nullptr);}
                    iterator end_preorder(){return iterator(nullptr);}
                    iterator end_inorder(){return iterator(nullptr);}
                    iterator begin_inorder(){return iterator(nullptr);}
                    iterator end_postorder(){return iterator(nullptr);}
                    iterator begin_postorder(){return iterator(nullptr);}
                    iterator begin(){return iterator(nullptr);}
                    iterator end(){return iterator(nullptr);}
                    friend std::ostream& operator<<(std::ostream& output,const BinaryTree<T> &tree){return output;}

    };
}
