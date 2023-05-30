#pragma once
#include "node.h"

namespace miit
{
    class List
    {
        private:
            Node *head;
            Node *tail;
        public:

            std::string toString();
            /**
            * @brief Конструктор класса List.
            * @param head Указатель на первый элемент списка.
            * @param tail Указатель на последний элемент списка.
            */
            List(Node* head = nullptr, Node* tail = nullptr);

            /**
             * @brief Деструктор класса List.
            */
            ~List();
        
            /**
             * @brief Вставляет новый узел с заданными данными в конец списка
             * @param data Данные для вставки
             */
            void PushBack(const int data);

            /**
             * @brief Вставляет новый узел с заданными данными в начало списка
             * @param data Данные для вставки
             */
            void PushAhead(const int data);
            /**
             * @brief Удаляет узел с конца списка
             */
            void DeleteBack();

            /**
             * @brief Удаляет узел с начала списка
             */
            void DeleteAhead();

            /**
             * @brief Проверяет, пуст ли список
             * @return True, если список пуст, иначе false
             */
            bool IsEmpty();

            /**
             * @brief Перегружает оператор << для вывода списка
             * @param os Поток вывода
             * @param list Список для вывода
             * @return Поток вывода
             */
            friend std::ostream& operator << (std::ostream& os, const List& list);

            /**
             * @brief Перегружает оператор == для сравнения двух списков
             * @param list Список для сравнения
             * @return True, если списки равны, иначе false
             */
            bool operator == (miit::List& list);
            
            /**
             * @brief Перегружает оператор != для сравнения двух списков
             * @param list Список для сравнения
             * @return True, если списки не равны, иначе false
             */
            bool operator != (miit::List list);
    };
}