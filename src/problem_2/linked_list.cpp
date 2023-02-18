#include "linked_list.h"

template<class T>
void LinkedList<T>::push_front(const T &value) {
    /*
     * TODO: homework
     */

    ListNode<T>* newNode = new ListNode<T>(value);
    newNode->next = head->next;
    head->next = newNode;
    num_of_element++;
}

template<class T>
void LinkedList<T>::push_back(const T &value) {
    /*
     * TODO: homework
     */
    ListNode<T> *new_node = new ListNode<T>(value);
    ListNode<T> *current = head;

    while (current->next != nullptr) {
        current = current->next;
    }

    current->next = new_node;
    num_of_element++;

}

template<class T>
void LinkedList<T>::pop_back() {
    /*
     * TODO: homework
     */
    if (num_of_element == 0) {
        std::cout << "Can't pop from empty list! \n";
        return;
    }

    ListNode<T> *current = head;
    while (current->next->next != nullptr) {
        current = current->next;
    }
    delete current->next;
    current->next = nullptr;
    num_of_element--;

}

template<class T>
void LinkedList<T>::pop_front() {
    /*
     * TODO: homework
     */
    if (head->next == nullptr) {
        std::cout << "The list is already empty" << std::endl;
        return;
    }

    ListNode<T> *temp = head->next;
    head->next = temp->next;
    delete temp;

    num_of_element--;
}


template<class T>
void LinkedList<T>::remove(T &valu) {
    /*
     * TODO: homework
     */
    ListNode<T>* currNode = head->next;
    ListNode<T>* prevNode = head;

    while (currNode != nullptr) {
        if (currNode->val == valu) {
            prevNode->next = currNode->next;
            delete currNode;
            currNode = prevNode->next;
            num_of_element--;
        }
        else {
            prevNode = currNode;
            currNode = currNode->next;
        }
    }
}

/*
 * merge in ascending order
 */
template<class T>
void LinkedList<T>::merge(const List<T> &ot) {
    /*
     * TODO: homework
     */
    /**
     * Sorry the program would terminate if this was uncommented so I commented it
     *
    const LinkedList<T>* ot_list = dynamic_cast<const LinkedList<T>*>(&ot);

    ListNode<T>* curr1 = head->next;
    ListNode<T>* curr2 = ot_list->head->next;
    ListNode<T>* prev = head;
    while (curr1 != nullptr && curr2 != nullptr) {
        if (curr1->val < curr2->val) {
            prev = curr1;
            curr1 = curr1->next;
        } else {
            ListNode<T>* next = curr2->next;
            prev->next = curr2;
            curr2->next = curr1;
            prev = curr2;
            curr2 = next;
        }
    }
    if (curr2 != nullptr) {
        prev->next = curr2;
    }
    num_of_element += ot_list->size();
     **/
}

template<class T>
void LinkedList<T>::reverse_iterative() {
    /*
     * TODO: homework
     */



}