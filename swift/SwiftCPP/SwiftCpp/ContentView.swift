//
//  ContentView.swift
//  SwiftCpp
//
//  Created by 최민한 on 2022/10/22.
//

import SwiftUI

struct ContentView: View
{
    @State var number = 0
    var body: some View
    {
        VStack
        {
            // 显示图片一个小地球
            Image(systemName: "globe")
                .imageScale(.large)
                .foregroundColor(.accentColor)
        
            // 在屏幕打印字符串
            Text("Hello, world!")
            // 在屏幕打印字符串，输出sayHello内容
            Text(HelloWorldWrapper().sayHello(0000))
            
            // 获取沙盒home路径并打印
            let homeDirectory = NSHomeDirectory()
            Text(homeDirectory)
            // 将NS路径作为参数传递给c++接口
            let status = HelloWorldWrapper().setNSPath(homeDirectory)
            let image = UIImage(named: "000000005001.jpg")
//            imageView.image = image
            // 创建按钮
            Button
            {
                number = HelloWorldWrapper().getRandomNumber()
            }
            label:
            {
                Text("refresh")
            }
            Text("\(number)")

        }
        .padding()
    }
}


class ViewController: UIViewController {

    // 假设你已经通过Storyboard或代码创建了一个UIImageView，并且其IBOutlet已经连接到此属性
    @IBOutlet weak var imageView: UIImageView!

    override func viewDidLoad() {
        super.viewDidLoad()

        // 方法1：直接从Assets.xcassets中加载图片
        if let image = UIImage(named: "exampleImage") {
            imageView.image = image
        } else {
            print("Image not found")
        }

        // 方法2：从项目主bundle中加载（一般情况下与方法1效果相同，除非图片不在Assets）
        // 注意：这种方法需要图片的全名（包括扩展名）
        /*if let imagePath = Bundle.main.path(forResource: "exampleImage", ofType: "png"),
           let image = UIImage(contentsOfFile: imagePath) {
            imageView.image = image
        } else {
            print("Image not loaded")
        }*/
    }
}

struct ContentView_Previews: PreviewProvider
{
    static var previews: some View
    {
        ContentView()
        ViewController()
    }
}
