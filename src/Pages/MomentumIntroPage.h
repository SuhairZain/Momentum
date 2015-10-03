/*
 * MomentumIntroPage.h
 *
 *  Created on: Oct 23, 2014
 *      Author: SuhairZain
 */

#ifndef MOMENTUMINTROPAGE_H_
#define MOMENTUMINTROPAGE_H_

#include <bb/cascades/CheckBox>
#include <bb/cascades/Color>
#include <bb/cascades/Page>

using namespace bb::cascades;

class MomentumIntroPage: public Page
{
Q_OBJECT
signals:
    void goClicked(bool);
private slots:
    void onGoClicked();
public:
    MomentumIntroPage(Color, Color);
private:
    CheckBox *checkBox;
};

#endif /* MOMENTUMINTROPAGE_H_ */
