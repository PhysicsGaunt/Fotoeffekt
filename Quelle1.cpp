#include<iostream>
#include<math.h>

using namespace std;

int main() {
	double u0 = 0;	// Dunkelspannung U_i0
	double u = 0;	// U_i
	double du = 0;	// Fehler U_i
	double su = 0;	// Wurzel U_i-U_i0
	double dsu = 0;	// Fehler Wurzel U_i-U_i0

	cout << "U0(mV)= ";
	cin >> u0;
	u0=u0/1000;

	while (true) {
		system("cls");
		
		cout << "U(mV)= ";
		cin >> u;
		u=u/1000;
		
		
		if (u >= 0.1)
		{
			du = sqrt(0.003*0.003*(u*u + u0*u0) + 0.0008*0.0008*(u*u + u0*u0) + 0.00005);
		}
		else {
			du = sqrt(0.003*0.003*(u*u + u0*u0) + 0.0008*0.0008*(u*u + u0*u0) + 0.00002725);
		}
		
		u = u - u0;
		double au = fabs(u);
		su = sqrt(au);
		dsu = 0.5*du/su;
		
		cout << endl << "U-U0(V): "<< u << " +- " << du << endl;
		cout << "Wurzel U-U0(V): "<< su << "  +-  " << dsu << endl << endl;
		system("pause");
	}
return 0;
}
