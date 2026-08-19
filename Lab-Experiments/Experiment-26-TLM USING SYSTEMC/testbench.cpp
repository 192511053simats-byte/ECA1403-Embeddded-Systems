#include <systemc>
#include "design.cpp"

using namespace sc_core;

int sc_main(int argc, char* argv[]) {

    Initiator initiator("initiator");
    Target target("target");

    // Connect Initiator and Target
    initiator.socket.bind(target.socket);

    // Start simulation
    sc_start();

    return 0;
}
