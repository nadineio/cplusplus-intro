#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

class Person {
protected:
	string	name, gender, death;
	int		birth;

public:
	//Constructors
	Person(string name, int birth, string death, string gender);
	Person();

	//Access Methods
	string	getName();
	string	getKey();
	int		getBirth();
	string	getDeath();
	string	getGender();

	//Mutators
	void setName(string name);
	void setBirth(int birth);
	void setDeath(string death);
	void setGender(string gender);

	//Print
	void print(ostream& ostr);
};

//Constructors
Person::Person(string name, int birth, string death, string gender) {
	this->name = name;
	this->birth = birth;
	this->death = death;
	this->gender = gender;
}

Person::Person() {
	name = "";
	birth = 0;
	death = "";
	gender = "";
}

//Access Methods
string Person::getName() {
	return name;
}

string Person::getKey() {
	return getName();
}

int Person::getBirth() {
	return birth;
}

string Person::getDeath() {
	return death;
}

string Person::getGender() {
	return gender;
}

//Mutators
void Person::setName(string name) {
	this->name = name;
}

void Person::setBirth(int birth) {
	this->birth = birth;
}

void Person::setDeath(string death) {
	this->death = death;
}

void Person::setGender(string gender) {
	this->gender = gender;
}

//Print
void Person::print(ostream & ostr) {
	ostr << name << endl << birth << endl << death << endl << gender << endl;
}
