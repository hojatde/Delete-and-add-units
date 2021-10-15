/*
admin baraye voroad az admin estefade mikonad.
barname ba visual studio 2019 neveshte shode ast.
*/

#include <iostream>
#include <fstream>//be manzoor save and load information.
#include <iomanip>//teve setw.

using namespace std;


//tarif dars be onvan class
class dars {
protected:
	string name;
	string id;

public:
	dars();
	void set_name(string s);
	void set_id(string id);
	string get_name();
	string get_id();
};

dars::dars()//tabe sazande
{
	name = "khali";
	id = " ";
}

void dars::set_name(string s)
{
	name = s;
}
void dars::set_id(string s)
{
	id = s;
}
string dars::get_name()
{
	return name;
}
string dars::get_id()
{
	return id;
}

//tarif student be onvan class
class student {
protected:
	string name;
	string id;
	int tedad_dars_student;
	dars doroos_student[20];//araay az doroos baraye daneshjoo

public:
	student();
	void set_name(string s);
	string get_name();
	void set_id(string s);
	string get_id();
	void add_dars_student(dars& s);
	void delete_dars_student(string id);
	void show_doroos_student();
	void search(dars &d);
};
student::student()
{
	name = "khali";
	id = "0";
	tedad_dars_student = -1;
}

void student::search(dars &d)
{
	int y;
	y = tedad_dars_student;
	if (y > -1)
	{
		for (int m =0 ; m <= y; m++)
		{
			if (doroos_student[m].get_name() == d.get_name())
			{
				cout << "   " << "ID daneshjoo :  " << get_id() << endl;
			}
		}
	}
}

void student::delete_dars_student(string id)
{
	int c = -1;
	for (int i = 0; i < 20; i++)
	{
		if (id == doroos_student[i].get_id())
		{
			c = i;
		}
		if (c != -1)
			break;
	}
	if (c != -1)
	{
		for (c; c < 19; c++)
		{
			doroos_student[c].set_id(doroos_student[c + 1].get_id());
			doroos_student[c].set_name(doroos_student[c + 1].get_name());
		}
		doroos_student[19].set_id("khali");
		doroos_student[19].set_name("khali");
		tedad_dars_student -= 1;
		cout << "<><> dars mored nazar ba moafaghiat hazf shod." << endl;

	}
	if (c == -1)
	{
		cout << "<><> dars vared shode tavasot daneshjoo entekhab nashode ast." << endl;
	}
}

void student::show_doroos_student()
{
	int i;
	i = tedad_dars_student;
	cout << "<><> doroos entekhabi daneshjoo :  " << endl;
	for (int j = 0; j <= i; j++)
	{
		cout << "<><> id dars    :    " << doroos_student[j].get_id() << "        ";
		cout << "<><> name dars :     " << doroos_student[j].get_name() << endl;
	}
	if (i == -1)
	{
		cout << "<><> daneshjoo darsi entekhab nakarde ast.";
	}
}
void student::add_dars_student(dars& s)
{
	int i;
	int b = 0;

	i = tedad_dars_student;
	if (i < 20)
	{
		for (int g = 0; g <= i; g++)
		{
			if (s.get_name() == doroos_student[g].get_name())
			{
				cout << "<><> !Warning  dars az ghabl bardashte shode ast." << endl;
				b++;
				break;
			}
		}
		if (b == 0)
		{
			tedad_dars_student += 1;
			i = tedad_dars_student;
			doroos_student[i] = s;
			cout << "<><> dars mored nazar ba moafaghiat add shod." << endl;
		}
	}
	else
	{
		cout << "<><> !warning tedad dars mojaz ra dar nazar begirid.";
	}

}

void student::set_name(string s)
{
	name = s;
}
void student::set_id(string s)
{
	id = s;
}

string student::get_id()
{
	return id;
}
string student::get_name()
{
	return name;
}


//tarif class ke be soorat protected az class student va darsbe ers borde shode

//--------------->>>>> mitavan in class ra be onvan class doost do tabe student va class ham tarif kard----
//--------------->>>>> mitavan in class ra be onvan class doost do tabe student va class ham tarif kard----
//--------------->>>>> mitavan in class ra be onvan class doost do tabe student va class ham tarif kard----
//be mnazoor dastresi be etelaat baraye save va load etelaat bayad ya friend tarif shavad ya be ers bebarad.

/*
azaye calss ha ra be onvan protected dar nazar gereftim ta class admin betavand be an dastresi dashte bashad
va hengam save and load moshkli be vojood nyayad.
*/

class admin_system : protected dars, protected student
{
protected:

	string id_admin;//admin
	dars doroos_mojod[100];//array az doroos araee shode be tool 100
	int tedad_dars;
	student students_mojod[100];//array az student ijad shode be tool 100
	int tedad_student;

public:

	admin_system();
	string show_id_admin();//bargardandan id vorood admin 
	void add_dars(string name_dars, string id_dars);//azafe kardan dars
	void delete_dars(string name_dars, string id_dars);
	void add_student(string name_student, string id_student);
	void delete_student(string name_student, string id_student);
	void show_student();
	void show_doroos();
	int vorood_student(string name, string id);
	void add_dars_for_student(string id, int o);
	void show_student_dars(int t);
	void delete_dars_for_student(string id, int o);
	void save();
	void load();
	void tedad();
	void show_student_in_dars();
};

admin_system::admin_system()//tabe sazande
{
	id_admin = "admin";
	tedad_dars = 0;
	tedad_student = 0;
}

void admin_system::tedad()
{
	cout << "<><> tedad student sabt shode dar system :" << tedad_student;
	cout << endl <<"<><>tedad dars sabt shode dar system :" <<tedad_dars << endl;
}

void admin_system::show_student_in_dars()
{
	if (tedad_dars > 0)
	{
		int i;
		int s;
		s = tedad_student;
		i = tedad_dars;
		for (int c = 0; c < i; c++)
		{
			cout << endl << "ID dars   :    " << doroos_mojod[c].get_id() << "         " << "NAME dars   :   ";
			cout << doroos_mojod[c].get_name() << endl << "<><>Daneshjooyan mojood    =     "<<endl;
			for (int k = 0; k < s; k++)
			{
				students_mojod[k].search(doroos_mojod[c]);
			}
		}
	}
}

void admin_system::save()
{
	ofstream f1;
	f1.open("info", ios::out);
	int i;
	i = tedad_dars;
	f1.write((char*)&i, sizeof(i));
	for (int c = 0; c < i; c++)
	{
		f1.write((char*)&doroos_mojod[c], sizeof(dars));
	}



	int j;
	j = tedad_student;

	f1.write((char*)&j, sizeof(int));
	for (int c = 0; c < j; c++)
	{
		f1.write((char*)&students_mojod[c], sizeof(student));
	}
	f1.close();
}

void admin_system::load()
{
	ifstream f1;
	f1.open("info", ios::in);
	f1.read((char*)&tedad_dars, sizeof(int));
	int i;
	i = tedad_dars;
	for (int c = 0; c < i; c++)
	{
		f1.read((char*)&doroos_mojod[c], sizeof(dars));
	}
	f1.read((char*)&tedad_student, sizeof(int));
	int j;
	j = tedad_student;
	for (int c = 0; c < j; c++)
	{
		f1.read((char*)&students_mojod[c], sizeof(student));
	}

	f1.close();
}

void admin_system::show_student_dars(int t)
{
	students_mojod[t].show_doroos_student();
}

void admin_system::delete_dars_for_student(string id, int o)
{
	students_mojod[o].delete_dars_student(id);
}

void admin_system::add_dars_for_student(string id, int o)
{
	int c = -1;
	for (int i = 0; i < 100; i++)
	{
		if (id == doroos_mojod[i].get_id())
		{
			c = i;
			students_mojod[o].add_dars_student(doroos_mojod[c]);
			break;
		}
	}
	if (c == -1)
	{
		cout << "<><> dars entekhab shode eraee nashode ast." << endl;
	}

}

int admin_system::vorood_student(string name, string id)
{
	int c = -1;
	int q = tedad_student;
	for (int i = 0; i < q; i++)
	{
		if (name == students_mojod[i].get_name())
		{
			c = i;
			break;
		}
	}
	if (c == -1)
	{
		for (int i = 0; i < q; i++)
		{
			if (id == students_mojod[i].get_id())
			{
				c = i;
				break;
			}
		}
	}
	if (c == -1)
	{
		cout << "<><> daneshjooei ba in id ya name vojood nadarad." << endl;
	}
	return c;
}
void admin_system::show_student()
{
	int i;
	i = tedad_student;
	if (i == 0)
	{
		cout << "<><> hich student sabt nashode ast." << endl;
	}
	else
	{
		for (int j = 0; j < i; j++)
		{
			cout << "<><> ID daneshjoo ::  " << students_mojod[j].get_id() << setw(50) << "NAME daneshjoo  ::  " << students_mojod[j].get_name() << endl;
		}
	}
}

void admin_system::show_doroos()
{
	int i;
	i = tedad_dars;
	if (i == 0)
	{
		cout << "<><> hich darsi dar system sabt nashode ast." << endl;
	}
	else
	{
		for (int j = 0; j < i; j++)
		{
			cout << setw(20) << "<><> ID dars ::  " << doroos_mojod[j].get_id() << "            " << "NAME dars ::   " << doroos_mojod[j].get_name() << endl;
		}
	}
}

string admin_system::admin_system::show_id_admin()
{
	return id_admin;
}

void admin_system::add_dars(string name_dars, string id_dars)
{
	int w = -1;
	dars k;
	k.set_name(name_dars);
	k.set_id(id_dars);
	int s = tedad_dars;
	for (int p = 0; p < s; p++)
	{
		if (doroos_mojod[p].get_id() == id_dars)
			w++;
		if (doroos_mojod[p].get_name() == name_dars)
			w++;
	}
	if (w == -1)
	{
		doroos_mojod[s] = k;
		cout << "<><> dars sabt shod" << endl;
		tedad_dars++;
	}
	else
	{
		cout << "<><> --warning-- dars mored nazar dar sabt shode ast";
	}

}

void admin_system::delete_dars(string name_dars, string id_dars)
{
	int c = -1;;
	for (int i = 0; i < 100; i++)
	{
		if (name_dars == doroos_mojod[i].get_name())
		{
			doroos_mojod[i].set_name("khali");
			doroos_mojod[i].set_id("khali");
			c = i;
		}
		if (c != -1)
			break;
	}


	if (c == -1)
	{
		for (int i = 0; i < 100; i++)
		{
			if (id_dars == doroos_mojod[i].get_id())
			{
				doroos_mojod[i].set_name("khali");
				doroos_mojod[i].set_id("khali");
				c = i;
			}
			if (c != -1)
				break;
		}

	}
	if (c != -1)
	{
		for (c; c < 99; c++)
		{
			doroos_mojod[c].set_name(doroos_mojod[c + 1].get_name());
			doroos_mojod[c].set_id(doroos_mojod[c + 1].get_id());
		}
	}
	if (c != -1)
	{
		doroos_mojod[99].set_name("khali");
		doroos_mojod[99].set_id("khali");
		cout << endl;
		cout << "<><> dars mored nazar hazf shod.";
		tedad_dars -= 1;
	}
	if (c == -1)
		cout << "<><> dars mored nazar dar list mojood nist" << endl;
}

void admin_system::add_student(string name_student, string id_student)
{
	int w = -1;
	int i;
	i = tedad_student;
	for (int p = 0; p < i; p++)
	{

		if (students_mojod[p].get_id() == id_student)
			w++;
	}
	if (w == -1)
	{
		students_mojod[i].set_name(name_student);
		students_mojod[i].set_id(id_student);
		cout << "<><> daneshjoo sabt shod." << endl << endl;;
		tedad_student = tedad_student + 1;
	}
	else
	{
		cout << "<><> --warning-- student az ghabl dar system sabt shode ast.";
	}
}

void admin_system::delete_student(string name_student, string id_student)
{
	int c = -1;
	int q = tedad_student;
	for (int i = 0; i < q; i++)
	{
		if (name_student == students_mojod[i].get_name())
		{
			c = i;
			break;
		}
	}

	if (c == -1)
	{
		for (int i = 0; i < q; i++)
		{
			if (id_student == students_mojod[i].get_id())
			{
				c = i;
				break;
			}
		}
	}
	if (c != -1)
	{
		for (c; c < q; c++)
		{
			students_mojod[c].set_name(students_mojod[c + 1].get_name());
			students_mojod[c].set_id(students_mojod[c + 1].get_id());
		}
	}
	if (c != -1)
	{
		students_mojod[99].set_name("khali");
		students_mojod[99].set_id("khali");
		cout << "<><>  student mored nazar hazf shod." << endl;
		tedad_student -= 1;
	}
	if (c == -1)
	{
		cout << "<><>  student moread nazar dar list mojood nist.";
	}
}

int main()
{
	admin_system admin;
	admin.load();
	string l;
	string m1, m2;
	bool j = 1;//ta zamani ke har karbar dar hesab karbari bashad meghadr an 1 va dar soorati ke az hesab karbari khod kharej shavad meghdar on 0 khahad bood
	char g;
	cout << endl << "              +++++++khosh amadid+++++++             " << endl;
	while (1)
	{
		admin.save();
		cout << endl << "=====================================================================" << endl;
		cout << "       baraye vorood lofta name ya id khod ra vared konid :" << endl << endl;
		cout << "   ======  ";
		cin >> l;
		cout << endl;
		if (l == admin.show_id_admin())//vorood be onvan admin
		{
			cout << "------" << "   shoma be onvan >>>  admin   <<<< vared shodid  " << "------" << endl << endl;
			j = 1;


			while (j)
			{
				cout << endl;
				cout << "***************************************************************" << endl;
				cout << "  entekhab konid" << endl;
				cout << "  1.ezafe kardan daneshjoo." << endl;
				cout << "  2.hazf kardan daneshjoo." << endl;
				cout << "  3.ezafe kardan dars." << endl;
				cout << "  4.hazf dars" << endl;
				cout << "  5.namayesh daneshjooyan" << endl;
				cout << "  6.namayesh doroos" << endl;
				cout << "  7.namayesh daneshjooyan sabt nami dar dars." << endl;
				cout << "  8.save and exit" << endl << endl;
				cout << "  entekhab shoma    ->  ";
				cin >> g;

				switch (g)//entekhab karbar
				{
				case '1' :
					cout << "--lotfa name daneshjoo ra vared konid  :    ";
					cin >> m1;
					cout << "--lofta id daneshjoo ra vared konid    :    ";
					cin >> m2;

					admin.add_student(m1, m2);
					break;

				case '2':
					cout << "--lofta id ya shomare daneshjoo ra vared konid  :  ";
					cin >> m1;
					admin.delete_student(m1, m1);
					break;

				case '3':
					cout << "--lotfa name dars ra vared konid    :    ";
					cin >> m1;
					cout << "--lofta id dars ra vared konid      :    ";
					cin >> m2;
					admin.add_dars(m1, m2);
					break;
				case '4':
					cout << "--lofta name ya id dars ra vared konid" << endl;
					cin >> m1;
					admin.delete_dars(m1, m1);
					break;

				case '5':
					admin.show_student();
					break;

				case '6':

					admin.show_doroos();
					break;

				case '7':
					admin.show_student_in_dars();
					break;

				case '8':
					j = 0;
					break;

				default:
					cout << "--entekhab shoma eshtebah ast" << endl;
					break;
				}

			}
		}
		else//dar soorati ke karbar vared shode student bashad
		{
			int t;
			t = admin.vorood_student(l, l);
			if (t != -1)
			{
				cout << "    shoma be onvan ---> student <-- vared shodid ";
				j = 1;
				while (j)
				{
					cout << endl;
					cout << endl << "-----------------------------------------------------------------------" << endl << endl;
					cout << "   entekhab konid" << endl;
					cout << "  1.baraye add dars." << endl;
					cout << "  2.baraye hazf dars" << endl;
					cout << "  3.baraye moshahede list doroos bardashte shode student." << endl;
					cout << "  4.baraye moshahede list doroos eraee shode. " << endl;
					cout << "  5.save and exit." << endl;
					cout << "  entekhab shoma    ->  ";

					cin >> g;
					switch (g)
					{
					case '1':
						cout << "--id dars ra vared konid     ::     ";
						cin >> m1;
						admin.add_dars_for_student(m1, t);
						break;

					case '2':
						cout << "--id dars ra vared konid     ::      ";
						cin >> m1;
						admin.delete_dars_for_student(m1, t);
						break;
					case '3':
						admin.show_student_dars(t);
						break;

					case '4':
						admin.show_doroos();
						break;

					case '5':
						j = 0;
						break;

					default:
						break;

					}
				}

			}
			else//dar soorati ke karbar na admin bashad va na student
			{
				cout << "     karbari ba in moshakhasat dar system sabt nist.";
			}
		}

	}
}
