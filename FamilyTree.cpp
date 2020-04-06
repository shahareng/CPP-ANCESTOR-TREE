#include "FamilyTree.hpp"

#include <iostream>
using namespace std;


namespace family
{

    Tree::Tree(string name)
    {
        root->key_value = name;
        root->left=NULL;
        root->right=NULL;
    }
    
    // add father to someone that apear in the tree
    Tree& Tree::addFather(string kid, string father)
    {

        return *this;
    }

    // add mother to someone that apear in the tree
    Tree& Tree::addMother(string kid, string mother)
    {

        return *this;   
    }

    // return the relation in the tree ; e.g: mothre, father, unrelated and more..
    string Tree::relation(string name)
    {

        return "mother";
    }

    // return the name of the relation
    string Tree::find(string relat)
    {

        return "Yosef";
    }

    // display the tree
    void Tree::display()
    {

    }

    // delete the name and all his parents from the tree
    void Tree::remove(string name)
    {

    }
};