#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
#include<string>
#include<list>
using namespace std;

struct CalcInfo
{
	double base;
	double percent;
	double premium;
	double hour;
	double rate_per_hour;
	double sales;
};

struct ISalaryCalculator
{
	virtual double calcSalary() = 0;
};

//1 почасовой оклад
class Rule1 : public ISalaryCalculator
{
protected:
	double hour;
	double rate_per_hour;
public:
	Rule1() { hour = 0; rate_per_hour = 0; }
	Rule1(double hour, double rate_per_hour) { this->hour = hour; this->rate_per_hour = rate_per_hour; }
	virtual double calcSalary()
	{
		return hour * rate_per_hour;
	}
};

//2 оплата оклад + премия
class Rule2 : public ISalaryCalculator
{
protected:
	double base;
	double premium;
public:
	Rule2() { base = 0; premium = 0; }
	Rule2(double base, double premium) { this->base = base; this->premium = premium; }
	virtual double calcSalary()
	{
		return base + premium;
	}
};

//3 оплата база + % от выручки

class Rule3 :public ISalaryCalculator
{
protected:
	double base;
	double percent;
public:
	Rule3() { base = 0; percent = 0; }
	Rule3(double base, double percent) { this->base = base; this->percent = percent; }
	virtual double calcSalary()
	{
		return base + (base * percent);
	}
};

//4 оклад
class Rule4 : public ISalaryCalculator
{
protected:
	double base;

public:
	Rule4() { base = 0; }
	Rule4(double base) { this->base = base; }
	virtual double calcSalary()
	{
		return base;
	}
};

//Запрограммируйте понятие «Домашний Адрес» (характеристики: город, улица, номер дома, номер офиса или квартиры). 
class AdressInfo
{
protected:
	string city;
	string street;
	int n_House;
	int n_AappartHumant;
public:
	AdressInfo() { city = "no city"; street = "no street"; n_House = NULL; n_AappartHumant = NULL; }
	AdressInfo(string city, string street, int n_House, int n_AappartHumant)
	{
		this->city = city; this->street = street; this->n_House = n_House; this->n_AappartHumant = n_AappartHumant;
	};
	void setCity(string city) { this->city = city; }
	void setStreet(string street) { this->street = street; }
	void setN_House(int n_House) { this->n_House = n_House; }
	void setN_AappartHumant(int n_AppartHumant) { this->n_AappartHumant = n_AppartHumant; }

	string getCity() { return this->city; }
	string getStreet() { return this->street; }
	int getN_House() { return this->n_House; }
	int getN_AappartHumant() { return this->n_AappartHumant; }

	void print()
	{
		cout << this->city << ",\t" << this->street << ",\t" << this->n_House << ",\t" << this->n_AappartHumant << ".\n";
	}

	friend ostream& operator<<(ostream& ost, const AdressInfo& Adress)
	{
		ost << Adress.city << ",\t" << Adress.street << ",\t" << Adress.n_House << ",\t" << Adress.n_AappartHumant << ".\n";
		return ost;
	}
};

//Запрограммируйте понятие «Животное» (характеристик:пол,возраст). 
class AnimalEntity : public AdressInfo
{
protected:
	int age;
	string sex;
public:
	AnimalEntity() { age = NULL; sex = "no sex"; };
	AnimalEntity(int age, string sex)
	{
		this->age = age; this->sex = sex;
	};

	void setAge(int age) { this->age = age; }
	void setSex(string sex) { this->sex = sex; }

	int getAge() { return this->age; }
	string getSex() { return this->sex; }

	void print()
	{
		cout << this->sex << ",\t" << this->age << "\n";
	}

	friend ostream& operator<<(ostream& ost, const AnimalEntity& Animal)
	{
		ost << Animal.sex << ",\t" << Animal.age << ".\n";
		return ost;
	}
};

//Запрограммируйте понятие «Человек» (характеристики: имя, фамилия). 
class HumanEntity : public AnimalEntity
{
protected:
	string name;
	string surname;
public:
	HumanEntity() { name = "no name"; surname = "no surname"; };
	HumanEntity(string name, string surname)
	{
		this->name = name; this->surname = surname;
	};

	void setName(string name) { this->name = name; }
	void setSurname(string surname) { this->surname = surname; }

	string getName() { return this->name; }
	string getSurname() { return this->surname; }

	void print()
	{
		cout << this->name << ",\t" << this->surname << ".\n";
	}

	friend ostream& operator<<(ostream& ost, const HumanEntity& Human)
	{
		ost << Human.name << ",\t" << Human.surname << ".\n";
		return ost;
	}
};

//Запрограммируйте понятие «Личность»(характеристики: телефон, «Адрес»). 
class Person : public HumanEntity
{
protected:
	string  n_Phone;
	AdressInfo adressInfo;
public:
	Person() { n_Phone = "no phone"; }
	Person(string name, string surname, string city, string street, int n_House, int n_AappartHumant, string sex, int age, string stringn_Phone)
	{
		adressInfo.setCity(city);
		adressInfo.setStreet(street);
		adressInfo.setN_House(n_House);
		adressInfo.setN_AappartHumant(n_AappartHumant);
		this->n_Phone = n_Phone;
	}

	void setN_Phone(string n_Phone) { this->n_Phone = n_Phone; }
	void setAdressInfo(AdressInfo adressInfo) { this->adressInfo = adressInfo; }

	string getN_Phone() { return this->n_Phone; }
	AdressInfo getAdressInfo() { return this->adressInfo; }

	void print()
	{
		cout << this->n_Phone << ",\t" << this->adressInfo << ".\n";
	}

	friend ostream& operator<<(ostream& ost, const Person& Person)
	{
		ost << Person.n_Phone << ",\t" << Person.adressInfo << ".\n";
		return ost;
	}
};

//Запрограммируйте понятия «Сотрудник» (характеристики: должность, карточный счет в банке, заработная плата)
class Employee : public Person, public ISalaryCalculator
{
protected:
	string position;
	string cardAccount;
	double salary;
	double base;
	double hour;
	double rate_per_hour;
	double percent;


	ISalaryCalculator* salaryCalc;

public:
	Employee() : Person() { position = "no position", cardAccount = "no card account", salary = NULL; }
	Employee(string name, string surname, string city, string street, int n_House, int n_AappartHumant, int  age, string sex, string n_Phone, string position, string cardAccount, int value, CalcInfo calcInfo)
		:Person(name, surname, city, street, n_House, n_AappartHumant, sex, age, n_Phone)
	{
		this->name = name;
		this->surname = surname;
		this->city = city;
		this->street = street;
		this->n_House = n_House;
		this->n_AappartHumant = n_AappartHumant;
		this->age = age;
		this->sex = sex;
		this->n_Phone = n_Phone;
		this->base = calcInfo.base;
		this->percent = calcInfo.percent;
		this->hour = calcInfo.hour;
		this->rate_per_hour = calcInfo.rate_per_hour;
		this->position = position;
		this->cardAccount = cardAccount;
		this->salaryCalc = SalarycalcCreate(value, calcInfo);
	}

	static ISalaryCalculator* SalarycalcCreate(int value, CalcInfo calcInfo)
	{
		ISalaryCalculator* salaryCalc = NULL;
		switch (value)
		{
		case 1: salaryCalc = new Rule1(calcInfo.hour, calcInfo.rate_per_hour); break;
		case 2: salaryCalc = new Rule2(calcInfo.base, calcInfo.premium); break;
		case 3: salaryCalc = new Rule3(calcInfo.base, calcInfo.percent); break;
		case 4: salaryCalc = new Rule4(calcInfo.base); break;
		default: salaryCalc = new Rule4(calcInfo.base);
			break;
		}
		return salaryCalc;
	}

	/*virtual double calcSalary()
	{
		if (this->salaryCalc == NULL)
			return 0;
		else
			return this->salaryCalc->calcSalary();
	}*/

	void setPosition(string position) { this->position = position; }
	void setCardAccount(string cardAccount) { this->cardAccount = cardAccount; }
	void setSalary(double salary) { this->salary = salary; }

	string getPosition() { return this->position; }
	string getCardAccount() { return this->cardAccount; }
	double getSalary() { return this->salary; }

	void print()
	{
		cout << "First Name\t" << this->name << endl;
		cout << "Last Name\t" << this->surname << endl;
		cout << "Sity\t\t" << this->city << endl;
		cout << "Street\t\t" << this->street << endl;
		cout << "House number\t" << this->n_House << endl;
		cout << "Apa number\t" << this->n_AappartHumant << endl;
		cout << "Sex\t\t" << this->sex << endl;
		cout << "Age\t\t" << this->age << endl;
		cout << "Phone number\t" << this->n_Phone << endl;
		cout << "Position\t" << this->position << endl;
		cout << "Card Account\t" << this->cardAccount << endl;
		cout << "Salary\t\t" << this->salary << endl;
		cout << "_____________________________________________________________________________________________________________\n";
	}

	friend class Department;
	friend ostream& operator<<(ostream& ost, const Employee& Emp)
	{
		ost << "First Name\t" << Emp.name << endl;
		ost << "Last Name\t" << Emp.surname << endl;
		ost << "Sity\t\t" << Emp.city << endl;
		ost << "Street\t\t" << Emp.street << endl;
		ost << "House number\t" << Emp.n_House << endl;
		ost << "Apa number\t" << Emp.n_AappartHumant << endl;
		ost << "Sex\t\t" << Emp.sex << endl;
		ost << "Age\t\t" << Emp.age << endl;
		ost << "Phone number\t" << Emp.n_Phone << endl;
		ost << "Position\t" << Emp.position << endl;
		ost << "Card Account\t" << Emp.cardAccount << endl;
		ost << "Salary\t\t" << Emp.salaryCalc->calcSalary() << endl;
		ost << "_________________________________________________________________________________________________________________\n";
		return ost;
	}

	virtual double calcSalary()
	{
		if (this->salaryCalc == NULL)
		{
			return 0;
		}
		else
		{
			return this->salaryCalc->calcSalary();
		}
	}
};

//Запрограммируйте понятие «Отдел»(название отдела, список сотрудников, начальник отдела)
class Department : public Employee
{
protected:
	string n_department;
	string boss;
	list<Employee> listEmployeers;

	int countEmpl;
public:
	Department() { this->n_department = "no name departHumant", this->boss = "no name Boss"; }
	Department(string n_department, string boss) { this->n_department = n_department; this->boss = boss; }


	void setN_departHumant(string n_department) { this->n_department = n_department; }
	void setBoss(string boss) { this->boss = boss; }


	string getN_departHumant() { return this->n_department; }
	string getBoss() { return this->boss; }
	list<Employee> getEmployees() { return listEmployeers; }

	void AddEmployees(Employee listEmployeers) { this->listEmployeers.push_back(listEmployeers); }

	friend ostream& operator<<(ostream& ost, Department& Dep)
	{
		ost << "\t\t\t\tDepartament Name:\t" << Dep.n_department << endl;
		ost << "\t\t\t\tDepartament boss:\t" << Dep.boss << endl;
		return ost;
	}
};




int main()
{
	CalcInfo calcInfo;

	calcInfo.hour = 120;         // оплата в час 
	calcInfo.rate_per_hour = 12; // сколько часов 
	calcInfo.base = 1000;        // оклад
	calcInfo.premium = 1370;     // премияч
	calcInfo.percent = 0.63;     // процент




	Department depart1("it department", "Ivan Ivanov");
	cout << depart1;		
	//																										         		   					  1 почасовой оклад
//																																				  2 оплата оклад + премия
//																																				  3 оплата база + % от выручки
//																																		 		  4... оклад	
//																																                         |
//                                                                                                                                                       |
	vector<Employee*> Human;     //  имя     фамилия    город        улица      дом  кв  лет  пол           телефон       должность       карта          |  
	Employee* Human1 = new Employee("Ivan", "Ivanov", "Kharkov", "Volosataya", 147, 422, 47, "male", "+3 (095) 240-04-40 ", "QA", "2222 3121 4342 5432", 1, calcInfo);
	Employee* Human2 = new Employee("Petr", "Petrov", "Kiyev", "Serbskaya", 23, 312, 22, "male", "+3 (067) 433-24-40 ", "Junior QA", "2331 5436 4534 5434", 2, calcInfo);
	Employee* Human3 = new Employee("Andryusha", "Ryzhiy", "Kharkov", "Klochkovska", 12, 42, 1, "male", "+3 (099) 243-23-65 ", "Junior QA", "3121 4342 1234 2222", 3, calcInfo);
	Employee* Human4 = new Employee("Alina", "Alinovnaм", "Kharkov", "Myasnaya", 343, 43, 11, "male", "+3 (099) 232-94-87 ", "QA", "3231 3287 092 2978", 4, calcInfo);

	Human.push_back(Human1);
	Human.push_back(Human2);
	Human.push_back(Human3);
	Human.push_back(Human4);

	vector<Employee*>::iterator ptr;
	/*cout << "before sorting : " << endl;*/
	for (ptr = Human.begin(); ptr < Human.end();
		ptr++)   cout << *(*ptr) << "";//двойное разыменование                          //Вектор
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//																					// Лист 
	//Department departList1;
	//departList1.setBoss("Ivan Ivanov");
	//departList1.setN_departHumant("it department");
	//departList1.AddEmployees(*Human1);
	//departList1.AddEmployees(*Human2);
	//departList1.AddEmployees(*Human3);
	//departList1.AddEmployees(*Human4);

	//list<Department> departList;
	//departList.push_back(departList1);


	//for (list<Department>::iterator i = departList.begin(); i != departList.end(); ++i)
	//{
	//	cout << *i<< endl;
	//}
	//for (auto HumanList : departList1.getEmployees())
	//{
	//	cout << HumanList << endl;
	//}

	system("pause");
	return 0;
};