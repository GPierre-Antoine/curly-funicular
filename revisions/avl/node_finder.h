//
// Created by pierreantoine on 08/10/18.
//

#ifndef CURLY_FUNICULAR_NODE_FINDER_H
#define CURLY_FUNICULAR_NODE_FINDER_H

#include "node.h"

namespace avl {

    class node_finder {
        node *parent = nullptr;
        node *match = nullptr;
        bool matched = false;
        bool is_right_child = false;

        void apply_find(const int &value);

        void apply_lowest();

    public:

        node *get_parent() const;

        node *get_match() const;

        bool matches() const;

        bool match_is_right_child() const;

        bool match_has_no_children() const;

        bool match_has_one_child() const;

        explicit operator bool() const;

        static avl::node_finder find_closest(avl::node &node, const int &value);

        static avl::node_finder find_lowest(avl::node &node);
    };
}


#endif //CURLY_FUNICULAR_NODE_FINDER_H
