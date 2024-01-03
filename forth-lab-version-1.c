// Дан текст. Группы символов, разделенные пробелами (одним или несколькими) и не содержащие пробелов внутри себя, 
// будем называть словами. Найти количество слов, начинающихся с буквы "t"

// 1 вариант. Сделать библиотеку для пошаговой обработки односвязного списка (2 вариант - двусвязный)

// какие действия должны быть в библиотеке
// 1) начать работу со списком --- ввести список
// 2) сделать список пустым --- очистить список
// 3) проверка - список пуст или нет
// 4) установить рабочий указатель в начало списка
// 5) проверка - рабочий указатель в конце списка?
// 6) передвинуть рабочий указатель списка вперед
// 7) показать значение элемента списка за указателем
// 8) удалить элемент списка за указателем
// 9) взять элемент списка за указателем
// 10) изменить значение элемента списка за указателем
// 11) добавить элемент за указателем
// 12) распечатать структуру данных
// 13) закончить работу со списком

#include <stdio.h>
#include <stdlib.h>
#include "singlyLinkedList-test.h"

int main() {

    int mainChoice;
    int choice;
    Node* head = NULL;
    Node* current = NULL;

    do {
        printf("\n\tГлавное меню:\n");
        printf("1. Начать работу со списком\n");
        printf("0. Выход из программы\n");
        printf("\n Выберите опцию: ");
        scanf("%d", &mainChoice);
        getchar();

        switch (mainChoice) {
            case 1:
                {
                    do {
                        printf("\n\tМеню операций со списком:\n");
                        printf("1. Ввести список\n");
                        printf("2. Очистить список\n");
                        printf("3. Проверка: список пуст или нет?\n");
                        printf("4. Установить рабочий указатель в начало списка\n");
                        printf("5. Проверка: рабочий указатель в конце списка?\n");
                        printf("6. Передвинуть рабочий указатель списка вперед\n");
                        printf("7. Показать значение элемента списка за указателем\n");
                        printf("8. Удалить элемент списка за указателем\n");
                        printf("9. Взять элемент списка за указателем\n");
                        printf("10. Изменить значение элемента списка за указателем\n");
                        printf("11. Добавить элемент за указателем\n");
                        printf("12. Распечатать структуру данных\n");
                        printf("0. Вернуться в главное меню\n");
                        printf("\n Выберите опцию: ");
                        scanf("%d", &choice);
                        getchar();

                        switch (choice) {
                            case 1:
                                {
                                    printf("\n Введите элементы для списка: ");
                                    inputList(&head, &current);
                                    printList(head);
                                }
                                break;
                            case 2:
                                {
                                    clearList(&head, &current);
                                    printList(head);
                                }
                                break;
                            case 3:
                                {
                                    isListEmpty(head);
                                    printList(head);
                                }
                                break;
                            case 4:
                                {
                                    setPointerAtTheBeginning(&head, &current);
                                    printValueBehindPointer(current);
                                    printList(head);
                                }
                                break;
                            case 5:
                                {
                                    isPointerAtTheEnd(current);
                                    printValueBehindPointer(current);
                                    printList(head);
                                }
                                break;
                            case 6:
                                {
                                    printValueBehindPointer(current);
                                    movePointerForward(&current);
                                    printValueBehindPointer(current);
                                    printList(head);
                                }
                                break;
                            case 7:
                                {
                                    printValueBehindPointer(current);
                                    printList(head);
                                }
                                break;
                            case 8:
                                {
                                    deleteElementAfterPointer(&head, current);
                                    printValueBehindPointer(current);
                                    printList(head);
                                }
                                break;
                            case 9:
                                {
                                    char value;
                                    getElementAfterPointer(current, &value);
                                    if (value != '\0') {
                                        printf("\n Значение элемента списка за указателем: %c\n", value);
                                    } else {
                                        printf("\n Нет значения элемента списка за указателем %c\n", value);
                                    }
                                    printValueBehindPointer(current);
                                    printList(head);
                                }
                                break;
                            case 10:
                                {
                                    changeValueAfterPointer(current);
                                    printList(head);
                                }
                                break;
                            case 11:
                                {
                                    addElementAfterPointer(&current, &head);
                                    printList(head);
                                }
                                break;
                            case 12:
                                printList(head);
                                break;
                            case 0:
                                clearList(&head, &current);
                                printf("\n Работа со списком закончена. Возвращение в главное меню. \n");
                                break;
                            default:
                                printf("\n Неверная опция, выберите другую\n");
                        }
                    } while (choice != 0);
                }
                break;
            case 0:
                printf("\n Завершение программы\n");
                break;
            default:
                printf("\n Неверная опция, выберите другую\n");
        }
    } while (mainChoice != 0);

    return 0;
}