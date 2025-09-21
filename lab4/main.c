#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


typedef enum {
    English,
    Ukrainian,
} Language;

typedef struct {
    char title[100];
    float price;
    unsigned int pages;
    Language lang;
    float weight;
    int year;
} Data;

typedef struct {
    Data data;
    struct Node* next;
} Node;

Data new_data(char title[100], float price, unsigned int pages, Language lang, float weight, int year) {
    Data data = {
        title,
        price,
        pages,
        lang,
        weight,
        year
    };

    return data;
}

Node* new(Data data) {
    Node* node = malloc(sizeof(Node));
    Node* next = malloc(sizeof(Node));
    node->data = data;
    return node;
}

Node* clean(Node* node) {
    Node* next = node->next;
    free(node);
    if (next) {
        clean(next);
    }
}

Node* add(Node* node, Data data) {
    Node* next = malloc(sizeof(Node));
    next->data = data;
    node->next = next;
    return next;
}

void print_data(Data data) {
    printf("Title: %s\nPrice: %f\nPages: %d\nLanguage: %s\nWeight: %f\nYear: %d\n\n", data.title, data.price, data.pages, (data.lang == English) ? "English" : "Ukrainian", data.weight, data.year);
}

void print_node(Node* node) {
    print_data(node->data);
    Node* next = node->next;
    if (next) {
        print_node(next);
    }
}

int main() {
    Data data1 = {
        "Harry Potter and the Philosopher’s Stone",
        460,
        352,
        English,
        287,
        2014
    };

    Data data2 = {
        "Harry Potter and the Chamber of Secrets",
        424,
        384,
        Ukrainian,
        200,
        2014
    };

    Data data3 = {
        "Harry Potter and the Prisoner of Azkaban",
        395,
        480,
        English,
        385,
        2014
    };

    Node* list = new(data1);
    add(add(list, data2), data3);
    print_node(list);
    clean(list);
    return 0;
}