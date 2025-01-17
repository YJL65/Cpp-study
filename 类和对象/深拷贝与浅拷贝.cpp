#include<iostream>
using namespace std;

//浅拷贝的问题是导致堆区的重复释放
class person {
public:
	person() {
		cout << "person 默认构造函数调用" << endl;
	}
	person(int age,int height) {
		m_age = age;
		m_height=new int(height);
		cout << "person 有参构造函数调用" << endl;
	}
	//自己实现拷贝构造函数 解决浅拷贝带来的问题
	person(const person& p) {
		m_age = p.m_age;
		cout << "person 拷贝构造函数调用" << endl;
		//m_height = p.m_height  浅拷贝:堆区的重复释放
		m_height = new int(*p.m_height);
	}
	~person() {
		//将堆区的开辟数据做释放操作
		if (m_height != NULL) {
			delete m_height;
			m_height = NULL;
		}
		cout << "person 析构函数调用" << endl;
	}
	int m_age;
	int* m_height;
};

void testo1() {
	person p1(18,160);
	cout << "p1的年龄：" << p1.m_age <<"身高为："<<*p1.m_height<< endl;

	person p2(p1);
	cout << "p2的年龄：" << p2.m_age <<"身高为：" <<* p1.m_height << endl;

}

int main() {
	testo1();
	system("pause");
	return 0;
}