 
//Date：2021/11/16
 
#include <iostream>
using namespace std;

template <typename T>
class CircularQueue{
public:
    //循环队列的初始化
    CircularQueue(int max_size)
    {
        //构造一个空队列Q
        max_size_ = max_size;
        base_ = new T[max_size_];//为队列分配一个最大容量为Maxsize的数组空间
        if (!base_)
        {
            exit(-1);//存储分配失败
        }
        front_ = rear_ = 0;//头指针和尾指针置为零，队列为空
    }

    //循环队列的入队
    bool EnQueue(T& e)
    {
        std::unique_lock<std::mutex> lock(mutex_);
        //插入一个元素e为Q的新的队尾元素
        if ((rear_ + 1) % max_size_ == front_)
        {
            return false;//队满
        }
  
        base_[rear_] = e; //新元素插入队尾
        rear_ = (rear_ + 1) % max_size_;//队尾指针加1
        return true;
    }
    
    //循环队列的出队
    bool DeQueue(T& e)
    {
        std::unique_lock<std::mutex> lock(mutex_);
        //删除Q的队头元素，用e返回其值
        if (front_ == rear_)
        {
            return false;//队空
        }

        e = base_[front_]; //保存队头元素
        front_ = (front_ + 1) % max_size_;//队头指针加1
        return true;
    }
    
    //取循环队列的队头元素
    bool GetHead(T& e)
    {
        std::unique_lock<std::mutex> lock(mutex_);
        //返回Q的队头元素，不修改队头指针
        if (front_ == rear_)
        {
            return false;//队列为空，取元素失败
        }
        e = base_[front_];
        return true;
    }
    
    //4、求长
    void QueueLength()
    {
        std::unique_lock<std::mutex> lock(mutex_);
        //返回Q的元素个数，即队列的长度
        int n = (rear_ - front_ + max_size_) % max_size_;
        cout << "队列长度为：" << n << endl;
    }
    
    //5、判空
    void QueueEmpty()
    {
        std::unique_lock<std::mutex> lock(mutex_);
        if (front_ == rear_)
            cout << "队列为空！" << endl;
        else
            cout << "队列不为空！" << endl;
    }
    
    //6、清空
    void ClearQueue()
    {
        std::unique_lock<std::mutex> lock(mutex_);
        rear_ = front_ = 0;
    }
    
    //7、销毁
    ~CircularQueue()
    {
        if (base_)
        {
            delete[] base_;
            base_ = NULL;
            rear_ = front_ = 0;
        }
    }
    
    //8、打印
    void PrintQueue()
    {
        std::unique_lock<std::mutex> lock(mutex_);
        T* p = base_;
        int n = (rear_ - front_ + max_size_) % max_size_;
        for (int i = 1; i <= n; i++)
        {
            cout << "第" << i << "个元素为：" << *p++ << endl;
        }
    }

private:
	T* base_;
	int front_;
	int rear_;
    int max_size_;
    std::mutex mutex_;
    std::condition_variable cv_;
};

//1、入队
template <class T>
void EnQueue(CircularQueue<T> &queue)
{
    int flag;
    int e;
    cout << "请输入入队元素：";
    cin >> e;
    flag = queue.EnQueue(e);
    if (flag)
        cout << "入队成功！" << endl;
    else
        cout << "入队失败！" << endl;
}

//2、出队
template <class T>
void DeQueue(CircularQueue<T> &queue)
{
    T e;
    int flag;
    flag = queue.DeQueue(e);
    if (flag)
        cout << "出队元素为：" << e << endl;
    else
        cout << "出队失败！" << endl;
}

//3、取值
template <class T>
void GetHead(CircularQueue<T> &queue)
{
    T e;
    int flag;
    flag=queue.GetHead(e);
    if (flag)
        cout << "取得的队头元素为：" << e << endl;
    else
        cout << "取值失败！" << endl;
}

//菜单
void menu()
{
	cout << "***   ";
	cout << "1、入队   ";
	cout << "2、出队   ";
	cout << "3、取值   ";
	cout << "4、求长   ";
	cout << "5、判空   ";
	cout << "6、清空   ";
	cout << "7、销毁   ";
	cout << "8、打印   ";
	cout << "0、退出   ";
	cout << "***" << endl;
}
 
int main()
{
    system("clear");//清屏操作
	int select;
	CircularQueue<int> queue(10);
    int ele = 10;
	while (1)
	{
		menu();
		cout << "请输入菜单序号：";
		cin >> select;
		switch (select)
		{
		case 1://入队
			EnQueue<int>(queue);
			//按任意键继续
			break;
		case 2://出队
			DeQueue<int>(queue);
			break;
		case 3://取队头元素
			GetHead<int>(queue);
			break;
		case 4://求队列长度
			queue.QueueLength();
			break;
		case 5://判断队列是否为空
			queue.QueueEmpty();
			break;
		case 6://清空队列
			queue.ClearQueue();
			break;
		case 8://从队头到队尾遍历栈并打印
			queue.PrintQueue();
			break;
		case 0:
			cout << "欢迎下次使用!" << endl;//退出
			return 0;
			break;
		default:
			cout << "菜单序号输入有误！" << endl;
			break;
		}
	}

	return 0;
}