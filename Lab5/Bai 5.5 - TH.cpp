#include <iostream>
#include <string>

using namespace std;

class Person {
	protected:
	    string Name;
	    string Address;
	    int Phone;
	public:
	    Person() {}
	    Person(string name, string address, int phone)
	        : Name(name), Address(address), Phone(phone) {}
	        
	    string getName(){
	    	return Name;
		}
};

class Officer : public virtual Person {
	protected:
	    float Salary;
	public:
	    Officer() {}
	    Officer(string name, string address, int phone, float salary)
	        : Person(name, address, phone), Salary(salary) {}
	        
	    float getSalary(){
	    	return Salary;
		}
};

class Student : public virtual Person {
	protected:
	    float Fee;
	public:
	    Student() {}
	    Student(string name, string address, int phone, float fee)
	        : Person(name, address, phone), Fee(fee) {}
};

class OffStudent : public Officer, public Student {
	public:
	    OffStudent(string name, string address, int phone, float salary, float fee)
	        : Officer(name, address, phone, salary), Student(name, address, phone, fee) {}
	
	    void OutScreen() {
	        cout << "Name: " << Name << endl;
	        cout << "Address: " << Address << endl;
	        cout << "Phone: " << Phone << endl;
	        cout << "Salary: " << Officer::Salary << endl;
	        cout << "Fee: " << Student::Fee << endl;
	    }
};

void sortOffStudentsByName(OffStudent offStudents[], const int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (offStudents[j].getName() > offStudents[j + 1].getName()) {
                swap(offStudents[j], offStudents[j + 1]);
            }
        }
    }
}

int main() {
    const int n = 3;
    OffStudent offStudents[n] = {
        OffStudent("Nhan", "123 Linh Nam", 123456789, 5000000, 1000),
        OffStudent("Nguyet", "456 Vinh Hung", 987654321, 6000000, 2000),
        OffStudent("Lan", "789 Tam Trinh", 543216789, 4000000, 1500)
    };

    cout << "DANH SACH DOI TUONG:" << endl;
    for (int i = 0; i < n; ++i) {
        offStudents[i].OutScreen();
        
		cout << endl;
    }

    cout << "DANH SACH DOI TUONG CO LUONG LA 5 TRIEU:" << endl;
    for (int i = 0; i < n; ++i) {
        if (offStudents[i].getSalary() == 5000000) {
            offStudents[i].OutScreen();
            break;
        }
    }

    cout << "DANH SACH DOI TUONG THEO CHIEU TANG DAN CUA TEN:" << endl;
    sortOffStudentsByName(offStudents, n);
    for (int i = 0; i < n; ++i) {
        offStudents[i].OutScreen();
        
		cout << endl;
    }

    return 0;
}
