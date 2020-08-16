/* 
【单例模式】只有一个对象。
	通过static实现。
【类在编译阶段分配内存】
	在main函数执行前打印操作。（默认构造函数中...）
*/

class ChairMan
{
public:
	static ChairMan* getInstance()
	{
		return singleMan;
	}

private:
	//构造函数私有化，不可以创建多个对象。
	ChairMan(){};//默认构造。
	ChairMan(const ChairMan&){};//拷贝构造

	static ChairMan* singleMan;//类内声明，类外初始化。
};

//编译阶段执行下列语句
ChairMan* ChairMan::singleMan = new ChairMan;//ChairMan作用域:相当于在ChairMan类内。

void test()
{
	ChairMan * c1 = ChairMan::getInstance();
	ChairMan * c2 = ChairMan::getInstance();
}


//在main函数执行前打印操作。（默认构造函数中...）
#include <iostream>
using namespace std;
 
class a {
  public:
    a() {
        cout << "before the main function" << endl;
    }
    ~a(){
        cout << "after the main function" << endl;
    };
};
 
a b;
 
int main() {
    cout << "now main function is working" << endl;
    return 0;
}