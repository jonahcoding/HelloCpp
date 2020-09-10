#include <iostream>

using namespace std;
//const int StackIncreMent = 20;

template<class Type>
class Stack
{
private:
	Type *data;
	int top;
	int m_capacity;
public:
	//无参构造
	Stack();
	//有参构造
	Stack(int capacity);
	//拷贝构造
	Stack(const Stack<Type>& otherStack);
	//析构
	~Stack();
	//赋值运算符重载
	Stack<Type> operator=(const Stack<Type>& otherStack);
	void initStack();
	bool isEmptyStack()const;
	bool IsFullStack() const;
	void destoryStack();
	void pop(Type& data);
	void push(Type data);
	void expandCapacity();
};

template<class Type>
Stack<Type>::Stack()
{
	this->m_capacity = 10;//默认容量为10
	data = new Type[this->m_capacity];
	top = 0;
}

template<class Type>
Stack<Type>::Stack(int capacity)
{
	this->m_capacity = capacity;
	data = new Type[this->m_capacity];
	top = 0;
}

template<class Type>
Stack<Type>::~Stack()
{
	if(this != NULL)
	{
		destoryStack();
	}
}

template<class Type>
void Stack<Type>::destoryStack()
{
	top = 0;
	delete[] data;
	data = NULL;
}













template<class Type>
Stack<Type>::Stack(int maxSize)
{
	this->maxSize = maxSize;
	data = new Type[maxSize];
	top = 0;
}

template<class Type>
Stack<Type>::Stack(const Stack<Type>& otherStack)//新建对象的数组没有空间，这时要申请空间
{
	maxSize = otherStack.maxSize;
	data = new Type[maxSize];
	top = otherStack.top;
	if (!otherStack.isEmptyStack())
	{
		memcpy(data, otherStack.data, maxSize);
	}
}

template<class Type>
Stack<Type>::~Stack()
{
	if (data != NULL)
	{
		destoryStack();
	}
}

template<class Type>
Stack<Type> Stack<Type>::operator=(const Stack<Type>& otherStack)
{
	if (this != &otherStack)
	{
		if (!otherStack.isEmptyStack())
		{
			if (maxSize != otherStack.top) //要被赋值的对象太小，要重新申请
			{
				maxSize = otherStack.maxSize;
				delete[] data;
				data = new Type[maxSize];
			}
			top = otherStack.top;
			memcpy(data, otherStack.data, maxSize);
		}
	}
	return *this;
}

template<class Type>
void Stack<Type>::initStack()
{
	top = 0;
}

template<class Type>
bool Stack<Type>::isEmptyStack()const
{
	return (top == 0);
}

template<class Type>
bool Stack<Type>::IsFullStack()const
{
	return (top == maxSize);//top表示指针位置，最大为Max-1
}

template<class Type>
void Stack<Type>::destoryStack()
{
	top = 0;
	delete[] data;
	data = NULL;
}

template<class Type>
void Stack<Type>::pop(Type& NewItem)
{
	if (isEmptyStack())
	{
		NewItem = -1;
		cout << "栈空" << endl;
	}
	else
	{
		NewItem = data[--top];
	}
}

template<class Type>
void Stack<Type>::push(Type NewItem)
{
	if (IsFullStack())
	{
		maxSize = StackIncreMent + maxSize;
		//maxSize = maxSize * 2;
		Type* newData = new Type[maxSize];
		memcpy(newData, data, maxSize);
		delete data;
		data = newData;
	}
	data[top++] = NewItem;
}

template<class Type>
void Stack<Type>::expandCapacity()
{
	this->maxSize = 2 * maxSize; 
}

int main()
{
	Stack<int> s;
	int a[4] = { 1,2,3,4 };
	for (int i = 0; i<4; i++)
	{
		s.push(a[i]);
	}
	Stack<int> s1 = s;
	for (int i = 0; i<4; i++)
	{
		int temp;
		s1.pop(temp);
		cout << temp << endl;
	}

	system("pause");
	return 0;
}