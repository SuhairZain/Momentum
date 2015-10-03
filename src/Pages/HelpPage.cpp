/*
 * HelpPage.cpp
 *
 *  Created on: Oct 21, 2014
 *      Author: SuhairZain
 */

#include <src/Pages/HelpPage.h>

#include <bb/cascades/Container>
#include <bb/cascades/DockLayout>
#include <bb/cascades/ImageView>
#include <bb/cascades/Label>
#include <bb/cascades/StackLayoutProperties>

HelpPage::HelpPage(Color bg, Color item)
{
    ImageView *logo = ImageView::create().
            horizontal(HorizontalAlignment::Center).
            image("asset:///images/logo.png");

    Label *textLabel = Label::create().
            horizontal(HorizontalAlignment::Center).
            vertical(VerticalAlignment::Center).
            multiline(TRUE).
            text("This app shows you a new word to learn every day along with some quotes"
                    " that can make your day. \n\nYou can set yourself in the right direction by "
                    "setting your focus for the day, which will remind you "
                    "by displaying it as the wallpaper. You can also choose from "
                    "different wallpapers to set as the background for your goal."
                    "\n\nYou can save the words and quotes so that you can view "
                    "them even when there's no internet connection.");
    textLabel->textStyle()->setColor(bg);
            textLabel->textStyle()->setFontSize(FontSize::PointValue);
            textLabel->textStyle()->setFontSizeValue(7);
            textLabel->textStyle()->setFontWeight(FontWeight::W100);
            textLabel->textStyle()->setTextAlign(TextAlign::Center);

    Container *textC = Container::create().
            horizontal(HorizontalAlignment::Center).
            layoutProperties(StackLayoutProperties::create().spaceQuota(1)).
            layout(DockLayout::create()).
            add(textLabel);

    Container *contentC = Container::create().
            layoutProperties(StackLayoutProperties::create().spaceQuota(1)).
            horizontal(HorizontalAlignment::Fill).
            background(item).
            add(logo).
            add(textC);

    Container *rootC = Container::create().
            background(bg).
            left(6).
            top(6).
            right(6).
            bottom(6).
            add(contentC);
    setContent(rootC);
}

