#include "systemc.h" 
/*
SC_MODULE(testbench)
{

	sc_out<sc_logic> A_p, B_p, CIN_p;
	sc_in<sc_logic> SUM_p, COUT_p;

	SC_CTOR(testbench)
	{
		SC_THREAD(process);
	}

	void process()
	{
		//Case 0
		A_p = SC_LOGIC_0;
		B_p = SC_LOGIC_0;
		CIN_p = SC_LOGIC_0;
		wait(5, SC_NS);
		assert(SUM_p == SC_LOGIC_0);
		assert(COUT_p == SC_LOGIC_0);
		wait(10, SC_NS);
		print();

		//Case 1
		A_p = SC_LOGIC_0;
		B_p = SC_LOGIC_0;
		CIN_p = SC_LOGIC_1;
		//wait(5, SC_NS);
		//assert(SUM_p == SC_LOGIC_1);
		//assert(COUT_p == SC_LOGIC_0);
		wait(10, SC_NS);
		print();

		//Case 2
		A_p = SC_LOGIC_0;
		B_p = SC_LOGIC_1;
		CIN_p = SC_LOGIC_0;
		//wait(5, SC_NS);					
		//assert(SUM_p == SC_LOGIC_0);
		//assert(COUT_p == SC_LOGIC_0); 
		wait(10, SC_NS);
		print();

		//Case 3
		A_p = SC_LOGIC_0;
		B_p = SC_LOGIC_1;
		CIN_p = SC_LOGIC_1;
		//wait(5, SC_NS);
		//assert(SUM_p == SC_LOGIC_1);
		//assert(COUT_p == SC_LOGIC_0);
		wait(10, SC_NS);
		print();

		//Case 4
		A_p = SC_LOGIC_1;
		B_p = SC_LOGIC_0;
		CIN_p = SC_LOGIC_0;
		//wait(5, SC_NS);					
		//assert(SUM_p == SC_LOGIC_0);
		//assert(COUT_p == SC_LOGIC_0); 
		wait(10, SC_NS);
		print();

		//Case 5
		A_p = SC_LOGIC_1;
		B_p = SC_LOGIC_0;
		CIN_p = SC_LOGIC_1;
		//wait(5, SC_NS);
		//assert(SUM_p == SC_LOGIC_1);
		//assert(COUT_p == SC_LOGIC_0);
		wait(10, SC_NS);
		print();

		//Case 6
		A_p = SC_LOGIC_1;
		B_p = SC_LOGIC_1;
		CIN_p = SC_LOGIC_0;
		//wait(5, SC_NS);					
		//assert(SUM_p == SC_LOGIC_0);	
		//assert(COUT_p == SC_LOGIC_0);
		wait(10, SC_NS);
		print();

		//Case 7
		A_p = SC_LOGIC_1;
		B_p = SC_LOGIC_1;
		CIN_p = SC_LOGIC_1;
		//wait(5, SC_NS);
		//assert(SUM_p == SC_LOGIC_1);
		//assert(COUT_p == SC_LOGIC_0);
		wait(10, SC_NS);
		print();

		sc_stop();	//End Simulation
	}


	void print()
	{
		cout << "At time " << sc_time_stamp() << "::";
		cout << "(a,b,carry_in): ";
		cout << A_p.read() << B_p.read() << CIN_p.read();
		cout << "  (sum,carry_out): " << SUM_p.read() << COUT_p.read() << endl;
	}
};
*/