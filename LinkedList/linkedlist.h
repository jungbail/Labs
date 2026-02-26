#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    int num_wins;
    int year;
    struct node *next; // notice this pointer!
} Pair;

typedef struct list
{
    Pair *head;
    int size;
} NeuList;

Pair *new_node(int wins, int year, Pair *next)
{

    Pair *newNode = (Pair *)malloc(sizeof(Pair));
    newNode->num_wins = wins;
    newNode->year = year;
    newNode->next = next;
    return newNode;
}

NeuList* create_list() {
    NeuList *list = (NeuList *)malloc(sizeof(NeuList));
    list->head = NULL;
    list->size = 0;
    return list;
}

void push_front(NeuList *list, int wins, int year)
{
    Pair *newNode = new_node(wins, year, list->head);
    list->head = newNode;
    list->size++;
}

void add_back(NeuList *list, int wins, int year) {
    Pair *newNode = new_node(wins, year, NULL);
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Pair *curr = list->head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
    list->size++;
}

void print_list(NeuList *list)
{
    Pair *current = list->head;
    while(current != NULL){
        if(current->next != NULL){
        printf("(%d, %d) -> ", current->num_wins, current->year);
        }
        else{
            printf("(%d, %d)\n", current->num_wins, current->year);
        }
        current = current->next;
    }
}

Pair *find(NeuList *list, int year)
{
    Pair* current = list->head;
    while(current != NULL){
        if(current->year == year){
            return current;
        }
        current = current->next;
    }
    return NULL; // Not find.
}


void free_list(NeuList *list)
{
    Pair* current = list->head;
    while(current != NULL){
            Pair* nextNode = current->next;
            free(current);
            current = nextNode;
    }
    free(list);
}

void isEmpty(NeuList *list){
    return list->size == 0;
}


void findNode(NeuList *list, size_t index){
    if(index >= list->size) return NULL;
    int count = 0;
    Pair* curr = list->head;
    while(count != index){
        curr = curr->next;
        count++;
    }
    return curr;
}

void insert_element(NeuList *list, size_t index, int win, int year){
    if(list == NULL ||index > list->size){
        return;
    }
    
    Pair* new_node = new_node(win, year, list->head);

    if(index == 0){
        new_node->next = list->head;
        list->head = new_node;
    } else {
        Pair* prev = findNode(NeuList *list, size_t index); 
        if(prev != NULL){
            new_node -> next = prev -> next;
            prev -> next = new_node;
        }else{
            free(new_node);
            return;
        }
    } 
    list -> size++;
}

void remove_element(NeuList *list, size_t index){
    if(index == 0){
        Pair* save  = list->head;
        list->head = save->next;
        free(save);
    }
    Pair* pre = findNode(list, index - 1);
    Pair* cur = pre->next;
    pre->next = cur->next;
    free(cur);
    list->size--;
}

#endif //LINKED_LIST_H
}

#endif //LINKED_LIST_H