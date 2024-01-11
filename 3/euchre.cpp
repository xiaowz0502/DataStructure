#include <iostream>
#include "Card.h"
#include "Pack.h"
#include "Player.h"
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;


// Project UID 1d9f47bfc76643019cfbf037641defe1
class Game{
public:
    void shuffle(ifstream& pack_input, char *argv[]);
    void Playersetting(char *argv[]);
    void Deal();
    bool makeTrumpRoundOne();
    void makeTrumpRoundTwo();
    void addThreeCard(int Playernumber1);
    void addTwoCard(int Playernumber2);
    void addCardRound();
    bool dealercheck(int possiblePlayer);
    void trickTakingOneRound();
    void trickTakingAfterOneRound();
    void scoreCalculator();
    void deletePlayer();
    void printBeginning();
    void printWinner();
    void printScore();
    bool scoreOver(char *argv[]);
    void end();
    void handIncrease();
    void resetTricks();
    void shuffleCheck(char *argv[]);
    void printTitle(char *argv[]);
    
    
private:
    Pack playpack;
    vector<Player*> gamePlayer;
    int turn = 0;
    Card upCard;
    string order_up_suit;
    int PersonOrderup;
    int PersonNextled;
    int TrumpTeamTricks = 0;
    int NontrumpTeamTricks = 0;
    int TrumpTeamScore = 0;
    int NontrumpTeamScore = 0;
    int standardScore = 0;
    int dealer = turn % 4;
    int team02 = 0;
    int team13 = 0;
};

bool styleCheck(int argc, char *argv[]);
bool fileOpenCheck(ifstream& input,char *argv[]);
int const playerSize = 4;

int main(int argc, char *argv[]){
    Game game;
    if (styleCheck(argc,argv) == false){return 1;}
    game.printTitle(argv);
    ifstream input;
    input.open(argv[1]);
    game.Playersetting(argv);
    if (fileOpenCheck(input,argv) == false){return 1;}
    game.shuffle(input, argv);
    while (!game.scoreOver(argv)){
    game.shuffleCheck(argv);
    game.Deal();
    game.printBeginning();
        if (game.makeTrumpRoundOne()== false){
            game.makeTrumpRoundTwo();
        }
        cout << endl;
    game.trickTakingOneRound(); cout << endl;
    game.trickTakingAfterOneRound(); cout << endl;
    game.trickTakingAfterOneRound(); cout << endl;
    game.trickTakingAfterOneRound(); cout << endl;
    game.trickTakingAfterOneRound(); cout << endl;
    game.handIncrease();
    game.scoreCalculator();
    game.printWinner();
    game.printScore(); cout << endl;
    game.resetTricks();
    }
    game.end();
    game.deletePlayer();
    return 0;
}


bool styleCheck(int argc, char *argv[]){
    if ((argc != 12 || atoi(argv[3]) < 1 || atoi(argv[3]) > 100)){
        cout << "Usage: euchre.exe PACK_FILENAME [shuffle|noshuffle] "
             << "POINTS_TO_WIN NAME1 TYPE1 NAME2 TYPE2 NAME3 TYPE3 "
             << "NAME4 TYPE4" << endl;
        return false;
        
    }
    else if (string (argv[2]) != "shuffle" && string (argv[2]) != "noshuffle"){
        cout << "Usage: euchre.exe PACK_FILENAME [shuffle|noshuffle] "
             << "POINTS_TO_WIN NAME1 TYPE1 NAME2 TYPE2 NAME3 TYPE3 "
             << "NAME4 TYPE4" << endl;
        return false;
    }
    
    else if(string(argv[5]) != "Simple" && string(argv[5]) != "Human"){
        cout << "Usage: euchre.exe PACK_FILENAME [shuffle|noshuffle] "
             << "POINTS_TO_WIN NAME1 TYPE1 NAME2 TYPE2 NAME3 TYPE3 "
             << "NAME4 TYPE4" << endl;
        return false;
    }
    else if(string(argv[7]) != "Simple" && string(argv[7]) != "Human"){
        cout << "Usage: euchre.exe PACK_FILENAME [shuffle|noshuffle] "
             << "POINTS_TO_WIN NAME1 TYPE1 NAME2 TYPE2 NAME3 TYPE3 "
             << "NAME4 TYPE4" << endl;
        return false;
    }
    else if(string(argv[9]) != "Simple" && string(argv[9]) != "Human"){
        cout << "Usage: euchre.exe PACK_FILENAME [shuffle|noshuffle] "
             << "POINTS_TO_WIN NAME1 TYPE1 NAME2 TYPE2 NAME3 TYPE3 "
             << "NAME4 TYPE4" << endl;
        return false;
    }
    else if(string(argv[11]) != "Simple" && string(argv[11]) != "Human"){
        cout << "Usage: euchre.exe PACK_FILENAME [shuffle|noshuffle] "
             << "POINTS_TO_WIN NAME1 TYPE1 NAME2 TYPE2 NAME3 TYPE3 "
             << "NAME4 TYPE4" << endl;
        return false;
    }
    return true;
}

bool fileOpenCheck(ifstream& input, char *argv[]){
    if (!input.is_open()){
        cout << "Error opening " << string(argv[1]) << endl;
        return false;
    }
    else{
        return true;
    }
}

void Game:: shuffle(ifstream& pack_input, char *argv[]){
    playpack.reset();
    playpack = Pack(pack_input);
    if (string(argv[2]) == "shuffle"){
        playpack.shuffle();
    }
}

void Game::Playersetting(char *argv[]){
    gamePlayer.push_back(Player_factory(string(argv[4]), string(argv[5])));
    gamePlayer.push_back(Player_factory(string(argv[6]), string(argv[7])));
    gamePlayer.push_back(Player_factory(string(argv[8]), string(argv[9])));
    gamePlayer.push_back(Player_factory(string(argv[10]), string(argv[11])));
}

void Game::addThreeCard(int Playernumber1){
    gamePlayer[Playernumber1]->add_card(playpack.deal_one());
    gamePlayer[Playernumber1]->add_card(playpack.deal_one());
    gamePlayer[Playernumber1]->add_card(playpack.deal_one());
}

void Game::addTwoCard(int Playernumber2){
    gamePlayer[Playernumber2]->add_card(playpack.deal_one());
    gamePlayer[Playernumber2]->add_card(playpack.deal_one());
}

void Game::addCardRound(){
    addThreeCard((turn + 1) % 4);
    addTwoCard((turn + 2) % 4);
    addThreeCard((turn + 3) % 4);
    addTwoCard(turn % 4);
    
    addTwoCard((turn + 1) % 4);
    addThreeCard((turn + 2) % 4);
    addTwoCard((turn + 3) % 4);
    addThreeCard(turn % 4);
}

void Game::Deal(){
    playpack.reset();
    addCardRound();
    upCard = playpack.deal_one();
}

bool Game::dealercheck(int possiblePlayer){
    int number = turn % 4;
    if (possiblePlayer != number){
        return false;
    }
    return true;
}

bool Game::makeTrumpRoundOne(){
    for (int i = 1; i < playerSize + 1; i++){
        if (gamePlayer[(dealer + i)% 4]->make_trump(upCard,
            dealercheck((dealer + i) % 4), 1, order_up_suit)){
            cout << gamePlayer[(dealer + i) % 4]->get_name()
            << " orders up "
            << upCard.get_suit()<<endl;
            gamePlayer[dealer % 4]->add_and_discard(upCard);
            PersonOrderup = (dealer + i) % 4;
            return true;
        }
        else{
            cout << gamePlayer[(dealer + i) % 4]->get_name()<<" passes" << endl;
        }
    }
    return false;
}

void Game::makeTrumpRoundTwo(){
    for (int i = 1; i < playerSize + 1; i++){
        if (gamePlayer[(dealer + i) % 4]->make_trump(upCard,
            dealercheck((dealer + i) % 4), 2, order_up_suit)){
            PersonOrderup = (dealer + i) % 4;
            cout << gamePlayer[(dealer + i) % 4]->get_name()
            << " orders up "
            << order_up_suit<<endl;
            break;
        }
        else{
            cout << gamePlayer[(dealer + i) % 4]->get_name()<<" passes" << endl;
        }
    }
}

void Game::trickTakingOneRound(){
    Card cardArray[4];
    cardArray[0] = gamePlayer[(turn % 4 + 1) % 4]->lead_card(order_up_suit);
    cout <<cardArray[0]<<" led by " << gamePlayer[(turn % 4 + 1) % 4]->get_name()<<endl;
    
    cardArray[1] = gamePlayer[(turn % 4 + 2) % 4]->play_card(cardArray[0], order_up_suit);
    cout <<cardArray[1]<<" played by "
    << gamePlayer[(turn % 4 + 2) % 4]->get_name()<<endl;
    
    cardArray[2] = gamePlayer[(turn % 4 + 3) % 4]->play_card(cardArray[0], order_up_suit);
    cout<<cardArray[2]<<" played by " <<gamePlayer[(turn % 4 + 3) % 4]->get_name()<<endl;
    
    cardArray[3] = gamePlayer[(turn % 4)]->play_card(cardArray[0], order_up_suit);
    cout<<cardArray[3]<<" played by " <<gamePlayer[(turn % 4)]->get_name()<<endl;
    
    Card mostValuedCard = cardArray[0];
    int cardWinnerNumber = (turn % 4 + 1) % 4;
    
    for (int i = 0; i < 4; i ++){
        if (Card_less(mostValuedCard,  cardArray[i],  cardArray[0], order_up_suit)){
            mostValuedCard = cardArray[i];
            cardWinnerNumber = (turn % 4 + i + 1) % 4;
        }
    }
    if (cardWinnerNumber != PersonOrderup && cardWinnerNumber != (PersonOrderup + 2) % 4){
        NontrumpTeamTricks = NontrumpTeamTricks + 1;
    }
    else{
        TrumpTeamTricks = TrumpTeamTricks + 1;
    }
    cout<<gamePlayer[cardWinnerNumber]->get_name()<<" takes the trick"<<endl;
    PersonNextled = cardWinnerNumber;
}

void Game::trickTakingAfterOneRound(){
    Card cardArray[4];
    cardArray[0] = gamePlayer[PersonNextled]->lead_card(order_up_suit);
    cout<<cardArray[0]<<" led by "<<gamePlayer[PersonNextled]->get_name()<<endl;
    
    cardArray[1] =
    gamePlayer[(PersonNextled + 1) % 4]
    ->play_card(cardArray[0], order_up_suit);
    cout<<cardArray[1]<<" played by "
    <<gamePlayer[(PersonNextled + 1) % 4]->get_name()<<endl;
    
    cardArray[2] = gamePlayer[(PersonNextled + 2) % 4]
    ->play_card(cardArray[0], order_up_suit);
    cout<<cardArray[2]<<" played by "
    <<gamePlayer[(PersonNextled + 2) % 4]->get_name()<<endl;
    cardArray[3] = gamePlayer[(PersonNextled + 3) % 4]
    ->play_card(cardArray[0], order_up_suit);
    cout<<cardArray[3]<<" played by "
    <<gamePlayer[(PersonNextled + 3) % 4]->get_name()<<endl;
    Card mostValuedCard = cardArray[0];
    int cardWinnerNumber = PersonNextled;
    for (int i = 0; i < 4; i ++){
        bool b = Card_less(mostValuedCard,  cardArray[i],  cardArray[0], order_up_suit);
        if (b){
            mostValuedCard = cardArray[i];
            cardWinnerNumber = (PersonNextled + i) % 4;
        }
    }
    PersonNextled = cardWinnerNumber;
    
    if (cardWinnerNumber != PersonOrderup && cardWinnerNumber != (PersonOrderup + 2) % 4){
        NontrumpTeamTricks = NontrumpTeamTricks + 1;
    }
    else{
        TrumpTeamTricks = TrumpTeamTricks + 1;
    }
    cout<<gamePlayer[PersonNextled]->get_name()<<" takes the trick"<<endl;
}


void Game::scoreCalculator(){
    
    
    if(PersonOrderup == 0 || PersonOrderup == 2){
        if (TrumpTeamTricks == 3 || TrumpTeamTricks == 4){
            team02 = team02 + 1;
            TrumpTeamScore = TrumpTeamScore + 1;
        }
        if(TrumpTeamTricks == 5){
            team02 = team02 + 2;
            TrumpTeamScore = TrumpTeamScore + 2;
        }
        if (NontrumpTeamTricks >= 3){
            team13 = team13 + 2;
            NontrumpTeamScore = NontrumpTeamScore + 2;
            
        }
    }
    else{
        if (TrumpTeamTricks == 3 || TrumpTeamTricks == 4){
            team13 = team13 + 1;
            TrumpTeamScore = TrumpTeamScore + 1;
        }
        if(TrumpTeamTricks == 5){
            team13 = team13 + 2;
            TrumpTeamScore = TrumpTeamScore + 2;
        }
        if (NontrumpTeamTricks >= 3){
            team02 = team02 + 2;
            NontrumpTeamScore = NontrumpTeamScore + 2;
        }
    }
    
}


void Game::deletePlayer(){
    for (int i = 0; i < 4; ++i) {
      delete gamePlayer[i];
    }
}

void Game::printBeginning(){
    cout << "Hand " << turn <<endl;
    cout << gamePlayer[turn % 4]->get_name()<<" deals" << endl;
    cout << upCard <<" turned up"<<endl;
}

void Game::printWinner(){
    if(PersonOrderup == 0 || PersonOrderup == 2){
        if (TrumpTeamTricks > NontrumpTeamTricks){
                cout << gamePlayer[0]->get_name()<< " and "
            <<gamePlayer[2]->get_name()<<" win the hand"<<endl;
            if (TrumpTeamTricks == 5){
                cout << "march!"<<endl;
            }
        }
        else{
            cout << gamePlayer[1]->get_name()<< " and "
            <<gamePlayer[3]->get_name()<<" win the hand"<<endl;
            if (NontrumpTeamTricks == 3
                ||NontrumpTeamTricks == 4
                || NontrumpTeamTricks == 5){
                cout << "euchred!"<<endl;
            }
        }
    }
    else{
        if (TrumpTeamTricks > NontrumpTeamTricks){
                cout << gamePlayer[1]->get_name()<< " and "
            <<gamePlayer[3]->get_name()<<" win the hand"<<endl;
            if (TrumpTeamTricks == 5){
                cout << "march!"<<endl;
            }
        }
        else{
            cout << gamePlayer[0]->get_name()<< " and "
            <<gamePlayer[2]->get_name()<<" win the hand"<<endl;
            if (NontrumpTeamTricks == 3
                ||NontrumpTeamTricks == 4
                || NontrumpTeamTricks == 5){
                cout << "euchred!"<<endl;
            }
        }
    }
}

void Game::printScore(){
    if (PersonOrderup == 1 || PersonOrderup == 3){
        cout << gamePlayer[0]->get_name()
        <<" and "<<gamePlayer[2]->get_name()
        <<" have "<<team02<<" points"<<endl;
        cout << gamePlayer[1]->get_name()
        <<" and "<<gamePlayer[3]->get_name()
        <<" have "<<team13<<" points"<<endl;
    }
    else if(PersonOrderup == 0 || PersonOrderup == 2){
        cout << gamePlayer[0]->get_name()
        <<" and "<<gamePlayer[2]->get_name()
        <<" have "<<team02<<" points"<<endl;
        cout << gamePlayer[1]->get_name()
        <<" and "<<gamePlayer[3]->get_name()
        <<" have "<<team13<<" points"<<endl;
    }
}

bool Game::scoreOver(char *argv[]){
    standardScore = atoi(argv[3]);
    if (team02 >= standardScore || team13 >=standardScore){
        return true;
    }
    return false;
}

void Game::end(){
    if (team02 > team13){
            cout << gamePlayer[0]->get_name()<< " and "
                <<gamePlayer[2]->get_name()<<" win!"<<endl;
        }
    else{
            cout << gamePlayer[1]->get_name()<< " and "
            <<gamePlayer[3]->get_name()<<" win!"<<endl;
        }
}

void Game::handIncrease(){
    turn = turn + 1;
    dealer = turn % 4;
}

void Game::resetTricks(){
    TrumpTeamTricks = 0;
    NontrumpTeamTricks = 0;
}

void Game::shuffleCheck(char *argv[]){
    if (turn > 0 && string(argv[2]) == "shuffle"){
        playpack.shuffle();
    }
}


void Game::printTitle(char *argv[]){
    cout << "./euchre.exe pack.in " << string(argv[2])<<" "<< atoi(argv[3])<<" ";
    cout << string(argv[4])<<" "<<string(argv[5]) << " ";
    cout<< string(argv[6]) <<" "<< string(argv[7]) << " ";
    cout<< string(argv[8])<<" "<<string(argv[9]) << " ";
    cout<< string(argv[10])<<" "<<string(argv[11]) << " ";
    cout << endl;
}
