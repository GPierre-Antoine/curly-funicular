//
// Created by pierreantoine on 08/10/18.
//

#ifndef CURLY_FUNICULAR_NODE_H
#define CURLY_FUNICULAR_NODE_H

namespace avl {
    class node_finder;

    class node {
        node *left = nullptr;
        node *right = nullptr;
        int value = 0;

        void cleanup();

        void node::clean_no_children(avl::node_finder &finder) const;

        void node::clean_one_child(avl::node_finder &finder) const;

        void node::clean_two_children(avl::node_finder &finder) const;

    public:
        explicit node(int value);

        node();

        ~node();

        void add(int token);

        void remove(int token);

        int getValue() const;

        bool hasLeft() const;

        bool hasRight() const;

        node *getLeft();

        node *getRight();
    };
}


#endif //CURLY_FUNICULAR_NODE_H
