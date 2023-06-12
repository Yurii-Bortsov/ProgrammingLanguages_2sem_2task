#include "node.h"

namespace miit
{
    Node::Node(const int data, Node* next, Node* previous)
    :data(data), next(next), previous(previous){}
    
    bool Node::operator==(const Node &node)
    {
        bool value = (data == node.data) * (next == node.next) * (previous == node.previous);
        return value;
    }

    bool Node::operator!= (const Node& node)
    {
            return !(*this == node);
    }
}
