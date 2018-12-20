/*!
 * \brief:  Counter.cpp
 * \author: godbod
 */

#include "Counter.h"

const float elasticity = 0.95;

Counter::Counter(QObject *parent) : QObject(parent)
{
    // initialisation des propriétés
    m_counter = 0;
    temps1 = 0;
    temps2 = 0;
    flagChuteLibre = true;
    // hauteur de la chute en metre
    h0 = 500;
    E = elasticity;
    g = 9.99;

    QObject::connect(&timer, SIGNAL(timeout()), this, SLOT(doTheStuff()));
    timer.start(25);
}

// Je pense qu'on peut faire mieux !!!
void Counter::doTheStuff()
{
    // On commence toujours par une chute libre
    if((h0 - elasticity * g * temps1*temps1) > 0) {
        setCounter(h0-E*g*pow(temps1,2));
        temps1 = temps1 + 0.25;
    } else if((h0 - elasticity * g * temps1 * temps1) < 0) {
        flagChuteLibre = false;
    }

    // on peut donc faire un premier rebond
    if (flagChuteLibre == false) {
        if ((E*sqrt(2 * g * h0) * temps2 - elasticity * g * pow(temps2, 2)) >= 0) {
            setCounter(E*sqrt(2 * g * h0)*temps2 - elasticity * g * pow(temps2, 2));
            temps2 = temps2 + 0.25;
        } else {
            // On continue les rebonds...
            h0 = pow(E,2)*h0;
            if(h0 == 0) {
                exit(0);
            }
            temps2 = 0;
        }
    }
}

float Counter::getCounter()
{
    return m_counter;
}

void Counter::setCounter(float c)
{
    if (c != m_counter)
    {
        m_counter = c;
        emit counterUpdated();
    }
}
