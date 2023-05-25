#include "list.h"
#include <iostream>

miit::List::List()
{
    head = nullptr;
    tail = nullptr;
}

void miit::List::PushBack(const int data)
 {
     Node *node = new Node(data);

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
 		Node *temp = this->head->previous; // запоминаем указатель на предпоследний элемент
 		this->head->previous->next = node; // меняем указатель с головы на новый узел
 		node->previous = temp; // вставляем указатель на бывший предпоследний элемент, теперь этот элемент третий с конца
 		node->next = head; // новый узел указывает на голову
 		this->head->previous = node; // голова указывает на новый узел
 		head->data = data; // меняем data головы на новый data

 	}
 }

void miit::List::PushAhead(const int data)
{
    Node *node = new Node(data);

    if (this->IsEmpty())
	{
		this->head = node;
 		this->tail = node;
 		this->head->previous = this->tail;
 		this->tail->next = this->head;
	}
	else if (this->head == this->tail)
	{
		this->tail = node;
		this->tail->previous = nullptr;
		this->tail->next = this->head;
		this->head->previous = this->tail;
		this->head->next = nullptr;
	}
	else
	{
		node->data = tail->data;
		Node *temp = this->tail->next;
		this->tail->next->previous = node;
		node->next = temp;
		node->previous = tail;
		this->tail->next = node;
		tail->data = data;

	}
}

void miit::List::DeleteBack()
{
    if (this->IsEmpty())
	{
		throw std::out_of_range("The List is empty.");
	}
	else
	{
		Node *temp = this->head->previous;

		this->head->previous->previous->next = this->head;
		this->head->previous = temp->previous;
		this->head->data = temp->data;
		
		delete temp;
	}
}

void miit::List::DeleteAhead()
{
    if (this->IsEmpty())
	{
		throw std::out_of_range("The List is empty.");
	}
	else
	{
		Node *temp = this->tail->next;

		this->tail->next->next->previous = this->tail;
		this->tail->next = temp->next;
		this->tail->data = temp->data;
		delete temp;

	}
}

bool miit::List::IsEmpty()
{
    return (this->head == nullptr);
}


std::ostream &miit::operator<<(std::ostream &os, const List &list)
{
    Node *temp = list.tail;
    while (temp != list.head->next)
    {
        os << temp->data << " ";
        temp = temp->next;
    }
	delete temp;
    return os;
}

bool miit::List::operator==(const miit::List &list)
{
	Node *lha = list.tail;
	Node *rha = this->tail;
    while (lha != list.head->next)
    {
		if (rha->data != lha->data)
		{
			return false;
		}
        rha = rha->next;
		lha = lha->next;
    }
	delete(lha);
	delete(rha);
	return true;
}

bool miit::List::operator!=(const miit::List &list)
{
    return !(*this == list);
}
