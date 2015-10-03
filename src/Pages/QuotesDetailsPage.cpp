/*
 * QuotesDetailsPage.cpp
 *
 *  Created on: Oct 15, 2014
 *      Author: SuhairZain
 */

#include <src/Pages/QuotesDetailsPage.h>

#include <bb/cascades/ActionItem>
#include <bb/system/Clipboard>
#include <bb/cascades/Container>
#include <bb/cascades/DockLayout>
#include <bb/cascades/Label>
#include <bb/system/SystemToast>

QuotesDetailsPage::QuotesDetailsPage(QVariantMap quoteDetails, Color bg, Color item)
{
    quote = quoteDetails["quote"].toString();
    author = quoteDetails["author"].toString();
    QString link = quoteDetails["link"].toString();

    Label *authorLabel = Label::create().
            horizontal(HorizontalAlignment::Center).
            multiline(TRUE).
            text(author);
    authorLabel->textStyle()->setColor(Color::DarkGray);
    authorLabel->textStyle()->setFontSize(FontSize::PointValue);
    authorLabel->textStyle()->setFontSizeValue(8);

    Label *quoteLabel = Label::create().
            horizontal(HorizontalAlignment::Center).
            multiline(TRUE).
            text(quote);
    quoteLabel->textStyle()->setTextAlign(TextAlign::Center);
    quoteLabel->textStyle()->setColor(Color::Black);
    quoteLabel->textStyle()->setFontSize(FontSize::PointValue);
    quoteLabel->textStyle()->setFontSizeValue(12);
    quoteLabel->textStyle()->setFontWeight(FontWeight::W100);

    Label *linkLabel = Label::create().
            horizontal(HorizontalAlignment::Center).
            multiline(TRUE).
            format(TextFormat::Html).
            text("<a href=\"" + link +"\">" + link + "</a>");
    linkLabel->textStyle()->setFontSize(FontSize::PointValue);
    linkLabel->textStyle()->setFontSizeValue(7);

    Container *contentC = Container::create().
            horizontal(HorizontalAlignment::Center).
            vertical(VerticalAlignment::Center).
            add(authorLabel).
            add(quoteLabel).
            add(linkLabel);

    Container *containerBgC = Container::create().
            horizontal(HorizontalAlignment::Fill).
            vertical(VerticalAlignment::Fill).
            layout(DockLayout::create()).
            background(item).
            add(contentC);

    Container *rootC = Container::create().
            layout(DockLayout::create()).
            left(6).
            top(6).
            right(6).
            bottom(6).
            background(bg).
            add(containerBgC);
    setContent(rootC);

    addAction(ActionItem::create().
            title("Copy Quote").
            image("asset:///images/icons/ic_copy_quote.png").
            onTriggered(this, SLOT(onCopyQuoteTriggered())),
            ActionBarPlacement::OnBar);

    addAction(ActionItem::create().
            title("Copy Quote & Author").
            image("asset:///images/icons/ic_copy_quote_author.png").
            onTriggered(this, SLOT(onCopyQuoteAuthorTriggered())),
            ActionBarPlacement::OnBar);
}

void QuotesDetailsPage::onCopyQuoteAuthorTriggered()
{
    bb::system::Clipboard cBoard;
    cBoard.insert("text/plain", QString(quote + " - " + author).toAscii());
    cBoard.insert("text/html", QString(quote + " - " + author).toAscii());

    bb::system::SystemToast *toast = new bb::system::SystemToast;
    toast->setBody("Quote + Author copied");
    connect(toast, SIGNAL(finished(bb::system::SystemUiResult::Type)), toast, SLOT(deleteLater()));
    toast->show();

}

void QuotesDetailsPage::onCopyQuoteTriggered()
{
    bb::system::Clipboard cBoard;
    cBoard.insert("text/plain", quote.toAscii());
    cBoard.insert("text/html", quote.toAscii());

    bb::system::SystemToast *toast = new bb::system::SystemToast;
    toast->setBody("Quote copied");
    connect(toast, SIGNAL(finished(bb::system::SystemUiResult::Type)), toast, SLOT(deleteLater()));
    toast->show();
}
