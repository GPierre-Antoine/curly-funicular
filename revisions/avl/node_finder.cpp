//
// Created by pierreantoine on 08/10/18.
//

#include "node_finder.h"

avl::node_finder avl::node_finder::find_closest(avl::node &node, const int &value) {
    node_finder finder;
    finder.match = &node;
    finder.apply_find(value);
    return finder;
}

void avl::node_finder::apply_find(const int &value) {
    while (match) {
        if (value == match->getValue()) {
            matched = true;
            return;
        }
        parent = match;
        if (value < match->getValue()) {
            is_right_child = false;
            if (match->hasLeft()) {
                match = match->getLeft();
            } else {
                match = nullptr;
            }
        } else {
            is_right_child = true;
            if (match->hasRight()) {
                match = match->getRight();
            } else {
                match = nullptr;
            }
        }
    }
}

avl::node *avl::node_finder::get_parent() const {
    return parent;
}

avl::node *avl::node_finder::get_match() const {
    return match;
}

bool avl::node_finder::matches() const {
    return matched;
}

avl::node_finder::operator bool() const {
    return matches();
}

bool avl::node_finder::match_is_right_child() const {
    return is_right_child;
}

bool avl::node_finder::match_has_no_children() const {
    return (!match->hasLeft() && !match->hasRight());
}

bool avl::node_finder::match_has_one_child() const {
    return match->hasLeft() ^ match->hasRight();
}

avl::node_finder avl::node_finder::find_lowest(avl::node &node) {
    node_finder finder{};
    finder.match = &node;
    finder.apply_lowest();
    return finder;
}

void avl::node_finder::apply_lowest() {
    while (match->hasLeft()) {
        parent = match;
        match = match->getLeft();
    }
}


