/*
 * MomentumImageChooser.cpp
 *
 *  Created on: Oct 24, 2014
 *      Author: SuhairZain
 */

#include <src/Pages/MomentumSetterThumb.h>

#include <bb/cascades/ImageView>
#include <bb/cascades/TapHandler>

MomentumSetterThumb::MomentumSetterThumb(int num, Color pColor, bool isSelected)
{
    number = num;
    paddingColor = pColor;

    TapHandler *thumbTap = TapHandler::create().
            onTapped(this, SLOT(onTapped()));

    ImageView *image = ImageView::create().
            image(Image("asset:///images/wallpapers/thumbs/" + QString::number(num) + ".png")).
            addGestureHandler(thumbTap);
    this->add(image);
    this->setLeftPadding(6);
    this->setTopPadding(6);
    this->setRightPadding(6);
    this->setBottomPadding(6);

    if(isSelected)
        this->setBackground(paddingColor);
}

void MomentumSetterThumb::onTapped()
{
    emit tapped(number);
    this->setBackground(paddingColor);
}
