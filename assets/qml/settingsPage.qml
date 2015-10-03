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
        Container {
            leftPadding: 6
            topPadding: 6
            rightPadding: 6
            bottomPadding: 6
            bottomMargin: 6
            horizontalAlignment: HorizontalAlignment.Fill
            background: Color.create(itemColor)
            layout: StackLayout {
                orientation: LayoutOrientation.LeftToRight
            }
            Label {
                verticalAlignment: VerticalAlignment.Center
                layoutProperties: StackLayoutProperties {
                    spaceQuota: 1
                }
                multiline: true
                text: "Show support message"
                textStyle.color: Color.Black
                textStyle.fontSize: FontSize.PointValue
                textStyle.fontSizeValue: 10
                textStyle.fontWeight: FontWeight.W100
            }
            ToggleButton {
                verticalAlignment: VerticalAlignment.Center
            }
        }
        Container {
            leftPadding: 6
            topPadding: 6
            rightPadding: 6
            bottomPadding: 6
            horizontalAlignment: HorizontalAlignment.Fill
            background: Color.create(itemColor)
            layout: StackLayout {
                orientation: LayoutOrientation.LeftToRight
            }
            Label {
                verticalAlignment: VerticalAlignment.Center
                layoutProperties: StackLayoutProperties {
                    spaceQuota: 1
                }
                multiline: true
                text: "Show momentum intro"
                textStyle.color: Color.Black
                textStyle.fontSize: FontSize.PointValue
                textStyle.fontSizeValue: 10
                textStyle.fontWeight: FontWeight.W100
            }
            ToggleButton {
                verticalAlignment: VerticalAlignment.Center
            }
        }
    }
}
