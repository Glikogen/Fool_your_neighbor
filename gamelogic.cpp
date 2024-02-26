#include "gamelogic.h"
#include "CardsValues.h"


GameLogic::GameLogic(QObject *parent)
    : QObject{parent}
{

}

void GameLogic::startGame(int players, int cards)
{
    int amountOfPlayers = players;
    int amountOfCards = cards;

    qDebug() << "players = " << players << " and cards = " << cards;

    QList<Card*> newDeck;

    //создаем упорядоченную колоду, заполняем сначала каждую масть (4 масти, 12 величин)
    int start_value = amountOfCards == 36 ? 4 : 0;

    for(int suit = 0; suit < 4; suit++){
        for(int value = start_value; value < 13; value++){
            Card *card = new Card(static_cast<CardSuit>(suit), static_cast<CardValue>(value));
            newDeck.push_back(card);
        }
    }

    //размещиваем колоду
    QList<Card*> Deck;
    for(int i = 0; i < amountOfCards; i++) {
        int randIndex = QRandomGenerator::global()->bounded(0, newDeck.count());
        Card *randomCard = newDeck.at(randIndex);
        Deck.append(randomCard);
        newDeck.removeAt(randIndex);
    }

    QList<Card*> player1Deck;
    QList<Card*> player2Deck;
    QList<Card*> player3Deck;
    QList<Card*> player4Deck;

    for(int i = 0; i < amountOfCards; i++) {
        //поочередно раздаем карты игрокам
        switch (i%amountOfPlayers) {
        case 0:
            player1Deck.append(Deck.at(i));
            break;
        case 1:
            player2Deck.append(Deck.at(i));
            break;
        case 2:
            player3Deck.append(Deck.at(i));
            break;
        case 3:
            player4Deck.append(Deck.at(i));
            break;
        }
    }

    qDebug() << "у игрока №1 следующие карты:";//карты 1го игрока
    for(int i = 0; i < player1Deck.count(); i++){
        qDebug() << "\t" << player1Deck.at(i)->StringValue() << " " << player1Deck.at(i)->StringSuit();
    }

    qDebug() << "у игрока №2 следующие карты:";//карты 2го игрока
    for(int i = 0; i < player2Deck.count(); i++){
        qDebug() << "\t" << player2Deck.at(i)->StringValue() << " " << player2Deck.at(i)->StringSuit();
    }

    qDebug() << "у игрока №3 следующие карты:";//карты 3го игрока
    for(int i = 0; i < player3Deck.count(); i++){
        qDebug() << "\t" << player3Deck.at(i)->StringValue() << " " << player3Deck.at(i)->StringSuit();
    }

    qDebug() << "у игрока №4 следующие карты:";//карты 4го игрока
    for(int i = 0; i < player4Deck.count(); i++){
        qDebug() << "\t" << player4Deck.at(i)->StringValue() << " " << player4Deck.at(i)->StringSuit();
    }


}
