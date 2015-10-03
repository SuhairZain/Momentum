/*
 * Copyright (c) 2011-2014 BlackBerry Limited.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

import bb.cascades 1.2

TabbedPane {
    property string bgColor: "#c63d0f"
    property string itemColor: "#eab543"
    showTabsOnActionBar: true
    Tab {
        title: "Home"
        imageSource: "asset:///images/icons/ic_home.png"
        Page {
            Container {
                background: Color.create(bgColor)
                leftPadding: 6
                topPadding: 6
                rightPadding: 6
                bottomPadding: 6
                Container {
                    horizontalAlignment: HorizontalAlignment.Fill
                    background: Color.create(itemColor)
                    bottomMargin: 6
                    //visible: false
                    Label {
                        horizontalAlignment: HorizontalAlignment.Center
                        multiline: true
                        text: "This app needs internet connectivity in order to fetch new words and quotes. Please enable connections from settings and press here to retry."
                        textStyle.color: Color.Black
                        textStyle.textAlign: TextAlign.Center
                        textStyle.fontSize: FontSize.PointValue
                        textStyle.fontSizeValue: 5
                        textStyle.fontWeight: FontWeight.W100
                    }
                }
                Container {
                    //topMargin: 6
                    bottomMargin: 6
                    layout: StackLayout {
                        orientation: LayoutOrientation.LeftToRight
                    }
                    layoutProperties: StackLayoutProperties {
                        spaceQuota: 1
                    }
                    //horizontalAlignment: HorizontalAlignment.Fill
                    Container {
                        rightMargin: 6
                        layoutProperties: StackLayoutProperties {
                            spaceQuota: 1.06
                        }
                        background: Color.create(itemColor)
                        //background: Color.create("#fbc73a")
                        verticalAlignment: VerticalAlignment.Fill
                        Container {
                            layout: StackLayout {
                                orientation: LayoutOrientation.LeftToRight
                            }
                            horizontalAlignment: HorizontalAlignment.Fill
                            ImageButton {
                                defaultImageSource: "asset:///images/icons/ic_reload.png"
                            }
                            Label {
                                verticalAlignment: VerticalAlignment.Center
                                text: "Word of the day"
                                textStyle.color: Color.DarkGray
                                textStyle.fontWeight: FontWeight.W400
                            }
                            ImageButton {
                                defaultImageSource: "asset:///images/icons/ic_add.png"
                            }
                        }
                        Container {
                            layout: DockLayout {
                            
                            }
                            layoutProperties: StackLayoutProperties {
                                spaceQuota: 1
                            }
                            horizontalAlignment: HorizontalAlignment.Fill
                            verticalAlignment: VerticalAlignment.Fill
                            Label {
                                horizontalAlignment: HorizontalAlignment.Center
                                verticalAlignment: VerticalAlignment.Center
                                text: "bibliotaph"
                                multiline: true
                                textStyle.color: Color.Black
                                textStyle.textAlign: TextAlign.Center
                                textStyle.fontSize: FontSize.PointValue
                                textStyle.fontSizeValue: 12
                                textStyle.fontWeight: FontWeight.W100
                            }
                        }
                    }
                    Container {
                        layoutProperties: StackLayoutProperties {
                            spaceQuota: 1
                        }
                        background: Color.create(itemColor)
                        //background: Color.create("#99e94a")
                        verticalAlignment: VerticalAlignment.Fill
                        Label {
                            horizontalAlignment: HorizontalAlignment.Center
                            text: "Set a goal for today"
                            textStyle.color: Color.DarkGray
                            textStyle.fontWeight: FontWeight.W400
                        }
                        Container {
                            layout: DockLayout {
                            
                            }
                            layoutProperties: StackLayoutProperties {
                                spaceQuota: 1
                            }
                            horizontalAlignment: HorizontalAlignment.Fill
                            verticalAlignment: VerticalAlignment.Fill
                            ImageButton {
                                horizontalAlignment: HorizontalAlignment.Center
                                verticalAlignment: VerticalAlignment.Center
                                defaultImageSource: "asset:///images/buttons/momentum.png"
                                pressedImageSource: "asset:///images/buttons/momentumPressed.png"
                            }
                        }
                    }
                }
                Container {
                    horizontalAlignment: HorizontalAlignment.Fill
                    background: Color.create(itemColor)
                    bottomMargin: 6
                    layout: StackLayout {
                        orientation: LayoutOrientation.LeftToRight
                    }
                    Label {
                        layoutProperties: StackLayoutProperties {
                            spaceQuota: 1
                        }
                        verticalAlignment: VerticalAlignment.Center
                        multiline: true
                        text: "Please support this app by reviewing or making a donation. It's easy and takes just a minute. Click here to know more."
                        textStyle.color: Color.White
                        textStyle.textAlign: TextAlign.Center
                        textStyle.fontSize: FontSize.PointValue
                        textStyle.fontSizeValue: 6
                        textStyle.fontWeight: FontWeight.W100
                    }
                    ImageButton {
                        defaultImageSource: "asset:///images/icons/ic_clear.png"
                        verticalAlignment: VerticalAlignment.Center
                    }
                }
                Container {
                    layoutProperties: StackLayoutProperties {
                        spaceQuota: 1.3
                    }
                    background: Color.create(itemColor)
                    //verticalAlignment: VerticalAlignment.Fill
                    Container {
                        layout: StackLayout {
                            orientation: LayoutOrientation.LeftToRight
                        }
                        horizontalAlignment: HorizontalAlignment.Fill
                        ImageButton {
                            defaultImageSource: "asset:///images/icons/ic_reload.png"
                        }
                        Container {
                            verticalAlignment: VerticalAlignment.Center
                            layoutProperties: StackLayoutProperties {
                                spaceQuota: 1
                            }
                            Label {
                                horizontalAlignment: HorizontalAlignment.Center
                                text: "Inspirational quote"
                                textStyle.color: Color.DarkGray
                                textStyle.fontWeight: FontWeight.W400
                            }
                        }
                        ImageButton {
                            defaultImageSource: "asset:///images/icons/ic_add.png"
                        }
                    }
                    Container {
                        layout: DockLayout {
                        
                        }
                        layoutProperties: StackLayoutProperties {
                            spaceQuota: 1
                        }
                        horizontalAlignment: HorizontalAlignment.Fill
                        verticalAlignment: VerticalAlignment.Fill
                        Label {
                            horizontalAlignment: HorizontalAlignment.Center
                            verticalAlignment: VerticalAlignment.Center
                            text: "A life spent making mistakes is not only more honourable but more useful than a life spent in doing nothing.\n- Bernard Shaw"
                            multiline: true
                            textStyle.color: Color.Black
                            textStyle.textAlign: TextAlign.Center
                            textStyle.fontSize: FontSize.PointValue
                            textStyle.fontSizeValue: 10
                            textStyle.fontWeight: FontWeight.W100
                        }
                    }
                }
            }
        }
    }
    Tab {
        title: "Saved words"
        imageSource: "asset:///images/icons/ic_view_list.png"
        Page {
            Container {
                background: Color.create(bgColor)
            }
        }
    }
    Tab {
        title: "Saved quotes"
        imageSource: "asset:///images/icons/ic_view_list.png"
        Page {
            Container {
                background: Color.create(bgColor)
            }
        }
    }
}