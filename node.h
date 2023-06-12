#pragma once
#include <iostream>

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

        /**
         * @brief Оператор сравнения двух объектов класса Node.
         * @param point Объект класса Node.
         * @return true/false в зависимости от объектов.
        */
        bool operator == (const Node& node);

        /**
         * @brief Оператор сравнения двух объектов класса Node.
         * @param point Объект класса Node.
         * @return true/false в зависимости от объектов.
        */
        bool operator != (const Node& node);
    };  
}
