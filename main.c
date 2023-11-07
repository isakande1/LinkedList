
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int item;
    struct Node *next;
};

struct List {
    struct Node *head;
    struct Node *tail;
};

struct List newssl(void) {
    struct List list;
    list.head = NULL;
    list.tail = NULL;
    return list;
}

int isempty(struct List *list) {
    return list->head == NULL;
}

void push(struct List *list, int item) {
    struct Node *node = malloc(sizeof(struct Node));
    node->item = item;
    node->next = list->head;
    if(isempty(list)) {
        list->tail = node;
    }
    list->head = node;
}

int pop(struct List *list) {
    struct Node *node = list->head;
    int item = node->item;
    list->head = node->next;
    if(isempty(list)) {
        list->tail = NULL;
    }
    free(node);
    return item;
}

void append(struct List *list, int item) {
    struct Node *node = malloc(sizeof(struct Node));
    node->item = item;
    node->next = NULL;
    if(!isempty(list)) {
        list->tail->next = node;
        list->tail = node;
    }else {
        node->next = list->head;
        list->head=node;
        list->tail = node;
    }
}

int lenght(struct List *list) {
    int i = 0;
    struct Node *node = list->head;
    for( ;node!=NULL; node = node->next) {
        i++;
    }
    return i;
}
 int contain(struct List *list, int item) {
    struct Node *node = list->head;
    for( ; node != NULL; node = node->next) {
        if(node->item == item) {
            return 1;
        }
    }
    return 0;
 }

 void clear(struct List *list) {
    while(!isempty(list)) {
        pop(list);
    }
 }

 void display(struct List *list) {
    struct Node *node = list->head;
    for( ; node!= NULL; node = node->next) {
       printf("%d\n",node->item);
    }
 }

int main(void){
    struct List list = newssl();
    push(&list,1);
    push(&list,5);
    push(&list,8);
    append(&list,10);
    printf("%d\n",pop(&list));
    printf("%d\n",lenght(&list));
   /* display(&list);*/
    return 0;
}

