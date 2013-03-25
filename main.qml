/*!
 * \brief:  main.qml
 * \author: godbod
 */

import QtQuick 1.0

Rectangle
{
    color: "black"
    height: 700
    width:  700

    rotation: 180
    smooth: true

    Image
    {
        height: 40
        width:  40
        x:350
        y:myCounter.counter
        id: name
        rotation: 180
        source: "./godbod.png"
        smooth: true
    }
}
