#include <iostream>
#include <string>

using namespace std;

struct student
{
	string fio;
	int numbergroup;
	int grade[5];
	float averagegrade;
};

void fillstudents(int countstudent, student* students, short gradesize)
{
	for (short i = 0; i < countstudent; i++)
	{
		cout << "\nСтудент # " << i + 1 << endl;
		cout << "Введите ФИО: ";
		cin.ignore();
		getline(cin, students[i].fio);
		cout << "Введите номер группы: ";
		cin >> students[i].numbergroup;
		cout << "Введите оценки (5 штук): ";
		for (short j = 0; j < gradesize; j++)
		{
			short mark;
			cin >> mark;
			if (mark <= 5 && mark >= 2)
			{
				students[i].grade[j] = mark;
				students[i].averagegrade += mark;
			}
			else
			{
				j--;
			}
		}

		students[i].averagegrade /= 5;
	}
}

void sortstudentsbygroup(int countstudent, student* students)
{
	for (short i = 0; i < countstudent - 1; i++)
	{
		for (short j = 0; j < countstudent - i - 1; j++)
		{
			if (students[j].numbergroup > students[j + 1].numbergroup)
			{
				swap(students[j].numbergroup, students[j + 1].numbergroup);
			}
		}
	}
}

void viewstudentsaveragegrade(int countstudent, student* students, short gradesize)
{
	int countstudents = 0;
	for (short i = 0; i < countstudent; i++)
	{
		if (students[i].averagegrade <= 4)
		{
			continue;
		}

		cout << endl;
		cout << "Студент # " << i + 1 << endl;
		cout << "ФИО: ";
		cout << students[i].fio;
		cout << "\nНомер группы: ";
		cout << students[i].numbergroup;
		cout << endl;
		countstudents++;
	}

	if (countstudents == 0)
	{
		cout << "В списке нет студентов со средним баллом выше 4.0.";
	}
}

void viewstuppedstudents(int countstudent, student* students, short gradesize) {
	for (short i = 0; i < length; i++)
	{

	}
}

int main()
{
	setlocale(LC_ALL, "RU");
	cout << "Введите количество студентов: ";
	int countstudent;
	cin >> countstudent;

	student* students = new student[countstudent];
	short gradesize = sizeof(students[1].grade) / sizeof(students[1].grade[0]);

	fillstudents(countstudent, students, gradesize);
	sortstudentsbygroup(countstudent, students);
	viewstudentsaveragegrade(countstudent, students, gradesize);

	
	delete[] students;
}



