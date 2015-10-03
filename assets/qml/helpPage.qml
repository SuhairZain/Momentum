import bb.cascades 1.2

Page {
    property string bgColor: "#c63d0f"
    property string itemColor: "#eab543"
    Container {
        layout: DockLayout {
            
        }
        background: Color.create(bgColor)
        leftPadding: 6
        topPadding: 6
        rightPadding: 6
        bottomPadding: 6
        Container {
            horizontalAlignment: HorizontalAlignment.Fill
            verticalAlignment: VerticalAlignment.Fill
            background: Color.create(itemColor)
            layout: DockLayout {
                
            }
            Container {
                horizontalAlignment: HorizontalAlignment.Fill
                verticalAlignment: VerticalAlignment.Fill
                ImageView {
                    horizontalAlignment: HorizontalAlignment.Center
                    imageSource: "asset:///images/logo.png"
                }
                Container {
                    layoutProperties: StackLayoutProperties {
                        spaceQuota: 1
                    }
                    layout: DockLayout {
                        
                    }
                    Label {
                        horizontalAlignment: HorizontalAlignment.Center
                        verticalAlignment: VerticalAlignment.Center
                        multiline: true
                        text: "This app shows you a new word to learn every day "+ 
                        "along with some quotes that can make your day. "+
                        "\n\nYou can set yourself in the right direction by "+
                        "setting your focus for the day, which will remind you "+
                        "by displaying it as the wallpaper. You can also choose from "+
                        "different wallpapers to set as the background for your goal."+
                        "\n\nYou can save the words and quotes so that you can view "+
                        "them even when there's no internet connection."
                        textStyle.color: Color.create(bgColor)
                        //textStyle.color: Color.White
                        textStyle.fontSize: FontSize.PointValue
                        textStyle.fontSizeValue: 7
                        textStyle.fontWeight: FontWeight.W100
                        textStyle.textAlign: TextAlign.Center
                    }
                }
            }
        }
    }
}
