#include <systemc.h>
#include "design.cpp"

int sc_main(int argc, char* argv[]) {

    // FIFO channel
    sc_fifo<int> fifo(5);

    // Create modules
    Producer producer("Producer");
    Consumer consumer("Consumer");

    // Connect modules
    producer.out(fifo);
    consumer.in(fifo);

    // Start simulation
    sc_start(10, SC_SEC);

    return 0;
}
