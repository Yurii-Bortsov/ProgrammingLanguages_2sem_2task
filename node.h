#pragma once

namespace miit
{
    struct Node
    {
        int data;
        Node* next;
        Node* previous;

        /**
         * @brief Конструктор класса Node.
         * @param data Значение, которое содержит элемент списка.
         * @param next Указатель на следующий элемент списка.
         * @param previous Указатель на предыдующий элемент списка.
        */
        Node(const int data, Node* next = nullptr, Node* previous = nullptr);
    };
}
