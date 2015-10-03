import bb.cascades 1.2

Page {
    Container {
        layout: DockLayout {
            
        }
        leftPadding: 6
        topPadding: 6
        rightPadding: 6
        bottomPadding: 6
        background: Color.create("#c63d0f")
        Container {
            layout: DockLayout {
            
            }
            background: Color.create("#eab543")
            horizontalAlignment: HorizontalAlignment.Fill
            verticalAlignment: VerticalAlignment.Fill
            Container {
                horizontalAlignment: HorizontalAlignment.Center
                verticalAlignment: VerticalAlignment.Center
                Label {
                    text: "Bernard Shaw"
                    multiline: true
                    horizontalAlignment: HorizontalAlignment.Center
                    textStyle.color: Color.DarkGray
                    textStyle.fontSize: FontSize.PointValue
                    textStyle.fontSizeValue: 8
                }
                Label {
                    horizontalAlignment: HorizontalAlignment.Center
                    multiline: true
                    textStyle.textAlign: TextAlign.Center
                    textStyle.color: Color.Black
                    textStyle.fontSize: FontSize.PointValue
                    textStyle.fontSizeValue: 12
                    textStyle.fontWeight: FontWeight.W100
                    text: "A life spent making mistakes is not only more honourable but more useful than a life spent in doing nothing. Even if it wasn't so, I wouldn't care. Would I actually say that? Well, what if I really did. Wow, this is awesome. It's fabulous and wonderful too. Oh My God."
                }
                Label {
                    multiline: true
                    horizontalAlignment: HorizontalAlignment.Center
                    //textStyle.color: Color.DarkGray
                    textFormat: TextFormat.Html
                    textStyle.fontSize: FontSize.PointValue
                    textStyle.fontSizeValue: 7
                    //textStyle.fontWeight: FontWeight.W800
                    text: "<a href=\"http://forismatic.com/en/d832db6eb0/\">http://forismatic.com/en/d832db6eb0/</a>"
                }
            }
        }
    }
}
