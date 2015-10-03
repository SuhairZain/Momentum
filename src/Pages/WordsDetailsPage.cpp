/*
 * WordsDetailsPage.cpp
 *
 *  Created on: Oct 15, 2014
 *      Author: SuhairZain
 */

#include <src/Pages/WordsDetailsPage.h>

#include <bb/cascades/Container>
//#include <bb/cascades/Divider>
#include <bb/cascades/DockLayout>
#include <bb/cascades/Label>
#include <bb/cascades/ScrollView>
#include <bb/cascades/StackLayout>
#include <bb/cascades/StackLayoutProperties>

WordsDetailsPage::WordsDetailsPage(QVariantMap wordDetails, Color bg, Color item)
{
    QString word = wordDetails["word"].toString();
    QVariantList examples = wordDetails["examples"].toList();
    QVariantList definitions = wordDetails["definitions"].toList();

    Label *wordLabel = Label::create().
            multiline(TRUE).
            text(word);
    wordLabel->textStyle()->setColor(Color::Black);
    wordLabel->textStyle()->setFontSize(FontSize::PointValue);
    wordLabel->textStyle()->setFontSizeValue(15);

    Container *contentC = Container::create().
            left(6).
            right(6).
            add(wordLabel);

    TextStyle typeStyle;
    typeStyle.setColor(Color::DarkGray);
    typeStyle.setFontSize(FontSize::PointValue);
    typeStyle.setFontSizeValue(8);

    TextStyle exAndDefStyle;
    exAndDefStyle.setTextAlign(TextAlign::Justify);
    exAndDefStyle.setColor(Color::Black);
    exAndDefStyle.setFontSize(FontSize::PointValue);
    exAndDefStyle.setFontSizeValue(7);
    exAndDefStyle.setFontWeight(FontWeight::W100);

    if(definitions.size()>0)
    {
        Label *definitionLabel = Label::create().
                text("definitions").
                textStyle(typeStyle);
        contentC->add(definitionLabel);

        for(int i=0; i<definitions.size(); i++)
        {
            QVariantMap currDefMap = definitions.at(i).toMap();

            Label *currDefType = Label::create().
                    text(currDefMap["partOfSpeech"].toString());
            currDefType->textStyle()->setColor(Color::Gray);
            currDefType->textStyle()->setFontSize(FontSize::PointValue);
            currDefType->textStyle()->setFontSizeValue(7);

            Label *currDefinition = Label::create().
                    layoutProperties(StackLayoutProperties::create().spaceQuota(1)).
                    multiline(TRUE).
                    text(currDefMap["text"].toString()).
                    format(TextFormat::Html).
                    textStyle(exAndDefStyle);

            Container *currDefC = Container::create().
                    layout(StackLayout::create().orientation(LayoutOrientation::LeftToRight)).
                    add(currDefType).
                    add(currDefinition);
            contentC->add(currDefC);

            /*if(i!=definitions.size()-1)
                contentC->add(new Divider);*/
        }
    }

    if(examples.size()>0)
    {
        Label *exampleLabel = Label::create().
                text("examples").
                textStyle(typeStyle);
        contentC->add(exampleLabel);

        for(int i=0; i<examples.size(); i++)
        {
            Label *currExample = Label::create().
                    multiline(TRUE).
                    format(TextFormat::Html).
                    text(examples.at(i).toString()).
                    textStyle(exAndDefStyle);
            contentC->add(currExample);

            /*if(i!=examples.size()-1)
                contentC->add(new Divider);*/
        }
    }

    if(wordDetails["note"].toString()!="")
    {
        Label *noteHeadLabel = Label::create().
                text("note").
                textStyle(typeStyle);
        contentC->add(noteHeadLabel);

        Label *noteLabel = Label::create().
                multiline(TRUE).
                text(wordDetails["note"].toString()).
                format(TextFormat::Html).
                textStyle(exAndDefStyle);
        contentC->add(noteLabel);
    }

    ScrollView *contentScrollView = ScrollView::create().
            horizontal(HorizontalAlignment::Fill).
            vertical(VerticalAlignment::Fill).
            content(contentC);

    Container *contentBgC = Container::create().
            horizontal(HorizontalAlignment::Fill).
            vertical(VerticalAlignment::Fill).
            layout(DockLayout::create()).
            background(item).
            add(contentScrollView);

    Container *rootC = Container::create().
            layout(DockLayout::create()).
            left(6).
            top(6).
            right(6).
            bottom(6).
            background(bg).
            add(contentBgC);
    setContent(rootC);
}
