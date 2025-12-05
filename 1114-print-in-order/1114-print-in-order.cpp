class Foo {
public:
    Foo() {
        
    }
    binary_semaphore s1{0};
    binary_semaphore s2{0};
    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        s1.release();
    }

    void second(function<void()> printSecond) {
        s1.acquire();
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        s2.release();
    }

    void third(function<void()> printThird) {
        s2.acquire();
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};