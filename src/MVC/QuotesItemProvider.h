/*
 * QuotesItemProvider.h
 *
 *  Created on: Oct 15, 2014
 *      Author: SuhairZain
 */

#ifndef QUOTESITEMPROVIDER_H_
#define QUOTESITEMPROVIDER_H_

#include <bb/cascades/CustomControl>
#include <bb/cascades/Label>
#include <bb/cascades/ListItemListener>
#include <bb/cascades/ListItemProvider>

using namespace bb::cascades;

class QuotesItem: public CustomControl, public ListItemListener
{
Q_OBJECT
public:
    QuotesItem(Color);

    void updateItem(const QString);
    void select(bool select);
    void reset(bool selected, bool activated);
    void activate(bool activate);

private:
    Label *name;
};

class QuotesItemProvider: public ListItemProvider
{
public:
    QuotesItemProvider(Color color){itemColor = color;};
    VisualNode *createItem(ListView*, const QString &);

    void updateItem(ListView*, VisualNode*, const QString&,
                    const QVariantList&, const QVariant&);
private:
    Color itemColor;
};

#endif /* QUOTESITEMPROVIDER_H_ */
