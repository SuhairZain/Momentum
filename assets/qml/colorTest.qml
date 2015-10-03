import bb.cascades 1.2

Page {
    Container {
        Container {
            layoutProperties: StackLayoutProperties {
                spaceQuota: 1
            }
            layout: StackLayout {
                orientation: LayoutOrientation.LeftToRight
            }
            Container {
                layoutProperties: StackLayoutProperties {
                    spaceQuota: 1
                }
                horizontalAlignment: HorizontalAlignment.Fill
                verticalAlignment: VerticalAlignment.Fill
                background: Color.DarkRed
            }
            Container {
                layoutProperties: StackLayoutProperties {
                    spaceQuota: 1
                }
                horizontalAlignment: HorizontalAlignment.Fill
                verticalAlignment: VerticalAlignment.Fill
                background: Color.create("#c90369")
            }
        }
        Container {
            layoutProperties: StackLayoutProperties {
                spaceQuota: 1
            }
            layout: StackLayout {
                orientation: LayoutOrientation.LeftToRight
            }
            Container {
                layoutProperties: StackLayoutProperties {
                    spaceQuota: 1
                }
                horizontalAlignment: HorizontalAlignment.Fill
                verticalAlignment: VerticalAlignment.Fill
                background: Color.DarkMagenta
            }
            Container {
                layoutProperties: StackLayoutProperties {
                    spaceQuota: 1
                }
                horizontalAlignment: HorizontalAlignment.Fill
                verticalAlignment: VerticalAlignment.Fill
                background: Color.Magenta
            }
        }
    }
}
