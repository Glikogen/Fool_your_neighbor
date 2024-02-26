#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "gamelogic.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/CardGame/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);

    qmlRegisterType<GameLogic>("GameLogic",1,0,"GameLogic");

    engine.load(url);

    return app.exec();
}
