/*
 * SupportPage.cpp
 *
 *  Created on: Oct 17, 2014
 *      Author: SuhairZain
 */

#include <src/Pages/SupportPage.h>

#include <bb/cascades/Container>
#include <bb/cascades/DockLayout>
#include <bb/cascades/ImageButton>
#include <bb/cascades/Label>
#include <bb/cascades/StackLayout>
#include <bb/cascades/StackLayoutProperties>

using namespace bb::platform;

SupportPage::SupportPage(Color bg, Color item)
{
    TextStyle titleStyle;
    titleStyle.setColor(Color::DarkGray);
    titleStyle.setFontSize(FontSize::PointValue);
    titleStyle.setFontSizeValue(8);

    Label *requestTitle = Label::create().
            horizontal(HorizontalAlignment::Center).
            text("Why do it?").
            textStyle(titleStyle);

    Label *requestLabel = Label::create().
            multiline(TRUE).
            horizontal(HorizontalAlignment::Center).
            text("We believe that everyone has the right to everything good. "
                    "And thus we didn't want to put our app on sale. This is an open source project "
                    "and to help us continue this effort, we request you to make a donation or write "
                    "us a review, or both if you feel generous.\nYou may disable this request from settings.");
    requestLabel->textStyle()->setColor(Color::Black);
    requestLabel->textStyle()->setTextAlign(TextAlign::Center);
    requestLabel->textStyle()->setFontWeight(FontWeight::W100);
    requestLabel->textStyle()->setFontSize(FontSize::PointValue);
    requestLabel->textStyle()->setFontSizeValue(7);

    Container *requestC = Container::create().
            //layoutProperties(StackLayoutProperties::create().spaceQuota(0.9)).
            bottomMargin(6).
            background(item).
            horizontal(HorizontalAlignment::Fill).
            add(requestTitle).
            add(requestLabel);

    Label *reviewTitle = Label::create().
            horizontal(HorizontalAlignment::Center).
            text("Review our app").
            textStyle(titleStyle);

    ImageButton *reviewButton = ImageButton::create().
            horizontal(HorizontalAlignment::Center).
            vertical(VerticalAlignment::Center).
            defaultImage("asset:///images/buttons/bbWorld.png");

    Container *reviewContentC = Container::create().
            horizontal(HorizontalAlignment::Center).
            layout(DockLayout::create()).
            layoutProperties(StackLayoutProperties::create().spaceQuota(1)).
            add(reviewButton);

    Container *reviewC = Container::create().
            horizontal(HorizontalAlignment::Fill).
            bottomMargin(6).
            background(item).
            layoutProperties(StackLayoutProperties::create().spaceQuota(0.4)).
            add(reviewTitle).
            add(reviewContentC);

    Label *donateLabel = Label::create().
            horizontal(HorizontalAlignment::Center).
            text("Or make a donation").
            textStyle(titleStyle);

    Container *donateLabelC =  Container::create().
            horizontal(HorizontalAlignment::Fill).
            add(donateLabel);

    ImageButton *donate3 = ImageButton::create().
            defaultImage("asset:///images/buttons/3.png").
            connect(SIGNAL(clicked()), this, SLOT(on3Clicked()));

    Container *donate3c = Container::create().
            layout(DockLayout::create()).
            left(6).
            top(6).
            bottom(6).
            background(bg).
            add(donate3);

    ImageButton *donate2 = ImageButton::create().
            horizontal(HorizontalAlignment::Center).
            defaultImage("asset:///images/buttons/2.png").
            connect(SIGNAL(clicked()), this, SLOT(on2Clicked()));

    Container *donate2c = Container::create().
            layout(DockLayout::create()).
            left(6).
            top(6).
            bottom(6).
            background(bg).
            add(donate2);

    ImageButton *donate1 = ImageButton::create().
            horizontal(HorizontalAlignment::Center).
            defaultImage("asset:///images/buttons/1.png").
            connect(SIGNAL(clicked()), this, SLOT(on1Clicked()));

    Container *donate1c = Container::create().
            layout(DockLayout::create()).
            left(6).
            top(6).
            right(6).
            bottom(6).
            background(bg).
            add(donate1);

    Container *donateButtonsC = Container::create().
            layout(StackLayout::create().orientation(LayoutOrientation::LeftToRight)).
            horizontal(HorizontalAlignment::Center).
            vertical(VerticalAlignment::Center).
            add(donate3c).
            add(donate2c).
            add(donate1c);

    Container *donateAmountC = Container::create().
            horizontal(HorizontalAlignment::Center).
            layoutProperties(StackLayoutProperties::create().spaceQuota(1)).
            layout(DockLayout::create()).
            add(donateButtonsC);

    Container *donationC = Container::create().
            background(item).
            layoutProperties(StackLayoutProperties::create().spaceQuota(0.9)).
            horizontal(HorizontalAlignment::Fill).
            add(donateLabelC).
            add(donateAmountC);

    Container *rootC = Container::create().
            left(6).
            right(6).
            top(6).
            bottom(6).
            background(bg).
            add(requestC).
            add(reviewC).
            add(donationC);

    setContent(rootC);
}

void SupportPage::on1Clicked()
{
    purchaseWithSKU("donation099");
}

void SupportPage::on2Clicked()
{
    purchaseWithSKU("donation199");
}

void SupportPage::on3Clicked()
{
    purchaseWithSKU("donation299");
}

void SupportPage::onPurchaseFinished(PurchaseReply *reply)
{
    qDebug()<<reply->receipt().isValid()<<reply->receipt().digitalGoodId();
    sender()->deleteLater();
}

void SupportPage::purchaseWithSKU(QString sku)
{
    PaymentManager *manager = new PaymentManager;
    connect(manager, SIGNAL(purchaseFinished(bb::platform::PurchaseReply*)),
            this, SLOT(onPurchaseFinished(bb::platform::PurchaseReply*)));
    manager->requestPurchase("", sku);
}
