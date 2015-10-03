/*
 * WordsItemProvider.h
 *
 *  Created on: Oct 14, 2014
 *      Author: SuhairZain
 */

#ifndef WORDSITEMPROVIDER_H_
#define WORDSITEMPROVIDER_H_

#include <bb/cascades/CustomControl>
#include <bb/cascades/Label>
#include <bb/cascades/ListItemListener>
#include <bb/cascades/ListItemProvider>

using namespace bb::cascades;

class EmailItem: public CustomControl, public ListItemListener
{
Q_OBJECT
public:
    EmailItem(Color);

    void updateItem(const QString);
    void select(bool select);
    void reset(bool selected, bool activated);
    void activate(bool activate);

private:
    Label *name;
};

class EmailItemProvider: public ListItemProvider
{
public:
    EmailItemProvider(Color color){itemColor = color;}
    VisualNode *createItem(ListView*, const QString &);

    void updateItem(ListView*, VisualNode*, const QString&,
            const QVariantList&, const QVariant&);
private:
    Color itemColor;
};

#endif /* WORDSITEMPROVIDER_H_ */
