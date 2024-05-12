// Copyright 2021 NNTU-CS
#include "train.h"
Train::Train() : countOp(0), first(nullptr) {}

void Train::addCage(bool light) {
    if (first != nullptr) {
        Cage* next = first->next;
        first->next = new Cage;
        first->next->prev = first;
        first = first->next;
        next->prev = first;
        first->next = next;
        first->light = light;
    } else {
        first = new Cage;
        first->light = light;
        first->prev = first;
        first->next = first;
    }
}

int Train::getLength() {
    int length = 0;
    Cage* currentWagon = first;

    if (!currentWagon->light) {
        currentWagon->light = true;
    }

    while (currentWagon->next != first) {
        currentWagon = currentWagon->next;
        countOp++;
        length++;
    }

    if (!currentWagon->light) {
        currentWagon->light = true;
        length++;
    }

    return length;
}

int Train::getOpCount() {
    return countOp;
}
