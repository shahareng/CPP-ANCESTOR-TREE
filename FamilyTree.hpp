#include <iostream>
using namespace std;

struct node
{
    string key_value;
    node *left;
    node *right;
};

namespace family
{
    class Tree
    {
        public:

        Tree(string name);
        Tree& addFather(string kid, string father);
        Tree& addMother(string kid, string mother);
        string relation(string name);
        string find(string relat);
        void display();
        void remove(string name);

        struct node *root;
    };
};