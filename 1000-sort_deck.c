#include "deck.h"


/**
 * sort_deck - sorts a DLL of integers in
 * ascending order using the insertion sort
 * algorithm
 *
 * @deck: deck to sort
 * Return: no return
 */
void sort_deck(deck_node_t **deck)
{   
    int s, r;
    char kinds[4] = {'S', 'H', 'C', 'D'};

    kind_t suits[4] = {SPADE, HEART, CLUB, DIAMOND};
    const char *rank[13] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};


    if (!(*deck)->next || !deck)
        return;


    for (s = 0; s < 4; s++)
    {
        for (r = 0; r < 13; r++)
        {   
            if (r)
                printf(", ");
            printf("{%s, %c}", rank[r], kinds[suits[s]]);
        }
        if ( s < 3)
            printf("\n");
    }
    *deck = NULL;
}
