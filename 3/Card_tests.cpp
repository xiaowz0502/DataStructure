// Project UID 1d9f47bfc76643019cfbf037641defe1

#include "Card.h"
#include "unit_test_framework.h"
#include <string>
#include <iostream>
#include <cassert>

using namespace std;


TEST(test_card_ctor) {
    Card c(Card::RANK_ACE, Card::SUIT_HEARTS);
    ASSERT_EQUAL(Card::RANK_ACE, c.get_rank());
    ASSERT_EQUAL(Card::SUIT_HEARTS, c.get_suit());
}

TEST(test_basic){
    
    Card ninespade(Card::RANK_NINE, Card::SUIT_SPADES);
    Card jackspade(Card::RANK_JACK, Card::SUIT_SPADES);
    Card acespade(Card::RANK_ACE, Card::SUIT_SPADES);
    Card jackclub(Card::RANK_JACK, Card::SUIT_CLUBS);
    Card aceclub(Card::RANK_ACE, Card::SUIT_CLUBS);
    
    //test is_face
    assert(!ninespade.is_face());
    assert(jackspade.is_face());
    assert(acespade.is_face());
    
    //test trump
    const string trump = Card::SUIT_SPADES;
    assert(jackspade.is_right_bower(trump));
    assert(jackclub.is_left_bower(trump));
    
    assert(jackclub.is_trump(trump));
    assert(jackspade.is_trump(trump));
    assert(!aceclub.is_trump(trump));
    
}

TEST(test_operater){
    Card ninespade(Card::RANK_NINE, Card::SUIT_SPADES);
    Card jackspade(Card::RANK_JACK, Card::SUIT_SPADES);
    Card acespade(Card::RANK_ACE, Card::SUIT_SPADES);
    Card jackclub(Card::RANK_JACK, Card::SUIT_CLUBS);
    Card aceclub(Card::RANK_ACE, Card::SUIT_CLUBS);
    
    //   operator<<
    ostringstream expected;
    expected << "Jack of Spades";
    ostringstream actual;
    actual << jackspade;
    assert(actual.str() == expected.str());
    //   operator<
    assert(jackclub < aceclub);
    assert(jackspade < jackclub);
    //   operator<=
    assert(jackclub <= aceclub);
    assert(jackspade <= jackclub);
    assert(jackclub <= jackclub);
    //   operator>
    assert(aceclub > jackclub);
    assert(jackclub > jackspade);
    //   operator>=
    assert(jackclub >= jackspade);
    assert(jackclub >= jackclub);
    assert(aceclub > jackclub);
    //   operator==
    assert(aceclub == aceclub);
    assert(jackspade == jackspade);
    //   operator!=
    assert(jackspade != jackclub);
}

TEST(test_card_less){
    
    Card ninespade(Card::RANK_NINE, Card::SUIT_SPADES);
    Card jackspade(Card::RANK_JACK, Card::SUIT_SPADES);
    Card acespade(Card::RANK_ACE, Card::SUIT_SPADES);
    Card jackclub(Card::RANK_JACK, Card::SUIT_CLUBS);
    Card aceclub(Card::RANK_ACE, Card::SUIT_CLUBS);
    Card tenclub(Card::RANK_TEN, Card::SUIT_CLUBS);
    Card jackheart(Card::RANK_JACK, Card::SUIT_HEARTS);
    Card tenheart(Card::RANK_TEN, Card::SUIT_HEARTS);
    Card ninediamond(Card::RANK_NINE, Card::SUIT_DIAMONDS);
    Card jackdiamond(Card::RANK_JACK, Card::SUIT_DIAMONDS);
    
    //trump only
    const string trump = Card::SUIT_SPADES;
    
    // a!=trump, b!=trump
    assert(!Card_less(jackclub,aceclub,trump));
    assert(!Card_less(jackclub,jackheart,trump));
    assert(Card_less(jackheart,aceclub,trump));
    assert(!Card_less(jackclub,jackclub,trump));
    
    //a==trump, b!=trump
    assert(Card_less(acespade,jackclub,trump));
    assert(!Card_less(jackspade,jackclub,trump));
    assert(!Card_less(acespade,jackheart,trump));
    
    //a!=trump,b==trump
    assert(Card_less(jackclub,jackspade,trump));
    assert(!Card_less(jackclub,acespade,trump));
    assert(Card_less(jackheart,ninespade,trump));
    
    //a==trump,b==trump
    assert(Card_less(ninespade,acespade,trump));
    assert(Card_less(acespade,jackspade,trump));
    assert(Card_less(ninespade,jackspade,trump));
    
    //trump and led
    Card led_card_1(Card::RANK_JACK,Card::SUIT_CLUBS);
    Card led_card_2(Card::RANK_JACK,Card::SUIT_HEARTS);
    
    //a!=trump, b!=trump
        //a!=led, b!=led
            assert(Card_less(tenheart,jackheart,led_card_1,trump));
            
            assert(!Card_less(jackclub,tenclub,led_card_2,trump));
            assert(Card_less(ninediamond,jackdiamond,led_card_2,trump));
            assert(!Card_less(jackclub,jackdiamond,led_card_2,trump));
            assert(Card_less(jackdiamond,jackclub,led_card_2,trump));
        //a==led, b!=led
            assert(!Card_less(jackclub,jackheart,led_card_1,trump));
            
            assert(Card_less(jackheart,jackclub,led_card_2,trump));
            assert(!Card_less(tenheart,jackdiamond,led_card_2,trump));
    
        //a!=led, b==led
            assert(Card_less(tenheart,jackclub,led_card_1,trump));
    
            assert(Card_less(jackdiamond,tenheart,led_card_2,trump));
            assert(!Card_less(jackclub,jackheart,led_card_2,trump));
    
        //a==led,b==led
            assert(!Card_less(jackclub,aceclub,led_card_1,trump));
            assert(Card_less(tenclub,aceclub,led_card_1,trump));
    
            assert(!Card_less(jackheart,tenheart,led_card_2,trump));
    //a==trump,b!=trump
    assert(Card_less(acespade,jackclub,led_card_1,trump));
    assert(!Card_less(jackspade,jackclub,led_card_1,trump));
    assert(!Card_less(ninespade,jackheart,led_card_1,trump));
    
    assert(!Card_less(ninespade,jackheart,led_card_2,trump));
    
    //a!=trump,b==trump
    assert(!Card_less(jackclub,acespade,led_card_1,trump));
    assert(Card_less(jackclub,jackspade,led_card_1,trump));
    assert(Card_less(jackheart,ninespade,led_card_1,trump));
    
    assert(Card_less(jackheart,ninespade,led_card_2,trump));
    assert(Card_less(jackclub,jackspade,led_card_2,trump));
    
    //a==trump,b==trump
    assert(!Card_less(jackspade,ninespade,led_card_1,trump));
    assert(Card_less(ninespade,jackspade,led_card_1,trump));
    assert(Card_less(ninespade,acespade,led_card_1,trump));
    
    assert(!Card_less(jackspade,ninespade,led_card_2,trump));
    assert(Card_less(ninespade,jackspade,led_card_2,trump));
    assert(Card_less(ninespade,acespade,led_card_2,trump));
    
}
// Add more test cases here

TEST_MAIN()
