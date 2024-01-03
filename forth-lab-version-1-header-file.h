#ifndef __singlyLinkedList__
#define __singlyLinkedList__

#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    char data;
    struct Node* next; // указатель на следующий элемент
} Node;

// объявление указателей
Node* head = NULL;
Node* current = NULL;
char input;

Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node)); // выделяем память под новый узел
    if (newNode != NULL) {
        newNode->data = data; 
        newNode->next = NULL; 
        return newNode;
    } else {
        printf("Ошибка выделения памяти\n");
        return NULL;
    }
}

void inputList(Node** head, Node** current) {
    while ((input = getchar()) != '\n') { // считываем каждый символ ввода до символа новой строки
        Node* newNode = createNode(input); // создаем новый узел
        if (*head == NULL) { // если список пуст
            *head = newNode;
            *current = newNode;
        } else {
            (*current)->next = newNode;
            *current = newNode;
        }
    }
}

void printList(Node* head) {
    printf("\n Содержимое списка: ");
    Node* current = head; // обходим список с помощью current
    while (current != NULL) {
        printf("%c", current->data);
        current = current->next;
    }
    printf("\n");
}

void clearList(Node** head, Node** current) {
    if (*head == NULL) {
        printf("\n Список уже пустой\n");
        return;
    } else {
        Node* temp = *head;
        Node* next;
        while (temp != NULL) {
            next = temp->next; // сохраняем указатель на следующий узел, чтобы при удалении его не потерять 
            free(temp);
            temp = next;
        }
        *head = NULL;
        *current = NULL; 
        printf("\n Список очистился \n");
    }
}

void isListEmpty(Node* head) {
    if (head == NULL) {
        printf("\n Список пуст\n");
    } else {
        printf("\n Список не пуст\n");
    }
}

void setPointerAtTheBeginning(Node** head, Node** current) {
    if (current != NULL) { // проверяем пустой список или нет
        *current = *head;
        printf("\n Рабочий указатель в начале списка\n");
    } else {
        printf("\n Список пустой\n");
    }
}

void printValueBehindPointer(Node* current) {
    if (current != NULL && current->next != NULL) { // проверяем существует ли узел за текущим узлом
        current = current->next;
        printf("\n Элемент за указателем на данный момент: ");
        printf("%c", current->data);
    } else {
        printf("\n Элемент за указателем показать нельзя: нечего показывать, т.к. за указателем ничего нет\n");
    }
}


void isPointerAtTheEnd(Node* current) {
    if (current != NULL) {
        if (current->next == NULL) {
            printf("\n Рабочий указатель находится в конце списка\n");
        } else {
            printf("\n Рабочий указатель не находится в конце списка\n");
        }
    } else {
        printf("\n Список пустой\n");
    }
}

void movePointerForward(Node** current) {
    if ((*current) != NULL && (*current)->next != NULL) {
        (*current) = (*current)->next; // передвигаем укзатель вперед
        printf("\n Рабочий указатель передвинули вперед \n");
    } else {
        printf("\n Рабочий указатель не передвинулся  \n");
    }
}

void deleteElementAfterPointer(Node** head, Node* current) {
    if (current != NULL) { // проверяем не пустой ли список
        if (current->next != NULL) { //проверяем  существует ли следующий узел
            Node* temp = current->next; 
            current->next = temp->next; 
            free(temp); 
            printf("\n Элемент за указателем удален \n");
        } else {
            printf("\n Ошибка: не можем удалить элемент за указателем, т.к. за указателем нет ничего\n");
        }
    } else {
        printf("\n Ошибка: список пуст\n");
    }
}

void getElementAfterPointer(Node* current, char* value) {
    if (current != NULL && current->next != NULL) { // проверяем существует ли узел за текущим узлом
        *value = current->next->data; // заносим значение в переменную
    } else {
        *value = '\0'; 
    }
}

void changeValueAfterPointer(Node* current) {
    if (current != NULL && current->next != NULL) { // проверяем существует ли узел за текущим узлом
        printf("\n Введите значение, на которое хотите заменить элемент: ");
        char newValue = getchar();
        getchar(); 
        current->next->data = newValue;
    } else {
        printf("\n Указатель находится в конце списка, замена невозможна.\n");
    }
}

void addElementAfterPointer(Node** current, Node** head) {
    printf("\nВведите значение, которое хотите добавить: ");
    char data = getchar();
    getchar(); 
    Node* newNode = createNode(data); //создаем новый узел для добавления элемента
    newNode->next = NULL; 

    if (*current == NULL) {
        *head = newNode; 
        *current = newNode; 
    } else {
        newNode->next = (*current)->next;
        (*current)->next = newNode;
        *current = newNode; 
    }
}


#endif