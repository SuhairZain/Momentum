import bb.cascades 1.2

Page {
    Container {
        id: rootC
        layout: DockLayout {
        
        }
        leftPadding: 6
        topPadding: 6
        rightPadding: 6
        bottomPadding: 6
        background: Color.create("#c63d0f")
        Container {
            id: itemBgC
            layout: DockLayout {
            
            }
            background: Color.create("#eab543")
            horizontalAlignment: HorizontalAlignment.Fill
            verticalAlignment: VerticalAlignment.Fill
            ScrollView {
                horizontalAlignment: HorizontalAlignment.Fill
                verticalAlignment: VerticalAlignment.Fill
                Container {
                    leftPadding: 6
                    rightPadding: 6
                    Label {
                        text: "tummler"
                        multiline: true
                        textStyle.color: Color.Black
                        textStyle.fontSize: FontSize.PointValue
                        textStyle.fontSizeValue: 15
                    }
                    Label {
                        text: "examples:"
                        textStyle.color: Color.DarkGray
                        textStyle.fontSize: FontSize.PointValue
                        textStyle.fontSizeValue: 8
                    }
                    Label {
                        multiline: true
                        textStyle.textAlign: TextAlign.Justify
                        textStyle.color: Color.Black
                        textStyle.fontSize: FontSize.PointValue
                        textStyle.fontSizeValue: 7
                        textStyle.fontWeight: FontWeight.W100
                        text: "As in previous shows, she re-creates a Sophie Tucker routine, 'Max From the Income Tax,' which ostensibly is about economic chaos but reveals more about her fascination with Tucker, a Jewish tummler who for 60 years made herself the butt literally of her own jokes about being a zaftig farbissina."
                    }
                    Divider {
                    
                    }
                    Label {
                        multiline: true
                        textStyle.textAlign: TextAlign.Justify
                        textStyle.color: Color.Black
                        textStyle.fontSize: FontSize.PointValue
                        textStyle.fontSizeValue: 7
                        textStyle.fontWeight: FontWeight.W100
                        text: "He nearly died from pneumonia last year and gets around in a wheelchair, difficult for a fizzy, rubbery-faced tummler who once danced a soft-shoe if you pointed a camera at him."
                    }
                    Label {
                        text: "definitions:"
                        textStyle.color: Color.DarkGray
                    }
                    Container {
                        layout: StackLayout {
                            orientation: LayoutOrientation.LeftToRight
                        }
                        Label {
                            text: "noun"
                            textStyle.fontSize: FontSize.PointValue
                            textStyle.fontSizeValue: 7
                            textStyle.color: Color.Gray
                        }
                        Label {
                            layoutProperties: StackLayoutProperties {
                                spaceQuota: 1
                            }
                            multiline: true
                            textStyle.color: Color.Black
                            textStyle.fontSize: FontSize.PointValue
                            textStyle.fontSizeValue: 7
                            textStyle.fontWeight: FontWeight.W100
                            text: "(noun) One who encourages audience participation."
                        }
                    }
                    Divider {
                    
                    }
                    Container {
                        layout: StackLayout {
                            orientation: LayoutOrientation.LeftToRight
                        }
                        Label {
                            text: "noun"
                            textStyle.fontSize: FontSize.PointValue
                            textStyle.fontSizeValue: 7
                            textStyle.color: Color.Gray
                        }
                        Label {
                            layoutProperties: StackLayoutProperties {
                                spaceQuota: 1
                            }
                            multiline: true
                            textStyle.color: Color.Black
                            textStyle.fontSize: FontSize.PointValue
                            textStyle.fontSizeValue: 7
                            textStyle.fontWeight: FontWeight.W100
                            text: "(noun) Someone who incites others into action."
                        }
                    }
                    Label {
                        text: "note:"
                        textStyle.color: Color.DarkGray
                    }
                    Label {
                        multiline: true
                        textStyle.textAlign: TextAlign.Justify
                        textStyle.color: Color.Black
                        textStyle.fontSize: FontSize.PointValue
                        textStyle.fontSizeValue: 7
                        textStyle.fontWeight: FontWeight.W100
                        text: "‘Tummler’ comes from the Yiddish ‘tumlen,’ to make a racket."
                    }
                }
            }
        }
    }
}
