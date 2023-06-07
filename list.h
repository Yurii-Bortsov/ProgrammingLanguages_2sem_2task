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

            /**
             * @brief Конструктор перемещения класса List.
             * @param other Объект для перемещения.
             */
            List(List&& other) noexcept;

            /**
             * @brief Оператор присваивания перемещением для класса List.
             * @param other Объект для перемещения.
             * @return Ссылка на текущий объект.
             */
            List& operator=(List&& other) noexcept;

            /**
             * @brief Конструктор копирования класса List.
             * @param other Объект для копирования.
             */
            List(const List& other);

            /**
             * @brief Оператор присваивания копированием для класса List.
             * @param other Объект для копирования.
             * @return Ссылка на текущий объект.
             */
            List& operator=(const List& other);

            /**
             * @brief Очищает список, удаляя все его элементы.
             */
            void clear();

            /**
             * @brief Возвращает строковое представление списка.
             * @return Строка, содержащая все элементы списка.
             */
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