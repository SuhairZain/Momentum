/*
 * Copyright (c) 2011-2014 BlackBerry Limited.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "applicationui.hpp"

#include <bb/cascades/QmlDocument>
#include <bb/cascades/AbstractPane>

#include <bb/cascades/ActionItem>
#include <bb/cascades/Application>
#include <bb/cascades/DockLayout>
#include <bb/cascades/FadeTransition>
#include <bb/cascades/HelpActionItem>
#include <bb/platform/HomeScreen>
#include <bb/cascades/ImageView>
#include <bb/system/InvokeManager>
#include <bb/system/InvokeRequest>
#include <bb/system/InvokeTargetReply>
#include <bb/data/JsonDataAccess>
#include <bb/cascades/ListView>
#include <bb/cascades/Menu>
#include <bb/cascades/Page>
#include <bb/cascades/ParallelAnimation>
#include <bb/cascades/SettingsActionItem>
#include <bb/cascades/StackLayout>
#include <bb/cascades/StackLayoutProperties>
#include <bb/cascades/TapHandler>
#include <bb/cascades/TranslateTransition>

#include "Pages/QuotesDetailsPage.h"
#include "MVC/QuotesItemProvider.h"

#include "Pages/WordsDetailsPage.h"
#include "MVC/WordsItemProvider.h"

#include "Pages/HelpPage.h"
#include "Pages/InfoPage.h"
#include "Pages/MomentumIntroPage.h"
#include "Pages/MomentumSetterPage.h"
#include "Pages/SettingsPage.h"
#include "Pages/SupportPage.h"

#include "SplashLetter.h"
#include "MomentumImageHelper.h"

#include <time.h>
#include <stdlib.h>

ApplicationUI::ApplicationUI()
{
    /*QmlDocument *qml = QmlDocument::create("asset:///qml/momentumPreview.qml").parent(this);
    AbstractPane *root = qml->createRootObject<AbstractPane>();
    Application::instance()->setScene(root);*/

    //bb::platform::HomeScreen *myHomeScreen = new bb::platform::HomeScreen;
    //myHomeScreen->setWallpaper(QUrl(""));
    //bb::platform::PaymentManager::setConnectionMode(bb::platform::PaymentConnectionMode::Test);

    randomWordIndex = randomQuoteIndex = -1;
    isQuoteLoading = isWordLoading = TRUE;

    wordsDataModel = quotesDataModel = NULL;
    noConnectionC = supportC = NULL;
    addWordButton = addQuoteButton = reloadWordButton = NULL;
    wordLabel = quoteLabel = NULL;
    homeNavPane = wordsNavPane = quotesNavPane = NULL;
    rootPane = NULL;

    srand(time(NULL));

    //TODO
    QSettings colorSettings("Suhair Zain", "Momentum");
    /*bgColor = Color::fromARGB(0xffc63d0f);
    itemColor = Color::fromARGB(0xffeab543);*/
    //qDebug()<<colorSettings.value("item").toString().toInt(NULL, 16);
    itemColor = Color::fromARGB(colorSettings.value("item").toString().toLongLong(NULL, 16));
    bgColor = Color::fromARGB(colorSettings.value("bg").toString().toLongLong(NULL, 16));
    qDebug()<<colorSettings.value("item").toString().toLongLong(NULL, 16);
    qDebug()<<colorSettings.value("bg").toString().toLongLong(NULL, 16);

    Container *splashContentC = Container::create().
            horizontal(HorizontalAlignment::Center).
            vertical(VerticalAlignment::Center);

    Container *splashBG = Container::create().
            layout(DockLayout::create()).
            horizontal(HorizontalAlignment::Fill).
            vertical(VerticalAlignment::Fill).
            background(itemColor).
            add(splashContentC);

    Container *splashRootC = Container::create().
            layout(DockLayout::create()).
            left(6).
            top(6).
            right(6).
            bottom(6).
            background(bgColor).
            add(splashBG);

    Page *splashPage = Page::create().
            content(splashRootC);

    Application::instance()->setScene(splashPage);

    ImageView *logo = ImageView::create().
            ty(-50).
            opacity(0.1).
            horizontal(HorizontalAlignment::Center).
            image("asset:///images/splash/logo.png");
    splashContentC->add(logo);

    FadeTransition *fadeLogoIn = FadeTransition::create(logo).
            parent(logo).
            duration(500).
            to(1);

    TranslateTransition *moveLogoIn = TranslateTransition::create(logo).
            parent(logo).
            duration(500).
            toY(0);

    Container *lettersC = Container::create().
            horizontal(HorizontalAlignment::Center).
            layout(StackLayout::create().orientation(LayoutOrientation::LeftToRight));
    splashContentC->add(lettersC);

    QList<QChar> lettersList;
    lettersList<<'p'<<'r'<<'i'<<'s'<<'m'<<'a';

    for(int i=0; i<lettersList.size(); i++)
    {
        SplashLetter *currLetter = new SplashLetter(lettersList.at(i), i*50);
        lettersC->add(currLetter);
    }

    ImageView *momentumLogo = ImageView::create().
            opacity(0.1).
            tx(800).
            horizontal(HorizontalAlignment::Center).
            image("asset:///images/logo.png");
    splashContentC->add(momentumLogo);

    TranslateTransition *moveMomentumIn = TranslateTransition::create(momentumLogo).
            duration(500).
            toX(0);

    FadeTransition *fadeMomentumIn = FadeTransition::create(momentumLogo).
            duration(500).
            to(1);

    ParallelAnimation *momentumAnimation = ParallelAnimation::create().
            parent(this).
            add(moveMomentumIn).
            add(fadeMomentumIn);

    fadeLogoIn->play();
    moveLogoIn->play();
    connect(moveLogoIn, SIGNAL(ended()), momentumAnimation, SLOT(play()));

    //setupAppView();
    QTimer::singleShot(2000, this, SLOT(setupAppView()));
}

void ApplicationUI::addToQuotes()
{
    addQuoteButton->setVisible(FALSE);

    //if(!quoteMap.isEmpty())
    quotesDataModel->append(quoteMap);

    QFile tempFile(QDir::home().absoluteFilePath("quotes.json"));

    bb::data::JsonDataAccess jda;

    QVariantList quotesData;
    for(int i=0; i<quotesDataModel->size(); i++)
        quotesData.append(quotesDataModel->value(i));

    if(tempFile.open(QIODevice::WriteOnly))
    {
        jda.save(quotesData, &tempFile);
    }
}

void ApplicationUI::addToWords()
{
    addWordButton->setVisible(FALSE);

    //if(!wordMap.isEmpty())
    wordsDataModel->append(wordMap);

    QFile tempFile(QDir::home().absoluteFilePath("words.json"));

    bb::data::JsonDataAccess jda;

    QVariantList wordsData;
    for(int i=0; i<wordsDataModel->size(); i++)
        wordsData.append(wordsDataModel->value(i));

    if(tempFile.open(QIODevice::WriteOnly))
    {
        jda.save(wordsData, &tempFile);
    }
}

void ApplicationUI::onClearClicked()
{
    supportC->setVisible(FALSE);
}

void ApplicationUI::onHelpActionTriggered()
{
    NavigationPane *currPane = static_cast<NavigationPane*>(rootPane->activePane());
    currPane->push(new HelpPage(bgColor, itemColor));
}

void ApplicationUI::onInfoActionTriggered()
{
    InfoPage *page = new InfoPage(bgColor, itemColor);
    connect(page, SIGNAL(supportTapped()), this, SLOT(onInfoPageSupportTapped()));
    NavigationPane *currPane = static_cast<NavigationPane*>(rootPane->activePane());
    currPane->push(page);
}

void ApplicationUI::onInfoPageSupportTapped()
{
    NavigationPane *currPane = static_cast<NavigationPane*>(rootPane->activePane());
    currPane->push(new SupportPage(bgColor, itemColor));
}

void ApplicationUI::onMomentumClicked()
{
    QSettings appSettings("Prisma", "Momentum");
    if(appSettings.value("showIntro", TRUE).toBool())
    {
        MomentumIntroPage *introPage = new MomentumIntroPage(bgColor, itemColor);
        connect(introPage, SIGNAL(goClicked(bool)), this, SLOT(onMomentumIntroGoClicked(bool)));
        homeNavPane->push(introPage);
    }
    else
    {
        homeNavPane->setPeekEnabled(FALSE);
        homeNavPane->push(new MomentumSetterPage(bgColor, itemColor));
    }
}

void ApplicationUI::onMomentumIntroGoClicked(bool checked)
{
    if(checked)
    {
        onSettingsPageIntroMessageChanged(FALSE);
    }
    homeNavPane->setPeekEnabled(FALSE);
    homeNavPane->push(new MomentumSetterPage(bgColor, itemColor));

    /*Page *introPage = homeNavPane->at(1);
    homeNavPane->remove(introPage);
    introPage->deleteLater();*/
}

void ApplicationUI::onNavpaneTopChanged()
{
    NavigationPane *temp = static_cast<NavigationPane*>(sender());
    if(temp->count()>1)
        Application::instance()->setMenuEnabled(FALSE);
    else
    {
        Application::instance()->setMenuEnabled(TRUE);

        if(temp==homeNavPane)
            homeNavPane->setPeekEnabled(TRUE);
    }

}

void ApplicationUI::onNetworkConnectionsTapped()
{
    bb::system::InvokeRequest request;
    request.setAction("bb.action.OPEN");
    request.setMimeType("settings/view");
    request.setTarget("sys.settings.target");
    request.setUri("settings://networkconnections");

    bb::system::InvokeManager *manager = new bb::system::InvokeManager;
    bb::system::InvokeTargetReply *reply = manager->invoke(request);
    connect(reply, SIGNAL(finished()), manager, SLOT(deleteLater()));
}

void ApplicationUI::onPopEnded(Page *poppedPage)
{
    poppedPage->deleteLater();
}

void ApplicationUI::onQuotesListTriggered(QVariantList qIndexPath)
{
    quotesNavPane->push(new QuotesDetailsPage(quotesDataModel->data(qIndexPath).toMap(), bgColor, itemColor));
}

void ApplicationUI::onQuotesReplyFinished()
{
    QNetworkReply *reply = static_cast<QNetworkReply*>(sender());

    if(reply)
    {
        if(reply->error()==QNetworkReply::NoError)
        {
            randomQuoteIndex = -1;

            noConnectionC->setVisible(FALSE);

            bb::data::JsonDataAccess jda;

            QVariantMap replyQuote = jda.load(reply).toMap();
            //qDebug()<<"Quote"<<replyQuote;
            //qDebug()<<"Processed quote"<<replyQuote;

            QString q = replyQuote["quoteText"].toString();
            if(q=="")
            {
                onRefreshQuote();
                return;
            }
            quoteMap["quote"] = q;
            QString auth = replyQuote["quoteAuthor"].toString();
            if(auth=="")
                auth = "Unknown";
            quoteMap["author"] = auth;
            quoteMap["link"] = replyQuote["quoteLink"].toString();

            quoteLabel->setText(quoteMap["quote"].toString() + "\n- " + quoteMap["author"].toString());

            QString quote = quoteMap["quote"].toString();
            bool found = FALSE;
            for(int i=0; i<quotesDataModel->size(); ++i)
            {
                //qDebug()<<quotesDataModel->value(i).toMap()["quote"].toString()<<"  -- "<<quote;
                if(quotesDataModel->value(i).toMap()["quote"].toString()==quote)
                {
                    found = TRUE;
                    break;
                }
            }
            if(!found)
                addQuoteButton->setVisible(TRUE);
            else
                addQuoteButton->setVisible(FALSE);
        }
        else
        {
            //quoteMap.clear();
            qDebug()<<"Quote error"<<reply->errorString();
            noConnectionC->setVisible(TRUE);

            randomQuoteIndex = rand()%quotesDataModel->size();
            QVariantMap tempMap = quotesDataModel->value(randomQuoteIndex).toMap();

            quoteLabel->setText("<i>" + tempMap["quote"].toString() + "\n- " + tempMap["author"].toString() + "</i>");

            addQuoteButton->setVisible(FALSE);
        }

        reply->deleteLater();
    }
    isQuoteLoading = FALSE;
}

void ApplicationUI::onQuoteTapped()
{
    if(!isQuoteLoading)
    {
        NavigationPane *currPane = static_cast<NavigationPane*>(rootPane->activePane());
        if(randomQuoteIndex==-1)
            currPane->push(new QuotesDetailsPage(quoteMap, bgColor, itemColor));
        //quotesNavPane->push(new QuotesDetailsPage(quoteMap, bgColor, itemColor));
        else
            currPane->push(new QuotesDetailsPage(quotesDataModel->value(randomQuoteIndex).toMap(), bgColor, itemColor));
        //quotesNavPane->push(new QuotesDetailsPage(quotesDataModel->value(randomQuoteIndex).toMap(), bgColor, itemColor));
        //rootPane->setActiveTab(rootPane->at(2));
    }
}

void ApplicationUI::onRefreshQuote()
{
    isQuoteLoading = TRUE;
    QNetworkRequest quoteRequest;
    quoteRequest.setUrl(QUrl("http://api.forismatic.com/api/1.0/?"
            "method=getQuote&lang=en&format=json"));
    QNetworkReply *quoteReply = netManager.get(quoteRequest);
    connect(quoteReply, SIGNAL(finished()), this, SLOT(onQuotesReplyFinished()));

    quoteLabel->setText("<i>Loading.. Please Wait..</i>");
}

void ApplicationUI::onRefreshWord()
{
    isWordLoading = TRUE;
    QNetworkRequest wordRequest;
    wordRequest.setUrl(QUrl("http://api.wordnik.com/v4/words.json/wordOfTheDay?"
            "api_key=a2a73e7b926c924fad7001ca3111acd55af2ffabf50eb4ae5"));
    QNetworkReply *wordReply = netManager.get(wordRequest);
    connect(wordReply, SIGNAL(finished()), this, SLOT(onWordsReplyFinished()));

    wordLabel->setText("<i>Loading..</i>");
}

void ApplicationUI::onSettingsActionTriggered()
{
    NavigationPane *currPane = static_cast<NavigationPane*>(rootPane->activePane());

    QSettings appSettings("Prisma", "Momentum");
    bool support = appSettings.value("supportMessage", TRUE).toBool();
    bool intro = appSettings.value("showIntro", TRUE).toBool();
    SettingsPage *page = new SettingsPage(bgColor, itemColor, support, intro);
    connect(page, SIGNAL(introMessageChanged(bool)), this, SLOT(onSettingsPageIntroMessageChanged(bool)));
    connect(page, SIGNAL(supportMessageChanged(bool)), this, SLOT(onSettingsPageSupportMessageChanged(bool)));
    currPane->push(page);
}

void ApplicationUI::onSettingsPageIntroMessageChanged(bool checked)
{
    QSettings appSettings("Prisma", "Momentum");
    appSettings.setValue("showIntro", checked);
    appSettings.sync();
}

void ApplicationUI::onSettingsPageSupportMessageChanged(bool checked)
{
    QSettings appSettings("Prisma", "Momentum");
    appSettings.setValue("supportMessage", checked);
    appSettings.sync();

    supportC->setVisible(checked);
}

void ApplicationUI::onSupportTapped()
{
    homeNavPane->push(new SupportPage(bgColor, itemColor));
}

void ApplicationUI::onWordsListTriggered(QVariantList wIndexPath)
{
    wordsNavPane->push(new WordsDetailsPage(wordsDataModel->data(wIndexPath).toMap(), bgColor, itemColor));
}

void ApplicationUI::onWordsReplyFinished()
{
    QNetworkReply *reply = static_cast<QNetworkReply*>(sender());

    if(reply)
    {
        if(reply->error()==QNetworkReply::NoError)
        {
            randomWordIndex = -1;

            reloadWordButton->setVisible(FALSE);

            noConnectionC->setVisible(FALSE);

            //qDebug()<<reply->readAll();

            bb::data::JsonDataAccess jda;
            QVariantMap replyWord = jda.load(reply).toMap();
            //qDebug()<<"Processed word"<<replyWord;

            wordMap["word"] = replyWord["word"].toString();
            wordMap["note"] = replyWord["note"].toString();

            QList<QString> examplesList;
            QVariantList replyExamplesList = replyWord["examples"].toList();
            for(int i=0; i<replyExamplesList.size(); i++)
            {
                examplesList.append(replyExamplesList.at(i).toMap()["text"].toString());
            }
            wordMap["examples"] = QVariant(examplesList);

            QList<QVariant> definitionsList;
            QVariantList replyDefinitionsList = replyWord["definitions"].toList();
            for(int i=0; i<replyDefinitionsList.size(); i++)
            {
                QVariantMap tempDefMap;
                tempDefMap["text"] = replyDefinitionsList.at(i).toMap()["text"].toString();
                tempDefMap["partOfSpeech"] = replyDefinitionsList.at(i).toMap()["partOfSpeech"].toString();

                definitionsList.append(tempDefMap);
            }
            wordMap["definitions"] = definitionsList;

            wordLabel->setText(wordMap["word"].toString());

            addWordButton->setVisible(TRUE);

            QSettings appSettings("Prisma", "Momentum");
            appSettings.setValue("lastDate", QDate::currentDate());
            appSettings.setValue("lastSavedWord", wordMap);
            appSettings.sync();
        }
        else
        {
            //wordMap.clear();
            qDebug()<<"Word error"<<reply->errorString();
            noConnectionC->setVisible(TRUE);

            randomWordIndex = rand()%wordsDataModel->size();
            QVariantMap tempMap = wordsDataModel->value(randomWordIndex).toMap();

            wordLabel->setText("<i>" + tempMap["word"].toString() + "</i>");

            addWordButton->setVisible(FALSE);
        }

        reply->deleteLater();
    }

    isWordLoading = FALSE;
}

void ApplicationUI::onWordTapped()
{
    if(!isWordLoading)
    {
        NavigationPane *currPane = static_cast<NavigationPane*>(rootPane->activePane());
        if(randomWordIndex==-1)
            currPane->push(new WordsDetailsPage(wordMap, bgColor, itemColor));
        //wordsNavPane->push(new WordsDetailsPage(wordMap, bgColor, itemColor));
        else
            currPane->push(new WordsDetailsPage(wordsDataModel->value(randomWordIndex).toMap(), bgColor, itemColor));
        //wordsNavPane->push(new WordsDetailsPage(wordsDataModel->value(randomWordIndex).toMap(), bgColor, itemColor));
        //rootPane->setActiveTab(rootPane->at(1));
    }
}

void ApplicationUI::setupAppView()
{
    TextStyle noConnectionStyle;
    noConnectionStyle.setTextAlign(TextAlign::Center);
    noConnectionStyle.setColor(Color::Black);
    noConnectionStyle.setFontSize(FontSize::PointValue);
    noConnectionStyle.setFontSizeValue(5);
    noConnectionStyle.setFontWeight(FontWeight::W100);

    Label *noConnectionLabel = Label::create().
            horizontal(HorizontalAlignment::Center).
            multiline(TRUE).
            text("This app needs internet connectivity in order to fetch new words and quotes."
                    " Please click here to open connection settings.").
                    textStyle(noConnectionStyle);

    TapHandler *noConnectionHandler = TapHandler::create().
            onTapped(this, SLOT(onNetworkConnectionsTapped()));

    noConnectionC = Container::create().
            addGestureHandler(noConnectionHandler).
            horizontal(HorizontalAlignment::Fill).
            background(itemColor).
            bottomMargin(6).
            visible(FALSE).
            add(noConnectionLabel);

    TextStyle titleStyle;
    titleStyle.setColor(Color::DarkGray);
    titleStyle.setFontWeight(FontWeight::W400);

    reloadWordButton = ImageButton::create().
            defaultImage("asset:///images/icons/ic_reload.png").
            connect(SIGNAL(clicked()), this, SLOT(onRefreshWord()));

    Label *wordTitleLabel = Label::create().
            horizontal(HorizontalAlignment::Center).
            text("Word of the day").
            textStyle(titleStyle);

    Container *wordTitleLabelC = Container::create().
            layoutProperties(StackLayoutProperties::create().spaceQuota(1)).
            vertical(VerticalAlignment::Center).
            add(wordTitleLabel);

    addWordButton = ImageButton::create().
            defaultImage("asset:///images/icons/ic_add.png").
            connect(SIGNAL(clicked()), this, SLOT(addToWords()));

    Container *wordTitleC = Container::create().
            horizontal(HorizontalAlignment::Fill).
            layout(StackLayout::create().orientation(LayoutOrientation::LeftToRight)).
            add(reloadWordButton).
            add(wordTitleLabelC).
            add(addWordButton);

    TapHandler *wordTapHandler = TapHandler::create().
            onTapped(this, SLOT(onWordTapped()));

    wordLabel = Label::create().
            addGestureHandler(wordTapHandler).
            horizontal(HorizontalAlignment::Center).
            vertical(VerticalAlignment::Center).
            format(TextFormat::Html).
            //text("bibliotaph").
            multiline(TRUE);
    wordLabel->textStyle()->setTextAlign(TextAlign::Center);
    wordLabel->textStyle()->setColor(Color::Black);
    wordLabel->textStyle()->setFontSize(FontSize::PointValue);
    wordLabel->textStyle()->setFontSizeValue(12);
    wordLabel->textStyle()->setFontWeight(FontWeight::W100);

    Container *wordContentC = Container::create().
            layout(DockLayout::create()).
            layoutProperties(StackLayoutProperties::create().spaceQuota(1)).
            horizontal(HorizontalAlignment::Fill).
            vertical(VerticalAlignment::Fill).
            add(wordLabel);

    Container *wordC = Container::create().
            layoutProperties(StackLayoutProperties::create().spaceQuota(1.06)).
            vertical(VerticalAlignment::Fill).
            background(itemColor).
            rightMargin(6).
            add(wordTitleC).
            add(wordContentC);

    Label *momentumTitleLabel = Label::create().
            horizontal(HorizontalAlignment::Center).
            text("Momentum").
            textStyle(titleStyle);

    //qDebug()<<MomentumImageHelper::fromText("You").width();

    ImageButton *momentumButton = ImageButton::create().
            horizontal(HorizontalAlignment::Center).
            vertical(VerticalAlignment::Center).
            //defaultImage(Image(MomentumImageHelper::fromText("Make App, Not War"))).
            defaultImage("asset:///images/buttons/momentum.png").
            pressedImage("asset:///images/buttons/momentumPressed.png").
            connect(SIGNAL(clicked()), this, SLOT(onMomentumClicked()));

    Container *momentumContentC = Container::create().
            layout(DockLayout::create()).
            layoutProperties(StackLayoutProperties::create().spaceQuota(1)).
            horizontal(HorizontalAlignment::Fill).
            vertical(VerticalAlignment::Fill).
            add(momentumButton);

    Container *momentumC = Container::create().
            layoutProperties(StackLayoutProperties::create().spaceQuota(1)).
            vertical(VerticalAlignment::Fill).
            background(itemColor).
            add(momentumTitleLabel).
            add(momentumContentC);

    Container *wordAndMomentumC = Container::create().
            layout(StackLayout::create().orientation(LayoutOrientation::LeftToRight)).
            layoutProperties(StackLayoutProperties::create().spaceQuota(1)).
            bottomMargin(6).
            add(wordC).
            add(momentumC);

    Label *supportLabel = Label::create().
            layoutProperties(StackLayoutProperties::create().spaceQuota(1)).
            multiline(TRUE).
            vertical(VerticalAlignment::Center).
            text("Please support this app by reviewing or making a donation. It's easy and takes just a minute. Click here to know more.");
    supportLabel->textStyle()->setColor(Color::White);
    supportLabel->textStyle()->setTextAlign(TextAlign::Center);
    supportLabel->textStyle()->setFontSize(FontSize::PointValue);
    supportLabel->textStyle()->setFontSizeValue(6);
    supportLabel->textStyle()->setFontWeight(FontWeight::W100);

    ImageButton *clearSupport = ImageButton::create().
            vertical(VerticalAlignment::Center).
            defaultImage("asset:///images/icons/ic_clear.png").
            connect(SIGNAL(clicked()), this, SLOT(onClearClicked()));

    TapHandler *supportTapHandler = TapHandler::create().
            onTapped(this, SLOT(onSupportTapped()));

    QSettings appSettings("Prisma", "Momentum");
    supportC = Container::create().
            horizontal(HorizontalAlignment::Fill).
            layout(StackLayout::create().orientation(LayoutOrientation::LeftToRight)).
            background(itemColor).
            bottomMargin(6).
            visible(appSettings.value("supportMessage", TRUE).toBool()).
            add(supportLabel).
            add(clearSupport).
            addGestureHandler(supportTapHandler);

    ImageButton *reloadQuoteButton = ImageButton::create().
            defaultImage("asset:///images/icons/ic_reload.png").
            connect(SIGNAL(clicked()), this, SLOT(onRefreshQuote()));

    Label *quoteTitleLabel = Label::create().
            horizontal(HorizontalAlignment::Center).
            text("Inspirational quote").
            textStyle(titleStyle);

    Container *quoteTitleLabelC = Container::create().
            layoutProperties(StackLayoutProperties::create().spaceQuota(1)).
            vertical(VerticalAlignment::Center).
            add(quoteTitleLabel);

    addQuoteButton = ImageButton::create().
            defaultImage("asset:///images/icons/ic_add.png").
            connect(SIGNAL(clicked()), this, SLOT(addToQuotes()));

    Container *quoteTitleC = Container::create().
            horizontal(HorizontalAlignment::Fill).
            layout(StackLayout::create().orientation(LayoutOrientation::LeftToRight)).
            add(reloadQuoteButton).
            add(quoteTitleLabelC).
            add(addQuoteButton);

    TapHandler *quoteTapHandler = TapHandler::create().
            onTapped(this, SLOT(onQuoteTapped()));

    quoteLabel = Label::create().
            addGestureHandler(quoteTapHandler).
            horizontal(HorizontalAlignment::Center).
            vertical(VerticalAlignment::Center).
            format(TextFormat::Html).
            multiline(TRUE);//.
    //text("A life spent making mistakes is not only more honorable but more useful than a life spent in doing nothing.\n- Bernard Shaw");
    quoteLabel->textStyle()->setTextAlign(TextAlign::Center);
    quoteLabel->textStyle()->setColor(Color::Black);
    quoteLabel->textStyle()->setFontSize(FontSize::PointValue);
    quoteLabel->textStyle()->setFontSizeValue(10);
    quoteLabel->textStyle()->setFontWeight(FontWeight::W100);

    Container *quoteContentC = Container::create().
            layout(DockLayout::create()).
            layoutProperties(StackLayoutProperties::create().spaceQuota(1)).
            horizontal(HorizontalAlignment::Fill).
            vertical(VerticalAlignment::Fill).
            add(quoteLabel);

    Container *quoteC = Container::create().
            layoutProperties(StackLayoutProperties::create().spaceQuota(1.3)).
            background(itemColor).
            add(quoteTitleC).
            add(quoteContentC);

    Container *homeC = Container::create().
            background(bgColor).
            left(6).
            top(6).
            right(6).
            bottom(6).
            add(noConnectionC).
            add(wordAndMomentumC).
            add(supportC).
            add(quoteC);

    /*Page *homePage = Page::create().
            content(homeC);*/

    homeNavPane = NavigationPane::create().
            add(Page::create().content(homeC));
    connect(homeNavPane, SIGNAL(popTransitionEnded(bb::cascades::Page*)), this, SLOT(onPopEnded(bb::cascades::Page*)));
    connect(homeNavPane, SIGNAL(topChanged(bb::cascades::Page*)), this, SLOT(onNavpaneTopChanged()));

    Tab *homeTab = Tab::create().
            content(homeNavPane).
            title("Home").
            image("asset:///images/icons/ic_home.png");

    bb::data::JsonDataAccess jda;

    wordsDataModel = new ArrayDataModel;

    if(QFile(QDir::home().absoluteFilePath("words.json")).exists())
    {
        QVariantList wordsList = jda.load(QDir::home().absoluteFilePath("words.json")).toList();
        wordsDataModel->append(wordsList);
    }
    else
    {
        QVariantList wordsList = jda.load(QDir::current().absoluteFilePath("app/native/assets/json/words.json")).toList();
        wordsDataModel->append(wordsList);
        addToWords();
    }

    ListView *wordsListView = ListView::create().
            listItemProvider(new EmailItemProvider(itemColor)).
            connect(SIGNAL(triggered(QVariantList)), this, SLOT(onWordsListTriggered(QVariantList))).
            dataModel(wordsDataModel);

    Container *wordsRootC = Container::create().
            background(bgColor).
            left(6).
            top(6).
            right(6).
            bottom(6).
            add(wordsListView);

    wordsNavPane = NavigationPane::create().
            add(Page::create().content(wordsRootC));
    connect(wordsNavPane, SIGNAL(popTransitionEnded(bb::cascades::Page*)), this, SLOT(onPopEnded(bb::cascades::Page*)));
    connect(wordsNavPane, SIGNAL(topChanged(bb::cascades::Page*)), this, SLOT(onNavpaneTopChanged()));

    Tab *wordsTab = Tab::create().
            content(wordsNavPane).
            title("Saved words").
            image("asset:///images/icons/ic_view_list.png");

    quotesDataModel = new ArrayDataModel;

    if(QFile(QDir::home().absoluteFilePath("quotes.json")).exists())
    {
        QVariantList quotesList = jda.load(QDir::home().absoluteFilePath("quotes.json")).toList();
        quotesDataModel->append(quotesList);
    }
    else
    {
        QVariantList quotesList = jda.load(QDir::current().absoluteFilePath("app/native/assets/json/quotes.json")).toList();
        quotesDataModel->append(quotesList);
        addToQuotes();
    }

    ListView *quotesListView = ListView::create().
            listItemProvider(new QuotesItemProvider(itemColor)).
            connect(SIGNAL(triggered(QVariantList)), this, SLOT(onQuotesListTriggered(QVariantList))).
            dataModel(quotesDataModel);

    Container *quotesRootC = Container::create().
            background(bgColor).
            left(6).
            top(6).
            right(6).
            bottom(6).
            add(quotesListView);

    quotesNavPane = NavigationPane::create().
            add(Page::create().content(quotesRootC));
    connect(quotesNavPane, SIGNAL(popTransitionEnded(bb::cascades::Page*)), this, SLOT(onPopEnded(bb::cascades::Page*)));
    connect(quotesNavPane, SIGNAL(topChanged(bb::cascades::Page*)), this, SLOT(onNavpaneTopChanged()));

    Tab *quotesTab = Tab::create().
            content(quotesNavPane).
            title("Saved quotes").
            image("asset:///images/icons/ic_quote.png");

    rootPane = TabbedPane::create().
            showTabsOnActionBar(TRUE).
            add(homeTab).
            add(wordsTab).
            add(quotesTab);

    onRefreshQuote();

    //QSettings appSettings("Prisma", "Momentum");
    if(appSettings.value("lastDate", QDate::currentDate().addDays(-1)).toDate()==QDate::currentDate())
    {
        QVariantMap lastWord = appSettings.value("lastSavedWord").toMap();
        //qDebug()<<"Last saved"<<lastWord;
        randomWordIndex = -1;

        wordMap["word"] = lastWord["word"].toString();
        wordMap["note"] = lastWord["note"].toString();

        /*QList<QVariant> examplesList;
        QVariantList replyExamplesList = lastWord["examples"].toList();
        for(int i=0; i<replyExamplesList.size(); i++)
        {
            examplesList.append(replyExamplesList.at(i).toMap()["text"].toString());
        }*/
        wordMap["examples"] = lastWord["examples"].toList();

        QList<QVariant> definitionsList;
        QVariantList replyDefinitionsList = lastWord["definitions"].toList();
        for(int i=0; i<replyDefinitionsList.size(); i++)
        {
            QVariantMap tempDefMap;
            tempDefMap["text"] = replyDefinitionsList.at(i).toMap()["text"].toString();
            tempDefMap["partOfSpeech"] = replyDefinitionsList.at(i).toMap()["partOfSpeech"].toString();

            definitionsList.append(tempDefMap);
        }
        wordMap["definitions"] = definitionsList;

        wordLabel->setText(wordMap["word"].toString());

        QString word = wordMap["word"].toString();
        bool found = FALSE;
        for(int i=0; i<wordsDataModel->size(); ++i)
        {
            if(wordsDataModel->value(i).toMap()["word"].toString()==word)
            {
                found = TRUE;
                break;
            }
        }
        if(found)
            addWordButton->setVisible(FALSE);
        else
            addWordButton->setVisible(TRUE);

        reloadWordButton->setVisible(FALSE);
        isWordLoading = FALSE;
    }
    else
    {
        onRefreshWord();
    }

    HelpActionItem *helpAction = HelpActionItem::create().
            onTriggered(this, SLOT(onHelpActionTriggered()));

    ActionItem *infoAction = ActionItem::create().
            image("asset:///images/icons/ic_info.png").
            title("Info").
            onTriggered(this, SLOT(onInfoActionTriggered()));

    SettingsActionItem *settingsAction = SettingsActionItem::create().
            onTriggered(this, SLOT(onSettingsActionTriggered()));

    Menu *appMenu = Menu::create().
            help(helpAction).
            addAction(infoAction).
            settings(settingsAction);
    Application::instance()->setMenu(appMenu);
    Application::instance()->setScene(rootPane);

}
