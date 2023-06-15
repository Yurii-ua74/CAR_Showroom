// Реализуйте  интерфейс для 
// добавления данных,
// удаления данных,
// отображения данных,
// сортировке данных по различным параметрам,
// поиску данных по различным параметрам.
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
	cout << "Название автомобиля:\t" << n.name << endl;
	cout << "Год выпуска автомобиля:\t" << n.release << endl;
	cout << "Объем двигателя:\t" << n.engine << endl;
	cout << "Стоимость автомобиля:\t" << n.price << endl;
	cout << endl;	
	ii++;
};

struct comp_car
{                             // функтор сравнения 
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
	cout << "Найден автомобиль:\n";
	cout << "Наименование :   \t" << n.name << endl;
	cout << "Год выпуска :    \t" << n.release << endl;
	cout << "Объем двигателя :\t" << n.engine << endl;
	cout << "Стоимость :      \t" << n.price << endl;
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
		cout << "   " << "БАЗЫ АВТОСАЛОНА\n";
		cout << "0 - закончить работу\n";
		cout << "1 - добавление данных\n";
		cout << "2 - удаление данных\n";
		cout << "3 - отображение данных\n";
		cout << "4 - сортировка данных по различным параметрам\n";
		cout << "5 - поиск данных по различным параметрам\n";
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
				 cout << "Какой по счету автомобиль удалить из базы? ";
				 cin >> it;
				 auto iter = car_vect.cbegin();        // указатель на первый элемент
				 car_vect.erase(iter + it - 1);        // удаляем элемент
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
					 cout << "\tМЕНЮ Сортировки\n";
					 cout << "0 - закончить сортировку\n";
					 cout << "1 - отсортировать по названию автомобилей в алфавитном порядке\n";
					 cout << "2 - отсортировать по году выпуска\n";
					 cout << "3 - отсортировать по объему двигателя\n";
					 cout << "4 - отсортировать по цене\n";
					 cin >> ch_sort;
					 switch (ch_sort)
					 {
					 case 0: {} break;
					 case 1:
					 {
						 system("cls");
						 cout << "данные отсортированы по названию автомобилей в алфавитном порядке\n";
						 ii = 0;
						 sort(car_vect.begin(), car_vect.end(), comp_car(1));  // 1 - по  name
						 for_each(car_vect.begin(), car_vect.end(), print);
						 cout << endl;                    
					 }
					 break;
					 case 2:
					 {
						 system("cls");
						 cout << "данные отсортированы по году выпуска автомобилей\n";
						 ii = 0;
						 sort(car_vect.begin(), car_vect.end(), comp_car(2));   // 2 - по  release
						 for_each(car_vect.begin(), car_vect.end(), print);
						 cout << endl;
					 }
					 break;
					 case 3:
					 {
						 system("cls");
						 cout << "данные отсортированы по объему двигателя\n";
						 ii = 0;
						 sort(car_vect.begin(), car_vect.end(), comp_car(3));   // 3 - по  engine
						 for_each(car_vect.begin(), car_vect.end(), print);
						 cout << endl;
					 }
					 break;
					 case 4:
					 {
						 system("cls");
						 cout << "данные отсортированы по стоимости автомобиля\n";
						 ii = 0;
						 sort(car_vect.begin(), car_vect.end(), comp_car(4));   // 4 - по  price
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
				      cout << "\tМЕНЮ Поиска\n";
				      cout << "0 - закончить поиск\n";
				      cout << "1 - найти по названию автомобиля\n";
				      cout << "2 - найти по году выпуска\n";
				      cout << "3 - найти по объему двигателя\n";
				      cout << "4 - найти по цене\n";
				      cin >> ch_find;
					  switch (ch_find)
					  {
					  case 0: {} break;
					  case 1:
					  {
						  system("cls");	
						  string tmp;
						  cout << "Ввести название автомобиля\n";
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
						  cout << "Ввести год выпуска автомобиля\n";					 
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
						  cout << "Ввести объем двигателя автомобиля\n";
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
						  cout << "Ввести стоимость автомобиля\n";
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


void Adding_Data(vector<car>& car_vect)                // начальные данные базы                 
{
	system("cls");
	car carr;
	int ch;	
	char av;
	do
	{
		cout << "0 - Вернуться в главное меню\n";
		cout << "1 - Ввести автоматически данные 8-и автомобилей\n";
		cout << "2 - Ввести данные вручную\n";
		cin >> ch;
		if (ch == 1)
		{
			for (int i = 0; i < 8; i++)
			{
				switch (i)
				{
				case 0: car_vect.push_back(car("Ford", 2022, 2.4, "24500€"));         
					break;
				case 1: car_vect.push_back(car("BMW", 2020, 1.8, "21800€"));                        
					break;
				case 2: car_vect.push_back(car("Audi", 2021, 2.2, "35000€"));
					break;
				case 3: car_vect.push_back(car("Honda", 2018, 2.6, "19000€"));
					break;
				case 4: car_vect.push_back(car("Toyota", 2019, 3.3, "31000€"));
					break;
				case 5: car_vect.push_back(car("Mazda", 2012, 1.6, "9000€"));
					break;
				case 6: car_vect.push_back(car("Mitsubishi", 2010, 1.8, "10000€"));
					break;
				case 7: car_vect.push_back(car("Kia", 2014, 1.6, "12100€"));
					break;
				}			
			}
			system("cls");
			cout << "Введено автоматически данные 8-и автомобилей \n";
		}
		else if (ch == 2)
		{
			do
			{
				cout << "ввести название автомобиля\n";
				cin.ignore();
				getline(cin, carr.name);
				cout << "ввести год выпуска автомобиля\n";
				cin >> carr.release;
				cout << "ввести объем двигателя автомобиля\n";
				cin >> carr.engine;
				cout << "ввести стоимость автомобиля\n";
				cin.ignore();
				getline(cin, carr.price);                      // для значка евро нажать Alt(левый) + только на цифровом блоке 0136 (или 0128)  €   доллар -- Alt(левый) + 0036  $   
				car_vect.push_back(car(carr.name, carr.release, carr.engine, carr.price));
				cout << "\nВвести данные следующего автомобиля?  \"Y\" or \"N\" :"; 
				cout << endl;			
				cin >> av;
			} while (av == 'Y' || av == 'y' || av == 'Н' || av == 'н');
		}
	} while (ch != 0);
	system("cls");
}

