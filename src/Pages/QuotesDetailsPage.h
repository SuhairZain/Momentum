/*
 * QuotesDetailsPage.h
 *
 *  Created on: Oct 15, 2014
 *      Author: SuhairZain
 */

#ifndef QUOTESDETAILSPAGE_H_
#define QUOTESDETAILSPAGE_H_

#include <bb/cascades/Color>
#include <bb/cascades/Page>

using namespace bb::cascades;

class QuotesDetailsPage: public Page
{
Q_OBJECT
private slots:
    void onCopyQuoteAuthorTriggered();
    void onCopyQuoteTriggered();
public:
    QuotesDetailsPage(QVariantMap, Color, Color);
private:
    QString quote, author;
};

#endif /* QUOTESDETAILSPAGE_H_ */
