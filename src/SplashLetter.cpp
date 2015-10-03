/*
 * SplashLetter.cpp
 *
 *  Created on: Oct 20, 2014
 *      Author: SuhairZain
 */

#include <src/SplashLetter.h>

#include <bb/cascades/Container>
#include <bb/cascades/DockLayout>
#include <bb/cascades/FadeTransition>
#include <bb/cascades/ImageView>
#include <bb/cascades/ParallelAnimation>
#include <bb/cascades/TranslateTransition>

SplashLetter::SplashLetter(QChar l, int d)
{
    ImageView *letterImage = ImageView::create().
            horizontal(HorizontalAlignment::Center).
            vertical(VerticalAlignment::Center).
            image(Image("asset:///images/splash/" + QString(l) + ".png")).
            opacity(0.1).
            tx(-50);

    FadeTransition *fadeIn = FadeTransition::create(letterImage).
            duration(500).
            to(1);

    TranslateTransition *moveIn = TranslateTransition::create(letterImage).
            duration(500).
            toX(0);

    ParallelAnimation *comboAnim = ParallelAnimation::create(letterImage).
            parent(this).
            delay(d).
            add(fadeIn).
            add(moveIn);

    Container *rootC = Container::create().
            layout(DockLayout::create()).
            add(letterImage);

    setRoot(rootC);

    comboAnim->play();
}

