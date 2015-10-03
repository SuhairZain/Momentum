/*
 * MomentumIntroPage.cpp
 *
 *  Created on: Oct 23, 2014
 *      Author: SuhairZain
 */

#include <src/Pages/MomentumIntroPage.h>

#include <bb/cascades/Container>
#include <bb/cascades/DockLayout>
#include <bb/cascades/ImageButton>
#include <bb/cascades/Label>
#include <bb/cascades/StackLayout>

MomentumIntroPage::MomentumIntroPage(Color bg, Color item)
{
    Label *descLabel = Label::create().
            multiline(TRUE).
            horizontal(HorizontalAlignment::Center).
            text("We know that you have something important to do today "
                    "and that you would love to be reminded about it. We help you "
                    "remember it by setting it as your wallpaper. Awesome, isn't it?");
    descLabel->textStyle()->setColor(Color::Black);
    descLabel->textStyle()->setFontSize(FontSize::PointValue);
    descLabel->textStyle()->setFontSizeValue(8);
    descLabel->textStyle()->setFontWeight(FontWeight::W100);
    descLabel->textStyle()->setTextAlign(TextAlign::Center);

    checkBox = CheckBox::create();

    Label *toggleText = Label::create().
            text("I got it. Do not show this message again");
    toggleText->textStyle()->setColor(Color::Black);
    toggleText->textStyle()->setFontSize(FontSize::PointValue);
    toggleText->textStyle()->setFontSizeValue(7);
    toggleText->textStyle()->setFontWeight(FontWeight::W100);

    Container *doNotShowC = Container::create().
            horizontal(HorizontalAlignment::Center).
            layout(StackLayout::create().orientation(LayoutOrientation::LeftToRight)).
            add(checkBox).
            add(toggleText);

    ImageButton *goButton = ImageButton::create().
            horizontal(HorizontalAlignment::Center).
            defaultImage("asset:///images/buttons/goButton.png").
            connect(SIGNAL(clicked()), this, SLOT(onGoClicked()));

    Container *innerC = Container::create().
            horizontal(HorizontalAlignment::Center).
            vertical(VerticalAlignment::Center).
            add(descLabel).
            add(doNotShowC).
            add(goButton);

    Container *contentC = Container::create().
            left(6).
            right(6).
            horizontal(HorizontalAlignment::Fill).
            vertical(VerticalAlignment::Fill).
            layout(DockLayout::create()).
            background(item).
            add(innerC);

    Container *rootC = Container::create().
            left(6).
            top(6).
            right(6).
            bottom(6).
            background(bg).
            layout(DockLayout::create()).
            add(contentC);
    setContent(rootC);
}

void MomentumIntroPage::onGoClicked()
{
    emit goClicked(checkBox->isChecked());
}
