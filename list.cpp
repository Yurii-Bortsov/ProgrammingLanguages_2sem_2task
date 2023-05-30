#include "list.h"
#include <iostream>
#include <sstream>


miit::List::List(Node* head, Node* tail):head(head), tail(tail){}

miit::List::~List()
{
	while (this->tail != this->head)
	{
		miit::List::DeleteAhead();
	}

	if (this->tail == this->head)
	{
		delete head;
		head = nullptr;
	}
}

void miit::List::PushBack(const int data)
 {
     Node *node = new Node(data);

     if (this->IsEmpty())
 	{
 		this->tail = node;
 		this->head = node;
 		this->tail->next = this->head;
 		this->head->previous = this->tail;
 	}
 	else if (this->tail == this->head)
 	{
 		this->tail = node;
 		this->tail->next = this->head;
 		this->head->previous = this->tail;
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

void miit::List::PushAhead(const int data)
{
    Node *node = new Node(data);

    if (this->IsEmpty())
	{
		this->tail = node;
 		this->head = node;
	}
	else if (this->tail == this->head)
	{
		this->head = node;
		this->head->previous = this->tail;
		this->tail->next = this->head;
	}
	else
	{
		node->data = head->data;
		Node *temp = this->head->previous;
		this->head->previous->next = node;
		node->previous = temp;
		node->next = head;
		this->head->previous = node;
		head->data = data;
	}
}

void miit::List::DeleteBack()
{
    Node* next = this->tail->next;

	if (next != nullptr)
	{
		next->previous = nullptr;
	}
	delete this->tail;
	this->tail = next;
}

void miit::List::DeleteAhead()
{
	Node* previous = this->head->previous;

	if (previous != nullptr)
	{
		previous->next = nullptr;
	}
	delete this->head;
	this->head = previous;
}

bool miit::List::IsEmpty()
{
    return (this->tail == nullptr);
}


std::ostream &miit::operator<<(std::ostream &os, const List &list)
{
    Node *temp = list.head;
    while (temp != list.tail->previous)
    {
        os << temp->data << " ";
        temp = temp->previous;
    }
    return os;
}
bool miit::List::operator== (miit::List& list)
{
	return (this->toString() == list.toString());
}

std::string miit::List::toString()
{
	std::stringstream buffer;
	buffer << *this;
    return buffer.str();
}

bool miit::List::operator!=(miit::List list)
{
    return !(*this == list);
}