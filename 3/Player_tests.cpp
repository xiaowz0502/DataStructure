// Project UID 1d9f47bfc76643019cfbf037641defe1

#include "Player.h"
#include "unit_test_framework.h"

#include <iostream>

using namespace std;

TEST(test_player_get_name) {
    Player * alice = Player_factory("Alice", "Simple");
    ASSERT_EQUAL("Alice", alice->get_name());
    cout<<"TEST PASS"<< endl;
    delete alice;
}

// Add more tests here

TEST (human_mode){
    Player * human = Player_factory("HumanTest", "Human");
    ostringstream oss1;
    oss1 << * human;
    ASSERT_EQUAL(oss1.str(), "HumanTest");
    delete human;
    cout<<"TEST PASS"<< endl;
}


TEST(simple_Add){
    Player * simple1 = Player_factory("simple1", "Simple");
    ASSERT_EQUAL("simple1", simple1->get_name());
    simple1->add_card(Card(Card::RANK_NINE, Card::SUIT_HEARTS));
    simple1->add_card(Card(Card::RANK_JACK, Card::SUIT_HEARTS));
    simple1->add_card(Card(Card::RANK_QUEEN, Card::SUIT_HEARTS));
    simple1->add_card(Card(Card::RANK_KING, Card::SUIT_HEARTS));
    simple1->add_card(Card(Card::RANK_TEN, Card::SUIT_HEARTS));
    string trump1;
    Card nine_heart(Card::RANK_NINE, Card::SUIT_HEARTS);
    bool orderup1 = simple1->make_trump(nine_heart, true, 1, trump1);
    ASSERT_TRUE(orderup1);
    ASSERT_EQUAL(trump1, Card::SUIT_HEARTS);
    delete simple1;
    
    Player * simple2 = Player_factory("simple2", "Simple");
    ASSERT_EQUAL("simple2", simple2->get_name());
    simple2->add_card(Card(Card::RANK_QUEEN, Card::SUIT_HEARTS));
    simple2->add_card(Card(Card::RANK_JACK, Card::SUIT_HEARTS));
    simple2->add_card(Card(Card::RANK_NINE, Card::SUIT_SPADES));
    simple2->add_card(Card(Card::RANK_QUEEN, Card::SUIT_DIAMONDS));
    simple2->add_card(Card(Card::RANK_NINE, Card::SUIT_DIAMONDS));
    string trump2;
    bool orderup2 = simple2->make_trump(nine_heart, true, 1, trump2);
    ASSERT_TRUE(orderup2);
    ASSERT_EQUAL(trump2, Card::SUIT_HEARTS);
    delete simple2;
    
    Player * simple3 = Player_factory("simple3", "Simple");
    ASSERT_EQUAL("simple3", simple3->get_name());
    simple3->add_card(Card(Card::RANK_NINE, Card::SUIT_HEARTS));
    simple3->add_card(Card(Card::RANK_NINE, Card::SUIT_CLUBS));
    simple3->add_card(Card(Card::RANK_NINE, Card::SUIT_SPADES));
    simple3->add_card(Card(Card::RANK_TEN, Card::SUIT_DIAMONDS));
    simple3->add_card(Card(Card::RANK_NINE, Card::SUIT_DIAMONDS));
    string trump3;
    bool orderup3 = simple3->make_trump(nine_heart, true, 1, trump3);
    ASSERT_FALSE(orderup3);
    delete simple3;
    
    Player * simple6 = Player_factory("simple6", "Simple");
    ASSERT_EQUAL("simple6", simple6->get_name());
    simple6->add_card(Card(Card::RANK_NINE, Card::SUIT_HEARTS));
    simple6->add_card(Card(Card::RANK_NINE, Card::SUIT_CLUBS));
    simple6->add_card(Card(Card::RANK_NINE, Card::SUIT_SPADES));
    simple6->add_card(Card(Card::RANK_TEN, Card::SUIT_DIAMONDS));
    simple6->add_card(Card(Card::RANK_NINE, Card::SUIT_DIAMONDS));
    string trump6;
    Card card6 = Card(Card::RANK_QUEEN, Card::SUIT_DIAMONDS);
    bool orderup6 = simple6->make_trump(card6, true, 1, trump6);
    ASSERT_FALSE(orderup6);
    delete simple6;
    
    Player * simple7 = Player_factory("simple7", "Simple");
    ASSERT_EQUAL("simple7", simple7->get_name());
    simple7->add_card(Card(Card::RANK_NINE, Card::SUIT_HEARTS));
    simple7->add_card(Card(Card::RANK_QUEEN, Card::SUIT_CLUBS));
    simple7->add_card(Card(Card::RANK_JACK, Card::SUIT_SPADES));
    simple7->add_card(Card(Card::RANK_TEN, Card::SUIT_DIAMONDS));
    simple7->add_card(Card(Card::RANK_NINE, Card::SUIT_DIAMONDS));
    string trump7;
    Card card7 = Card(Card::RANK_TEN, Card::SUIT_CLUBS);
    bool orderup7 = simple7->make_trump(card7, true, 1, trump7);
    ASSERT_TRUE(orderup7);
    ASSERT_EQUAL(trump7, Card::SUIT_CLUBS);
    delete simple7;
    
    Player * simple4 = Player_factory("simple4", "Simple");
    ASSERT_EQUAL("simple4", simple4->get_name());
    simple4->add_card(Card(Card::RANK_JACK, Card::SUIT_DIAMONDS));
    simple4->add_card(Card(Card::RANK_QUEEN, Card::SUIT_DIAMONDS));
    simple4->add_card(Card(Card::RANK_NINE, Card::SUIT_SPADES));
    simple4->add_card(Card(Card::RANK_TEN, Card::SUIT_DIAMONDS));
    simple4->add_card(Card(Card::RANK_NINE, Card::SUIT_DIAMONDS));
    string trump4;
    bool orderup4 = simple4->make_trump(nine_heart, false, 2, trump4);
    ASSERT_TRUE(orderup4);
    ASSERT_EQUAL(trump4, Card::SUIT_DIAMONDS);
    delete simple4;
    
    Player * simple5 = Player_factory("simple5", "Simple");
    ASSERT_EQUAL("simple5", simple5->get_name());
    simple5->add_card(Card(Card::RANK_JACK, Card::SUIT_SPADES));
    simple5->add_card(Card(Card::RANK_QUEEN, Card::SUIT_SPADES));
    simple5->add_card(Card(Card::RANK_NINE, Card::SUIT_SPADES));
    simple5->add_card(Card(Card::RANK_TEN, Card::SUIT_DIAMONDS));
    simple5->add_card(Card(Card::RANK_NINE, Card::SUIT_DIAMONDS));
    string trump5;
    bool orderup5 = simple5->make_trump(nine_heart, true, 2, trump5);
    ASSERT_TRUE(orderup5);
    ASSERT_EQUAL(trump5, Card::SUIT_DIAMONDS);
    delete simple5;
    
    Player * simple8 = Player_factory("simple8", "Simple");
    ASSERT_EQUAL("simple8", simple8->get_name());
    simple8->add_card(Card(Card::RANK_JACK, Card::SUIT_SPADES));
    simple8->add_card(Card(Card::RANK_QUEEN, Card::SUIT_SPADES));
    simple8->add_card(Card(Card::RANK_NINE, Card::SUIT_SPADES));
    simple8->add_card(Card(Card::RANK_TEN, Card::SUIT_CLUBS));
    simple8->add_card(Card(Card::RANK_NINE, Card::SUIT_CLUBS));
    string trump8;
    bool orderup8 = simple8->make_trump(nine_heart, true, 2, trump8);
    ASSERT_TRUE(orderup8);
    ASSERT_EQUAL(trump8, Card::SUIT_DIAMONDS);
    delete simple8;
    
    Player * simple9 = Player_factory("simple9", "Simple");
    ASSERT_EQUAL("simple9", simple9->get_name());
    simple9->add_card(Card(Card::RANK_JACK, Card::SUIT_SPADES));
    simple9->add_card(Card(Card::RANK_QUEEN, Card::SUIT_SPADES));
    simple9->add_card(Card(Card::RANK_NINE, Card::SUIT_HEARTS));
    simple9->add_card(Card(Card::RANK_TEN, Card::SUIT_CLUBS));
    simple9->add_card(Card(Card::RANK_NINE, Card::SUIT_DIAMONDS));
    string trump9;
    bool orderup9 = simple9->make_trump(nine_heart, true, 2, trump9);
    ASSERT_TRUE(orderup9);
    ASSERT_EQUAL(trump9, Card::SUIT_DIAMONDS);
    delete simple9;
    
    
    Player * simple10 = Player_factory("simple10", "Simple");
    ASSERT_EQUAL("simple10", simple10->get_name());
    simple10->add_card(Card(Card::RANK_JACK, Card::SUIT_DIAMONDS));
    simple10->add_card(Card(Card::RANK_QUEEN, Card::SUIT_SPADES));
    simple10->add_card(Card(Card::RANK_NINE, Card::SUIT_SPADES));
    simple10->add_card(Card(Card::RANK_TEN, Card::SUIT_CLUBS));
    simple10->add_card(Card(Card::RANK_NINE, Card::SUIT_DIAMONDS));
    string trump10;
    bool orderup10 = simple10->make_trump(nine_heart, false, 2, trump10);
    ASSERT_TRUE(orderup10);
    ASSERT_EQUAL(trump10, Card::SUIT_DIAMONDS);
    delete simple10;
    
    Player * simple11 = Player_factory("simple11", "Simple");
    ASSERT_EQUAL("simple11", simple11->get_name());
    simple11->add_card(Card(Card::RANK_JACK, Card::SUIT_CLUBS));
    simple11->add_card(Card(Card::RANK_QUEEN, Card::SUIT_SPADES));
    simple11->add_card(Card(Card::RANK_NINE, Card::SUIT_SPADES));
    simple11->add_card(Card(Card::RANK_TEN, Card::SUIT_CLUBS));
    simple11->add_card(Card(Card::RANK_NINE, Card::SUIT_HEARTS));
    string trump11;
    bool orderup11 = simple11->make_trump(nine_heart, false, 2, trump11);
    ASSERT_FALSE(orderup11);
    delete simple11;
}
TEST(test_card_make1){
    Player * simple1 = Player_factory("simple1", "Simple");
    ASSERT_EQUAL("simple1", simple1->get_name());
    simple1->add_card(Card(Card::RANK_NINE, Card::SUIT_HEARTS));
    simple1->add_card(Card(Card::RANK_JACK, Card::SUIT_HEARTS));
    simple1->add_card(Card(Card::RANK_QUEEN, Card::SUIT_HEARTS));
    simple1->add_card(Card(Card::RANK_KING, Card::SUIT_HEARTS));
    simple1->add_card(Card(Card::RANK_TEN, Card::SUIT_HEARTS));
    string trump1;
    Card nine_heart(Card::RANK_NINE, Card::SUIT_HEARTS);
    bool orderup1 = simple1->make_trump(nine_heart, false, 1, trump1);
    ASSERT_TRUE(orderup1);
    ASSERT_EQUAL(trump1, Card::SUIT_HEARTS);
    delete simple1;
}
TEST(test_card_make2){
    Player * simple1 = Player_factory("simple1", "Simple");
    ASSERT_EQUAL("simple1", simple1->get_name());
    simple1->add_card(Card(Card::RANK_NINE, Card::SUIT_HEARTS));
    simple1->add_card(Card(Card::RANK_JACK, Card::SUIT_DIAMONDS));
    simple1->add_card(Card(Card::RANK_QUEEN, Card::SUIT_HEARTS));
    simple1->add_card(Card(Card::RANK_KING, Card::SUIT_SPADES));
    simple1->add_card(Card(Card::RANK_TEN, Card::SUIT_CLUBS));
    string trump1;
    Card nine_heart(Card::RANK_JACK, Card::SUIT_HEARTS);
    bool orderup1 = simple1->make_trump(nine_heart, false, 1, trump1);
    ASSERT_TRUE(orderup1);
    ASSERT_EQUAL(trump1, Card::SUIT_HEARTS);
    delete simple1;
}
TEST(test_card_make3){
    Player * simple1 = Player_factory("simple1", "Simple");
    ASSERT_EQUAL("simple1", simple1->get_name());
    simple1->add_card(Card(Card::RANK_NINE, Card::SUIT_CLUBS));
    simple1->add_card(Card(Card::RANK_JACK, Card::SUIT_DIAMONDS));
    simple1->add_card(Card(Card::RANK_QUEEN, Card::SUIT_HEARTS));
    simple1->add_card(Card(Card::RANK_KING, Card::SUIT_SPADES));
    simple1->add_card(Card(Card::RANK_TEN, Card::SUIT_CLUBS));
    string trump1;
    Card nine_heart(Card::RANK_JACK, Card::SUIT_HEARTS);
    bool orderup1 = simple1->make_trump(nine_heart, false, 2, trump1);
    ASSERT_TRUE(orderup1);
    ASSERT_EQUAL(trump1, Card::SUIT_DIAMONDS);
    delete simple1;
}

TEST(test_card_make4){
    Player * simple1 = Player_factory("simple1", "Simple");
    ASSERT_EQUAL("simple1", simple1->get_name());
    simple1->add_card(Card(Card::RANK_NINE, Card::SUIT_CLUBS));
    simple1->add_card(Card(Card::RANK_JACK, Card::SUIT_DIAMONDS));
    simple1->add_card(Card(Card::RANK_QUEEN, Card::SUIT_SPADES));
    simple1->add_card(Card(Card::RANK_KING, Card::SUIT_SPADES));
    simple1->add_card(Card(Card::RANK_TEN, Card::SUIT_CLUBS));
    string trump1;
    Card nine_heart(Card::RANK_JACK, Card::SUIT_HEARTS);
    bool orderup1 = simple1->make_trump(nine_heart, true, 2, trump1);
    ASSERT_TRUE(orderup1);
    ASSERT_EQUAL(trump1, Card::SUIT_DIAMONDS);
    delete simple1;
}

TEST(test_card_make5){
    Player * simple1 = Player_factory("simple1", "Simple");
    ASSERT_EQUAL("simple1", simple1->get_name());
    simple1->add_card(Card(Card::RANK_NINE, Card::SUIT_CLUBS));
    simple1->add_card(Card(Card::RANK_JACK, Card::SUIT_DIAMONDS));
    simple1->add_card(Card(Card::RANK_QUEEN, Card::SUIT_SPADES));
    simple1->add_card(Card(Card::RANK_KING, Card::SUIT_SPADES));
    simple1->add_card(Card(Card::RANK_TEN, Card::SUIT_CLUBS));
    string trump1;
    Card nine_heart(Card::RANK_JACK, Card::SUIT_DIAMONDS);
    bool orderup1 = simple1->make_trump(nine_heart, true, 2, trump1);
    ASSERT_TRUE(orderup1);
    ASSERT_EQUAL(trump1, Card::SUIT_HEARTS);
    delete simple1;
}

TEST(test_card_make6){
    Player * simple1 = Player_factory("simple1", "Simple");
    ASSERT_EQUAL("simple1", simple1->get_name());
    simple1->add_card(Card(Card::RANK_NINE, Card::SUIT_CLUBS));
    simple1->add_card(Card(Card::RANK_TEN, Card::SUIT_DIAMONDS));
    simple1->add_card(Card(Card::RANK_QUEEN, Card::SUIT_SPADES));
    simple1->add_card(Card(Card::RANK_KING, Card::SUIT_SPADES));
    simple1->add_card(Card(Card::RANK_TEN, Card::SUIT_CLUBS));
    string trump1;
    Card nine_heart(Card::RANK_JACK, Card::SUIT_DIAMONDS);
    bool orderup1 = simple1->make_trump(nine_heart, true, 2, trump1);
    ASSERT_TRUE(orderup1);
    ASSERT_EQUAL(trump1, Card::SUIT_HEARTS);
    delete simple1;
}

TEST(test_card_make7){
    Player * simple1 = Player_factory("simple1", "Simple");
    ASSERT_EQUAL("simple1", simple1->get_name());
    simple1->add_card(Card(Card::RANK_NINE, Card::SUIT_CLUBS));
    simple1->add_card(Card(Card::RANK_TEN, Card::SUIT_DIAMONDS));
    simple1->add_card(Card(Card::RANK_QUEEN, Card::SUIT_CLUBS));
    simple1->add_card(Card(Card::RANK_KING, Card::SUIT_SPADES));
    simple1->add_card(Card(Card::RANK_TEN, Card::SUIT_CLUBS));
    string trump1;
    Card nine_heart(Card::RANK_JACK, Card::SUIT_DIAMONDS);
    bool orderup1 = simple1->make_trump(nine_heart, false, 2, trump1);
    ASSERT_FALSE(orderup1);
    delete simple1;
}


  TEST(test_simple_player_lead_card) {
  // Bob's hand
    Player * simple1 = Player_factory("simple1", "Simple");
    simple1->add_card(Card(Card::RANK_NINE, Card::SUIT_HEARTS));
    simple1->add_card(Card(Card::RANK_JACK, Card::SUIT_HEARTS));
    simple1->add_card(Card(Card::RANK_QUEEN, Card::SUIT_HEARTS));
    simple1->add_card(Card(Card::RANK_KING, Card::SUIT_HEARTS));
    simple1->add_card(Card(Card::RANK_TEN, Card::SUIT_HEARTS));
  // Bob adds a card to his hand and discards one card
    simple1->add_and_discard(
    Card(Card::RANK_NINE, Card::SUIT_SPADES) // upcard
  );
  // Bob leads
  Card card_led = simple1->lead_card(Card::SUIT_SPADES);
  // Verify the card Bob selected to lead
  Card king_hearts(Card::RANK_KING, Card::SUIT_HEARTS);
  ASSERT_EQUAL(card_led, king_hearts); //check led card
  delete simple1;
    
    Player * simple2 = Player_factory("simple2", "Simple");
    simple2->add_card(Card(Card::RANK_QUEEN, Card::SUIT_HEARTS));
    simple2->add_card(Card(Card::RANK_JACK, Card::SUIT_HEARTS));
    simple2->add_card(Card(Card::RANK_NINE, Card::SUIT_SPADES));
    simple2->add_card(Card(Card::RANK_QUEEN, Card::SUIT_DIAMONDS));
    simple2->add_card(Card(Card::RANK_KING, Card::SUIT_DIAMONDS));
    simple2->add_and_discard(
    Card(Card::RANK_NINE, Card::SUIT_DIAMONDS) // upcard
  );
    Card card_led2 = simple2->lead_card(Card::SUIT_DIAMONDS);
    Card QUEEN_HEARTS(Card::RANK_QUEEN, Card::SUIT_HEARTS);
    ASSERT_EQUAL(card_led2, QUEEN_HEARTS);
    delete simple2;
    
    Player * simple3 = Player_factory("simple3", "Simple");
    simple3->add_card(Card(Card::RANK_NINE, Card::SUIT_HEARTS));
    simple3->add_card(Card(Card::RANK_JACK, Card::SUIT_CLUBS));
    simple3->add_card(Card(Card::RANK_NINE, Card::SUIT_SPADES));
    simple3->add_card(Card(Card::RANK_TEN, Card::SUIT_DIAMONDS));
    simple3->add_card(Card(Card::RANK_NINE, Card::SUIT_DIAMONDS));
    simple3->add_and_discard(
    Card(Card::RANK_ACE, Card::SUIT_SPADES) // upcard
  );
    Card card_led3 = simple3->lead_card(Card::SUIT_SPADES);
    Card TEN_DIAMONDS(Card::RANK_TEN, Card::SUIT_DIAMONDS);
    ASSERT_EQUAL(card_led3, TEN_DIAMONDS);
    delete simple3;
      
      
      Player * simple4 = Player_factory("simple4", "Simple");
      simple4->add_card(Card(Card::RANK_ACE, Card::SUIT_DIAMONDS));
      simple4->add_card(Card(Card::RANK_TEN, Card::SUIT_DIAMONDS));
      simple4->add_card(Card(Card::RANK_NINE, Card::SUIT_DIAMONDS));
      Card card_led4 = simple4->lead_card(Card::SUIT_DIAMONDS);
      Card ACE_DIAMONDS(Card::RANK_ACE, Card::SUIT_DIAMONDS);
      ASSERT_EQUAL(card_led4, ACE_DIAMONDS);
      delete simple4;
    
      Player * simple5 = Player_factory("simple5", "Simple");
      simple5->add_card(Card(Card::RANK_ACE, Card::SUIT_DIAMONDS));
      Card card_led5 = simple5->lead_card(Card::SUIT_DIAMONDS);
      delete simple5;
      
      Player * simple6 = Player_factory("simple6", "Simple");
      simple6->add_card(Card(Card::RANK_ACE, Card::SUIT_DIAMONDS));
      simple6->add_card(Card(Card::RANK_TEN, Card::SUIT_CLUBS));
      Card card_led6 = simple6->lead_card(Card::SUIT_DIAMONDS);
      ASSERT_EQUAL(card_led5, ACE_DIAMONDS);
      delete simple6;
}
 
TEST(test_lead_test){
    Player * simple1 = Player_factory("simple1", "Simple");
    simple1->add_card(Card(Card::RANK_NINE, Card::SUIT_HEARTS));
    simple1->add_card(Card(Card::RANK_JACK, Card::SUIT_HEARTS));
    simple1->add_card(Card(Card::RANK_QUEEN, Card::SUIT_HEARTS));
    simple1->add_card(Card(Card::RANK_KING, Card::SUIT_HEARTS));
    simple1->add_card(Card(Card::RANK_TEN, Card::SUIT_HEARTS));
  Card card_led = simple1->lead_card(Card::SUIT_SPADES);
  Card king_hearts(Card::RANK_KING, Card::SUIT_HEARTS);
  ASSERT_EQUAL(card_led, king_hearts); //check led card
  delete simple1;
}

TEST(test_lead_test2){
    Player * simple1 = Player_factory("simple1", "Simple");
    simple1->add_card(Card(Card::RANK_NINE, Card::SUIT_HEARTS));
    simple1->add_card(Card(Card::RANK_JACK, Card::SUIT_HEARTS));
    simple1->add_card(Card(Card::RANK_QUEEN, Card::SUIT_HEARTS));
    simple1->add_card(Card(Card::RANK_KING, Card::SUIT_HEARTS));
    simple1->add_card(Card(Card::RANK_TEN, Card::SUIT_HEARTS));
  Card card_led = simple1->lead_card(Card::SUIT_HEARTS);
  Card king_hearts(Card::RANK_JACK, Card::SUIT_HEARTS);
  ASSERT_EQUAL(card_led, king_hearts); //check led card
  delete simple1;
}


TEST(test_lead_test3){
    Player * simple1 = Player_factory("simple1", "Simple");
    simple1->add_card(Card(Card::RANK_NINE, Card::SUIT_HEARTS));
    simple1->add_card(Card(Card::RANK_JACK, Card::SUIT_HEARTS));
    simple1->add_card(Card(Card::RANK_QUEEN, Card::SUIT_HEARTS));
    simple1->add_card(Card(Card::RANK_KING, Card::SUIT_HEARTS));
    simple1->add_card(Card(Card::RANK_TEN, Card::SUIT_HEARTS));
  Card card_led = simple1->lead_card(Card::SUIT_DIAMONDS);
  Card king_hearts(Card::RANK_KING, Card::SUIT_HEARTS);
  ASSERT_EQUAL(card_led, king_hearts); //check led card
  delete simple1;
}

TEST(test_lead_test4){
    Player * simple1 = Player_factory("simple1", "Simple");
    simple1->add_card(Card(Card::RANK_NINE, Card::SUIT_SPADES));
    simple1->add_card(Card(Card::RANK_JACK, Card::SUIT_HEARTS));
    simple1->add_card(Card(Card::RANK_QUEEN, Card::SUIT_CLUBS));
    simple1->add_card(Card(Card::RANK_KING, Card::SUIT_SPADES));
    simple1->add_card(Card(Card::RANK_TEN, Card::SUIT_CLUBS));
  Card card_led = simple1->lead_card(Card::SUIT_DIAMONDS);
  Card king_hearts(Card::RANK_KING, Card::SUIT_SPADES);
  ASSERT_EQUAL(card_led, king_hearts); //check led card
  delete simple1;
}

TEST(test_lead_test5){
    Player * simple1 = Player_factory("simple1", "Simple");
    simple1->add_card(Card(Card::RANK_NINE, Card::SUIT_SPADES));
    simple1->add_card(Card(Card::RANK_JACK, Card::SUIT_HEARTS));
  Card card_led = simple1->lead_card(Card::SUIT_DIAMONDS);
  Card king_hearts(Card::RANK_NINE, Card::SUIT_SPADES);
  ASSERT_EQUAL(card_led, king_hearts); //check led card
  delete simple1;
}

TEST(test_lead_test6){
    Player * simple1 = Player_factory("simple1", "Simple");
    simple1->add_card(Card(Card::RANK_NINE, Card::SUIT_SPADES));
    simple1->add_card(Card(Card::RANK_JACK, Card::SUIT_HEARTS));
  Card card_led = simple1->lead_card(Card::SUIT_HEARTS);
  Card king_hearts(Card::RANK_NINE, Card::SUIT_SPADES);
  ASSERT_EQUAL(card_led, king_hearts); //check led card
  delete simple1;
}

TEST(test_lead_test7){
    Player * simple1 = Player_factory("simple1", "Simple");
    simple1->add_card(Card(Card::RANK_JACK, Card::SUIT_DIAMONDS));
    simple1->add_card(Card(Card::RANK_JACK, Card::SUIT_HEARTS));
  Card card_led = simple1->lead_card(Card::SUIT_HEARTS);
  Card king_hearts(Card::RANK_JACK, Card::SUIT_HEARTS);
  ASSERT_EQUAL(card_led, king_hearts); //check led card
  delete simple1;
}

TEST(test_lead_test8){
    Player * simple1 = Player_factory("simple1", "Simple");
    simple1->add_card(Card(Card::RANK_JACK, Card::SUIT_DIAMONDS));
    simple1->add_card(Card(Card::RANK_TEN, Card::SUIT_HEARTS));
  Card card_led = simple1->lead_card(Card::SUIT_HEARTS);
  Card king_hearts(Card::RANK_JACK, Card::SUIT_DIAMONDS);
  ASSERT_EQUAL(card_led, king_hearts); //check led card
  delete simple1;
}

TEST(test_lead_test9){
    Player * simple1 = Player_factory("simple1", "Simple");
    simple1->add_card(Card(Card::RANK_JACK, Card::SUIT_SPADES));
    simple1->add_card(Card(Card::RANK_TEN, Card::SUIT_CLUBS));
  Card card_led = simple1->lead_card(Card::SUIT_HEARTS);
  Card king_hearts(Card::RANK_JACK, Card::SUIT_SPADES);
  ASSERT_EQUAL(card_led, king_hearts); //check led card
  delete simple1;
}

TEST(test_lead_test10){
    Player * simple1 = Player_factory("simple1", "Simple");
    simple1->add_card(Card(Card::RANK_NINE, Card::SUIT_SPADES));
    simple1->add_card(Card(Card::RANK_TEN, Card::SUIT_CLUBS));
  Card card_led = simple1->lead_card(Card::SUIT_HEARTS);
  Card king_hearts(Card::RANK_TEN, Card::SUIT_CLUBS);
  ASSERT_EQUAL(card_led, king_hearts); //check led card
  delete simple1;
}

TEST(test_lead_test11){
    Player * simple1 = Player_factory("simple1", "Simple");
    simple1->add_card(Card(Card::RANK_JACK, Card::SUIT_DIAMONDS));
    simple1->add_card(Card(Card::RANK_TEN, Card::SUIT_DIAMONDS));
  Card card_led = simple1->lead_card(Card::SUIT_HEARTS);
  Card king_hearts(Card::RANK_TEN, Card::SUIT_DIAMONDS);
  ASSERT_EQUAL(card_led, king_hearts); //check led card
  delete simple1;
}

TEST(test_lead_test12){
    Player * simple1 = Player_factory("simple1", "Simple");
    simple1->add_card(Card(Card::RANK_JACK, Card::SUIT_HEARTS));
    simple1->add_card(Card(Card::RANK_KING, Card::SUIT_HEARTS));
  Card card_led = simple1->lead_card(Card::SUIT_HEARTS);
  Card king_hearts(Card::RANK_JACK, Card::SUIT_HEARTS);
  ASSERT_EQUAL(card_led, king_hearts); //check led card
  delete simple1;
}

TEST(test_lead_test13){
    Player * simple1 = Player_factory("simple1", "Simple");
    simple1->add_card(Card(Card::RANK_JACK, Card::SUIT_HEARTS));
  Card card_led = simple1->lead_card(Card::SUIT_HEARTS);
  Card king_hearts(Card::RANK_JACK, Card::SUIT_HEARTS);
  ASSERT_EQUAL(card_led, king_hearts); //check led card
  delete simple1;
}

TEST(test_lead_test14){
    Player * simple1 = Player_factory("simple1", "Simple");
    simple1->add_card(Card(Card::RANK_JACK, Card::SUIT_HEARTS));
  Card card_led = simple1->lead_card(Card::SUIT_HEARTS);
  Card king_hearts(Card::RANK_JACK, Card::SUIT_HEARTS);
  ASSERT_EQUAL(card_led, king_hearts); //check led card
  delete simple1;
}

TEST(test_lead_test15){
    Player * simple1 = Player_factory("simple1", "Simple");
    simple1->add_card(Card(Card::RANK_JACK, Card::SUIT_DIAMONDS));
  Card card_led = simple1->lead_card(Card::SUIT_HEARTS);
  Card king_hearts(Card::RANK_JACK, Card::SUIT_DIAMONDS);
  ASSERT_EQUAL(card_led, king_hearts); //check led card
  delete simple1;
}

TEST(test_lead_test16){
    Player * simple1 = Player_factory("simple1", "Simple");
    simple1->add_card(Card(Card::RANK_JACK, Card::SUIT_CLUBS));
  Card card_led = simple1->lead_card(Card::SUIT_HEARTS);
  Card king_hearts(Card::RANK_JACK, Card::SUIT_CLUBS);
  ASSERT_EQUAL(card_led, king_hearts); //check led card
  delete simple1;
}

TEST(test_lead_test_17){
    Player * simple4 = Player_factory("simple4", "Simple");
    simple4->add_card(Card(Card::RANK_JACK, Card::SUIT_DIAMONDS));
    simple4->add_card(Card(Card::RANK_TEN, Card::SUIT_DIAMONDS));
    simple4->add_card(Card(Card::RANK_JACK, Card::SUIT_HEARTS));
    Card card_led4 = simple4->lead_card(Card::SUIT_DIAMONDS);
    Card ACE_DIAMONDS(Card::RANK_JACK, Card::SUIT_DIAMONDS);
    ASSERT_EQUAL(card_led4, ACE_DIAMONDS);
    delete simple4;
}

TEST(test_lead_test_18){
    Player * simple4 = Player_factory("simple4", "Simple");
    simple4->add_card(Card(Card::RANK_JACK, Card::SUIT_DIAMONDS));
    simple4->add_card(Card(Card::RANK_TEN, Card::SUIT_DIAMONDS));
    simple4->add_card(Card(Card::RANK_JACK, Card::SUIT_HEARTS));
    Card card_led4 = simple4->lead_card(Card::SUIT_HEARTS);
    Card ACE_DIAMONDS(Card::RANK_TEN, Card::SUIT_DIAMONDS);
    ASSERT_EQUAL(card_led4, ACE_DIAMONDS);
    delete simple4;
}

TEST(test_add_discard1){
    Player * simple1 = Player_factory("simple1", "Simple");
    simple1->add_card(Card(Card::RANK_NINE, Card::SUIT_HEARTS));
    simple1->add_and_discard(Card(Card::RANK_KING, Card::SUIT_HEARTS));
    ASSERT_EQUAL(simple1->lead_card(Card::SUIT_HEARTS),Card(Card::RANK_KING, Card::SUIT_HEARTS));
    delete simple1;
}

TEST(test_add_discard2){
    Player * simple1 = Player_factory("simple1", "Simple");
    simple1->add_card(Card(Card::RANK_JACK, Card::SUIT_DIAMONDS));
    simple1->add_card(Card(Card::RANK_ACE, Card::SUIT_DIAMONDS));
    Card upcard =Card(Card::RANK_KING, Card::SUIT_HEARTS);
    simple1->add_and_discard(upcard);
    ASSERT_EQUAL(simple1->lead_card(Card::SUIT_HEARTS),Card(Card::RANK_JACK, Card::SUIT_DIAMONDS));
    ASSERT_EQUAL(simple1->lead_card(Card::SUIT_HEARTS),Card(Card::RANK_KING, Card::SUIT_HEARTS));
    delete simple1;
}

TEST(test_add_discard3){
    Player * simple1 = Player_factory("simple1", "Simple");
    simple1->add_card(Card(Card::RANK_JACK, Card::SUIT_DIAMONDS));
    simple1->add_card(Card(Card::RANK_ACE, Card::SUIT_DIAMONDS));
    Card upcard =Card(Card::RANK_TEN, Card::SUIT_DIAMONDS);
    simple1->add_and_discard(upcard);
    ASSERT_EQUAL(simple1->lead_card(Card::SUIT_DIAMONDS),Card(Card::RANK_JACK, Card::SUIT_DIAMONDS));
    ASSERT_EQUAL(simple1->lead_card(Card::SUIT_DIAMONDS),Card(Card::RANK_ACE, Card::SUIT_DIAMONDS));
    delete simple1;
}

TEST(test_play_card_simple1){
   
    //五张牌hearts，led diamond, trump hearts
    Player * simple1 = Player_factory("simple1", "Simple");
    simple1->add_card(Card(Card::RANK_NINE, Card::SUIT_HEARTS));
    simple1->add_card(Card(Card::RANK_JACK, Card::SUIT_HEARTS));
    simple1->add_card(Card(Card::RANK_QUEEN, Card::SUIT_HEARTS));
    simple1->add_card(Card(Card::RANK_KING, Card::SUIT_HEARTS));
    simple1->add_card(Card(Card::RANK_TEN, Card::SUIT_HEARTS));
    Card nine_diamonds(Card::RANK_NINE, Card::SUIT_DIAMONDS);
    Card card_played = simple1->play_card(
      nine_diamonds,
      "Hearts"
    );
    ASSERT_EQUAL(card_played, Card(Card::RANK_NINE, Card::SUIT_HEARTS));
    delete simple1;
}

TEST(test_play_card_simple2){
    //五张牌没有
    Player * simple2 = Player_factory("simple2", "Simple");
    simple2->add_card(Card(Card::RANK_QUEEN, Card::SUIT_HEARTS));
    simple2->add_card(Card(Card::RANK_JACK, Card::SUIT_HEARTS));
    simple2->add_card(Card(Card::RANK_NINE, Card::SUIT_SPADES));
    simple2->add_card(Card(Card::RANK_QUEEN, Card::SUIT_DIAMONDS));
    simple2->add_card(Card(Card::RANK_NINE, Card::SUIT_DIAMONDS));
    Card nine_Clubes (Card::RANK_NINE, Card::SUIT_CLUBS);
    Card card_played2 = simple2->play_card(nine_Clubes, Card::SUIT_HEARTS);
    ASSERT_EQUAL(card_played2, Card(Card::RANK_NINE, Card::SUIT_SPADES));
    delete simple2;
}

TEST(test_play_card_simple4){
    //五张牌,led jack
    Player * simple4 = Player_factory("simple4", "Simple");
    simple4->add_card(Card(Card::RANK_QUEEN, Card::SUIT_HEARTS));
    simple4->add_card(Card(Card::RANK_JACK, Card::SUIT_CLUBS));
    simple4->add_card(Card(Card::RANK_NINE, Card::SUIT_SPADES));
    simple4->add_card(Card(Card::RANK_QUEEN, Card::SUIT_DIAMONDS));
    simple4->add_card(Card(Card::RANK_NINE, Card::SUIT_DIAMONDS));
    Card Jack_heart (Card::RANK_JACK, Card::SUIT_HEARTS);
    Card card_played4 = simple4->play_card(Jack_heart , Card::SUIT_DIAMONDS);
    ASSERT_EQUAL(card_played4, Card(Card::RANK_QUEEN, Card::SUIT_DIAMONDS));
    delete simple4;
}
TEST(test_play_card_simple5){
    Player * simple5 = Player_factory("simple5", "Simple");
    simple5->add_card(Card(Card::RANK_JACK, Card::SUIT_HEARTS));
    simple5->add_card(Card(Card::RANK_JACK, Card::SUIT_CLUBS));
    simple5->add_card(Card(Card::RANK_NINE, Card::SUIT_SPADES));
    simple5->add_card(Card(Card::RANK_QUEEN, Card::SUIT_DIAMONDS));
    simple5->add_card(Card(Card::RANK_NINE, Card::SUIT_DIAMONDS));
    Card Ten_heart (Card::RANK_TEN, Card::SUIT_HEARTS);
    Card card_played5 = simple5->play_card(Ten_heart , Card::SUIT_DIAMONDS);
    ASSERT_EQUAL(card_played5, Card(Card::RANK_NINE, Card::SUIT_SPADES));
    delete simple5;
}

TEST(test_play_card_simple6){
    Player * simple6 = Player_factory("simple6", "Simple");
    simple6->add_card(Card(Card::RANK_JACK, Card::SUIT_HEARTS));
    simple6->add_card(Card(Card::RANK_TEN, Card::SUIT_CLUBS));
    simple6->add_card(Card(Card::RANK_NINE, Card::SUIT_CLUBS));
    simple6->add_card(Card(Card::RANK_QUEEN, Card::SUIT_DIAMONDS));
    simple6->add_card(Card(Card::RANK_NINE, Card::SUIT_DIAMONDS));
    Card Ten_spade (Card::RANK_TEN, Card::SUIT_SPADES);
    Card card_played6 = simple6->play_card(Ten_spade , Card::SUIT_SPADES);
    ASSERT_EQUAL(card_played6, Card(Card::RANK_NINE, Card::SUIT_CLUBS));
    delete simple6;
}

TEST(test_play_card_simple7){
    Player * simple7 = Player_factory("simple7", "Simple");
    simple7->add_card(Card(Card::RANK_TEN, Card::SUIT_HEARTS));
    simple7->add_card(Card(Card::RANK_QUEEN, Card::SUIT_CLUBS));
    simple7->add_card(Card(Card::RANK_NINE, Card::SUIT_CLUBS));
    simple7->add_card(Card(Card::RANK_QUEEN, Card::SUIT_HEARTS));
    simple7->add_card(Card(Card::RANK_NINE, Card::SUIT_DIAMONDS));
    Card Ten_spade (Card::RANK_TEN, Card::SUIT_SPADES);
    Card card_played7 = simple7->play_card(Ten_spade , Card::SUIT_SPADES);
    ASSERT_EQUAL(card_played7, Card(Card::RANK_NINE, Card::SUIT_CLUBS));
    delete simple7;
}
    
TEST(test_play_card_simple8){
    Player * simple8 = Player_factory("simple8", "Simple");
    simple8->add_card(Card(Card::RANK_NINE, Card::SUIT_HEARTS));
    Card Ten_spade (Card::RANK_TEN, Card::SUIT_SPADES);
    Card card_played8 = simple8->play_card(Ten_spade , Card::SUIT_SPADES);
    ASSERT_EQUAL(card_played8, Card(Card::RANK_NINE, Card::SUIT_HEARTS));
    delete simple8;
}

TEST(test_play_card_simple9){
    Player * simple9 = Player_factory("simple9", "Simple");
    simple9->add_card(Card(Card::RANK_TEN, Card::SUIT_HEARTS));
    Card ACE_HEART (Card::RANK_ACE, Card::SUIT_HEARTS);
    Card card_played9 = simple9->play_card(ACE_HEART, Card::SUIT_HEARTS);
    ASSERT_EQUAL(card_played9, Card(Card::RANK_TEN, Card::SUIT_HEARTS));
    delete simple9;
}

TEST(test_play_card_simple3){
    Player * simple3 = Player_factory("simple3", "Simple");
    simple3->add_card(Card(Card::RANK_JACK, Card::SUIT_SPADES));
    simple3->add_card(Card(Card::RANK_NINE, Card::SUIT_CLUBS));
    simple3->add_card(Card(Card::RANK_TEN, Card::SUIT_CLUBS));
    Card QUEEN_CLUBES(Card::RANK_QUEEN, Card::SUIT_CLUBS);
    Card card_played3 = simple3->play_card(
      QUEEN_CLUBES,
      Card::SUIT_CLUBS
    );
    ASSERT_EQUAL(card_played3, Card(Card::RANK_JACK, Card::SUIT_SPADES));
    delete simple3;
}

TEST(test_play_card_simple10){
    Player * simple10 = Player_factory("simple10", "Simple");
    simple10->add_card(Card(Card::RANK_JACK, Card::SUIT_SPADES));
    simple10->add_card(Card(Card::RANK_NINE, Card::SUIT_HEARTS));
    simple10->add_card(Card(Card::RANK_TEN, Card::SUIT_CLUBS));
    Card QUEEN_HEART(Card::RANK_QUEEN, Card::SUIT_HEARTS);
    Card card_played10 = simple10->play_card(
      QUEEN_HEART,
      Card::SUIT_HEARTS
    );
    ASSERT_EQUAL(card_played10, Card(Card::RANK_NINE, Card::SUIT_HEARTS));
    delete simple10;
}
 
TEST(test_play_card_simple11){
    Player * simple11 = Player_factory("simple11", "Simple");
    simple11->add_card(Card(Card::RANK_JACK, Card::SUIT_SPADES));
    simple11->add_card(Card(Card::RANK_JACK, Card::SUIT_CLUBS));
    simple11->add_card(Card(Card::RANK_TEN, Card::SUIT_CLUBS));
    Card QUEEN_CLUBS(Card::RANK_QUEEN, Card::SUIT_CLUBS);
    Card card_played11 = simple11->play_card(
         QUEEN_CLUBS,
         Card::SUIT_CLUBS
    );
    ASSERT_EQUAL(card_played11, Card(Card::RANK_JACK, Card::SUIT_CLUBS));
    delete simple11;
}

TEST(test_play_card_simple12){
    Player * simple12 = Player_factory("simple12", "Simple");
    simple12->add_card(Card(Card::RANK_JACK, Card::SUIT_SPADES));
    simple12->add_card(Card(Card::RANK_JACK, Card::SUIT_DIAMONDS));
    simple12->add_card(Card(Card::RANK_TEN, Card::SUIT_CLUBS));
    Card QUEEN_Heart(Card::RANK_QUEEN, Card::SUIT_HEARTS);
    Card card_played12 = simple12->play_card(
         QUEEN_Heart,
         Card::SUIT_CLUBS
    );
    ASSERT_EQUAL(card_played12, Card(Card::RANK_JACK, Card::SUIT_DIAMONDS));
    delete simple12;
}

TEST(test_play_card_simple13){
    Player * simple13 = Player_factory("simple13", "Simple");
    simple13->add_card(Card(Card::RANK_TEN, Card::SUIT_SPADES));
    simple13->add_card(Card(Card::RANK_JACK, Card::SUIT_DIAMONDS));
    simple13->add_card(Card(Card::RANK_QUEEN, Card::SUIT_CLUBS));
    Card QUEEN_SPADES(Card::RANK_QUEEN, Card::SUIT_SPADES);
    Card card_played13 = simple13->play_card(
         QUEEN_SPADES,
         Card::SUIT_CLUBS
    );
    
    ASSERT_EQUAL(card_played13, Card(Card::RANK_TEN, Card::SUIT_SPADES));
    delete simple13;
}

TEST(test_play_card_simple14){
    Player * simple14 = Player_factory("simple14", "Simple");
    simple14->add_card(Card(Card::RANK_JACK, Card::SUIT_HEARTS));
    Card ACE_DIomand(Card::RANK_ACE, Card::SUIT_DIAMONDS);
    Card card_played14 = simple14->play_card(ACE_DIomand, Card::SUIT_DIAMONDS);
    ASSERT_EQUAL(card_played14, Card(Card::RANK_JACK, Card::SUIT_HEARTS));
    delete simple14;
}

TEST(test_play_card_simple15){
    Player * simple15 = Player_factory("simple15", "Simple");
    simple15->add_card(Card(Card::RANK_JACK, Card::SUIT_HEARTS));
    simple15->add_card(Card(Card::RANK_JACK, Card::SUIT_DIAMONDS));
    Card ACE_DIomand(Card::RANK_ACE, Card::SUIT_DIAMONDS);
    Card card_played15 = simple15->play_card(ACE_DIomand, Card::SUIT_HEARTS);
    ASSERT_EQUAL(card_played15, Card(Card::RANK_JACK, Card::SUIT_DIAMONDS));
    delete simple15;
}

TEST(test_play_card_simple16){
    Player * simple16 = Player_factory("simple16", "Simple");
    simple16->add_card(Card(Card::RANK_JACK, Card::SUIT_HEARTS));
    simple16->add_card(Card(Card::RANK_JACK, Card::SUIT_DIAMONDS));
    Card QUEEN_Heart(Card::RANK_QUEEN, Card::SUIT_HEARTS);
    Card card_played16 = simple16->play_card(QUEEN_Heart, Card::SUIT_HEARTS);
    ASSERT_EQUAL(card_played16, Card(Card::RANK_JACK, Card::SUIT_HEARTS));
    delete simple16;
}

TEST(test_play_card_simple17){
    Player * simple17 = Player_factory("simple17", "Simple");
    simple17->add_card(Card(Card::RANK_TEN, Card::SUIT_HEARTS));
    simple17->add_card(Card(Card::RANK_NINE, Card::SUIT_DIAMONDS));
    Card Ace_SPades = Card(Card::RANK_ACE, Card::SUIT_SPADES);
    Card card_played17 = simple17->play_card(Ace_SPades, Card::SUIT_HEARTS);
    ASSERT_EQUAL(card_played17, Card(Card::RANK_NINE, Card::SUIT_DIAMONDS));
    delete simple17;
}

TEST(test_play_card_simple18){
    Player * simple18 = Player_factory("simple18", "Simple");
    simple18->add_card(Card(Card::RANK_JACK, Card::SUIT_HEARTS));
    simple18->add_card(Card(Card::RANK_QUEEN, Card::SUIT_DIAMONDS));
    Card Ace_SPades = Card(Card::RANK_ACE, Card::SUIT_SPADES);
    Card card_played18 = simple18->play_card(Ace_SPades, Card::SUIT_HEARTS);
    ASSERT_EQUAL(card_played18, Card(Card::RANK_QUEEN, Card::SUIT_DIAMONDS));
    delete simple18;
}
    
TEST(test_play_card_simple19){
    Player * simple19 = Player_factory("simple19", "Simple");
    simple19->add_card(Card(Card::RANK_JACK, Card::SUIT_HEARTS));
    simple19->add_card(Card(Card::RANK_NINE, Card::SUIT_DIAMONDS));
    Card Ace_SPades = Card(Card::RANK_ACE, Card::SUIT_SPADES);
    Card card_played19 = simple19->play_card(Ace_SPades, Card::SUIT_HEARTS);
    ASSERT_EQUAL(card_played19, Card(Card::RANK_NINE, Card::SUIT_DIAMONDS));
    delete simple19;
}

TEST(test_play_card_simple20){
    Player * simple20 = Player_factory("simple20", "Simple");
    simple20->add_card(Card(Card::RANK_JACK, Card::SUIT_HEARTS));
    simple20->add_card(Card(Card::RANK_JACK, Card::SUIT_DIAMONDS));
    Card Ace_SPades = Card(Card::RANK_ACE, Card::SUIT_SPADES);
    Card card_played20 = simple20 -> play_card(Ace_SPades, Card::SUIT_SPADES);
    ASSERT_EQUAL(card_played20, Card(Card::RANK_JACK, Card::SUIT_HEARTS));
    delete simple20;
}
TEST(test_play_card_simple21){
    Player * simple21 = Player_factory("simple21", "Simple");
    simple21->add_card(Card(Card::RANK_ACE, Card::SUIT_HEARTS));
    simple21->add_card(Card(Card::RANK_JACK, Card::SUIT_HEARTS));
    Card Ace_SPades = Card(Card::RANK_QUEEN, Card::SUIT_HEARTS);
    Card card_played21 = simple21 -> play_card(Ace_SPades, Card::SUIT_DIAMONDS);
    ASSERT_EQUAL(card_played21, Card(Card::RANK_ACE, Card::SUIT_HEARTS));
    delete simple21;
}


TEST_MAIN()

