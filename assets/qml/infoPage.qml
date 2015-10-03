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
            Container {
                background: Color.create(itemColor)
                horizontalAlignment: HorizontalAlignment.Fill
                layoutProperties: StackLayoutProperties {
                    spaceQuota: 0.5
                }
                bottomMargin: 6
                layout: DockLayout {
                    
                }
                ImageView {
                    horizontalAlignment: HorizontalAlignment.Center
                    verticalAlignment: VerticalAlignment.Center
                    imageSource: "asset:///images/logo.png"
                }
            }
            Container {
                background: Color.create(itemColor)
                horizontalAlignment: HorizontalAlignment.Fill
                layoutProperties: StackLayoutProperties {
                    spaceQuota: 0.4
                }
                bottomMargin: 6
                layout: DockLayout {
                
                }
                Container {
                    horizontalAlignment: HorizontalAlignment.Center
                    verticalAlignment: VerticalAlignment.Center
                    Label {
                        horizontalAlignment: HorizontalAlignment.Center
                        text: "Support us"
                        textStyle.color: Color.DarkGray
                        textStyle.fontSize: FontSize.PointValue
                        textStyle.fontSizeValue: 9
                    }   
                    Label {
                        horizontalAlignment: HorizontalAlignment.Center
                        multiline: true
                        text: "Please support us by leaving a review or donation. Click here to know more"
                        textStyle.color: Color.White
                        textStyle.fontSize: FontSize.PointValue
                        textStyle.fontSizeValue: 7
                        textStyle.textAlign: TextAlign.Center
                    }
                }
            }
            Container {
                background: Color.create(itemColor)
                horizontalAlignment: HorizontalAlignment.Fill
                layoutProperties: StackLayoutProperties {
                    spaceQuota: 1
                }
                layout: DockLayout {
                    
                }
                Label {
                    horizontalAlignment: HorizontalAlignment.Center
                    verticalAlignment: VerticalAlignment.Center
                    multiline: true
                    text:"Quotes provided by forismatic.com\n" +
                    "Word of the day provided by wordnik.com" + 
                    "\n\nCoded by Suhair Zain\n" +
                    "Images by Vishnu GP\n\n" +
                    "You may obtain the source code for this project from github.com/suhairzain"
                    textStyle.fontSize: FontSize.PointValue
                    textStyle.fontSizeValue: 8
                    textStyle.color: Color.Black
                    textStyle.textAlign: TextAlign.Center
                    textStyle.fontWeight: FontWeight.W100
                }
            }
        }
    }
}
