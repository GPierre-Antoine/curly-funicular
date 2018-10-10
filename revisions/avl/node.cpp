//
// Created by pierreantoine on 08/10/18.
//

#include "node.h"
#include "node_finder.h"

avl::node::node() : value(0) {

}

avl::node::node(int v) : value(v) {

}

avl::node::~node() {
    cleanup();
}

typedef avl::node *node_ptr;

void cleanup(node_ptr &node) {
    if (node) {
        delete node;
        node = nullptr;
    }

}

void add(node_ptr &node_t, int token) {
    if (node_t) {
        node_t->add(token);
    } else {
        node_t = new avl::node(token);
    }
}

void avl::node::cleanup() {
    ::cleanup(left);
    ::cleanup(right);

}

void avl::node::add(int token) {
    if (token < this->value) {
        ::add(left, token);
    } else if (token > this->value) {
        ::add(right, token);
    }

}

int avl::node::getValue() const {
    return value;
}

bool avl::node::hasLeft() const {
    return this->left != nullptr;
}

bool avl::node::hasRight() const {
    return this->right != nullptr;
}

avl::node *avl::node::getRight() {
    return right;
}

avl::node *avl::node::getLeft() {
    return left;
}


void avl::node::clean_no_children(avl::node_finder &finder) const {
    if (finder.match_is_right_child()) {
        ::cleanup(finder.get_parent()->right);
    } else {
        ::cleanup(finder.get_parent()->left);
    }
}

void avl::node::remove(int token) {
    auto finder = node_finder::find_closest(*this, token);
    if (!finder)
        return;

    if (finder.match_has_no_children()) {
        clean_no_children(finder);
    } else if (finder.match_has_one_child()) {
        clean_one_child(finder);
    } else {
        clean_two_children(finder);
    }

}

void avl::node::clean_one_child(avl::node_finder &finder) const {
    if (finder.get_match()->hasLeft()) {

    } else {

    }
}

void avl::node::clean_two_children(avl::node_finder &finder) const {
    auto match = finder.get_match();
    auto otherfinder = avl::node_finder::find_lowest(*match->getRight());
}

