#ifndef STACK_HPP_INCLUDED
#define STACK_HPP_INCLUDED

#include <iostream>

using namespace std;

template <class T>
struct Node
{
    T data;
    Node *next;
};

template <class T>
void defaultPrint(Node<T> *data)
{
    cout << data << endl;
};

template <class T, class Q>
bool defaultSearchCriteria(Node<T> *node, Q elem)
{
    if (node->data == elem)
        return node->data;
};

template <class T>
class List
{
public:
    Node<T> *list = nullptr;
    T pop()
    {
        T data = list->data;
        Node<T> *aux_del = list;
        list = list->next;
        delete aux_del;
        return data;
    }

    void print(void (*_print)(Node<T> *) = defaultPrint)
    {
        Node<T> *aux = list;
        while (aux != nullptr)
        {
            _print(aux);
            aux = aux->next;
        };
    };

    // Use it for freeing up memory
    void empty()
    {
        while (list != nullptr)
            pop();
    };

    template <class Q>
    Node<T> *search(Q elem, bool (*_criteria)(Node<T> *, Q) = defaultSearchCriteria)
    {
        Node<T> *aux = list;
        bool found = false;
        while (aux != nullptr)
        {
            bool _found = _criteria(aux, elem);
            if (_found)
            {
                found = true;
                break;
            }
            aux = aux->next;
        };
        return found ? aux : nullptr;
    };

    // Removes all the elements that match a criteria
    template <class Q>
    void remove_all(Q elem, bool (*_criteria)(Node<T> *, Q) = defaultSearchCriteria)
    {
        if (this->list == nullptr)
            return;

        while (_criteria(this->list, elem))
        {
            T data = this->list->data;
            Node<T> *aux_del = this->list;
            this->list = this->list->next;
            delete aux_del;
        };

        Node<T> *aux = this->list;

        while (aux->next != nullptr)
        {
            bool hasExtracted = false;
            if (_criteria(aux->next, elem))
            {
                Node<T> *aux_del = aux->next;
                aux->next = aux->next->next;
                delete aux_del;
                hasExtracted = true;
            };
            if (hasExtracted)
                continue;
            aux = aux->next;
        };
    };

    // Removes the next node from the received node as a param
    void remove_next(Node<T> *node)
    {
        if (node->next != nullptr)
        {
            Node<T> *aux_del = node->next;
            node->next = node->next->next;
            delete aux_del;
        };
    };

    void duplicateLastValue()
    {
        Node<T> *duplicate = new Node<T>;
        duplicate->data = list->data;
        duplicate->next = list;
        list = duplicate;
    };

    void swap(int pos)
    {
        if (stack->next != nullptr)
        {
            T current = stack->data;
            T next = stack->next->data;
            stack->data = next;
            stack->next->data = current;
        };
    };

    /** The next utils fns only work if T is a primitive type
     * Works if T is a primitive type
     */

    T get_max()
    {
        Node<T> *_list = list;
        int max = 0;
        bool isMaxInit = false;
        while (_list != nullptr)
        {
            if (!isMaxInit)
            {
                max = _list->data;
                isMaxInit = true;
            }
            if (_list->data > max)
                max = _list->data;
            _list = _list->next;
        };

        return max;
    };

    float getAverage()
    {
        Node<int> *_list = list;
        float count = 0;
        float sum = 0;
        while (_list != nullptr)
        {
            count++;
            sum += _list->data;
            _list = _list->next;
        }

        return sum / count;
    };
};

template <class T>
class Stack : public List<T>
{
public:
    void push(T value)
    {
        Node<T> *new_node = new Node<T>;
        new_node->data = value;
        new_node->next = this->list;
        this->list = new_node;
    };
    void bulkPush(T values[], int dim)
    {
        for (int i = 0; i < dim; i++)
        {
            push(values[i]);
        };
    };
};

/**
 * The difference between a queue and a stack is that in the first one elements are pushed at the bottom, while in the stack the elements are push on top.
 */
template <class T>
class Queue : public List<T>
{
public:
    void push(T value)
    {
        Node<T> *new_queue = new Node<T>;
        new_queue->data = value;
        new_queue->next = nullptr;

        if (this->list == nullptr)
            this->list = new_queue;
        else
        {
            Node<T> *aux = this->list;
            while (aux->next != nullptr)
                aux = aux->next;
            aux->next = new_queue;
        };
    };
    void bulkPush(T values[], int dim)
    {
        for (int i = 0; i < dim; i++)
        {
            push(values[i]);
        };
    };
};

/** This is the default criteria used in the ordered lists.
 * It sorts from larger to smaller
 */
template <class T>
bool defaultCriteria(T value_1, T value_2)
{
    return value_1 >= value_2 ? true : false;
};

template <class T>
class OrderedList : public List<T>
{
private:
    bool (*criteria)(T, T);

public:
    OrderedList(bool (*_criteria)(T, T) = defaultCriteria)
    {
        criteria = _criteria;
    };
    void push(T value)
    {
        Node<T> *new_value = new Node<T>;
        new_value->data = value;

        // When the list has no value
        if (this->list == nullptr)
        {
            this->list = new_value;
            return;
        };

        // Compares with the first element
        if (criteria(value, this->list->data))
        {
            new_value->next = this->list;
            this->list = new_value;
            return;
        };

        Node<T> *aux = this->list;
        bool hasInserted = false;
        // Compares with the rest of the elements
        while (aux->next != nullptr)
        {
            if (criteria(value, aux->next->data))
            {
                new_value->next = aux->next;
                aux->next = new_value;
                hasInserted = true;
                return;
            };
            aux = aux->next;
        };
        // If it didn't meet criteria, it gets pushed on the bottom.
        if (!hasInserted)
            aux->next = new_value;
    };
    void bulkPush(T values[], int dim)
    {
        for (int i = 0; i < dim; i++)
        {
            push(values[i]);
        };
    };
    void extract(bool (*_criteria)(T))
    {
        if (this->list == nullptr)
            return;

        if (_criteria(this->list->data))
        {
            T data = this->list->data;
            Node<T> *aux_del = this->list;
            this->list = this->list->next;
            delete aux_del;
        };

        Node<T> *aux = this->list;
        while (aux->next != nullptr)
        {
            bool hasExtracted = false;
            if (_criteria(aux->next->data))
            {
                Node<T> *aux_del = aux->next;
                aux->next = aux->next->next;
                delete aux_del;
                hasExtracted = true;
            };
            if (hasExtracted)
                continue;
            aux = aux->next;
        };
    };
};

#endif
