// Shared Ptr Time: 13.1225 seconds
// Raw Ptr Time: 2.0699 seconds
// Raw C Ptr Time: 1.8337 seconds
// Unique Ptr Time: 3.49934 seconds

// https://zhuanlan.zhihu.com/p/668602202
// https://blog.csdn.net/gg_18826075157/article/details/71840286
// https://blog.csdn.net/weixin_44477424/article/details/125902769

// std::shared_ptr相比std::unique_ptr在效率上较低的原因主要可以归结为以下几个方面：
// 1. 引用计数的开销
// 内存占用：std::shared_ptr需要维护一个额外的引用计数（通常为原子类型），以跟踪指向对象的shared_ptr实例数量。
//         这意味着每个shared_ptr对象除了存储指向实际对象的指针外，还需要额外的空间来存储这个引用计数。
//         相比之下，std::unique_ptr不需要这样的开销，它仅仅是一个简单的指针封装。
// 原子操作：在多线程环境中，shared_ptr的引用计数需要通过原子操作来确保线程安全。这些原子操作通常比非原子操作更慢，
//         因为它们需要确保操作的原子性和一致性。而std::unique_ptr由于不共享所有权，因此不需要进行这样的操作。
// 2. 分配和销毁开销
// 内存分配：在创建std::shared_ptr时，除了为对象本身分配内存外，还需要为引用计数（通常是一个控制块）分配内存。
//         相比之下，std::unique_ptr只需要为对象本身分配内存。
// 销毁：当std::shared_ptr的最后一个实例被销毁时，除了释放对象本身的内存外，还需要释放引用计数的内存。
//      而std::unique_ptr只需释放对象内存。
// 3. 使用场景和性能考量
// 所有权模型：std::shared_ptr设计用于支持多个所有者共享同一对象的场景，而std::unique_ptr则用于独占所有权。
//           在只需要独占所有权的场合下，std::unique_ptr提供了更高的效率和更低的开销。
// 性能对比：有实验表明，在不开启编译器优化的情况下，std::shared_ptr的性能可能比new操作慢10倍，
//          而开启优化后也大概慢2-3倍。相比之下，std::unique_ptr的性能几乎与new和delete操作一样快。
// 4. 实际应用建议
// 在需要多个所有者共享同一对象的场景下，应使用std::shared_ptr，尽管这可能会带来一些性能开销。
// 在只需要独占所有权的场景下，应优先考虑使用std::unique_ptr，以获得更高的效率和更低的开销。


// 应该禁用掉new吗？
// 支持禁用new的理由：
//     资源管理：使用智能指针（如std::unique_ptr、std::shared_ptr）可以自动管理资源，减少内存泄漏的风险。
//             智能指针能够确保在作用域结束时自动释放所管理的资源，而无需手动调用delete。
//     异常安全：在C++中，如果在new表达式和相应的delete表达式之间抛出异常，可能会导致内存泄漏。
//             使用智能指针可以避免这个问题，因为它们采用RAII（Resource Acquisition Is Initialization）原则，
//             资源获取即初始化，并在作用域结束时自动释放。
//     代码清晰度：在大型项目中，频繁使用new和delete可能会使代码难以理解和维护。
//               使用智能指针和其他容器类（如std::vector、std::string等）可以使代码更加清晰和简洁。
//     现代C++实践：随着C++标准的发展，现代C++鼓励使用更加安全和高效的编程实践。禁用new（或至少限制其使用）是这些实践之一。
// 不禁用new的场景：
//     性能敏感的代码：在某些对性能要求极高的场景中，直接使用new和delete（或malloc和free）可能提供更好的性能。
//                  但是，这通常需要仔细的性能分析和优化。
//     与C代码交互：当C++代码需要与C代码交互，并且C代码使用了malloc和free时，C++代码可能也需要使用new和delete
//               （或使用C++的new和delete操作符的C版本，即::new和::delete），以保持内存管理的一致性。
//     特定库或框架的要求：某些第三方库或框架可能要求使用new和delete进行内存管理。
// 结论：
//     虽然在现代C++开发中，推荐使用智能指针和其他容器类来管理资源，但完全禁用new可能并不总是可行的或必要的。
//     重要的是要根据项目的具体需求和目标来做出决策。如果团队决定限制或避免使用new，那么应该明确这一点，
//     并在代码审查和编码标准中强制执行。同时，也应该意识到在某些特定情况下，使用new可能是合理的或必要的。

#include <iostream>  
#include <memory>  
#include <chrono>  
#include <stdlib.h>
// 使用 unique_ptr 的函数  

void testSharedPtr() {  
    auto start = std::chrono::high_resolution_clock::now();  
  
    for (int i = 0; i < 100000000; ++i) {  
        std::shared_ptr<int> ptr(new int(i));  
        // 模拟使用 ptr  
        (void)ptr.get();  
    }  

    auto end = std::chrono::high_resolution_clock::now();  
    std::chrono::duration<double> elapsed = end - start;  
    std::cout << "Shared Ptr Time: " << elapsed.count() << " seconds" << std::endl;  
}  

void testUniquePtr() {  
    auto start = std::chrono::high_resolution_clock::now();  
  
    for (int i = 0; i < 100000000; ++i) {  
        std::unique_ptr<int> ptr(new int(i));  
        // 模拟使用 ptr  
        (void)ptr.get();  
    }  

    auto end = std::chrono::high_resolution_clock::now();  
    std::chrono::duration<double> elapsed = end - start;  
    std::cout << "Unique Ptr Time: " << elapsed.count() << " seconds" << std::endl;  
}  

// 使用普通指针的函数  
void testRawPtr() {  
    auto start = std::chrono::high_resolution_clock::now();  
  
    for (int i = 0; i < 100000000; ++i) {  
        int* ptr = new int(i);  
        // 模拟使用 ptr  
        (void)ptr;  
        delete ptr;  
    }  
  
    auto end = std::chrono::high_resolution_clock::now();  
    std::chrono::duration<double> elapsed = end - start;  
    std::cout << "Raw Ptr Time: " << elapsed.count() << " seconds" << std::endl;  
}  

void testCRawPtr() {  
    auto start = std::chrono::high_resolution_clock::now();  
  
    for (int i = 0; i < 100000000; ++i) {  
        int* ptr = (int *)malloc(4);  
        *ptr =  i;
        free(ptr);
    }  
  
    auto end = std::chrono::high_resolution_clock::now();  
    std::chrono::duration<double> elapsed = end - start;  
    std::cout << "Raw C Ptr Time: " << elapsed.count() << " seconds" << std::endl;  
}  

int main() {  
    testSharedPtr();
    testRawPtr();
    testCRawPtr();
    testUniquePtr();   
    return 0;  
}