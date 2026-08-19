#include <systemc.h>

SC_MODULE(ClockDrivenProcesses)
{
    sc_in<bool> clk;

    void process1()
    {
        while (true)
        {
            wait();

            cout << sc_time_stamp()
                 << " : Process 1 is running" << endl;

            wait(5, SC_NS);

            cout << sc_time_stamp()
                 << " : Process 1 completed" << endl;
        }
    }

    void process2()
    {
        while (true)
        {
            wait();

            cout << sc_time_stamp()
                 << " : Process 2 is running" << endl;

            wait(3, SC_NS);

            cout << sc_time_stamp()
                 << " : Process 2 completed" << endl;
        }
    }

    void process3()
    {
        while (true)
        {
            wait();

            cout << sc_time_stamp()
                 << " : Process 3 is running" << endl;

            wait(2, SC_NS);

            cout << sc_time_stamp()
                 << " : Process 3 completed" << endl;
        }
    }

    SC_CTOR(ClockDrivenProcesses)
    {
        SC_THREAD(process1);
        sensitive << clk.pos();

        SC_THREAD(process2);
        sensitive << clk.pos();

        SC_THREAD(process3);
        sensitive << clk.pos();
    }
    };
