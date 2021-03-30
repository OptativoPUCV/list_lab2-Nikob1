#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    const void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(const void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList(){
    List * lista;
    lista=(List*)malloc(sizeof(List));
     lista->head=NULL;
     lista->tail=NULL;
     lista->current=NULL;
     return lista;
}

void * firstList(List * list) {
  if(!list->head){
  return NULL;
}
  list->current=list->head;
    return (void*)list->head->data;
}

void * nextList(List * list) {
  if(!list->current||!list->current->next){
    return NULL;
  }
  list->current=list->current->next;
    return (void*)list->current->data;
}

void * lastList(List * list) {
  if(!list->tail){
    return NULL;
  }
  list->current=list->tail;
    return (void*)list->tail->data;
}

void * prevList(List * list) {
  if(!list->current||!list->current->prev){
    return NULL;
  }
  list->current=list->current->prev;
    return (void*)list->current->data;
}

void pushFront(List * list, const void * data) {
  
  Node* nodo;
  Node* aux;
  nodo=createNode(data);
  if(!list->head){
  list->head=nodo;
  list->tail=nodo;
  list->current=nodo;
  }else{
    aux=list->head;
    list->head=nodo;
    list->head->next=aux;
    aux->prev=list->head;
  }
}

void pushBack(List * list, const void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, const void * data) {
  Node* nodo;
  Node* aux;
  nodo=createNode(data);
  if(!list->current){
    return (void)NULL;
    }
    else{
      if(list->current->next==NULL){
        aux=nodo;
        aux->prev=list->current;
        list->current->next=aux;
        list->tail=aux;
      }else{
        aux=nodo;
        aux=list->current;
        list->current->next=nodo;
        nodo->prev=aux;
        aux->next->prev=nodo;
        nodo->next=aux->next;
      }

    }
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
  Node* aux;
  Node* aux1;
  aux1=list->current;
  if(!list->current){
  return NULL;
  }
  if(list->current->next==NULL){
    
    list->current=list->current->prev;
    list->current->next=NULL;
    list->tail=list->current;

  }
  if(list->current->prev==NULL){
   
    list->current=list->current->next;
    list->current->prev=NULL;
    list->head=list->current;

  }else{
    aux=list->current;
    aux->prev->next=aux->next;
    aux->next->prev=aux->prev;
    
  }
  

    return (void*)aux1->data;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}