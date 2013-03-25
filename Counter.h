/*!
 * \brief:  Counter.h
 * \author: godbod
 */

#ifndef COUNTER_H
#define COUNTER_H

#include <QObject>
#include <iostream>
#include <math.h>
#include <QTimer>
#include <stdlib.h>

using namespace std;

#define DEBUG_DEMO_COUNTER 0
#undef  DEBUG_DEMO_COUNTER

class Counter : public QObject
{
    Q_OBJECT

    // Q_PROPERTY lu depuis le QML
    Q_PROPERTY(float counter READ getCounter WRITE setCounter NOTIFY counterUpdated)

public:
    explicit Counter(QObject *parent = 0);
    float getCounter();
    void setCounter(float);

signals:
    void counterUpdated();

public slots:
    void doTheStuff();

private:
    float m_counter;
    float temps1;
    float temps2;
    QTimer timer;
    float E;
    float g;
    float h0;
    //artifice
    bool flagChuteLibre;
};

#endif // COUNTER_H
