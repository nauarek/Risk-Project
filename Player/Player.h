#pragma once
#include "Cards.h"
#include "map.h"
#include "Orders.h"
#include "PlayerStrategies.h"
//#include "../Orders/Orders.h"
#include <iostream>
#include <vector>
using namespace std;

// Forward declarations
class Deck;
class Hand;
class Card;
class Territory;
class Map;
class OrdersLists;
class Order;
class PlayerStrategy;

///////////////////////////////// PLAYER /////////////////////////////////////

class Player {
private:
    static int* playerCount; // player count AND id
    int* id;
    string* name;
    Hand* hand;
    Deck* deck;
    OrdersLists* orders;
    vector<Territory*> territories;

    //Part 3 Abdur & Nauar
    int* reinforcements;
    vector<Player*> negotiations;
    bool* receivedCard;

    //Part 4
    PlayerStrategy* ps; //object of PlayerStrategy class

public:
    // CONSTRUCTOR
    Player(string* pName);

    //COPY CONSTRUCTOR
    Player(const Player& copyPlayer);

    // ASSIGNMENT OPERATOR
    Player &operator=(const Player &e);

    // STREAM INSERTION OPERATOR
    friend ostream &operator<<(ostream &out, const Player &player);

    // GETTERS
    int* getId();
    string* getName();
    Hand* getHand();
    OrdersLists* getOrders();
    vector<Territory*> getTerritories();

    //Part 3 Abdur & Nauar
    int* getReinforcements();

    vector<Player*> getNegotiations();
    bool* getReceivedCard();

    // SETTERS
    // void setPlayerCount(int playerCount);
    void setId(int newId);
    void setName(string* newName);
    void setHand(Hand* newHand);
    void setDeck(Deck* newDeck);
    void setOrders(OrdersLists* newOrders);
    void setTerritories(vector<Territory*> newTerritories);

    //Part 3 Abdur & Nauar
    void setReinforcements(int noOfReinforcements);
    void setNegotiations(vector<Player*> negotiations);
    void setReceivedCard(bool* boolean);

    //Part 4
    void removeTerritory(Territory* removeTerr);
    void setPlayerStrategy(PlayerStrategy* playerStrategy);
    PlayerStrategy* getPlayerStrategy();


    // OTHER
    void addTerritory(Territory* newTerr);
//    vector<Territory*> toAttack(Territory* source);
//    vector<Territory*> toDefend(Territory* source);
    vector<Order*> issueOrder();
    void resetRoundInfo();      // A3 P2 Amanda
    bool* hasTerritories();     // A3 P2 Amanda

    //PlayerStragey patterns
//    void issueOrder(ps->issueOrder);
//    void toAttack(ps->toAttack);
//    void toDefend(ps->toDefend);

    // DESTRUCTOR
    ~Player();
};