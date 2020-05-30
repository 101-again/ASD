#include <iostream>
 
using namespace std;

void Getting_Value(int a, int b, int x) { 
	bool status = true;
	int waterVolumeInA = 0;
	int waterVolumeInB = 0;
	int GCD=1; //ÍÎÄ
=
	int a_gcd = a;
	int b_gcd = b;

	int t;
	while (b_gcd != 0) {
		t = b_gcd;
		b_gcd = a_gcd % b_gcd;
		a_gcd = t;
		GCD = a_gcd;
	}

	//GCD = a;

	while (status)
	{
		if (a > b) {
			if ((GCD > 1 && x%GCD == 0 && a%b != 0) || GCD == 1 || (GCD > 1 && x%GCD == 0 && x%b==0)) {
					waterVolumeInA = 0;
					cout << "Empty A container\t"<<waterVolumeInA << "\t\t\t" << waterVolumeInB << endl;
					waterVolumeInA = a;
					cout << "Fill A container\t"<<waterVolumeInA << "\t\t\t" << waterVolumeInB << endl;
					waterVolumeInA = waterVolumeInA - (b - waterVolumeInB);
					waterVolumeInB = a - waterVolumeInA + waterVolumeInB;
					cout << "A->B\t\t\t" <<waterVolumeInA << "\t\t\t" << waterVolumeInB << endl;
					if (waterVolumeInB == x || waterVolumeInA == x)
					{
						status = false;
						break;
					}
					waterVolumeInB = 0;
					cout <<"Empty B container\t" <<waterVolumeInA << "\t\t\t" << waterVolumeInB << endl;
					waterVolumeInB = waterVolumeInA % b;
			}
			else {
				cout << "We can't get required volume" << endl;
			}
		}
		else if (b > a)
		{
			if ((GCD > 1 && x%GCD == 0 && b%a != 0) || GCD == 1 || (GCD > 1 && x%GCD == 0 && x%a == 0)) {
				waterVolumeInB = 0;
				cout << "Empty B container\t" << waterVolumeInA << "\t\t\t" << waterVolumeInB << endl;
				waterVolumeInB = b;
				cout << "Fill B container\t" << waterVolumeInA << "\t\t\t" << waterVolumeInB << endl;
				waterVolumeInB = waterVolumeInB - (a - waterVolumeInA);
				waterVolumeInA = b - waterVolumeInB + waterVolumeInA;
				cout << "B->A\t\t\t" << waterVolumeInA << "\t\t\t" << waterVolumeInB << endl;
				if (waterVolumeInA == x || waterVolumeInB == x)
				{
					status = false;
					break;
				}
				waterVolumeInA = 0;
				cout << "Empty A container\t" << waterVolumeInA << "\t\t\t" << waterVolumeInB << endl;
				waterVolumeInA = waterVolumeInB % a;
			}
			else {
				cout << "We can't get required volume" << endl;
			}

		}
		else if (a == b)
		{
			cout << "Empty containers\t" << waterVolumeInA << "\t\t\t" << waterVolumeInB << endl;
			waterVolumeInA = a;
			cout << "Fill A container\t" << waterVolumeInA << "\t\t\t" << waterVolumeInB << endl;
			break;
		}
	}
}

int main()
{
	int ñontainer_A;
	int ñontainer_B;
	int reqVolume_X;

	cout << "Enter volume of A container: ";
	cin >> ñontainer_A;
	cout << "Enter volume of B container: ";
	cin >> ñontainer_B;
	cout << "Enter required volume X: ";
	cin >> reqVolume_X;
	
	if ((ñontainer_A != ñontainer_B && (reqVolume_X < ñontainer_A || reqVolume_X < ñontainer_B)) || ((ñontainer_A == ñontainer_B) && (ñontainer_B==reqVolume_X)))
	{
		cout << "Action" << "\t\t" << "Volume of A container" << "\t" << "Volume of B container"<<endl;
		Getting_Value(ñontainer_A, ñontainer_B, reqVolume_X);
	}
	else if ((reqVolume_X > ñontainer_A && reqVolume_X > ñontainer_B) || ((ñontainer_A == ñontainer_B) && (ñontainer_B!=reqVolume_X))) {
		cout << "We can't get required volume" << endl;
	}

	system("pause");
	return 0;
}