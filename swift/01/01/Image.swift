//
//  Image.swift
//  01
//
//  Created by runge.liu on 2024/6/16.
//

import Foundation
import SwiftUI

struct Images: View {
    var body: some View {
        VStack {
            Image("image1") // 资源文件图片
                .resizable() // 可调整大小的
                .aspectRatio(contentMode: .fit) // 纵横比
                .frame(width: 200, height: 200) // 设置长宽
        }
    }
}

// 预览器，在app端进行预览(可选)
#Preview {
    Images()
}
