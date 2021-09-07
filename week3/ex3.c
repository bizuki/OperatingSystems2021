#include <stdio.h>
#include <stdlib.h>

struct linked_list {
    struct node {
        struct node *next;
        int value;
    };

    struct node *head;
};

struct linked_list create_list() {
    struct linked_list list;
    list.head = NULL;
    return list;
}

struct node create_node(int value) {
    struct node node;
    node.value = value;
    node.next = NULL;
    return node;
}


void check_list(struct linked_list* list) {
    if(list == NULL) {
        printf("List can't be NULL. Shutting down\n"); // i think that is not fixable error
        exit(0);
    }
}

// to insert after some node
struct node* insert_node(struct linked_list* list, struct node* after_which, struct node new_node) {
    check_list(list);
    if (after_which == NULL) {
        printf("Node after which new node will be inserted can't be NULL. Shutting down\n"); // i think that is not fixable error
        exit(0);
    }

    struct node* current_node = list->head;
    while (current_node != NULL && current_node != after_which) {
        current_node = current_node->next;
    }

    if (current_node == NULL) {
        printf("List is not contain such node. Shutting down\n"); // i think that is not fixable error
        exit(0);
    }
    
    struct node *next_node = current_node->next;

    struct node* new_node_ptr = (struct node*) malloc(sizeof(struct node));
    *new_node_ptr = new_node;
    current_node->next = new_node_ptr;
    new_node_ptr->next = next_node;
    return new_node_ptr;
}

// to make a new head
struct node* insert_head(struct linked_list* list, struct node new_node) {
    check_list(list);
    struct node* current_head = list->head;
    struct node* new_head = (struct node*) malloc(sizeof(struct node));
    *new_head = new_node;

    new_head->next = current_head;
    list->head = new_head;
    return new_head;
}

void print_list(struct linked_list* list) {
    check_list(list);
    struct node* current_node = list->head;
    while (current_node != NULL) {
        printf("%d ", current_node->value);
        current_node = current_node->next;
    }
    printf("\n");
}

void delete_node(struct linked_list* list, struct node* deleted_node) {
    check_list(list);
    if (deleted_node == NULL) {
        printf("Deleted node can't be NULL. Shutting down\n"); // i think that is not fixable error
        exit(0);
    }

    if (deleted_node == list->head) { // delete head
        struct node *old_head = list->head;
        list->head = list->head->next;
        free(old_head);
        return;
    } 


    struct node* current_node = list->head;
    struct node* previous_node = NULL;

    while (current_node != NULL && deleted_node != current_node) {
        previous_node = current_node;
        current_node = current_node->next;
    }

    if (current_node == NULL) {
        printf("List is not contain such node. Shutting down\n"); // i think that is not fixable error
        exit(0);
    }

    previous_node->next = current_node->next;
    free(current_node);
}

void free_list(struct linked_list* list) {
    struct node *current_node = list->head;
    while (current_node != NULL) {
        struct node *next_node = current_node->next;
        free(current_node);
        current_node = next_node;
    }
    list->head = NULL;
}


int main() {
    struct linked_list list = create_list();
    printf("Empty list:\n");
    print_list(&list);

    struct node* head = insert_head(&list, create_node(2));

    printf("List with only head:\n");
    print_list(&list);

    struct node* node = insert_node(&list, head, create_node(4));

    printf("List with 2 nodes:\n");
    print_list(&list);

    insert_node(&list, head, create_node(1));

    printf("List with node inserted after head linked with next node:\n");
    print_list(&list);

    node = insert_node(&list, node, create_node(5));

    printf("List with node inserted after last node:\n");
    print_list(&list);

    delete_node(&list, head);

    printf("List after deletion of head:\n");
    print_list(&list);

    head = insert_head(&list, create_node(9));

    delete_node(&list, head->next);

    printf("List after inserting new head and deleting 1:\n");
    print_list(&list);

    free_list(&list);

    printf("List after free_list:\n");
    print_list(&list);

}