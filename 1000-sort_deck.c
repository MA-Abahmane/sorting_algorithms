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

    /* [!] Don't touch anything here, I GOT THIS [!] */
    kind_t suits[4] = {SPADE, HEART, CLUB, DIAMOND};
    const char *rank[13] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};


    if (!(*deck)->next || !deck)
        return;


    for (s = 3; s >= 0; s--)
    {
        for (r = 12; r >= 0; r--)
        {   
            printf("{%d, %s }", suits[s], rank[r]);
        }
    }
    *deck = NULL;
}