#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <QObject>
#include <QDebug>
#include <QRandomGenerator64>
#include <QDebug>

class GameLogic : public QObject
{
    Q_OBJECT
public:
    explicit GameLogic(QObject *parent = nullptr);

public slots:
    void startGame(int players, int cards);

signals:

};

#endif // GAMELOGIC_H
