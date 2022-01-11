#include "systemc.h"
	SC_MODULE(BIT_ADDER)
{
	sc_in<sc_logic> a, b, cin;
	sc_out<sc_logic> sum, cout;

	SC_CTOR(BIT_ADDER)
	{
		SC_METHOD(process);
		sensitive << a << b << cin;
	}

	void process()
	{
		sc_logic aANDb, aXORb, cinANDaXORb;

		aANDb = a.read() & b.read();
		aXORb = a.read() ^ b.read();
		cinANDaXORb = cin.read() & aXORb;

		sum = aXORb ^ cin.read();
		cout = aANDb | cinANDaXORb;
	}
};

	SC_MODULE(bit_4_adder)
	{
		sc_in<sc_logic> aa0, aa1, aa2, aa3, ab0, ab1, ab2, ab3, gnd;
		sc_out<sc_logic> as0, as1, as2, as3, acin;

		sc_signal<sc_logic>  c0, c1, c2;
		BIT_ADDER adder0, adder1, adder2, adder3;

		SC_CTOR(bit_4_adder) :adder0("adder0"), adder1("adder1"), adder2("adder2"), adder3("adder3")
		{
			//SC_METHOD(process);
			sensitive << gnd << aa0 << aa1 << aa2 << aa3 << ab0 << ab1 << ab2 << ab3;

			adder0.a(aa0);
			adder0.b(ab0);
			adder0.cin(gnd);

			adder0.sum(as0);
			adder0.cout(c0);

			adder1.a(aa1);
			adder1.b(ab1);
			adder1.cin(c0);

			adder1.sum(as1);
			adder1.cout(c1);

			adder2.a(aa2);
			adder2.b(ab2);
			adder2.cin(c1);

			adder2.sum(as2);
			adder2.cout(c2);

			adder3.a(aa3);
			adder3.b(ab3);
			adder3.cin(c2);

			adder3.sum(as3);
			adder3.cout(acin);


		}

		void process()
		{

		}
	};
	SC_MODULE(one_to_four_and)
	{
		sc_in<sc_logic> a0, a1, a2, a3, b0;
		sc_out<sc_logic> and0, and1, and2, and3;

		SC_CTOR(one_to_four_and)
		{

			SC_METHOD(process);
			sensitive << b0 << a0 << a1 << a2 << a3;
		}

		void process()
		{
			//sc_logic a0ANDb0, a1ANDb0, a2ANDb0, a3ANDb0;

			and0.write(a0.read() & b0.read());
			and1.write(a1.read() & b0.read());
			and2.write(a2.read() & b0.read());
			and3.write(a3.read() & b0.read());

		}
	};

	SC_MODULE(multiplier) {
		sc_in<sc_logic> ma0, ma1, ma2, ma3,
						mb0, mb1, mb2, mb3, gnd;
		sc_out<sc_logic> ms0, ms1, ms2, ms3, ms4, ms5, ms6, ms7;
		//   P0	  P1   P2   P3   P4   P5   P6   P7
		sc_signal<sc_logic>		  A1B0, A2B0, A3B0,
							A0B1, A1B1, A2B1, A3B1,
							A0B2, A1B2, A2B2, A3B2,
							A0B3, A1B3, A2B3, A3B3;
		sc_signal<sc_logic> S11, S21, S31, C41, S19, S22, S23, C24;

		bit_4_adder bitadder0, bitadder1, bitadder2;
		one_to_four_and andfour0, andfour1, andfour2, andfour3;

		SC_CTOR(multiplier) :bitadder0("bitadder0"), bitadder1("bitadder1"), bitadder2("bitadder2"), andfour0("andfour0"), andfour1("andfour1"), andfour2("andfour2"), andfour3("andfour3")
		{
			sensitive << ma0 << ma1 << ma2 << ma3 << mb0 << mb1 << mb2 << mb3 << gnd;
			SC_METHOD(process);
			andfour0.b0(mb0);	//B0
			andfour0.a0(ma0);	//A0
			andfour0.a1(ma1);	//A1
			andfour0.a2(ma2);	//A2
			andfour0.a3(ma3);	//A3

			andfour0.and0(ms0);		//A0B0 P0
			andfour0.and1(A1B0);	//A1B0
			andfour0.and2(A2B0);	//A2B0
			andfour0.and3(A3B0);	//A3B0

			andfour1.b0(mb1);	//B1
			andfour1.a0(ma0);	//A0
			andfour1.a1(ma1);	//A1
			andfour1.a2(ma2);	//A2
			andfour1.a3(ma3);	//A3

			andfour1.and0(A0B1);	//A0B1
			andfour1.and1(A1B1);	//A1B1
			andfour1.and2(A2B1);	//A2B1
			andfour1.and3(A3B1);	//A3B1

			andfour2.b0(mb2);	//B2
			andfour2.a0(ma0);	//A0
			andfour2.a1(ma1);	//A1
			andfour2.a2(ma2);	//A2
			andfour2.a3(ma3);	//A3

			andfour2.and0(A0B2);	//A0B2
			andfour2.and1(A1B2);	//A1B2
			andfour2.and2(A2B2);	//A2B2
			andfour2.and3(A3B2);	//A3B2
		
			andfour3.b0(mb3);	//B3
			andfour3.a0(ma0);	//A0
			andfour3.a1(ma1);	//A1
			andfour3.a2(ma2);	//A2 
			andfour3.a3(ma3);	//A3
		
			andfour3.and0(A0B3);	//A0B3
			andfour3.and1(A1B3);	//A1B3
			andfour3.and2(A2B3);	//A2B3
			andfour3.and3(A3B3);    //A3B3 	
			/// first 4-bit adder
			bitadder0.aa0(A1B0);
			bitadder0.aa1(A2B0);
			bitadder0.aa2(A3B0);
			bitadder0.aa3(gnd);
			bitadder0.ab0(A0B1);
			bitadder0.ab1(A1B1);
			bitadder0.ab2(A2B1);
			bitadder0.ab3(A3B1);
			bitadder0.gnd(gnd);
		
			bitadder0.as0(ms1);//
			bitadder0.as1(S11);//
			bitadder0.as2(S21);//
			bitadder0.as3(S31);//
			bitadder0.acin(C41);//
			///
			bitadder1.aa0(S11);
			bitadder1.aa1(S21);
			bitadder1.aa2(S31);
			bitadder1.aa3(C41);
			bitadder1.ab0(A0B2);
			bitadder1.ab1(A1B2);
			bitadder1.ab2(A2B2);
			bitadder1.ab3(A3B2);
			bitadder1.gnd(gnd);

			bitadder1.as0(ms2);
			bitadder1.as1(S19);
			bitadder1.as2(S22);
			bitadder1.as3(S23);
			bitadder1.acin(C24);
			///
			bitadder2.aa0(S19);
			bitadder2.aa1(S22);
			bitadder2.aa2(S23);
			bitadder2.aa3(C24);
			bitadder2.ab0(A0B3);
			bitadder2.ab1(A1B3);
			bitadder2.ab2(A2B3);
			bitadder2.ab3(A3B3);
			bitadder2.gnd(gnd);

			bitadder2.as0(ms3);
			bitadder2.as1(ms4);
			bitadder2.as2(ms5);
			bitadder2.as3(ms6);
			bitadder2.acin(ms7);
		}
		void process()
		{

		}
	};

	SC_MODULE(mytestformul) {
		sc_out<sc_logic> tma0, tma1, tma2, tma3,
						 tmb0, tmb1, tmb2, tmb3, gnd;
		sc_in<sc_logic> tms0, tms1, tms2, tms3, tms4, tms5, tms6, tms7;
		SC_CTOR(mytestformul) {
			SC_THREAD(process);
		}
		void process()
		{
			gnd =  SC_LOGIC_0;
			tma0 = SC_LOGIC_0;
			tma1 = SC_LOGIC_0;
			tma2 = SC_LOGIC_0;
			tma3 = SC_LOGIC_0;
			tmb0 = SC_LOGIC_0;
			tmb1 = SC_LOGIC_0;
			tmb2 = SC_LOGIC_0;
			tmb3 = SC_LOGIC_0;

			wait(10, SC_NS);
			mymulprint();
			gnd = SC_LOGIC_0;
			tma0 = SC_LOGIC_1;
			tma1 = SC_LOGIC_0;
			tma2 = SC_LOGIC_0;
			tma3 = SC_LOGIC_0;
			tmb0 = SC_LOGIC_1;
			tmb1 = SC_LOGIC_0;
			tmb2 = SC_LOGIC_0;
			tmb3 = SC_LOGIC_0;

			wait(10, SC_NS);
			mymulprint();
			//1111*1111
			gnd = SC_LOGIC_0;
			tma0 = SC_LOGIC_1;
			tma1 = SC_LOGIC_1;
			tma2 = SC_LOGIC_1;
			tma3 = SC_LOGIC_1;
			tmb0 = SC_LOGIC_1;
			tmb1 = SC_LOGIC_1;
			tmb2 = SC_LOGIC_1;
			tmb3 = SC_LOGIC_1;

			wait(10, SC_NS);
			mymulprint();
			//1110 0000
			gnd = SC_LOGIC_0;
			tma0 = SC_LOGIC_0;
			tma1 = SC_LOGIC_1;
			tma2 = SC_LOGIC_1;
			tma3 = SC_LOGIC_1;
			tmb0 = SC_LOGIC_0;
			tmb1 = SC_LOGIC_0;
			tmb2 = SC_LOGIC_0;
			tmb3 = SC_LOGIC_0;

			wait(10, SC_NS);
			mymulprint();
			//0100*1100
			gnd = SC_LOGIC_0;
			tma0 = SC_LOGIC_0;
			tma1 = SC_LOGIC_0;
			tma2 = SC_LOGIC_1;
			tma3 = SC_LOGIC_0;
			tmb0 = SC_LOGIC_0;
			tmb1 = SC_LOGIC_0;
			tmb2 = SC_LOGIC_1;
			tmb3 = SC_LOGIC_1;

			wait(10, SC_NS);
			mymulprint();
			//1011*1001
			gnd = SC_LOGIC_0;
			tma0 = SC_LOGIC_1;
			tma1 = SC_LOGIC_0;
			tma2 = SC_LOGIC_0;
			tma3 = SC_LOGIC_1;
			tmb0 = SC_LOGIC_1;
			tmb1 = SC_LOGIC_1;
			tmb2 = SC_LOGIC_0;
			tmb3 = SC_LOGIC_1;

			wait(10, SC_NS);
			mymulprint();
			sc_stop();	//End Simulation
		}

		void mymulprint()
		{
			cout << "time:" << sc_time_stamp() << endl;
			cout << "multiplicand:";
			cout << tma3.read() << tma2.read() << tma1.read() << tma0.read() << endl;
			cout << "multiplier:  ";
			cout << tmb3.read() << tmb2.read() << tmb1.read() << tmb0.read() << endl;
			cout << "Product: ";
			cout << tms7.read() << tms6.read() << tms5.read() << tms4.read() << tms3.read() << tms2.read() << tms1.read() << tms0.read() << endl;
			cout << "----------------------------";
		}
	};

	SC_MODULE(mytest) {
		sc_out<sc_logic> ta0, ta1, ta2, ta3, tb0;
		sc_in<sc_logic> tand0, tand1, tand2, tand3;

		SC_CTOR(mytest) {
			SC_THREAD(process);
		}
		void process()
		{
			ta0 = SC_LOGIC_1;
			ta1 = SC_LOGIC_1;
			ta2 = SC_LOGIC_1;
			ta3 = SC_LOGIC_0;
			tb0 = SC_LOGIC_1;
			wait(10, SC_NS);
			myprint();

			ta0 = SC_LOGIC_0;
			ta1 = SC_LOGIC_0;
			ta2 = SC_LOGIC_1;
			ta3 = SC_LOGIC_0;
			tb0 = SC_LOGIC_1;
			wait(10, SC_NS);
			myprint();
			ta0 = SC_LOGIC_0;
			ta1 = SC_LOGIC_0;
			ta2 = SC_LOGIC_1;
			ta3 = SC_LOGIC_0;
			tb0 = SC_LOGIC_0;
			wait(10, SC_NS);
			myprint();
			sc_stop();	//End Simulation
		}
		void myprint()
		{


			cout << "time:" << sc_time_stamp() << endl;
			cout << "a:";
			cout << ta0.read() << ta1.read() << ta2.read() << ta3.read() << endl;
			cout << "b:";
			cout << tb0.read() << endl;
			cout << "result:" << tand0.read() << tand1.read() << tand2.read() << tand3.read() << endl;
			cout << "------------------------------" << endl;
		}


	};

	SC_MODULE(mytestforbit4adder)
	{
		sc_out<sc_logic> test_aa0, test_aa1, test_aa2, test_aa3, test_ab0, test_ab1, test_ab2, test_ab3, test_gnd;
		sc_in<sc_logic> test_as0, test_as1, test_as2, test_as3, test_acin;
		SC_CTOR(mytestforbit4adder)
		{
			SC_THREAD(process);
		}
		void process()
		{//0+0
			test_gnd = SC_LOGIC_0;
			test_aa0 = SC_LOGIC_0;
			test_aa1 = SC_LOGIC_0;
			test_aa2 = SC_LOGIC_0;
			test_aa3 = SC_LOGIC_0;

			test_ab0 = SC_LOGIC_0;
			test_ab1 = SC_LOGIC_0;
			test_ab2 = SC_LOGIC_0;
			test_ab3 = SC_LOGIC_0;
			wait(10, SC_NS);
			print4bit();
			//1+1
			test_gnd = SC_LOGIC_0;
			test_aa0 = SC_LOGIC_1;
			test_aa1 = SC_LOGIC_0;
			test_aa2 = SC_LOGIC_0;
			test_aa3 = SC_LOGIC_0;

			test_ab0 = SC_LOGIC_1;
			test_ab1 = SC_LOGIC_0;
			test_ab2 = SC_LOGIC_0;
			test_ab3 = SC_LOGIC_0;
			wait(10, SC_NS);
			print4bit();
			//11+11
			test_gnd = SC_LOGIC_0;
			test_aa0 = SC_LOGIC_1;
			test_aa1 = SC_LOGIC_1;
			test_aa2 = SC_LOGIC_0;
			test_aa3 = SC_LOGIC_0;

			test_ab0 = SC_LOGIC_1;
			test_ab1 = SC_LOGIC_1;
			test_ab2 = SC_LOGIC_0;
			test_ab3 = SC_LOGIC_0;
			wait(10, SC_NS);
			print4bit();

			test_gnd = SC_LOGIC_0;
			test_aa0 = SC_LOGIC_1;
			test_aa1 = SC_LOGIC_0;
			test_aa2 = SC_LOGIC_0;
			test_aa3 = SC_LOGIC_1;

			test_ab0 = SC_LOGIC_0;
			test_ab1 = SC_LOGIC_0;
			test_ab2 = SC_LOGIC_0;
			test_ab3 = SC_LOGIC_1;
			wait(10, SC_NS);
			print4bit();

			test_gnd = SC_LOGIC_1;
			test_aa0 = SC_LOGIC_1;
			test_aa1 = SC_LOGIC_1;
			test_aa2 = SC_LOGIC_1;
			test_aa3 = SC_LOGIC_1;

			test_ab0 = SC_LOGIC_1;
			test_ab1 = SC_LOGIC_1;
			test_ab2 = SC_LOGIC_1;
			test_ab3 = SC_LOGIC_1;
			wait(10, SC_NS);
			print4bit();

			sc_stop();
		}
		void print4bit()
		{
			cout << "time:" << sc_time_stamp() << endl;
			cout << "a:" << test_aa3.read() << test_aa2.read() << test_aa1.read() << test_aa0.read() << endl;
			cout << "b:" << test_ab3.read() << test_ab2.read() << test_ab1.read() << test_ab0.read() << endl;
			cout << "result:" << test_acin.read() << test_as3.read() << test_as2.read() << test_as1.read() << test_as0.read() << endl;
			cout << "--------------------------------- ";
		}

	};
