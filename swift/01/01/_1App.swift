//
//  _1App.swift
//  01
//
//  Created by runge.liu on 2024/6/15.
//

// app -> scene -> view

import SwiftUI // 导入SwiftUI

@main // 表明这是程序的主要入口
struct _1App: App { // 最大的容器
    var body: some Scene { // 场景
        WindowGroup { // 窗口组
            Images() // 显示图像
            ContentView() // 显示按钮与text
            
        }
    }
}
