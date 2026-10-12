#include<stdio.h>
#include<windows.h>
#include<stdlib.h>

// Node Definition
struct Node{
    int data;
    struct Node *next;
};

// Type definition
typedef struct Node Node;


//Funtion to reverse a singly linked list.
Node* Reverse(Node* head){
    Node* prev = NULL;
    Node* current = head;
    Node* Next = NULL;

    if(current == NULL){
        printf("No node exist in linked list.\n");
        return head;
    }

    while(current != NULL){
        Next = current->next;
        current->next = prev;
        prev = current;
        current = Next;
    }

    return prev;
}


// Function to traverse the list.
void Traverse(Node *head){
    Node *current = head;
    while( current != NULL){
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to check if a list is palindrome or not.
int checkPalindrome(Node *head){
    Node *slow = head;
    Node *fast = head;

    // Movinf forward the slow and fast pointer
    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reversersing the half list from middle.
    Node *halfReverse = Reverse(slow->next);

    Node *p1 = head;
    Node *p2 = halfReverse;

    // Matching the data
    while(p2 != NULL){
        if(p1->data != p2->data) return 0;
        p1 = p1->next;
        p2 = p2->next;
    }

    // Restoring the list back into original form after checking.
    slow->next = Reverse(halfReverse);
    return 1;

}

// Function to build a list from an array.
Node* BuildList(int arr[], int length){
    Node *current = NULL;
    Node* head = NULL;
    for(int i = 0; i < length; i++){
        Node *newNode = (Node*)malloc(sizeof(Node));
        newNode->data = arr[i];
        newNode->next = NULL;
        if(i == 0) {
            current = newNode;
            head = current;
        }
        current->next = newNode;
        current = newNode;
    }

    return head;
}

int main(){
    int list[] = {1,2,3,4,5,4,3,2,1};
    int length = sizeof(list)/sizeof(list[0]);

    Node *head = BuildList(list, length);
    Traverse(head);

    if(checkPalindrome(head)){
        printf("The linked list is palindrome.");
    }
    else{
        printf("The linked list is not palindrome!");
    }

    // Free the memory
    Node *current = head;
    while (current != NULL)    {
        Node *next = current->next;
        free(current);
        current = next;
    }
   
return 0;
}