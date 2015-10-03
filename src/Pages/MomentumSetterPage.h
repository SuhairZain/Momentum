/*
 * MomentumSetterPage.h
 *
 *  Created on: Oct 23, 2014
 *      Author: SuhairZain
 */

#ifndef MOMENTUMSETTERPAGE_H_
#define MOMENTUMSETTERPAGE_H_

#include <bb/cascades/Color>
#include <bb/cascades/Container>
#include <bb/cascades/Dialog>
#include <bb/cascades/ImageView>
#include <bb/cascades/Label>
#include <bb/cascades/Page>

using namespace bb::cascades;

class MomentumSetterPage: public Page
{
Q_OBJECT
private slots:
    void captureScreenAfterDelay();
    void onDialogOpened();
    void onGoalFieldTextChanging(QString);
    void onPreviewTapped();
    void onSelectedValueChanged(QVariant);
    void onSetAsWallClicked();
    void onThumbTapped(int);
public:
    MomentumSetterPage(Color, Color);
private:
    int lastTapped;

    Container *previewC, *imagesC;
    Dialog *tempD;
    ImageView *image;
    Label *goalLabel;
    QList<QString> colorList;
};

#endif /* MOMENTUMSETTERPAGE_H_ */
