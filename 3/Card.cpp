// Project UID 1d9f47bfc76643019cfbf037641defe1

#include <cassert>
#include <iostream>
#include <string>
#include "Card.h"
using namespace std;
// add any necessary #include or using directives here

// rank and suit names -- do not remove these
constexpr const char* const Card::RANK_TWO;
constexpr const char* const Card::RANK_THREE;
constexpr const char* const Card::RANK_FOUR;
constexpr const char* const Card::RANK_FIVE;
constexpr const char* const Card::RANK_SIX;
constexpr const char* const Card::RANK_SEVEN;
constexpr const char* const Card::RANK_EIGHT;
constexpr const char* const Card::RANK_NINE;
constexpr const char* const Card::RANK_TEN;
constexpr const char* const Card::RANK_JACK;
constexpr const char* const Card::RANK_QUEEN;
constexpr const char* const Card::RANK_KING;
constexpr const char* const Card::RANK_ACE;

constexpr const char* const Card::SUIT_SPADES;
constexpr const char* const Card::SUIT_HEARTS;
constexpr const char* const Card::SUIT_CLUBS;
constexpr const char* const Card::SUIT_DIAMONDS;

// add your code below

//EFFECTS Initializes Card to the Two of Spades
Card::Card(){
    rank = RANK_TWO;
    suit = SUIT_SPADES;
}

//REQUIRES rank is one of "Two", "Three", "Four", "Five", "Six", "Seven",
//  "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace"
//  suit is one of "Spades", "Hearts", "Clubs", "Diamonds"
//EFFECTS Initializes Card to specified rank and suit
Card::Card(const std::string &rank_in, const std::string &suit_in){
    
    assert(rank_in == RANK_TWO
           || rank_in == RANK_THREE
           || rank_in == RANK_FOUR
           || rank_in == RANK_FIVE
           || rank_in == RANK_SIX
           || rank_in == RANK_SEVEN
           || rank_in == RANK_EIGHT
           || rank_in == RANK_NINE
           || rank_in == RANK_TEN
           || rank_in == RANK_JACK
           || rank_in == RANK_QUEEN
           || rank_in == RANK_KING
           || rank_in == RANK_ACE);
    assert(suit_in == SUIT_SPADES
           || suit_in == SUIT_HEARTS
           || suit_in == SUIT_CLUBS
           || suit_in == SUIT_DIAMONDS);
    
    rank = rank_in;
    suit = suit_in;
}

//EFFECTS Returns the rank
std::string Card::get_rank() const{
    return rank;
}

//EFFECTS Returns the suit.  Does not consider trump.
std::string Card::get_suit() const{
    return suit;
}

//REQUIRES trump is a valid suit
//EFFECTS Returns the suit
//HINT: the left bower is the trump suit!
std::string Card::get_suit(const std::string &trump) const{
    assert(trump == SUIT_SPADES
           || trump == SUIT_HEARTS
           || trump == SUIT_CLUBS
           || trump == SUIT_DIAMONDS);
    if (rank == RANK_JACK && suit == Suit_next(trump)){
        return trump;
    }
    else{
        return suit;
    }
}

//EFFECTS Returns true if card is a face card (Jack, Queen, King or Ace)
bool Card::is_face() const{
    return(rank == RANK_JACK
           || rank == RANK_QUEEN
           || rank == RANK_KING
           || rank == RANK_ACE);
}

//REQUIRES trump is a valid suit
//EFFECTS Returns true if card is the Jack of the trump suit
bool Card::is_right_bower(const std::string &trump) const{
    assert(trump == SUIT_SPADES
           || trump == SUIT_HEARTS
           || trump == SUIT_CLUBS
           || trump == SUIT_DIAMONDS);
    return(rank == RANK_JACK && suit == trump);
}

//REQUIRES trump is a valid suit
//EFFECTS Returns true if card is the Jack of the next suit
bool Card::is_left_bower(const std::string &trump) const{
    assert(trump == SUIT_SPADES
           || trump == SUIT_HEARTS
           || trump == SUIT_CLUBS
           || trump == SUIT_DIAMONDS);
    return(rank == RANK_JACK && suit == Suit_next(trump));
}

//REQUIRES trump is a valid suit
//EFFECTS Returns true if the card is a trump card.  All cards of the trump
// suit are trump cards.  The left bower is also a trump card.
bool Card::is_trump(const std::string &trump) const{
    assert(trump == SUIT_SPADES
           || trump == SUIT_HEARTS
           || trump == SUIT_CLUBS
           || trump == SUIT_DIAMONDS);
    if(suit == trump || is_left_bower(trump)){
        return true;
    }
    else{
        return false;
    }
}

// NOTE: We HIGHLY recommend you check out the operator overloading
// tutorial in the project spec (see the appendices) before implementing
// the following operator overload functions:
//   operator<<
//   operator<
//   operator<=
//   operator>
//   operator>=
//   operator==
//   operator!=

//EFFECTS Returns true if lhs is lower value than rhs.
//  Does not consider trump.
bool operator<(const Card &lhs, const Card &rhs){
    
    int indexl = 0;
    int indexr = 0;
    
    int suitl = 0;
    int suitr = 0;
    
    for(int i = 0; i < 13; i++){
        if(RANK_NAMES_BY_WEIGHT[i] == lhs.get_rank()){
            indexl = i;
        }
        if(RANK_NAMES_BY_WEIGHT[i] == rhs.get_rank()){
            indexr = i;
        }
    }
    
    for(int i = 0; i < 4;i++){
        if(SUIT_NAMES_BY_WEIGHT[i] == lhs.get_suit()){
            suitl = i;
        }
        if(SUIT_NAMES_BY_WEIGHT[i] == rhs.get_suit()){
            suitr = i;
        }
    }
    if(indexl != indexr){
        return(indexl < indexr);
    }
    else{
        return (suitl < suitr);
    }
}

//EFFECTS Returns true if lhs is lower value than rhs or the same card as rhs.
//  Does not consider trump.
bool operator<=(const Card &lhs, const Card &rhs){
    int indexl = 0;
    int indexr = 0;
    
    int suitl = 0;
    int suitr = 0;
    
    for(int i = 0; i < 13; i++){
        if(RANK_NAMES_BY_WEIGHT[i] == lhs.get_rank()){
            indexl = i;
        }
        if(RANK_NAMES_BY_WEIGHT[i] == rhs.get_rank()){
            indexr = i;
        }
    }
    
    for(int i = 0; i < 4;i++){
        if(SUIT_NAMES_BY_WEIGHT[i] == lhs.get_suit()){
            suitl = i;
        }
        if(SUIT_NAMES_BY_WEIGHT[i] == rhs.get_suit()){
            suitr = i;
        }
    }
    if(indexl != indexr){
        return(indexl <= indexr);
    }
    else{
        return (suitl <= suitr);
    }
}

//EFFECTS Returns true if lhs is higher value than rhs.
//  Does not consider trump.
bool operator>(const Card &lhs, const Card &rhs){
    return (!(lhs<=rhs));
}

//EFFECTS Returns true if lhs is higher value than rhs or the same card as rhs.
//  Does not consider trump.
bool operator>=(const Card &lhs, const Card &rhs){
    return (!(lhs<rhs));
}

//EFFECTS Returns true if lhs is same card as rhs.
//  Does not consider trump.
bool operator==(const Card &lhs, const Card &rhs){
    return (lhs.get_rank() == rhs.get_rank() &&
            lhs.get_suit() == rhs.get_suit());
}

//EFFECTS Returns true if lhs is not the same card as rhs.
//  Does not consider trump.
bool operator!=(const Card &lhs, const Card &rhs){
    return (!(lhs==rhs));
}

//REQUIRES suit is a valid suit
//EFFECTS returns the next suit, which is the suit of the same color
std::string Suit_next(const std::string &suit){
    assert(suit == Card::SUIT_SPADES
           || suit == Card::SUIT_HEARTS
           || suit == Card::SUIT_CLUBS
           || suit == Card::SUIT_DIAMONDS);
    
    if(suit == Card::SUIT_SPADES){
        return Card::SUIT_CLUBS;
    }
    else if(suit == Card::SUIT_CLUBS){
        return Card::SUIT_SPADES;
    }
    else if(suit == Card::SUIT_HEARTS){
        return Card::SUIT_DIAMONDS;
    }
    else{
        return Card::SUIT_HEARTS;
    }
}

//EFFECTS Prints Card to stream, for example "Two of Spades"
std::ostream & operator<<(std::ostream &os, const Card &card){
    os << card.get_rank() << " " << "of" << " " << card.get_suit();
    return os;
}

//REQUIRES trump is a valid suit
//EFFECTS Returns true if a is lower value than b.  Uses trump to determine
// order, as described in the spec.
bool Card_less(const Card &a, const Card &b, const std::string &trump){
    assert(trump == Card::SUIT_SPADES
           || trump == Card::SUIT_HEARTS
           || trump == Card::SUIT_CLUBS
           || trump == Card::SUIT_DIAMONDS);
    
    if(a.get_suit() != trump && b.get_suit() != trump){
        if(a.get_suit() == Suit_next(trump)
           && a.get_rank() == Card::RANK_JACK){
            return false;
        }
        else if(b.get_suit() == Suit_next(trump)
                && b.get_rank() == Card::RANK_JACK){
            return true;
        }
        else{
            return (a<b);
        }
    }
    else if(a.get_suit() == trump && b.get_suit() != trump){
        if(b.get_suit() == Suit_next(trump)
           && b.get_rank() == Card::RANK_JACK){
            return !(a.get_rank() == Card::RANK_JACK);
        }
        else{
            return false;
        }
    }
    else if(a.get_suit() != trump && b.get_suit() == trump){
        if(a.get_suit() == Suit_next(trump)
           && a.get_rank() == Card::RANK_JACK){
            return (b.get_rank() == Card::RANK_JACK);
        }
        else{
            return true;
        }
    }
    else{
        if(a.get_rank() == Card::RANK_JACK){
            return false;
        }
        else if(b.get_rank() == Card::RANK_JACK){
            return true;
        }
        else{
            return (a<b);
        }
    }
}

//REQUIRES trump is a valid suit
//EFFECTS Returns true if a is lower value than b.  Uses both the trump suit
//  and the suit led to determine order, as described in the spec.
bool Card_less(const Card &a, const Card &b, const Card &led_card,
               const std::string &trump){
    assert(trump == Card::SUIT_SPADES
           || trump == Card::SUIT_HEARTS
           || trump == Card::SUIT_CLUBS
           || trump == Card::SUIT_DIAMONDS);
    string as = a.get_suit();
    string bs = b.get_suit();
    if(led_card.get_suit() == trump){
        return Card_less(a,b,trump);
    }
    string suit;
    if(led_card.is_left_bower(trump)){suit = trump;}
    else{suit = led_card.get_suit();}
    if(as != trump && bs != trump){
        if(as == suit && bs != suit){
            return(b.is_left_bower(trump));
        }
        else if(as != suit && bs == suit){
            return(!a.is_left_bower(trump));
        }
        else if(a.is_left_bower(trump)){return false;}
        else if(b.is_left_bower(trump)){return true;}
        else{return (a<b);}
    }
    else if(as == trump && bs != trump){
        return(b.is_left_bower(trump) && a.get_rank() != Card::RANK_JACK);
    }
    else if(as != trump && bs == trump){
        return(!(a.is_left_bower(trump) && b.get_rank() != Card::RANK_JACK));
    }
    else{
        if(a.get_rank() == Card::RANK_JACK){return false;}
        else if(b.get_rank() == Card::RANK_JACK){return true;}
        else{return (a<b);}
    }
}


