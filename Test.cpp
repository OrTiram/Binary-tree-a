#include <iostream>
#include <sstream>
#include <stdexcept>
#include <fstream>
#include <string>
#include "doctest.h"
#include "BinaryTree.hpp"
using namespace ariel;
using namespace std;

TEST_CASE("Int BinaryTree"){
    BinaryTree<int> binary_tree_int;
    CHECK_NOTHROW(binary_tree_int.add_root(1));
    CHECK_NOTHROW(binary_tree_int.add_left(1,2));
    CHECK_NOTHROW(binary_tree_int.add_right(1,3));
    CHECK_NOTHROW(binary_tree_int.add_left(3,6));
    CHECK_NOTHROW(binary_tree_int.add_left(2,4));
    CHECK_NOTHROW(binary_tree_int.add_right(2,5));
    CHECK_NOTHROW(binary_tree_int.add_right(5,7));
    CHECK_NOTHROW(binary_tree_int.add_right(6,8));
    CHECK_THROWS(binary_tree_int.add_left(9,7)); // 9 does not exist
    CHECK_THROWS(binary_tree_int.add_right(10,2)); // 10 does not exist

    int i = 0;
    int pre[] = {1,2,4,5,7,3,6,8};
    int In[] = {4,2,5,7,1,6,8,3};
    int post[] = {4,7,5,2,8,6,3,1};

    for (auto it=binary_tree_int.begin_preorder(); it!=binary_tree_int.end_preorder(); ++it)
    {
        CHECK_EQ(*it,pre[i++]);
       
    }  

    for (auto it=binary_tree_int.begin_inorder(); it!=binary_tree_int.end_inorder(); ++it)
    {
        CHECK_EQ(*it,In[i++]);
       
    }  
    for (auto it=binary_tree_int.begin_postorder(); it!=binary_tree_int.end_postorder(); ++it)
    {
        CHECK_EQ(*it,post[i++]);
        
    }  

}

TEST_CASE("String BinaryTree"){
    BinaryTree<string> binary_tree_string;
    CHECK_NOTHROW(binary_tree_string.add_root("1"));
    CHECK_NOTHROW(binary_tree_string.add_left("1","2"));
    CHECK_NOTHROW(binary_tree_string.add_right("1","3"));
    CHECK_NOTHROW(binary_tree_string.add_left("3","6"));
    CHECK_NOTHROW(binary_tree_string.add_left("2","4"));
    CHECK_NOTHROW(binary_tree_string.add_right("2","5"));
    CHECK_NOTHROW(binary_tree_string.add_right("5","7"));
    CHECK_NOTHROW(binary_tree_string.add_right("6","8"));
    CHECK_THROWS(binary_tree_string.add_left("9","7")); // 9 does not exist
    CHECK_THROWS(binary_tree_string.add_right("10","2")); // 10 does not exist

    int i = 0;
    string pre[] = {"1","2","4","5","7","3","6","8"};
    string In[] = {"4","2","5","7","1","6","8","3"};
    string post[] = {"4","7","5","2","8","6","3","1"};

    for (auto it=binary_tree_string.begin_preorder(); it!=binary_tree_string.end_preorder(); ++it)
    {
        CHECK_EQ(*it,pre[i++]);
        
    }  

    for (auto it=binary_tree_string.begin_inorder(); it!=binary_tree_string.end_inorder(); ++it)
    {
        CHECK_EQ(*it,In[i++]);
        
    }  
    for (auto it=binary_tree_string.begin_postorder(); it!=binary_tree_string.end_postorder(); ++it)
    {
        CHECK_EQ(*it,post[i++]);
        
    } 
   



}



