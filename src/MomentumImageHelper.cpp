/*
 * MomentumImageHelper.cpp
 *
 *  Created on: Oct 20, 2014
 *      Author: SuhairZain
 */

#include <src/MomentumImageHelper.h>

#include <Qt/qimage.h>
#include <bb/device/DisplayInfo>

QString MomentumImageHelper::fromText(QString /*text*/)
{
    qDebug()<<qApp->font();

    bb::device::DisplayInfo displayInfo;
    //int w=displayInfo.pixelSize().width(), h=displayInfo.pixelSize().height();
    int w = 320, h = 100;

    QImage finalImage(w, h, QImage::Format_ARGB32_Premultiplied);

    QPainter textPainter;
    textPainter.begin(&finalImage);
    qDebug()<<"1";
    finalImage.fill(Qt::white);
    textPainter.setPen(QPen(Qt::red, 12, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    qDebug()<<"Pen set";
    qDebug()<<textPainter.font();
    //qDebug()<<textPainter.fontInfo().family();
    //textPainter.drawLine(QPoint(0, 0), QPoint(320, 100));
    QFont arial("Arial", 10, 100, TRUE);
    textPainter.setFont(arial);
    qDebug()<<textPainter.font();

    //textPainter.drawText(QRectF(0, 0, 320, 100), Qt::AlignCenter, "I");
    qDebug()<<"2";

    finalImage.save(QDir::home().absoluteFilePath("image.png"), "png");

    return QDir::home().absoluteFilePath("image.png");
    //return bb::ImageData::fromPixels(finalImage.bits(), bb::PixelFormat::RGBA_Premultiplied, w, h, finalImage.bytesPerLine());
}

