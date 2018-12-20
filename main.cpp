/*!
 * \brief:  main.cpp
 * \author: godbod
 */

#include <QGuiApplication>
#include "Counter.h"
#include <QQuickView>
#include <QQmlContext>

int main(int argc, char **argv)
{
    QGuiApplication app(argc, argv);

    // Déclaration de la vue QML
    QQuickView* view = new QQuickView();
    Counter *c1 = new Counter();

    // recuperation du context
    QQmlContext *ctxt = view->rootContext();
    // liaison entre le BE et le FE
    ctxt->setContextProperty("myCounter", c1);
    view->setSource(QUrl("qrc:/main.qml"));

    // affichage
    view->show();

    return app.exec();
}
