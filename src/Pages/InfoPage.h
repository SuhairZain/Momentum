/*
 * InfoPage.h
 *
 *  Created on: Oct 21, 2014
 *      Author: SuhairZain
 */

#ifndef INFOPAGE_H_
#define INFOPAGE_H_

#include <bb/cascades/Color>
#include <bb/cascades/Page>

using namespace bb::cascades;

class InfoPage: public Page
{
Q_OBJECT
signals:
    void supportTapped();
public:
    InfoPage(Color, Color);
};

#endif /* INFOPAGE_H_ */
