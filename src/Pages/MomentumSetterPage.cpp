/*
 * MomentumSetterPage.cpp
 *
 *  Created on: Oct 23, 2014
 *      Author: SuhairZain
 */

#include <src/Pages/MomentumSetterPage.h>

#include <bb/device/DisplayInfo>
#include <bb/cascades/DockLayout>
#include <bb/cascades/DropDown>
#include <bb/platform/HomeScreen>
#include <bb/cascades/ImageButton>
#include <bb/system/ScreenShot>
#include <bb/cascades/ScrollView>
#include <bb/cascades/StackLayout>
#include <bb/cascades/TapHandler>
#include <bb/cascades/TextField>

#include <src/Pages/MomentumSetterThumb.h>

MomentumSetterPage::MomentumSetterPage(Color bg, Color item)
{
    tempD = NULL;
    lastTapped = 0;

    TextField *goalField = TextField::create().
            horizontal(HorizontalAlignment::Fill).
            hintText("Enter your goal here").
            connect(SIGNAL(textChanging(QString)),
                    this, SLOT(onGoalFieldTextChanging(QString)));

    /*ImageButton *chooseImage = ImageButton::create().
            horizontal(HorizontalAlignment::Center).
            defaultImage("asset:///images/chooseImage.png");*/

    imagesC = Container::create().
            layout(StackLayout::create().orientation(LayoutOrientation::LeftToRight));

    ScrollView *imageScroll = ScrollView::create().
            scrollMode(ScrollMode::Horizontal).
            content(imagesC);

    MomentumSetterThumb *thumb = new MomentumSetterThumb(0, bg, TRUE);
    connect(thumb, SIGNAL(tapped(int)), this, SLOT(onThumbTapped(int)));
    imagesC->add(thumb);

    for(int i=1; i<18; ++i)
    {
        MomentumSetterThumb *thumb = new MomentumSetterThumb(i, bg);
        connect(thumb, SIGNAL(tapped(int)), this, SLOT(onThumbTapped(int)));
        imagesC->add(thumb);
    }

    DropDown *colorChooser = DropDown::create().
            title("Text color");

    colorList<<"Black"<<"Blue"<<"Cyan"<<"Dark Blue"<<"Dark Cyan"
            <<"Dark Gray"<<"Dark Green"<<"Dark Magenta"<<"Dark Red"<<"Dark Yellow"
            <<"Gray"<<"Green"<<"Light Gray"<<"Magenta"<<"Red"
            <<"White"<<"Yellow"<<"Purple";

    for(int i=0; i<15; ++i)
        colorChooser->add(Option::create().text(colorList.at(i)).value(colorList.at(i)));

    colorChooser->add(Option::create().text(colorList.at(15)).value(colorList.at(15)).selected(TRUE));
    colorChooser->add(Option::create().text(colorList.at(16)).value(colorList.at(16)));
    colorChooser->add(Option::create().text(colorList.at(17)).value(colorList.at(17)));
    connect(colorChooser, SIGNAL(selectedValueChanged(QVariant)),
            this, SLOT(onSelectedValueChanged(QVariant)));

    ImageButton *setAsWallpaper = ImageButton::create().
            horizontal(HorizontalAlignment::Center).
            defaultImage("asset:///images/buttons/setAsWall.png").
            connect(SIGNAL(clicked()), this, SLOT(onSetAsWallClicked()));

    Container *contentC = Container::create().
            horizontal(HorizontalAlignment::Fill).
            vertical(VerticalAlignment::Bottom).
            background(item).
            left(6).
            top(6).
            right(6).
            bottom(6).
            add(goalField).
            add(imageScroll).
            //add(chooseImage).
            add(colorChooser).
            add(setAsWallpaper);

    TapHandler *previewTapHandler = TapHandler::create().
            onTapped(this, SLOT(onPreviewTapped()));

    bb::device::DisplayInfo dispInfo;

    image = ImageView::create().
            horizontal(HorizontalAlignment::Fill).
            vertical(VerticalAlignment::Fill).
            scalingMethod(ScalingMethod::AspectFill).
            image("asset:///images/wallpapers/0.png");

    goalLabel = Label::create().
            horizontal(HorizontalAlignment::Center).
            vertical(VerticalAlignment::Center).
            multiline(TRUE).
            text("Your goal appears here. Tap me to expand.");
    goalLabel->textStyle()->setColor(Color::White);
    goalLabel->textStyle()->setFontSize(FontSize::PointValue);
    goalLabel->textStyle()->setFontSizeValue(28);
    goalLabel->textStyle()->setTextAlign(TextAlign::Center);

    previewC = Container::create().
            layout(DockLayout::create()).
            horizontal(HorizontalAlignment::Fill).
            vertical(VerticalAlignment::Fill).
            scale(0.5).
            left(6).
            top(6).
            right(6).
            bottom(6).
            pivotY(-dispInfo.pixelSize().height()/2).
            addGestureHandler(previewTapHandler).
            background(bg).
            add(image).
            add(goalLabel);

    Container *rootC = Container::create().
            layout(DockLayout::create()).
            background(bg).
            add(contentC).
            add(previewC);
    setContent(rootC);
}

void MomentumSetterPage::captureScreenAfterDelay()
{
    bb::system::Screenshot sShot;
    QString fName = sShot.captureDisplay(QUrl(QDir::home().absoluteFilePath("ScreenShots/ss.jpg")));
    if(fName.isEmpty())
        qDebug()<<"Error"<<sShot.error();
    else
    {
        bb::platform::HomeScreen homeScr;
        homeScr.setWallpaper(QUrl("data/ScreenShots/ss.jpg"));
    }

    tempD->close();
}

void MomentumSetterPage::onDialogOpened()
{
    QTimer::singleShot(300, this, SLOT(captureScreenAfterDelay()));
}

void MomentumSetterPage::onGoalFieldTextChanging(QString text)
{
    if(text=="")
        goalLabel->setText("Your goal appears here. Tap me to expand.");
    else
        goalLabel->setText(text);
}

void MomentumSetterPage::onPreviewTapped()
{
    if(previewC->scaleX()==0.5f)
    {
        previewC->setScale(1);
    }
    else
    {
        previewC->setScale(0.5f);
    }
}

void MomentumSetterPage::onSelectedValueChanged(QVariant value)
{
    switch(colorList.indexOf(value.toString()))
    {
        case 0:
            goalLabel->textStyle()->setColor(Color::Black);
            break;
        case 1:
            goalLabel->textStyle()->setColor(Color::Blue);
            break;
        case 2:
            goalLabel->textStyle()->setColor(Color::Cyan);
            break;
        case 3:
            goalLabel->textStyle()->setColor(Color::DarkBlue);
            break;
        case 4:
            goalLabel->textStyle()->setColor(Color::DarkCyan);
            break;
        case 5:
            goalLabel->textStyle()->setColor(Color::DarkGray);
            break;
        case 6:
            goalLabel->textStyle()->setColor(Color::DarkGreen);
            break;
        case 7:
            goalLabel->textStyle()->setColor(Color::DarkMagenta);
            break;
        case 8:
            goalLabel->textStyle()->setColor(Color::DarkRed);
            break;
        case 9:
            goalLabel->textStyle()->setColor(Color::DarkYellow);
            break;
        case 10:
            goalLabel->textStyle()->setColor(Color::Gray);
            break;
        case 11:
            goalLabel->textStyle()->setColor(Color::Green);
            break;
        case 12:
            goalLabel->textStyle()->setColor(Color::LightGray);
            break;
        case 13:
            goalLabel->textStyle()->setColor(Color::Magenta);
            break;
        case 14:
            goalLabel->textStyle()->setColor(Color::Red);
            break;
        case 15:
            goalLabel->textStyle()->setColor(Color::White);
            break;
        case 16:
            goalLabel->textStyle()->setColor(Color::Yellow);
            break;
        case 17:
            goalLabel->textStyle()->setColor(Color::fromARGB(0xffc90369));
    }
}

void MomentumSetterPage::onSetAsWallClicked()
{
    ImageView *dialogImage = ImageView::create().
            horizontal(HorizontalAlignment::Fill).
            vertical(VerticalAlignment::Fill).
            scalingMethod(ScalingMethod::AspectFill).
            image(Image("asset:///images/wallpapers/" + QString::number(lastTapped) + ".png"));

    Label *dialogGoalLabel = Label::create().
            horizontal(HorizontalAlignment::Center).
            vertical(VerticalAlignment::Center).
            multiline(TRUE).
            text(goalLabel->text());
    dialogGoalLabel->textStyle()->setColor(goalLabel->textStyle()->color());
    dialogGoalLabel->textStyle()->setFontSize(FontSize::PointValue);
    dialogGoalLabel->textStyle()->setFontSizeValue(28);
    dialogGoalLabel->textStyle()->setTextAlign(TextAlign::Center);

    Container *rootC = Container::create().
            background(previewC->background().value<Color>()).
            left(6).
            top(6).
            right(6).
            bottom(6).
            layout(DockLayout::create()).
            add(dialogImage).
            add(dialogGoalLabel);

    Dialog *goalPopup = Dialog::create().
            onOpened(this, SLOT(onDialogOpened())).
            content(rootC);
    connect(goalPopup, SIGNAL(closed()), goalPopup, SLOT(deleteLater()));
    tempD = goalPopup;
    goalPopup->open();
}

void MomentumSetterPage::onThumbTapped(int num)
{
    static_cast<Container*>(imagesC->at(lastTapped))->resetBackground();
    lastTapped = num;
    image->setImage(Image("asset:///images/wallpapers/" + QString::number(num) + ".png"));
}
