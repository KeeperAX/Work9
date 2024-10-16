#include <iostream>
#include <string>

using namespace std;

struct student
{
	string fullName;
	int groupNumber;
	int grade[5];
	float averageGrade;
};

void fillStudents(int studentsCount, student* students, short gradesCount)
{
	for (short i = 0; i < studentsCount; i++)
	{
		cout << "\nСтудент # " << i + 1 << endl;
		cout << "Введите ФИО: ";
		cin.ignore();
		getline(cin, students[i].fullName);
		cout << "Введите номер группы: ";
		cin >> students[i].groupNumber;
		cout << "Введите оценки (5 штук): ";
		for (short j = 0; j < gradesCount; j++)
		{
			short grade;
			cin >> grade;
			if (grade <= 5 && grade >= 2)
			{
				students[i].grade[j] = grade;
				students[i].averageGrade += grade;
			}
			else
			{
				j--;
			}
		}

		students[i].averageGrade /= gradesCount;
	}
}

void sortStudentsByGroup(int studentsCount, student* students, short gradesCount)
{
	for (short i = 0; i < studentsCount - 1; i++)
	{
		for (short j = 0; j < studentsCount - i - 1; j++)
		{
			if (students[j].groupNumber > students[j + 1].groupNumber)
			{
				swap(students[j], students[j + 1]);
			}
		}
	}
}

void viewStudentsAverageGrade(int studentsCount, student* students, short gradesCount)
{
	system("cls");
	const int line_length = 40;
	cout << string(line_length, '-') << endl;
	cout << "Номер студента " << "\tId" << "\tНомер группы" << "Оценки\t" << endl;
	cout << string(line_length, '-') << endl;
	for (short i = 0; i < studentsCount; i++)
	{
		cout << i + 1 << "\t" << students[i].fullName << "\t" << students[i].groupNumber << "\t";
		for (short j = 0; j < gradesCount; j++)
		{
			cout << students[i].grade[j] << " ";
		}
		cout << "\t" << endl;
		cout << string(line_length, '-') << endl;
	}
	cout << endl;

	cout << "\tХорошисты" << endl;
	int countstudents = 0;
	for (short i = 0; i < studentsCount; i++)
	{
		if (students[i].averageGrade <= 4)
		{
			continue;
		}
		cout << "ФИО: ";
		cout << students[i].fullName;
		cout << "\nНомер группы: ";
		cout << students[i].groupNumber;
		cout << endl;
		countstudents++;
	}

	if (countstudents == 0)
	{
		cout << "В списке нет студентов со средним баллом выше 4.0.";
	}
}

void viewStuppedStudents(int studentsCount, student* students, short gradeSize) {
	short dvoechnic = 0, ans = 0;
	for (short i = 0; i < studentsCount; i++)
	{
		for (short j = 0; j < gradeSize; j++)
		{
			if (students[i].grade[j] == 2)
			{
				dvoechnic++;
			}
			if (dvoechnic == 1)
			{
				ans++; break;
			}
		}
	}
	cout << "Кол-во двоечников: " << ans << endl;
}

int main()
{
	setlocale(LC_ALL, "RU");
	cout << "Введите количество студентов: ";
	int studentsCount;
	cin >> studentsCount;

	student* students = new student[studentsCount];
	short gradesCount = sizeof(students[1].grade) / sizeof(students[1].grade[0]);

	fillStudents(studentsCount, students, gradesCount);
	sortStudentsByGroup(studentsCount, students, gradesCount);
	viewStudentsAverageGrade(studentsCount, students, gradesCount);
	viewStuppedStudents(studentsCount, students, gradesCount);

	delete[] students;
}



