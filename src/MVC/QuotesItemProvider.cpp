/*
 * QuotesItemProvider.cpp
 *
 *  Created on: Oct 15, 2014
 *      Author: SuhairZain
 */

#include <src/MVC/QuotesItemProvider.h>

#include <bb/cascades/Container>
#include <bb/cascades/controls/labelautosizeproperties.h>

QuotesItem::QuotesItem(Color color)
{
    name = Label::create().
            maxLineCount(2).
            multiline(TRUE);
    //name->autoSize()->setMaxLineCount(3);
    name->textStyle()->setColor(Color::Black);
    name->textStyle()->setFontSize(FontSize::PointValue);
    name->textStyle()->setFontSizeValue(10);
    name->textStyle()->setFontWeight(FontWeight::W100);

    Container *rootC = Container::create().
            //horizontal(HorizontalAlignment::Fill).
            left(6).
            top(6).
            right(6).
            bottom(6).
            preferredWidth(1440).
            background(color).
            add(name);

    setRoot(rootC);
    //setHorizontalAlignment(HorizontalAlignment::Fill);
    setBottomMargin(6);
}

void QuotesItem::activate(bool activate)
{
    // There is no special activate state, select and activated looks the same.
    /*if(activate)
    {
        borderContainer->setVisible(TRUE);
    }
    else
    {
        borderContainer->setVisible(FALSE);
    }*/
    select(activate);
}

void QuotesItem::reset(bool selected, bool activated)
{
    Q_UNUSED(activated);

    // Since items are recycled the reset function is where we have
    // to make sure that item state, defined by the arguments, is correct.
    select(selected);
}

void QuotesItem::select(bool /*select*/)
{
}

void QuotesItem::updateItem(const QString nameString)
{
    name->setText(nameString);
}

VisualNode * QuotesItemProvider::createItem(ListView*/* list*/, const QString &/*type*/)
{
    //We only have one item type so we do not need to check the type variable.
    QuotesItem *myItem = new QuotesItem(itemColor);
    return myItem;
}

void QuotesItemProvider::updateItem(ListView*, bb::cascades::VisualNode *listItem,
        const QString &, const QVariantList &, const QVariant &data)
{
    /*Q_UNUSED(list);
    Q_UNUSED(type);
    Q_UNUSED(indexPath);*/

    // Update the control with correct data.
    QString word = data.toMap()["quote"].toString();
    static_cast<QuotesItem *>(listItem)->updateItem(word);
}
