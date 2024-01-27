// matthew shen and esha patel are prog partners!

/*
    Interquartile Range

    Given a sorted singly linked list without a tail (e.g, head -> 1 -> 2 -> 3 -> 4), 
    return the interquartile range of the data set using the slow and fast pointer 
    approach OR using a methodology that does not iterate over the linked list 
    twice. You must not iterate over the entire linked list more than once and you 
    cannot use arrays, vectors, lists or an STL implementation of List ADT in this problem.

    Sample Input:
        2 4 4 5 6 7 8
    
    Sample Output:
        3.00 
*/

#include <iostream>
#include <iomanip>

class Node {
    public:
        int value;
        Node* next = nullptr;
};

Node* insertEnd(Node* head, int key)
{
    Node* temp = new Node();
    temp->value = key;
    if(head == nullptr)
        head = temp;
    else
    {
        Node* curr = head;
        while(curr->next != nullptr)
            curr = curr->next;
        curr->next = temp;
    }
    return head;
}

float interQuartile(Node* head)
{
    Node* fast_ptr = head;
    Node* q1_ptr = head;
    Node* q3_ptr = head;

    int count = 0;
    while (fast_ptr != nullptr) {
        fast_ptr = fast_ptr->next;
        // Increment q1_ptr when count-1 is divisible by 4
        if (count > 3 && (count-1) % 4 == 0)
            q1_ptr = q1_ptr->next;
        // Increment q3_ptr when count+1 is not divisible by 4
        if (count > 0 && (count+1) % 4 != 0)
            q3_ptr = q3_ptr->next;
        count++;
    }

    // If half of the input size is odd, pointers are already at the correct position
    if ((count/2) % 2 != 0) {
        return q3_ptr->value - q1_ptr->value;
    }
    // Else, take average of pointer value and next pointer value
    else {
        float lower_q = (q1_ptr->value + q1_ptr->next->value) / 2.0;
        float upper_q = (q3_ptr->value + q3_ptr->next->value) / 2.0;
        return upper_q - lower_q;
    }
}
