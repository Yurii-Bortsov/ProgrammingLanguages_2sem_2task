#include "node.h"

namespace miit
{
    Node::Node(const int data, Node* next, Node* previous)
    :data(data), next(next), previous(previous){}
}