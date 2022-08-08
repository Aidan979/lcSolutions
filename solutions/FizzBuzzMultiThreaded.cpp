#include <iostream>
#include <functional>
#include <Thread>
#include <mutex>
#include <condition_variable>

/*
My solution to the Leetcode problem "Fizz Buzz Multithreaded"

Problem: 
You have the four functions:

printFizz that prints the word "fizz" to the console,
printBuzz that prints the word "buzz" to the console,
printFizzBuzz that prints the word "fizzbuzz" to the console, and
printNumber that prints a given integer to the console.
You are given an instance of the class FizzBuzz that has four functions: fizz, buzz, fizzbuzz and number. The same instance of FizzBuzz will be passed to four different threads:

Thread A: calls fizz() that should output the word "fizz".
Thread B: calls buzz() that should output the word "buzz".
Thread C: calls fizzbuzz() that should output the word "fizzbuzz".
Thread D: calls number() that should only output the integers.
Modify the given class to output the series [1, 2, "fizz", 4, "buzz", ...] where the ith token (1-indexed) of the series is:

"fizzbuzz" if i is divisible by 3 and 5,
"fizz" if i is divisible by 3 and not 5,
"buzz" if i is divisible by 5 and not 3, or
i if i is not divisible by 3 or 5.
Implement the FizzBuzz class:

FizzBuzz(int n) Initializes the object with the number n that represents the length of the sequence that should be printed.
void fizz(printFizz) Calls printFizz to output "fizz".
void buzz(printBuzz) Calls printBuzz to output "buzz".
void fizzbuzz(printFizzBuzz) Calls printFizzBuzz to output "fizzbuzz".
void number(printNumber) Calls printnumber to output the numbers.

Ex:
Input: n = 15
Output: [1,2,"fizz",4,"buzz","fizz",7,8,"fizz","buzz",11,"fizz",13,14,"fizzbuzz"]
*/


class FizzBuzz {
private:

    int n;
    int index = 1;
    std::mutex m_Mutex;
    std::condition_variable indexCondition;

public:
    FizzBuzz(int n) : n(n){};

    template<class Condition, class PrintFunction, class ... Args>
    void conditionalPrint(const Condition& cond, const PrintFunction& print, const Args& ... args)
    {
        while(1)
        {    
            // lock mutex for current scope
            std::unique_lock<std::mutex> lock(m_Mutex);

            // Wait for wake notification and continue if index condition
            // is satisfied or all indicies are complete
            indexCondition.wait(lock, [this, cond]{return cond() || index > n;});
            if (index <= n){
                print(args...); // print any number/type of arguments
            }
            else {
                break;
            }
            ++index;   
            indexCondition.notify_all();
        }
    }
    
    // printFizz() outputs "fizz".
    void fizz(std::function<void()> printFizz) {
        conditionalPrint([this]{return index % 3 == 0 && !(index % 5 == 0);}, printFizz);
    }
    
    // printBuzz() outputs "buzz".
    void buzz(std::function<void()> printBuzz) {
        conditionalPrint([this]{return !(index % 3 == 0) && index % 5 == 0;}, printBuzz);
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(std::function<void()> printFizzBuzz) {
        conditionalPrint([this]{return index % 3 == 0 && index % 5 == 0;}, printFizzBuzz);
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(std::function<void(int)> printNumber) {
        conditionalPrint([this]{return !(index % 3 == 0 || index % 5 == 0);}, printNumber, this->index);
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