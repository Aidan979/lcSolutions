#include <iostream>
#include <functional>
#include <Thread>
#include <mutex>
#include <condition_variable>

class FizzBuzz {
private:

    int n;
    int i = 1;
    std::mutex m_Mutex;
    std::condition_variable indexCondition;

public:
    FizzBuzz(int n) : n(n){};

    template<class Condition, class PrintFunction, class ... Args>
    void printPattern(const Condition& cond, const PrintFunction& printer, const Args& ... args)
    {
        while(1){
            {
                std::unique_lock<std::mutex> lock(m_Mutex);
                indexCondition.wait(lock, cond);
                if (i <= n){
                    printer(args...);
                }
                else {
                    break;
                }
                ++i;
            }
            indexCondition.notify_all();
        }
    }
    
    // printFizz() outputs "fizz".
    void fizz(std::function<void()> printFizz) {
        printPattern([this]{return i % 3 == 0 && !(i % 5 == 0) || i > n;}, printFizz);
    }
    
    // printBuzz() outputs "buzz".
    void buzz(std::function<void()> printBuzz) {
        printPattern([this]{return !(i % 3 == 0) && i % 5 == 0 || i > n;}, printBuzz);
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(std::function<void()> printFizzBuzz) {
        printPattern([this]{return i % 3 == 0 && i % 5 == 0 || i > n;}, printFizzBuzz);
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(std::function<void(int)> printNumber) {
        printPattern([this]{return !(i % 3 == 0 || i % 5 == 0) || i > n;}, printNumber, this->i);
    }
};


int main()
{
    FizzBuzz fb(15);

    std::thread A([](FizzBuzz* fb){fb->fizz([]{std::cout << "fizz" << std::endl;});}, &fb);
    std::thread B([](FizzBuzz* fb){fb->buzz([]{std::cout << "buzz" << std::endl;});}, &fb);
    std::thread C([](FizzBuzz* fb){fb->fizzbuzz([]{std::cout << "fizzbuzz" << std::endl;});}, &fb);
    std::thread D([](FizzBuzz* fb){fb->number([](int x){std::cout << x << std::endl;});}, &fb);

    A.join();
    B.join();
    C.join();
    D.join();

    std::cout << "done" << std::endl;
    return 0;
}