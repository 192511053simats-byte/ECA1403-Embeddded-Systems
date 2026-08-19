#include <systemc.h>

// Producer Module
SC_MODULE(Producer) {
    sc_fifo_out<int> out;

    void produce() {
        for (int i = 1; i <= 5; i++) {
            cout << "Produced: " << i << endl;
            out.write(i);
            wait(1, SC_SEC);
        }
    }

    SC_CTOR(Producer) {
        SC_THREAD(produce);
    }
};


// Consumer Module
SC_MODULE(Consumer) {
    sc_fifo_in<int> in;

    void consume() {
        int value;

        in.read(value);
        cout << "Consumed: " << value << endl;

        wait(1, SC_SEC);

        in.read(value);
        cout << "Consumed: " << value << endl;

        wait(2, SC_SEC);

        in.read(value);
        cout << "Consumed: " << value << endl;

        wait(1, SC_SEC);

        in.read(value);
        cout << "Consumed: " << value << endl;

        wait(1, SC_SEC);

        in.read(value);
        cout << "Consumed: " << value << endl;
    }

    SC_CTOR(Consumer) {
        SC_THREAD(consume);
    }
};
