#ifndef CARDSVALUES_H
#define CARDSVALUES_H

#include <QObject>
#include <QDebug>

enum CardSuit {
    Spades,
    Clubs,
    Hearts,
    Diamonds
};

enum CardValue {
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    Ace
};

class Card {
public:
    Card(CardSuit suit, CardValue value) {
        Suit = suit;
        Value = value;
    }

    CardSuit Suit;
    CardValue Value;

    QString StringSuit() {
        QString result;
        switch (Suit) {
        case CardSuit::Clubs:
            result = "Clubs";
            break;
        case CardSuit::Diamonds:
            result = "Diamonds";
            break;
        case CardSuit::Hearts:
            result = "Hearts";
            break;
        case CardSuit::Spades:
            result = "Spades";
            break;
        }

        return result;
    }

    QString StringValue() {
        QString result;
        switch (Value) {
        case CardValue::Two:
            result = "Two";
            break;
        case CardValue::Three:
            result = "Three";
            break;
        case CardValue::Four:
            result = "Four";
            break;
        case CardValue::Five:
            result = "Five";
            break;
        case CardValue::Six:
            result = "Six";
            break;
        case CardValue::Seven:
            result = "Seven";
            break;
        case CardValue::Eight:
            result = "Eight";
            break;
        case CardValue::Nine:
            result = "Nine";
            break;
        case CardValue::Ten:
            result = "Ten";
            break;
        case CardValue::Jack:
            result = "Jack";
            break;
        case CardValue::Queen:
            result = "Queen";
            break;
        case CardValue::King:
            result = "King";
            break;
        case CardValue::Ace:
            result = "Ace";
            break;
        }

        return result;
    }

    //в консоли Qt Creatora не работает
    QString PrettyStringSuit() {
        QString result;
        switch (Suit) {
        case CardSuit::Clubs:
            result = "♣";
            break;
        case CardSuit::Diamonds:
            result = "♦";
            break;
        case CardSuit::Hearts:
            result = "♥";
            break;
        case CardSuit::Spades:
            result = "♠";
            break;
        }

        return result;
    }
};

#endif // CARDSVALUES_H
