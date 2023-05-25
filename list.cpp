#include "list.h"
#include <iostream>

miit::List::List()
{
    head = nullptr;
    tail = nullptr;
}

void miit::List::PushBack(const int data)
{
    auto node = new Node(data);

    if (this->IsEmpty())
	{
		this->head = node;
		this->tail = node;
		this->head->previous = this->tail;
		this->tail->next = this->head;
	}
	else if (this->head == this->tail)
	{
		this->head = node;
		this->head->previous = this->tail;
		this->tail->next = this->head;
	}
	else
	{
		node->data = head->data; // data нового узла равен data текущей головы
		auto temp = this->head->previous; // запоминаем указатель на предпоследний элемент
		this->head->previous->next = node; // меняем указатель с головы на новый узел
		node->previous = temp; // вставляем указатель на бывший предпоследний элемент, теперь этот элемент третий с конца
		node->next = head; // новый узел указывает на голову
		this->head->previous = node; // голова указывает на новый узел
		head->data = data; // меняем data головы на новый data
	}
    
}

bool miit::List::IsEmpty()
{
    return (this->head == nullptr);
}

std::ostream &miit::operator<<(std::ostream &os, const List &list)
{
    auto temp = list.tail;
    while (temp != list.head->next)
    {
        os << temp->data << " ";
        temp = temp->next;
    }
    return os;
}
