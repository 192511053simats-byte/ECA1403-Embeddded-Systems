#include <systemc.h>
#include "design.cpp"

int sc_main(int argc, char* argv[]) {

    binary_semaphore obj("Binary_Semaphore");

    sc_start(10, SC_SEC);

    return 0;
}
