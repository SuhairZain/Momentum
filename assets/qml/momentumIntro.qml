import bb.cascades 1.2

Page {
    property string bgColor: "#c63d0f"
    property string itemColor: "#eab543"
    Container {
        background: Color.create(bgColor)
        leftPadding: 6
        topPadding: 6
        rightPadding: 6
        bottomPadding: 6
        layout: DockLayout {
            
        }
        Container {
            horizontalAlignment: HorizontalAlignment.Fill
            verticalAlignment: VerticalAlignment.Fill
            background: Color.create(itemColor)
            layout: DockLayout {
                
            }
            Container {
                leftPadding: 6
                rightPadding: 6
                horizontalAlignment: HorizontalAlignment.Fill
                verticalAlignment: VerticalAlignment.Center
                Label {
                    horizontalAlignment: HorizontalAlignment.Center
                    textStyle.color: Color.Black
                    textStyle.fontSize: FontSize.PointValue
                    textStyle.fontSizeValue: 8
                    textStyle.fontWeight: FontWeight.W100
                    textStyle.textAlign: TextAlign.Center
                    multiline: true
                    text: "We know that you have something important to do today "+
                    "and that you would love to be reminded about it. We help you "+ 
                    "remember it by setting it as your wallpaper. Awesome, isn't it?"
                }
                Container {
                    horizontalAlignment: HorizontalAlignment.Center
                    layout: StackLayout {
                        orientation: LayoutOrientation.LeftToRight
                    }
                    CheckBox {
                    }
                    Label {
                        horizontalAlignment: HorizontalAlignment.Right
                        text: "I got it. Do not show this message again"
                        textStyle.color: Color.Black
                        textStyle.fontSize: FontSize.PointValue
                        textStyle.fontSizeValue: 7
                        textStyle.fontWeight: FontWeight.W100
                    }
                }
                ImageButton {
                    horizontalAlignment: HorizontalAlignment.Center
                    defaultImageSource: "asset:///images/buttons/goButton.png"
                }
            }
        }
    }
}
