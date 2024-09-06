#include <stdio.h>
#include <stdlib.h>

// Définition de la structure de la liste chaînée
struct Node {
    int data;
    struct Node* next;
};

// Fonction récursive pour trouver l'élément maximal
int findMaxRecursive(struct Node* head) {
    if (head == NULL) {
        return -1; // Assumant que tous les éléments sont positifs
    }
    
    int max = head->data;
    int max_in_rest = findMaxRecursive(head->next);
    
    return (max > max_in_rest) ? max : max_in_rest;
}

// Fonction pour ajouter un nouvel élément à la liste
void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// Fonction principale pour tester l'algorithme
int main() {
    struct Node* head = NULL;
    
    push(&head, 10);
    push(&head, 20);
    push(&head, 30);
    push(&head, 40);
    
    printf("Maximum value in the list is %d\n", findMaxRecursive(head));
    
    return 0;
}
