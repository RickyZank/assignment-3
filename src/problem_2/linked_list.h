#ifndef LINKED_LIST
#define LINKED_LIST

#include "list.h"
#include <stdexcept>

template<class T>
class LinkedList;

template<class T>
class ListNode {
    friend class LinkedList<T>;
private:
    T val;
    ListNode *next;
public:
    ListNode() : next(nullptr) {}
    ListNode(T val) : val(val), next(nullptr) {}
};

template<class T>
class LinkedList : public List<T> {
private:
    ListNode<T> *head;  // this implementation has a dummy head (sentry head node)
    size_t num_of_element;

public:
    LinkedList() {
        head = new ListNode<T>();
        num_of_element = 0;
    }

    LinkedList(size_t capacity) : LinkedList<T>() {} // to make test consistent

    // copy constructor
    LinkedList(const LinkedList<T> &other_list) : LinkedList() {
        /*
         * TODO: homework
         */

        ListNode<T>* otherCurrent = other_list.head->next;
        ListNode<T>* current = head;

        while (otherCurrent != nullptr) {
            current->next = new ListNode<T>(otherCurrent->val);
            current = current->next;
            otherCurrent = otherCurrent->next;
            num_of_element++;
        }

        /**
        ListNode<T>* rptr = other_list.head;
        ListNode<T>* ptr = new ListNode<T>;
        ptr->val = rptr->val;
        head = ptr;
        for ( ListNode<T>* rptr = rptr->next; rptr != NULL; rptr = rptr->next ) {
            ptr->next = new ListNode<T>;
            ptr->next->val = rptr->val;
            ptr = ptr->next;
        }
         **/

        /**
        ListNode<T>* current = head;

        // traverse the other list and copy each node
        ListNode<T>* otherCurrent = other_list.head;
        while (otherCurrent->next != nullptr) {
            otherCurrent = otherCurrent->next;
            current->next = new ListNode(otherCurrent->val);
            current = current->next;
        }

        // remove the dummy head node
        ListNode<T>* temp = head;
        head = head->next;
        delete temp;
        **/

    }

    // destructor
    virtual ~LinkedList() {
        ListNode<T> *p0 = head, *p1 = head->next;
        if (p1 == nullptr) {
            delete p0;
            return;
        }

        while (p1 != nullptr) {
            delete p0;
            p0 = p1;
            p1 = p1->next;
        }
        delete p0;
    }

    size_t capacity() const override {
        return num_of_element;
    }

    size_t size() const override {
        return num_of_element;
    }

    T &operator[](size_t index) {
        if (index >= num_of_element) {
            throw std::out_of_range("index out of range");
        }
        ListNode<T> *p = head;
        for (size_t i = 0; i < index; i++) {
            p = p->next;
        }
        return p->next->val;
    }

    bool operator==(const LinkedList<T> &other_list) {
        if (num_of_element != other_list.num_of_element) {
            return false;
        }

        ListNode<T> *p1 = head->next;
        ListNode<T> *p2 = other_list.head->next;
        for (size_t i = 0; i < num_of_element; i++) {
            if (p1 == nullptr || p2 == nullptr) {
                return false;
            }

            if (p1->val != p2->val) {
                return false;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        return true;
    }

    void push_front(const T &value) override;

    void push_back(const T &value) override;

    void pop_back() override;

    void pop_front() override;

    void remove(T &val) override;

    void merge(const List<T> &other) override;

    void reverse_iterative() override;
};

#include "linked_list.cpp"

#endif