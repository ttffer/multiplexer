#include "systemc.h" 
#include "bitadder.cpp"

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


int sc_main(int argc, char* argv[])
{

	/*
	//test for one for 4 and
	sc_signal<sc_logic> a0, a1, a2, a3, b0, and0, and1, and2, and3;

	one_to_four_and t1("t1");
	t1 << b0 << a0 << a1 << a2 << a3 << and0 << and1 << and2 << and3;
	mytest t2("t2");
	t2 << b0 << a0 << a1 << a2 << a3 << and0 << and1 << and2 << and3;
	*/
	/*
	sc_signal<sc_logic> A_s, B_s, CIN_s, SUM_s, COUT_s;
	BIT_ADDER adder1("BitAdder1");
	adder1 << A_s << B_s << CIN_s << SUM_s << COUT_s;
	testbench test1("TestBench1");
	test1 << A_s << B_s << CIN_s << SUM_s << COUT_s;
	*/
	/*
	//test for  four-bit adder
	sc_signal<sc_logic> aa0, aa1, aa2, aa3, ab0, ab1,
				ab2, ab3, gnd,as0, as1, as2, as3, acin;

	bit_4_adder bit4adder1("bit4adder1");
	bit4adder1<< gnd<<aa0 << aa1 << aa2 << aa3 << ab0 << ab1 << 
		ab2 << ab3 <<as0 << as1 << as2 << as3 << acin;

	mytestforbit4adder test4bitadder1("test4bitadder1");
	test4bitadder1 << gnd << aa0 << aa1 << aa2 << aa3 << ab0 << ab1 << ab2 
		<< ab3  << as0 << as1 << as2 << as3 << acin;
	*/
	//test for multiplier

	sc_signal<sc_logic> ma0, ma1, ma2, ma3,
						mb0, mb1, mb2, mb3, gnd,
						ms0, ms1, ms2, ms3, ms4, ms5, ms6, ms7;
	multiplier multiplierTEST("multiplierTEST");
	multiplierTEST <<gnd<< ma0 << ma1 << ma2 << ma3 <<
						   mb0 << mb1 << mb2 << mb3 << 
						   ms0 << ms1 << ms2 << ms3 << ms4 << ms5 << ms6 << ms7;
	mytestformul testbenchmul("testbenchmul");
	testbenchmul << gnd << ma0 << ma1 << ma2 << ma3 <<
						   mb0 << mb1 << mb2 << mb3 <<
						   ms0 << ms1 << ms2 << ms3 << ms4 << ms5 << ms6 << ms7;
	

	sc_start(200, SC_NS);
	system("PAUSE");
	return 0;

}