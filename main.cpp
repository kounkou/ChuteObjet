/*!
 * \brief:  main.cpp
 * \author: godbod
 */

#include <QApplication>
#include "Counter.h"
#include <QDeclarativeView>
#include <QDeclarativeContext>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    // Déclaration de la vue QML
    QDeclarativeView *view = new QDeclarativeView();
    Counter *c1 = new Counter();

    // recuperation du context
    QDeclarativeContext *ctxt = view->rootContext();
    // liaison entre le BE et le FE
    ctxt->setContextProperty("myCounter", c1);
    view->setSource(QUrl::fromLocalFile("./main.qml"));

    // affichage
    view->show();

    return app.exec();
}
