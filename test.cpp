#include <iostream>

class Singleton {
private:
    static Singleton* instance;  // 保存单例实例的指针

    Singleton() {}  // 私有构造函数，防止外部实例化
    Singleton(Singleton& s) = delete;
    Singleton& operator = (Singleton& s) = delete;
public:
    static Singleton* getInstance() {
        if (instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }
};

Singleton* Singleton::instance = nullptr;  // 初始化静态成员变量

int main() {
    Singleton* singleton = Singleton::getInstance();
    // 使用 singleton 对象进行操作

    return 0;
}