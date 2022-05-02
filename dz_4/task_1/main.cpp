#include <iostream>
#include "list.h"

using namespace std;

int main() {
    elem* list = nullptr;

    add_ind(list, 5);
    add_ind(list, 2);
    add_ind(list, 3);
    add_ind(list, 8);

    insert_ind(list, 0, 0);
    insert_ind(list, 0, 5);
    insert_ind(list, 2, 8);

    show_list(list);
}
