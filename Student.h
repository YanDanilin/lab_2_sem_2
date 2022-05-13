#pragma once
#include <iostream>


class Student {
private:
	std::string fio;
	int age = 0;
	int group = 0;
public:
	Student() {}
	Student(std::string fio, int age, int group) {
		this->fio = fio;
		this->age = age;
		this->group = group;
	}
	Student(const Student& another) {
		fio = another.fio;
		age = another.age;
		group = another.group;
	}	
	std::string GetName() const {
		return fio;
	}
	int GetAge() const {
		return age;
	}
	int GetGroup() const {
		return group;
	}
	Student& operator=(Student st) {
		std::swap(fio, st.fio);
		std::swap(age, st.age);
		std::swap(group, st.group);
		return *this;
	}
};

bool operator<(const Student& first, const Student& second) {
	return first.GetAge() < second.GetAge();
}
bool operator>(const Student& first, const Student& second) {
	return second < first;
}
bool operator==(const Student& first, const Student& second) {
	return !(first < second || second < first);
}
bool operator!=(const Student& first, const Student& second) {
	return !(first == second);
}
std::ostream& operator<<(std::ostream& out, const Student& student) {
	out << student.GetName() << " " << student.GetAge() << " " << student.GetGroup();
	return out;
}

