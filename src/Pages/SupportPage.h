/*
 * SupportPage.h
 *
 *  Created on: Oct 17, 2014
 *      Author: SuhairZain
 */

#ifndef SUPPORTPAGE_H_
#define SUPPORTPAGE_H_

#include <bb/cascades/Color>
#include <bb/cascades/Page>
#include <bb/platform/PaymentManager>
#include <bb/platform/PurchaseReply>

using namespace bb::cascades;

class SupportPage: public Page
{
Q_OBJECT
private slots:
    void on1Clicked();
    void on2Clicked();
    void on3Clicked();
    void onPurchaseFinished(bb::platform::PurchaseReply*);
    void purchaseWithSKU(QString);
public:
    SupportPage(Color, Color);
};

#endif /* SUPPORTPAGE_H_ */
