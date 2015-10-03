import bb.cascades 1.2

Page {
    property string bgColor: "#c63d0f"
    property string itemColor: "#eab543"
    property color tColor: Color.Black
    Container {
        background: Color.create(bgColor)
        leftPadding: 6
        topPadding: 6
        rightPadding: 6
        bottomPadding: 6
        Container {
            bottomMargin: 6
            background: Color.create(itemColor)
            horizontalAlignment: HorizontalAlignment.Fill
            layoutProperties: StackLayoutProperties {
                spaceQuota: 0.9
            }
            Label {
                horizontalAlignment: HorizontalAlignment.Center
                text: "Why do it?"
                textStyle.color: Color.DarkGray
                textStyle.fontSize: FontSize.PointValue
                textStyle.fontSizeValue: 8
            }
            Label {
                horizontalAlignment: HorizontalAlignment.Center
                multiline: true
                text: "We believe that everyone has the right to " + 
                "everything good. And thus we didn't wanted to put our app on sale. " +  
                "This is an open source project and to help us continue this effort, we request you to make a donation " +
                "or write us a review, or both if you feel generous."+
                "\nYou can disable this request from settings."
                textStyle.textAlign: TextAlign.Center
                textStyle.fontWeight: FontWeight.W100
                textStyle.fontSize: FontSize.PointValue
                textStyle.fontSizeValue: 7
            }
        }
        Container {
            layoutProperties: StackLayoutProperties {
                spaceQuota: 0.4
            }
            bottomMargin: 6
            horizontalAlignment: HorizontalAlignment.Fill
            background: Color.create(itemColor)
            Label {
                horizontalAlignment: HorizontalAlignment.Center
                text: "Review our app"
                textStyle.color: Color.DarkGray
                textStyle.fontSize: FontSize.PointValue
                textStyle.fontSizeValue: 8
            }
            Container {
                layoutProperties: StackLayoutProperties {
                    spaceQuota: 1
                }
                layout: DockLayout {
                
                }
                horizontalAlignment: HorizontalAlignment.Center
                Button {
                    horizontalAlignment: HorizontalAlignment.Center
                    verticalAlignment: VerticalAlignment.Center
                    text: "Go to app page on BlackBerry World"
                }
            }
        }
        Container {
            id: donationC
            layoutProperties: StackLayoutProperties {
                spaceQuota: 0.9
            }
            background: Color.create(itemColor)
            horizontalAlignment: HorizontalAlignment.Fill
            //bottomMargin: 6
            Label {
                horizontalAlignment: HorizontalAlignment.Center
                text: "Or make a donation"
                textStyle.color: Color.DarkGray
            }
            Container {
                id: donationAmountC
                horizontalAlignment: HorizontalAlignment.Center
                layoutProperties: StackLayoutProperties {
                    spaceQuota: 1
                }
                layout: DockLayout {
                
                }
                Container {
                    id: donationButtonsC
                    horizontalAlignment: HorizontalAlignment.Center
                    verticalAlignment: VerticalAlignment.Center
                    layout: StackLayout {
                        orientation: LayoutOrientation.LeftToRight
                    }
                    Container {
                        id: donate3c
                        layout: DockLayout {
                        
                        }
                        leftPadding: 6
                        topPadding: 6
                        bottomPadding: 6
                        background: Color.create(bgColor)
                        ImageButton {
                            defaultImageSource: "asset:///images/buttons/3.png"
                        }
                    }
                    Container {
                        layout: DockLayout {
                        
                        }
                        leftPadding: 6
                        topPadding: 6
                        bottomPadding: 6
                        background: Color.create(bgColor)
                        ImageButton {
                            defaultImageSource: "asset:///images/buttons/2.png"
                        }
                    }
                    Container {
                        layout: DockLayout {
                        
                        }
                        leftPadding: 6
                        topPadding: 6
                        rightPadding: 6
                        bottomPadding: 6
                        background: Color.create(bgColor)
                        ImageButton {
                            defaultImageSource: "asset:///images/buttons/1.png"
                        }
                    }
                }
            }
        }
    }
}
