/*
 * InfoPage.cpp
 *
 *  Created on: Oct 21, 2014
 *      Author: SuhairZain
 */

#include <src/Pages/InfoPage.h>

#include <bb/cascades/Container>
#include <bb/cascades/DockLayout>
#include <bb/cascades/ImageView>
#include <bb/cascades/Label>
#include <bb/cascades/StackLayoutProperties>
#include <bb/cascades/TapHandler>

InfoPage::InfoPage(Color bg, Color item)
{
    ImageView *image = ImageView::create().
            horizontal(HorizontalAlignment::Center).
            vertical(VerticalAlignment::Center).
            image("asset:///images/logo.png");

    Container *imageC = Container::create().
            layoutProperties(StackLayoutProperties::create().spaceQuota(0.5)).
            layout(DockLayout::create()).
            background(item).
            horizontal(HorizontalAlignment::Fill).
            bottomMargin(6).
            add(image);

    Label *supportTitle = Label::create().
            horizontal(HorizontalAlignment::Center).
            text("Support us");
    supportTitle->textStyle()->setColor(Color::DarkGray);
    supportTitle->textStyle()->setFontSize(FontSize::PointValue);
    supportTitle->textStyle()->setFontSizeValue(9);

    Label *supportText = Label::create().
            horizontal(HorizontalAlignment::Center).
            multiline(TRUE).
            text("Please support us by leaving a review or donation. Tap here to know more");
    supportText->textStyle()->setColor(Color::White);
    supportText->textStyle()->setFontSize(FontSize::PointValue);
    supportText->textStyle()->setFontSizeValue(7);
    supportText->textStyle()->setTextAlign(TextAlign::Center);

    Container *supportContentC = Container::create().
            horizontal(HorizontalAlignment::Center).
            vertical(VerticalAlignment::Center).
            add(supportTitle).
            add(supportText);

    TapHandler *handler = TapHandler::create().
            onTapped(this, SIGNAL(supportTapped()));

    Container *supportC = Container::create().
            addGestureHandler(handler).
            layoutProperties(StackLayoutProperties::create().spaceQuota(0.4)).
            layout(DockLayout::create()).
            background(item).
            horizontal(HorizontalAlignment::Fill).
            bottomMargin(6).
            add(supportContentC);

    Label *label = Label::create().
            horizontal(HorizontalAlignment::Center).
            vertical(VerticalAlignment::Center).
            multiline(TRUE).
            format(TextFormat::Html).
            text("Quotes provided by <a href=\"http://forismatic.com\">forismatic.com</a>\n"
                    "Word of the day provided by <a href=\"http://wordnik.com\">wordnik.com</a>\n\n"
                    "Coded by <a href=\"http://fb.com\">Suhair Zain</a>\n"
                    "Images by <a href=\"http://fb.com\">Vishnu GP</a>\n\n"
                    "You may obtain the source code for this project from "
                    "<a href=\"http://github.com/suhairzain\">github.com/suhairzain</a>");
    label->textStyle()->setColor(Color::Black);
    label->textStyle()->setFontSize(FontSize::PointValue);
    label->textStyle()->setFontSizeValue(8);
    label->textStyle()->setFontWeight(FontWeight::W100);
    label->textStyle()->setTextAlign(TextAlign::Center);

    Container *labelC = Container::create().
            layoutProperties(StackLayoutProperties::create().spaceQuota(1)).
            layout(DockLayout::create()).
            background(item).
            horizontal(HorizontalAlignment::Fill).
            add(label);

    Container *itemC = Container::create().
            horizontal(HorizontalAlignment::Fill).
            vertical(VerticalAlignment::Fill).
            add(imageC).
            add(supportC).
            add(labelC);

    Container *rootC = Container::create().
            layout(DockLayout::create()).
            background(bg).
            left(6).
            top(6).
            right(6).
            bottom(6).
            add(itemC);
    setContent(rootC);
}

