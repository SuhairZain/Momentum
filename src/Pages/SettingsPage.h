/*
 * SettingsPage.h
 *
 *  Created on: Oct 21, 2014
 *      Author: SuhairZain
 */

#ifndef SETTINGSPAGE_H_
#define SETTINGSPAGE_H_

#include <bb/cascades/Color>
#include <bb/cascades/Page>

using namespace bb::cascades;

class SettingsPage: public Page
{
Q_OBJECT
signals:
    void introMessageChanged(bool);
    void supportMessageChanged(bool);
public:
    SettingsPage(Color, Color, bool, bool);
};

#endif /* SETTINGSPAGE_H_ */
