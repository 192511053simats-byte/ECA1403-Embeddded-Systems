#include <systemc.h>
#include "design.cpp"

SC_MODULE(Testbench)
{
    sc_clock clk;

    ClockDrivenProcesses dut;

    SC_CTOR(Testbench)
        : clk("clk", 10, SC_NS),
          dut("dut")
    {
        dut.clk(clk);
    }
};

int sc_main(int argc, char* argv[])
{
    Testbench tb("tb");

    cout << "===== Simulation Started =====" << endl;

    sc_start(100, SC_NS);

    cout << "===== Simulation Completed =====" << endl;

    return 0;
}
