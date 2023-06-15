// ����������  ��������� ��� 
// ���������� ������,
// �������� ������,
// ����������� ������,
// ���������� ������ �� ��������� ����������,
// ������ ������ �� ��������� ����������.
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <algorithm>

; using namespace std;

int ii = 0;
struct car
{
	string name;
	int release;
	double engine;
	string price;
	car() : name(""), release(0), engine(0), price("") {};
	car(const string& nm, const int rel, const double eng, const string& pr) : name(nm), release(rel), engine(eng), price(pr) {};
};

auto print = [](car& n)
{  
	cout << "# " << ii + 1 << endl;
	cout << "�������� ����������:\t" << n.name << endl;
	cout << "��� ������� ����������:\t" << n.release << endl;
	cout << "����� ���������:\t" << n.engine << endl;
	cout << "��������� ����������:\t" << n.price << endl;
	cout << endl;	
	ii++;
};

struct comp_car
{                             // ������� ��������� 
	int what;
	bool compare(const struct car& f, const struct car& s) 
    {
		switch (abs(what)) 
        {
		case 1: return f.name < s.name;
		case 2: return f.release < s.release;
		case 3: return f.engine < s.engine;
		case 4: return f.price < s.price;
		default: return false;
		}
	}
public:
	comp_car(int what) : what(what) {}
	bool operator()(const struct car& f, const struct car& s) 
    {
		bool ret = compare(f, s);
		return what >= 0 ? ret : !ret;
	}
	
};


void Show(car & n)
{
	cout << "������ ����������:\n";
	cout << "������������ :   \t" << n.name << endl;
	cout << "��� ������� :    \t" << n.release << endl;
	cout << "����� ��������� :\t" << n.engine << endl;
	cout << "��������� :      \t" << n.price << endl;
	cout << endl;
}
void Adding_Data(vector<car>&car_vect);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	vector <car> car_vect;
	//car carr;
	int choice;
	do
	{
		cout << "\tMENU\n";
		cout << "   " << "���� ����������\n";
		cout << "0 - ��������� ������\n";
		cout << "1 - ���������� ������\n";
		cout << "2 - �������� ������\n";
		cout << "3 - ����������� ������\n";
		cout << "4 - ���������� ������ �� ��������� ����������\n";
		cout << "5 - ����� ������ �� ��������� ����������\n";
		cin >> choice;
		switch (choice)
		{
		     case 0: {} break;
		     case 1: 
		     {
				 system("cls");
				 Adding_Data(car_vect);
		     }
		     break;
		     case 2:
		     {	
				 int it;
				 cout << "����� �� ����� ���������� ������� �� ����? ";
				 cin >> it;
				 auto iter = car_vect.cbegin();        // ��������� �� ������ �������
				 car_vect.erase(iter + it - 1);        // ������� �������
				 ii = 0;
				 for_each(car_vect.begin(), car_vect.end(), print);
		     }
		     break;
		     case 3:
		     {
				 system("cls");
				 ii = 0;
				 for_each(car_vect.begin(), car_vect.end(), print);
		     }
		     break;
		     case 4:
		     {
				 system("cls");
				 int ch_sort = 0;
				 do
				 {
					 cout << "\t���� ����������\n";
					 cout << "0 - ��������� ����������\n";
					 cout << "1 - ������������� �� �������� ����������� � ���������� �������\n";
					 cout << "2 - ������������� �� ���� �������\n";
					 cout << "3 - ������������� �� ������ ���������\n";
					 cout << "4 - ������������� �� ����\n";
					 cin >> ch_sort;
					 switch (ch_sort)
					 {
					 case 0: {} break;
					 case 1:
					 {
						 system("cls");
						 cout << "������ ������������� �� �������� ����������� � ���������� �������\n";
						 ii = 0;
						 sort(car_vect.begin(), car_vect.end(), comp_car(1));  // 1 - ��  name
						 for_each(car_vect.begin(), car_vect.end(), print);
						 cout << endl;                    
					 }
					 break;
					 case 2:
					 {
						 system("cls");
						 cout << "������ ������������� �� ���� ������� �����������\n";
						 ii = 0;
						 sort(car_vect.begin(), car_vect.end(), comp_car(2));   // 2 - ��  release
						 for_each(car_vect.begin(), car_vect.end(), print);
						 cout << endl;
					 }
					 break;
					 case 3:
					 {
						 system("cls");
						 cout << "������ ������������� �� ������ ���������\n";
						 ii = 0;
						 sort(car_vect.begin(), car_vect.end(), comp_car(3));   // 3 - ��  engine
						 for_each(car_vect.begin(), car_vect.end(), print);
						 cout << endl;
					 }
					 break;
					 case 4:
					 {
						 system("cls");
						 cout << "������ ������������� �� ��������� ����������\n";
						 ii = 0;
						 sort(car_vect.begin(), car_vect.end(), comp_car(4));   // 4 - ��  price
						 for_each(car_vect.begin(), car_vect.end(), print);
						 cout << endl;
					 }
					 break;
					 }
					
				 } while (ch_sort != 0);
		     }
		     break;
		     case 5:
		     {
				 system("cls");
				 int ch_find = 0;
				 do
				 {
				      cout << "\t���� ������\n";
				      cout << "0 - ��������� �����\n";
				      cout << "1 - ����� �� �������� ����������\n";
				      cout << "2 - ����� �� ���� �������\n";
				      cout << "3 - ����� �� ������ ���������\n";
				      cout << "4 - ����� �� ����\n";
				      cin >> ch_find;
					  switch (ch_find)
					  {
					  case 0: {} break;
					  case 1:
					  {
						  system("cls");	
						  string tmp;
						  cout << "������ �������� ����������\n";
						  cin.ignore();
						  getline(cin, tmp);						  
						  ii = 0;			
						  //auto result = find_if(car_vect.begin(), car_vect.end(), [](vector<car>&car_vect) {});		  
						  for (int i = 0; i != car_vect.size(); i++)
						  {
						 	  car_vect[i].name;
							  if (car_vect[i].name == tmp)
							  {
								  Show(car_vect[i]);
							  }							  
						  }
					  }
					  break;
					  case 2:
					  {
						  system("cls");
						  int tmp;
						  cout << "������ ��� ������� ����������\n";					 
						  cin >> tmp;
						  ii = 0;						  		  
						  for (int i = 0; i != car_vect.size(); i++)
						  {
							  car_vect[i].release;
							  if (car_vect[i].release == tmp)
							  {
								  Show(car_vect[i]);
							  }
						  }
					  }
					  break;
					  case 3:
					  {
						  system("cls");
						  double tmp;
						  cout << "������ ����� ��������� ����������\n";
						  cin >> tmp;
						  ii = 0;
						  for (int i = 0; i != car_vect.size(); i++)
						  {
							  car_vect[i].engine;
							  if (car_vect[i].engine == tmp)
							  {
								  Show(car_vect[i]);
							  }
						  }
					  }
					  break;
					  case 4:
					  {
						  system("cls");
						  string tmp;
						  cout << "������ ��������� ����������\n";
						  cin.ignore();
						  getline(cin, tmp);
						  ii = 0;		  
						  for (int i = 0; i != car_vect.size(); i++)
						  {
							  car_vect[i].price;
							  if (car_vect[i].price == tmp)
							  {
								  Show(car_vect[i]);
							  }
						  }
					  }
					  break;
					  }
				 } while (ch_find != 0);			 
		     }
		     break;
		}
	} while (choice != 0);


	return 0;
}


void Adding_Data(vector<car>& car_vect)                // ��������� ������ ����                 
{
	system("cls");
	car carr;
	int ch;	
	char av;
	do
	{
		cout << "0 - ��������� � ������� ����\n";
		cout << "1 - ������ ������������� ������ 8-� �����������\n";
		cout << "2 - ������ ������ �������\n";
		cin >> ch;
		if (ch == 1)
		{
			for (int i = 0; i < 8; i++)
			{
				switch (i)
				{
				case 0: car_vect.push_back(car("Ford", 2022, 2.4, "24500�"));         
					break;
				case 1: car_vect.push_back(car("BMW", 2020, 1.8, "21800�"));                        
					break;
				case 2: car_vect.push_back(car("Audi", 2021, 2.2, "35000�"));
					break;
				case 3: car_vect.push_back(car("Honda", 2018, 2.6, "19000�"));
					break;
				case 4: car_vect.push_back(car("Toyota", 2019, 3.3, "31000�"));
					break;
				case 5: car_vect.push_back(car("Mazda", 2012, 1.6, "9000�"));
					break;
				case 6: car_vect.push_back(car("Mitsubishi", 2010, 1.8, "10000�"));
					break;
				case 7: car_vect.push_back(car("Kia", 2014, 1.6, "12100�"));
					break;
				}			
			}
			system("cls");
			cout << "������� ������������� ������ 8-� ����������� \n";
		}
		else if (ch == 2)
		{
			do
			{
				cout << "������ �������� ����������\n";
				cin.ignore();
				getline(cin, carr.name);
				cout << "������ ��� ������� ����������\n";
				cin >> carr.release;
				cout << "������ ����� ��������� ����������\n";
				cin >> carr.engine;
				cout << "������ ��������� ����������\n";
				cin.ignore();
				getline(cin, carr.price);                      // ��� ������ ���� ������ Alt(�����) + ������ �� �������� ����� 0136 (��� 0128)  �   ������ -- Alt(�����) + 0036  $   
				car_vect.push_back(car(carr.name, carr.release, carr.engine, carr.price));
				cout << "\n������ ������ ���������� ����������?  \"Y\" or \"N\" :"; 
				cout << endl;			
				cin >> av;
			} while (av == 'Y' || av == 'y' || av == '�' || av == '�');
		}
	} while (ch != 0);
	system("cls");
}

