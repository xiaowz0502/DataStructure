// Project UID 1d9f47bfc76643019cfbf037641defe1


#include "Card.h"
#include <array>
#include <string>
#include "Pack.h"

using namespace std;
// EFFECTS: Initializes the Pack to be in the following standard order:
//          the cards of the lowest suit arranged from lowest rank to
//          highest rank, followed by the cards of the next lowest suit
//          in order from lowest to highest rank, and so on.
// NOTE: The standard order is the same as that in pack.in.
// NOTE: Do NOT use pack.in in your implementation of this function
Pack::Pack(){
    int index = 0;
    for(int i = 0; i < 4; i++){
        for(int j = 7; j < 13; j++){
            cards[index] = Card(RANK_NAMES_BY_WEIGHT[j],SUIT_NAMES_BY_WEIGHT[i]);
            index++;
        }
    }
    next = 0;
}

// REQUIRES: pack_input contains a representation of a Pack in the
//           format required by the project specification
// MODIFIES: pack_input
// EFFECTS: Initializes Pack by reading from pack_input.
Pack::Pack(std::istream& pack_input){
    string of[24];
    string rank[24];
    string suit[24];
    for(int i = 0; i < 24; i++){
        pack_input >> rank[i] >> of[i] >> suit[i];
        cards[i] = Card(rank[i],suit[i]);
    }
    next = 0;
}

// REQUIRES: cards remain in the Pack
// EFFECTS: Returns the next card in the pack and increments the next index
Card Pack::deal_one(){
    Card c = cards[next];
    next++;
    return c;
}

// EFFECTS: Resets next index to first card in the Pack
void Pack::reset(){
    next = 0;
}

// EFFECTS: Shuffles the Pack and resets the next index. This
//          performs an in shuffle seven times. See
//          https://en.wikipedia.org/wiki/In_shuffle.
void Pack::shuffle(){
    int n = 0;
    Card order[PACK_SIZE];
    while(n<7){
        
        for(int i = 0; i < 12; i++){
            order[2 * i + 1] = cards[i];
        }
        int index = 0;
        for(int i = 12; i < 24; i++){
            order[index] = cards[i];
            index+=2;
        }
        for(int i = 0; i < 24; i++){
            cards[i] = order[i];
        }
        
        n++;
    }
    next = 0;
}

// EFFECTS: returns true if there are no more cards left in the pack
bool Pack::empty() const{
    return (next>23);
}

