/*
 * WordsItemProvider.cpp
 *
 *  Created on: Oct 14, 2014
 *      Author: SuhairZain
 */

#include <src/MVC/WordsItemProvider.h>

#include <bb/cascades/Container>

EmailItem::EmailItem(Color color)
{
    name = Label::create();
    name->textStyle()->setColor(Color::Black);
    name->textStyle()->setFontSize(FontSize::PointValue);
    name->textStyle()->setFontSizeValue(17);
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

void EmailItem::activate(bool activate)
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

void EmailItem::reset(bool selected, bool activated)
{
    Q_UNUSED(activated);

    // Since items are recycled the reset function is where we have
    // to make sure that item state, defined by the arguments, is correct.
    select(selected);
}

void EmailItem::select(bool /*select*/)
{
}

void EmailItem::updateItem(const QString nameString)
{
    name->setText(nameString);
}

VisualNode * EmailItemProvider::createItem(ListView*/* list*/, const QString &/*type*/)
{
    //We only have one item type so we do not need to check the type variable.
    EmailItem *myItem = new EmailItem(itemColor);
    return myItem;
}

void EmailItemProvider::updateItem(ListView*, bb::cascades::VisualNode *listItem,
        const QString &, const QVariantList &, const QVariant &data)
{
    /*Q_UNUSED(list);
    Q_UNUSED(type);
    Q_UNUSED(indexPath);*/

    // Update the control with correct data.
    QString word = data.toMap()["word"].toString();
    static_cast<EmailItem *>(listItem)->updateItem(word);
}
