//Project UID 1d9f47bfc76643019cfbf037641defe1

#include "Card.h"
#include <string>
#include <vector>
#include "Player.h"
#include <algorithm>
#include <cassert>

using namespace std;

class Simple: public Player{
public:
    Simple(const string name): name(name){}
    const string& get_name() const{
        return name;
    }
    void add_card(const Card &c){
        assert(hand.size() < MAX_HAND_SIZE);
        hand.push_back(c);
    }
    bool make_trump(const Card &upcard, bool is_dealer,
                    int round, std::string &order_up_suit) const{
        assert(round == 1 || round == 2);
        string trump = upcard.get_suit();
        string nextsuit = Suit_next(trump);
        int number = 0;
        int numbernext = 0;
        for(size_t i = 0; i < hand.size(); i++){
            if(hand[i].is_trump(trump) && hand[i].is_face()){
                number++;
            }
        }
        for(size_t i = 0; i < hand.size(); i++){
            if(hand[i].is_trump(nextsuit) && hand[i].is_face()){
                numbernext++;
            }
        }
        if(round == 1){
            if(number >= 2){
                order_up_suit = trump;
                return true;
            }
            else{
                return false;
            }
        }
        else if(round == 2 && !is_dealer){
            if(numbernext >= 1){
                order_up_suit = nextsuit;
                return true;
            }
            else{
                return false;
            }
        }
        else{
            order_up_suit = nextsuit;
            return true;
        }
    }
    void add_and_discard(const Card &upcard){
        assert(hand.size() >= 1);
        hand.push_back(upcard);
        string trump = upcard.get_suit();
        Card c = hand[0];
        size_t index = 0;
        for(size_t i = 0; i < hand.size(); i++){
            if(Card_less(hand[i], c, trump)){
                c = hand[i];
                index = i;
            }
        }
        hand.erase(hand.begin() + index);
    }
    Card lead_card(const std::string &trump){
        assert(hand.size() >= 1);
        assert(trump == Card::SUIT_SPADES
               || trump == Card::SUIT_HEARTS
               || trump == Card::SUIT_CLUBS
               || trump == Card::SUIT_DIAMONDS);
        size_t trumpcard = 0;
        size_t indextrump = 0;
        size_t indexnontrump =0;
        for(size_t i = 0; i < hand.size(); i++){
            if(hand[i].is_trump(trump)){
                trumpcard++;
                indextrump = i;
            }
            else{
                indexnontrump = i;
            }
        }
        
        if(trumpcard != hand.size()){
            Card c = hand[indexnontrump];
            for(size_t i = 0; i < hand.size(); i++){
                if(hand[i] > c && !hand[i].is_trump(trump)){
                    c = hand[i];
                    indexnontrump = i;
                }
            }
            hand.erase(hand.begin() + indexnontrump);
            return c;
        }
        else{
            Card c = hand[indextrump];
            for(size_t i = 0; i < hand.size(); i++){
                if(Card_less(c,hand[i],trump)){
                    c = hand[i];
                    indextrump = i;
                }
            }
            hand.erase(hand.begin() + indextrump);
            return c;
        }
    }
    Card play_card(const Card &led_card, const std::string &trump){
        assert(hand.size() >= 1);
        assert(trump == Card::SUIT_SPADES
               || trump == Card::SUIT_HEARTS
               || trump == Card::SUIT_CLUBS
               || trump == Card::SUIT_DIAMONDS);
        string suit;
        if(led_card.get_suit() == trump
            || led_card.is_left_bower(trump)){
            suit = trump;
        }
        else{
            suit = led_card.get_suit();
        }
        size_t suitcard = 0;
        size_t index = 0;
        
        for(size_t i = 0; i < hand.size(); i++){
            if(suit == trump &&
                (hand[i].get_suit() == suit || hand[i].is_left_bower(suit))){
                    suitcard++;
                    index = i;
                }
            else if(suit != trump &&
                hand[i].get_suit() == suit && !hand[i].is_left_bower(trump)){
                    suitcard++;
                    index = i;
                }
        }
        
        Card c = hand[index];
        
        if(suitcard!=0){
            for(size_t i = 0; i < hand.size(); i++){
                if(suit == trump &&
                   Card_less(c, hand[i], trump) &&
                       (hand[i].get_suit() == suit
                        || hand[i].is_left_bower(suit))){
                        c = hand[i];
                        index = i;
                    }
                else if(suit != trump &&
                        Card_less(c, hand[i], led_card, trump) &&
                       (hand[i].get_suit() == suit
                         && !hand[i].is_left_bower(trump))){
                        c = hand[i];
                        index = i;
                    }
            }
            hand.erase(hand.begin() + index);
            return c;
        }
        else{
            Card c = hand[0];
            size_t index = 0;
            for(size_t i = 0; i < hand.size(); i++){
                if(Card_less(hand[i], c, led_card, trump)){
                    c = hand[i];
                    index = i;
                }
            }
            hand.erase(hand.begin() + index);
            return c;
        }
    }
    
    
    
private:
    string name;
    vector<Card> hand;
};



class Human: public Player{
public:
    Human(const string name): name(name){}
    const string& get_name() const{
        return name;
    }
    void add_card(const Card &c){
        assert(hand.size() < MAX_HAND_SIZE);
        hand.push_back(c);
    }
    bool make_trump(const Card &upcard, bool is_dealer,
                    int round, std::string &order_up_suit) const{
        assert(round == 1 || round == 2);
        vector<Card> order;
        order = hand;
        sort(order.begin(), order.end());
        
        cout<<"Human player "<<name<<"'s hand: [0] "<<order[0]<<endl;
        cout<<"Human player "<<name<<"'s hand: [1] "<<order[1]<<endl;
        cout<<"Human player "<<name<<"'s hand: [2] "<<order[2]<<endl;
        cout<<"Human player "<<name<<"'s hand: [3] "<<order[3]<<endl;
        cout<<"Human player "<<name<<"'s hand: [4] "<<order[4]<<endl;
        cout<<"Human player "<<name<<", please enter a suit, or \"pass\":"<<endl;
        string input;
        cin >> input;
        if(input == "pass"){
            return false;
        }
        else{
            order_up_suit = input;
            return true;
        }
    }
    void add_and_discard(const Card &upcard){
        assert(hand.size() >= 1);

        sort(hand.begin(), hand.end());
        
        cout<<"Human player "<<name<<"'s hand: [0] "<<hand[0]<<endl;
        cout<<"Human player "<<name<<"'s hand: [1] "<<hand[1]<<endl;
        cout<<"Human player "<<name<<"'s hand: [2] "<<hand[2]<<endl;
        cout<<"Human player "<<name<<"'s hand: [3] "<<hand[3]<<endl;
        cout<<"Human player "<<name<<"'s hand: [4] "<<hand[4]<<endl;
        
        cout<<"Discard upcard: [-1]"<<endl;
        cout<<"Human player "<<name<<", please select a card to discard:";
        hand.push_back(upcard);
        //cout << "You can discard a card as you want \n";
        
        int input;
        cin >> input;
        if(input == -1){
            hand.erase(hand.begin() + (hand.size() - 1));
        }
        else{
            hand.erase(hand.begin() + input);
        }
        cout<<endl;
    }
    Card lead_card(const std::string &trump){
        assert(hand.size() >= 1);
        assert(trump == Card::SUIT_SPADES
               || trump == Card::SUIT_HEARTS
               || trump == Card::SUIT_CLUBS
               || trump == Card::SUIT_DIAMONDS);
        
        vector<Card> order;
        order = hand;
        sort(order.begin(), order.end());
        
        for(size_t i = 0; i < order.size(); i++){
            cout << "Human player "<< name<<"'s hand: ["<< i << "] "<<order[i] << "\n";
        }
        cout << "Human player "<<name<<", please select a card:" << endl;
        int input;
        cin >> input;
        
        Card c = order[input];
        size_t index = 0;
        for(size_t i = 0; i < hand.size(); i++){
            if(hand[i] == c){
                index = i;
            }
        }
        hand.erase(hand.begin() + index);
        return c;
    }
    Card play_card(const Card &led_card, const std::string &trump){
        return lead_card(trump);
    }
    
private:
    string name;
    vector<Card> hand;
};


//EFFECTS: Returns a pointer to a player with the given name and strategy
//To create an object that won't go out of scope when the function returns,
//use "return new Simple(name)" or "return new Human(name)"
//Don't forget to call "delete" on each Player* after the game is over
Player * Player_factory(const std::string &name, const std::string &strategy){
    if(strategy == "Simple"){
        return new Simple(name);
    }
    else if(strategy == "Human"){
        return new Human(name);
    }
    else{
        return nullptr;
    }
}

//EFFECTS: Prints player's name to os
std::ostream & operator<<(std::ostream &os, const Player &p){
    os << p.get_name();
    return os;
}





