#include <iostream>
#include <map>
#include <iterator>
#include <vector>
#include <string>
using namespace std;

//1 ф-я
void NEW_BUS(map<string, vector<string>>& bus_map)			//Добавляем маршрут
{
	vector<string> bus_stop;								//вектор остановок
	string bus_name, stop_name;
	int stop_counter;
	cout << "Введите название маршрута:" << endl;
	cin >> bus_name;
	cout << "Введите кол-во остановок:" << endl;
	cin >> stop_counter;
	for (int i = 0; i < stop_counter; i++)
	{
		cout << "Введите название " << (i + 1) << " остановки:" << endl;
		cin >> stop_name;
		bus_stop.push_back(stop_name);
	}
	bus_map[bus_name] = bus_stop;							//присваивание ключу(названию маршрута) вектор его остановок
}


//2 ф-я
void ALL_BUSES(const map<string, vector<string>>& bus_map)	//Вывод инфы о всех маршрутах
{
	if (bus_map.size() == 0)
	{
		cout << "No buses" << endl;
	}
	else
	{
		for (auto m : bus_map)
		{
			//cout <<"Размер ключа: "<<m.first.size()<<" Размер вектора: "<<m.second.size()<<endl;
			cout << "Bus " << m.first << ": ";
			for (int i = 0; i < m.second.size(); i++)
			{
				cout << m.second[i] << " ";
			}
			cout << endl;
		}
	}
}

//3 ф-я
void BUSES_FOR_STOP(const map<string, vector<string>>& bus_map)	//Вывод маршрутов, которые проходят через конкретную остановку
{
	vector<string> bus_name;
	string stop;
	cout << "Введите название остановки" << endl;
	cin >> stop;
	for (auto i : bus_map)
	{
		for (auto j : i.second)
		{
			if (j == stop)
			{
				bus_name.push_back(i.first);
			}
		}
	}
	if (bus_name.size() == 0)
	{
		cout << "No stop" << endl;
	}
	else
	{
		cout << "Stop " << stop << ": ";
		for (auto i : bus_name)
		{
			cout << i << " ";
		}
		cout << endl;
	}
}

//4 ф-я
void STOPS_FOR_BUS(const map<string, vector<string>>& bus_map)
{
	vector<string> bus_name;
	string route_name;
	cout << "Введите название маршрута" << endl;
	cin >> route_name;
	if (bus_map.find(route_name) != bus_map.end())
	{
		cout << "Bus " << route_name << ": ";
		for (auto i : bus_map.at(route_name))     //changed [] on at();
		{
			for (auto j : bus_map)
			{
				for (auto c : j.second)
				{
					if (c == i)
					{
						bus_name.push_back(j.first);
					}
				}
			}
			cout << "Stop " << i << ": ";

			for (auto i : bus_name)
			{
				if (bus_name.size() > 1)
				{
					if (i != route_name)
					{
						cout << i << " ";
					}
				}
				else
				{
					cout << "no interchange";
				}
			}

			bus_name.resize(0);
			cout << endl;
		}
	}
	else
	{
		cout << "No bus" << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	map<string, vector<string>> bus_map;
	int Q;
	cout << "Введите кол-во операций" << endl;
	cin >> Q;
	for (int op_counter = 0; op_counter < Q; op_counter++)
	{
		string operation;
		cout << "Name of operation" << endl;
		cin >> operation;
		if (operation == "NEW_BUS")
		{
			NEW_BUS(bus_map);
		}
		else if (operation == "ALL_BUSES")
		{
			ALL_BUSES(bus_map);
		}
		else if (operation == "BUSES_FOR_STOP")
		{
			BUSES_FOR_STOP(bus_map);
		}
		else if (operation == "STOPS_FOR_BUS")
		{
			STOPS_FOR_BUS(bus_map);
		}
		else
		{
			cout << "Не правильно указано название операции!!!";
			op_counter--;
			continue;
		}
	}

	return 0;
}


