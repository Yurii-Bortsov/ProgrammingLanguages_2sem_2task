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
            List();
            void PushBack(const int data);
            void PushAhead(const int data);
            void DeleteBack();
            void DeleteAhead();
            bool IsEmpty();
            
            /**
             * @brief Оператор вывода объекта List в поток.
             * @param os Поток вывода.
             * @param list Объект типа List, который нужно вывести.
             * @return Поток вывода.
            */
            friend std::ostream& operator << (std::ostream& os, const List& list);
    
            bool operator == (const miit::List& list);
            bool operator != (const miit::List& list);
    };
}