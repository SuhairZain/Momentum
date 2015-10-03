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

#ifndef ApplicationUI_HPP_
#define ApplicationUI_HPP_

#include <QObject>
#include <bb/cascades/ArrayDataModel>
#include <bb/cascades/Color>
#include <bb/cascades/Container>
#include <bb/cascades/ImageButton>
#include <bb/cascades/Label>
#include <bb/cascades/NavigationPane>
#include <bb/cascades/TabbedPane>

using namespace bb::cascades;

class ApplicationUI : public QObject
{
    Q_OBJECT
public:
    ApplicationUI();
private slots:
    void addToQuotes();
    void addToWords();
    void onClearClicked();
    void onHelpActionTriggered();
    void onInfoActionTriggered();
    void onInfoPageSupportTapped();
    void onMomentumClicked();
    void onMomentumIntroGoClicked(bool);
    void onNavpaneTopChanged();
    void onNetworkConnectionsTapped();
    void onPopEnded(bb::cascades::Page*);
    void onQuotesListTriggered(QVariantList);
    void onQuotesReplyFinished();
    void onQuoteTapped();
    void onRefreshQuote();
    void onRefreshWord();
    void onSettingsActionTriggered();
    void onSettingsPageIntroMessageChanged(bool);
    void onSettingsPageSupportMessageChanged(bool);
    void onSupportTapped();
    void onWordsListTriggered(QVariantList);
    void onWordsReplyFinished();
    void onWordTapped();
    void setupAppView();

private:
    int randomWordIndex, randomQuoteIndex;
    bool isQuoteLoading, isWordLoading;

    ArrayDataModel *wordsDataModel, *quotesDataModel;
    Color bgColor, itemColor;
    Container *noConnectionC, *supportC;
    ImageButton *addWordButton, *addQuoteButton, *reloadWordButton;
    Label *wordLabel, *quoteLabel;
    NavigationPane *homeNavPane, *wordsNavPane, *quotesNavPane;
    QNetworkAccessManager netManager;
    QVariantMap quoteMap, wordMap;
    TabbedPane *rootPane;
};

#endif /* ApplicationUI_HPP_ */
