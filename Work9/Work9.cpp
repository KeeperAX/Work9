#include <iostream>
#include <string>

using namespace std;

struct student
{
	string fio;
	int numberGroup;
	int grade[5];
	float averageGrade;
};

void fillStudents(int countStudent, student* students, short gradeSize)
{
	for (short i = 0; i < countStudent; i++)
	{
		cout << "\nСтудент # " << i + 1 << endl;
		cout << "Введите ФИО: ";
		cin.ignore();
		getline(cin, students[i].fio);
		cout << "Введите номер группы: ";
		cin >> students[i].numberGroup;
		cout << "Введите оценки (5 штук): ";
		for (short j = 0; j < gradeSize; j++)
		{
			short mark;
			cin >> mark;
			if (mark <= 5 && mark >= 2)
			{
				students[i].grade[j] = mark;
				students[i].averageGrade += mark;
			}
			else
			{
				j--;
			}
		}

		students[i].averageGrade /= 5;
	}
}

void sortStudentsByGroup(int countStudents, student* students)
{
	for (short i = 0; i < countStudents - 1; i++)
	{
		for (short j = 0; j < countStudents - i - 1; j++)
		{
			if (students[j].numberGroup > students[j + 1].numberGroup)
			{
				swap(students[j].numberGroup, students[j + 1].numberGroup);
			}
		}
	}
}

void viewStudentsAverageGrade(int countStudents, student* students, short gradeSize)
{
	int countstudents = 0;
	for (short i = 0; i < countStudents; i++)
	{
		if (students[i].averageGrade <= 4)
		{
			continue;
		}

		cout << endl;
		cout << "Студент # " << i + 1 << endl;
		cout << "ФИО: ";
		cout << students[i].fio;
		cout << "\nНомер группы: ";
		cout << students[i].numberGroup;
		cout << endl;
		countstudents++;
	}

	if (countstudents == 0)
	{
		cout << "В списке нет студентов со средним баллом выше 4.0.";
	}
}

void viewStuppedStudents(int countStudent, student* students, short gradeSize) {
	for (short i = 0; i < length; i++)
	{

	}
}

int main()
{
	setlocale(LC_ALL, "RU");
	cout << "Введите количество студентов: ";
	int countStudents;
	cin >> countStudents;

	student* students = new student[countStudents];
	short gradeSize = sizeof(students[1].grade) / sizeof(students[1].grade[0]);

	fillStudents(countStudents, students, gradeSize);
	sortStudentsByGroup(countStudents, students);
	viewStudentsAverageGrade(countStudents, students, gradeSize);

	delete[] students;
}



