#include "list.h"

#include <stdio.h>
#include <stdlib.h>

int main() {
    const char* data[][3] = {
        {"New York–No. NJ", "21199865", "19549649"},
        {"Los Angeles area", "16373445", "14531529"},
        {"Chicago area", "9157450", "8239820"},
        {"Washington–Baltimore", "7608708", "6727050"},
        {"San Francisco area", "7039362", "6253311"},
        {"Philadelphia–Atlantic City area", "6188463", "5892937"},
        {"Boston area", "5819100", "5455403"},
        {"Detroit area", "5456428", "5187171"},
        {"Dallas–Fort Worth", "5221801", "4350556"},
        {"Houston–Galveston area", "4669571", "3731131"},
        {"Atlanta area", "4112198", "2959950"},
        {"Miami–Fort Lauderdale", "3876380", "3192582"},
        {"Seattle area", "3554760", "2970328"},
        {"Phoenix area", "3251876", "2238480"},
        {"Minneapolis–St. Paul", "2694863", "2583643"},
        {"Cleveland area", "2945831", "2859644"},
        {"San Diego area", "2813833", "2498016"},
        {"St. Louis area", "2603067", "2492525"},
        {"Denver area", "2581504", "1980140"},
        {"San Juan, PR, area", "2450220", "2270840"}
    };

    MultiLinkedList* list = create_multi_linked_list();

    for (int i = 0; i < 20; i++) {
        insert_data(list, data[i][0], atoi(data[i][1]), atoi(data[i][2]));
    }

    print_list(list->head_2000, 2000);
    print_list(list->head_1990, 1990);

    free_multi_linked_list(list);

    return 0;
}

