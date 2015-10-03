/*
 * MomentumImageChooser.h
 *
 *  Created on: Oct 24, 2014
 *      Author: SuhairZain
 */

#ifndef MOMENTUMIMAGECHOOSER_H_
#define MOMENTUMIMAGECHOOSER_H_

#include <bb/cascades/Color>
#include <bb/cascades/Container>

using namespace bb::cascades;

class MomentumSetterThumb: public Container
{
Q_OBJECT
signals:
    void tapped(int);
private slots:
    void onTapped();
public:
    MomentumSetterThumb(int, Color, bool isSelected=FALSE);
private:
    Color paddingColor;
    int number;
};

#endif /* MOMENTUMIMAGECHOOSER_H_ */
