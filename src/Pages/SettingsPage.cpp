/*
 * SettingsPage.cpp
 *
 *  Created on: Oct 21, 2014
 *      Author: SuhairZain
 */

#include <src/Pages/SettingsPage.h>

#include <bb/cascades/Container>
#include <bb/cascades/Label>
#include <bb/cascades/StackLayout>
#include <bb/cascades/StackLayoutProperties>
#include <bb/cascades/TextStyle>
#include <bb/cascades/ToggleButton>

SettingsPage::SettingsPage(Color bg, Color item, bool supportChecked, bool introChecked)
{
    TextStyle tStyle;
    tStyle.setColor(Color::Black);
    tStyle.setFontSize(FontSize::PointValue);
    tStyle.setFontSizeValue(10);
    tStyle.setFontWeight(FontWeight::W100);

    Label *supportMessageLabel = Label::create().
            layoutProperties(StackLayoutProperties::create().spaceQuota(1)).
            vertical(VerticalAlignment::Center).
            text("Show support message").
            textStyle(tStyle);

    ToggleButton *supportToggle = ToggleButton::create().
            checked(supportChecked).
            connect(SIGNAL(checkedChanged(bool)), this, SIGNAL(supportMessageChanged(bool))).
            vertical(VerticalAlignment::Center);

    Container *supportMessageC = Container::create().
            layout(StackLayout::create().orientation(LayoutOrientation::LeftToRight)).
            background(item).
            left(6).
            top(6).
            right(6).
            bottom(6).
            add(supportMessageLabel).
            add(supportToggle);

    Label *introMessageLabel = Label::create().
            layoutProperties(StackLayoutProperties::create().spaceQuota(1)).
            vertical(VerticalAlignment::Center).
            text("Show momentum intro").
            textStyle(tStyle);

    ToggleButton *introToggle = ToggleButton::create().
            checked(introChecked).
            connect(SIGNAL(checkedChanged(bool)), this, SIGNAL(introMessageChanged(bool))).
            vertical(VerticalAlignment::Center);

    Container *introToggleC = Container::create().
            layout(StackLayout::create().orientation(LayoutOrientation::LeftToRight)).
            background(item).
            left(6).
            top(6).
            right(6).
            bottom(6).
            add(introMessageLabel).
            add(introToggle);

    Container *rootC = Container::create().
            left(6).
            top(6).
            right(6).
            bottom(6).
            background(bg).
            add(supportMessageC).
            add(introToggleC);
    setContent(rootC);
}

