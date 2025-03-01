#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot)
{
    if (head == NULL)
        return;
    Node *temp = head -> next;
    head -> next = NULL;
    if (head -> val <= pivot)
    {
        if (smaller == NULL)
            smaller = head;
        else
        {
            Node *end = smaller;
            while (end -> next != NULL)
                end = end -> next;
            end -> next = head;
        }
    }
	else
    {
        if (larger == NULL)
            larger = head;
	    else
	    {
	        Node *end = larger;
	        while (end -> next != NULL)
	            end = end -> next;
	        end -> next = head;
	    }
    }
    llpivot(temp, smaller, larger, pivot);
}
