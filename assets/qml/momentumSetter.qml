import bb.cascades 1.2

Page {
    property string bgColor: "#c63d0f"
    property string itemColor: "#eab543"
    property int iHeight: 80
    Container {
        background: Color.create(bgColor)
        /*leftPadding: 6
         topPadding: 6
         rightPadding: 6
         bottomPadding: 6*/
layout: DockLayout {
        
}
Container {
    horizontalAlignment: HorizontalAlignment.Fill
    verticalAlignment: VerticalAlignment.Bottom
    background: Color.create(itemColor)
    topPadding: 6
    bottomPadding: 6
    rightPadding: 6
    leftPadding: 6
    TextField {
        id: textField
        hintText: "Enter your goal here"
        onTextChanging: {
            textLabel.text = textField.text
        }
    }
    ScrollView {
        scrollViewProperties.scrollMode: ScrollMode.Horizontal
        Container {
            layout: StackLayout {
                orientation: LayoutOrientation.LeftToRight
            }
            Container {
                //background: Color.create(bgColor)
                leftPadding: 6
                rightPadding: 6
                topPadding: 6
                bottomPadding: 6
                ImageView {
                    verticalAlignment: VerticalAlignment.Center
                    preferredHeight: iHeight
                    scalingMethod: ScalingMethod.AspectFit
                    imageSource: "asset:///images/wallpapers/thumbs/1.png"
                }   
            }
            Container {
                background: Color.create(bgColor)
                leftPadding: 6
                rightPadding: 6
                topPadding: 6
                bottomPadding: 6
                ImageView {
                    verticalAlignment: VerticalAlignment.Center
                    preferredHeight: iHeight
                    scalingMethod: ScalingMethod.AspectFit
                    imageSource: "asset:///images/wallpapers/thumbs/1.png"
                }   
            }Container {
                //background: Color.create(bgColor)
                leftPadding: 6
                rightPadding: 6
                topPadding: 6
                bottomPadding: 6
                ImageView {
                    verticalAlignment: VerticalAlignment.Center
                    preferredHeight: iHeight
                    scalingMethod: ScalingMethod.AspectFit
                    imageSource: "asset:///images/wallpapers/thumbs/1.png"
                }   
            }
            Container {
                //background: Color.create(bgColor)
                leftPadding: 6
                rightPadding: 6
                topPadding: 6
                bottomPadding: 6
                ImageView {
                    verticalAlignment: VerticalAlignment.Center
                    preferredHeight: iHeight
                    scalingMethod: ScalingMethod.AspectFit
                    imageSource: "asset:///images/wallpapers/thumbs/1.png"
                }   
            }
            Container {
                //background: Color.create(bgColor)
                leftPadding: 6
                rightPadding: 6
                topPadding: 6
                bottomPadding: 6
                ImageView {
                    verticalAlignment: VerticalAlignment.Center
                    preferredHeight: iHeight
                    scalingMethod: ScalingMethod.AspectFit
                    imageSource: "asset:///images/wallpapers/thumbs/1.png"
                }   
            }
            Container {
                //background: Color.create(bgColor)
                leftPadding: 6
                rightPadding: 6
                topPadding: 6
                bottomPadding: 6
                ImageView {
                    verticalAlignment: VerticalAlignment.Center
                    preferredHeight: iHeight
                    scalingMethod: ScalingMethod.AspectFit
                    imageSource: "asset:///images/wallpapers/thumbs/1.png"
                }   
            }
            Container {
                //background: Color.create(bgColor)
                leftPadding: 6
                rightPadding: 6
                topPadding: 6
                bottomPadding: 6
                ImageView {
                    verticalAlignment: VerticalAlignment.Center
                    preferredHeight: iHeight
                    scalingMethod: ScalingMethod.AspectFit
                    imageSource: "asset:///images/wallpapers/thumbs/1.png"
                }   
            }
            Container {
                //background: Color.create(bgColor)
                leftPadding: 6
                rightPadding: 6
                topPadding: 6
                bottomPadding: 6
                ImageView {
                    verticalAlignment: VerticalAlignment.Center
                    preferredHeight: iHeight
                    scalingMethod: ScalingMethod.AspectFit
                    imageSource: "asset:///images/wallpapers/thumbs/1.png"
                }   
            }
            Container {
                //background: Color.create(bgColor)
                leftPadding: 6
                rightPadding: 6
                topPadding: 6
                bottomPadding: 6
                ImageView {
                    preferredHeight: iHeight
                    scalingMethod: ScalingMethod.AspectFit
                    imageSource: "asset:///images/wallpapers/thumbs/1.png"
                }   
            }
        }
    }
    DropDown {
        title: "Text color"
        selectedIndex: 0
        options: [
            Option {
                text: "White"
                value: Color.White
            },
            Option {
                text: "Black"
                value: Color.Black
            }
        ]
        onSelectedValueChanged: {
            textLabel.textStyle.setColor(selectedValue)
        }
    }
    ImageButton {
        horizontalAlignment: HorizontalAlignment.Center
        defaultImageSource: "asset:///images/buttons/setAsWall.png"
    }
}
Container {
    id: contentC
    gestureHandlers: TapHandler {
        onTapped: {
            if (contentC.scaleX==0.5)
            {
                contentC.scaleX=1
                contentC.scaleY=contentC.scaleX
            }
            else
            {
                contentC.scaleX=0.5
                contentC.scaleY=contentC.scaleX
            }
        }
    }
    horizontalAlignment: HorizontalAlignment.Fill
    verticalAlignment: VerticalAlignment.Fill
    background: Color.create(itemColor)
    layout: DockLayout {
    
    }
    scaleX: 0.5
    scaleY: scaleX
    pivotY: -640
    //pivotY: -200
    ImageView {
        id: goalImage
        horizontalAlignment: HorizontalAlignment.Center
        verticalAlignment: VerticalAlignment.Center
        scalingMethod: ScalingMethod.AspectFill
        imageSource: "asset:///images/wallpapers/1.png"
    }
    Label {
        id: textLabel
        horizontalAlignment: HorizontalAlignment.Center
        verticalAlignment: VerticalAlignment.Center
        text: "Ask GP for my calculator"
        multiline: true
        textStyle.fontSize: FontSize.PointValue
        //textStyle.fontSizeValue: 72 //MaxValue
        textStyle.fontSizeValue: 28 //MaxValue
        textStyle.color: Color.White
        textStyle.textAlign: TextAlign.Center
    }
}
    }
}