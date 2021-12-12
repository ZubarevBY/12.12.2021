//—ергей «убарев
#include <iostream>
#include <windows.h>
using namespace std;
class Knight {
//данные обьекта
private:
	double m_hp;
	double m_damage;
	string m_name;
public:
	//setter, функции -сеттеры (замен€ют присваивание)
	void setHp(double hp) { m_hp = hp; }
	void setDamage(double damage) { m_damage = damage; }
	void setName(string name) { m_name = name; }
	//геттер
	double getHp() { return m_hp; }
	double getDamage() { return m_damage; }
	string  getName() { return m_name; }

	//увеличение дамага
	void increaseDamage() {
		m_damage *= 1.1;
	}
	void print() {
		cout << "Knight name" << m_name << endl;
		cout << "Knight hp" << m_hp << endl;
		cout << "Knight damage" << m_damage << endl;
	}
};
class Mage {
	//данные обьекта
private:
	double m_hp;
	double m_damage;
	string m_name;
	//методы класса (функции - сеттеры (замен€ют присваивание)
public:
	//setter, функции -сеттеры (замен€ют присваивание)
	void setHp(double hp) { m_hp = hp; }
	void setDamage(double damage) { m_damage = damage; }
	void setName(string name) { m_name = name; }
	//геттер
	double getHp() { return m_hp; }
	double getDamage() { return m_damage; }
	string  getName() { return m_name; }

	//лечение
	void increaseHp(double addHp) {
		m_hp += addHp;
	}
	void print() {
		cout << "Mage name" << m_name << endl;
		cout << "Mage hp" << m_hp << endl;
		cout << "Mage damage" << m_damage << endl;
	}
};

int main() {
	Knight k1;
	k1.setName("Valera");
	k1.setHp(100);
	k1.setDamage(20);
	
	Mage m1;
	m1.setName("Travis");
	m1.setHp(50);
	m1.setDamage(20);
	m1.print();

	//основной игравой цикл
	while (true) {
	//m1.m_hp = m1.hp - k1.m_damage
		cout << "Knight hit mage" << endl;
		m1.setHp(m1.getHp() - k1.getDamage());
		//распечатаем мага
		m1.print();
		//провер€ем на смерть
		if (m1.getHp() <= 0) {
			cout << "Knight win!" << endl;
			break;
		}
		//рыцарь увеличил дамаг
		k1.increaseDamage();

		//мага
		cout << "Mage hit knigh" << endl;
		k1.setHp(k1.getHp() - m1.getDamage());
		//
		k1.print();
		if (k1.getHp() <= 0) {
			cout << "Mage win" << endl;
			break;
		}
		m1.increaseHp(50);
		Sleep(3000);
	}
	return 0;
}