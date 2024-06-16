//
//  ContentView.swift
//  01
//
//  Created by runge.liu on 2024/6/15.
//

// 设置app名字、设置图标、添加按钮、随机生成水果、显示随机生成内容
import SwiftUI

// 图标：
// 在Assets.xcassets中加载图标
// 图标大小必须为1024x1024否则会报错

// app名字
// 在工程选项Disaply Name中设置app名字

// 声明一个函数，用于随机返回一个变量
func mySelect() -> String{
    return ["🍏", "🍎", "🍐", "🍋", "🍌", "🍉", "🍇"].randomElement()! // 随机返回一个水果
}
struct ContentView: View {
    // 定义一个变量
    @State private var today = mySelect()
    var body: some View {
        VStack {
            Text("\(today)") // 相当于html框架
                .font(.system(size:100)) // 相当于css样式
                .padding()
            Button("今天吃啥"){
                // 脚本。每次点击，调用函数，更新变量
                today = mySelect()
            }
            // 按钮样式的修饰
            .padding()
            .background(.teal)
            .foregroundColor(.white)
            .cornerRadius(40)
            Spacer()
        }
        .padding()
    }
}

// 预览器，在app端进行预览(可选)
#Preview {
    ContentView()
}
