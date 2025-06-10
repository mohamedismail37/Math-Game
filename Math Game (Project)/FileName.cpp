#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

enum enQuestionsLevel { Easy = 1, Med = 2, Hard = 3, MixQuestionLevel = 4 };
enum enOperationType { Add = 1, Sub = 2, Mul = 3, Div = 4, MixOperationType = 5 };

short RandomNumberGenerator(int From , int To)
{
	return rand() % (To - From + 1) + From;
}

short NumberOfQuestions()
{
	short Number = 0;
	cout << "How Many Questions do you want to answer? ";
	cin >> Number;

	return Number;
}

enQuestionsLevel ReadQuestionLevel()
{
	short Number = 0;
	cout << "Enter Question Level [1] Easy, [2] Med, [3] Hard, [4] Mix ? ";
	cin >> Number;

	return enQuestionsLevel(Number);
}

enOperationType ReadOperationType()
{
	short Number = 0;
	cout << "Enter Operation Type [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix ? ";
	cin >> Number;

	return enOperationType(Number);
}

short GenerateNumberAccordingQuestionLevel(enQuestionsLevel QuestionLevel)
{
	switch (QuestionLevel)
	{
	case Easy:
		return RandomNumberGenerator(1, 10);
		break;
	case Med:
		return RandomNumberGenerator(10, 50);
		break;
	case Hard:
		return RandomNumberGenerator(50, 100);
		break;
	case MixQuestionLevel:
		return RandomNumberGenerator(1, 100);
		break;
	}
}

char GenerateOperationAccordingToOperationType(enOperationType OperationType)
{
	char arrOperationType[] = { '+','-','*','/' };
	switch (OperationType)
	{
	case Add:
		return '+';
		break;
	case Sub:
		return '-';
		break;
	case Mul:
		return '*';
		break;
	case Div:
		return '/';
		break;
	case MixOperationType:
		return arrOperationType[RandomNumberGenerator(0, 3)];
		break;
	}
}

short SimpleCalculator(short FirstNumber, short SecondNumber, char OperationType)
{
	switch (OperationType)
	{
	case '+':
		return FirstNumber + SecondNumber;
		break;
	case '-':
		return FirstNumber - SecondNumber;
			break;
	case '*':
		return FirstNumber * SecondNumber;
		break;
	case '/':
		return FirstNumber / SecondNumber;
		break;
	}
}

bool IsRightAnswer(int Answer, int EneterdAnswer)
{
	if (Answer == EneterdAnswer)
	{
		system("color 2F");
		cout << "\nRight Answer :-)\n";
		return true;
	}
	else
	{
		system("color 4F");
		cout << "\nWrong Answer :-(\n";
		cout << "The right answer is: " << Answer << endl;
		return false;
	}
}

string IsPass(short NumberOfQuestions, short WinTimes)
{
	if ((NumberOfQuestions / 2) < WinTimes)
		return "PASS";
	else if ((float(NumberOfQuestions) / 2) == WinTimes)
		return "Equal";
	else
		return "FAIL";


}

string ReturnLevelName(enQuestionsLevel QuestionLevel)
{
	switch (QuestionLevel)
	{
	case Easy:
		return "Easy";
		break;
	case Med:
		return "Med";
		break;
	case Hard:
		return "Hard";
		break;
	case MixQuestionLevel:
		return "Mix";
		break;
	}
}

string ReturnOperationType(enOperationType OperationType)
{
	char arrOperationType[] = { '+','-','*','/' };
	switch (OperationType)
	{
	case Add:
		return "+";
		break;
	case Sub:
		return "-";
		break;
	case Mul:
		return "*";
		break;
	case Div:
		return "/";
		break;
	case MixOperationType:
		return "Mix";
		break;
	}
}

void FinalResultScreen(short NumberOfQuestions, short WinTimes, string QuestionLevel, string OperationType)
{
	if (IsPass(NumberOfQuestions, WinTimes) == "PASS")
	{
		cout << "\n------------------------------\n";
		cout << " Final Results is PASS :-)\n";
		cout << "\n------------------------------\n";
	}
	else if (IsPass(NumberOfQuestions, WinTimes) == "Equal")
	{
		cout << "\n------------------------------\n";
		cout << " Final Results is EQAUL :-)\n";
		cout << "\n------------------------------\n";
		system("color 67");
	}
	else
	{
		cout << "\n------------------------------\n";
		cout << " Final Results is FAIL :-)\n";
		cout << "\n------------------------------\n";
	}

	cout << "Number of Questions: " << NumberOfQuestions << endl;
	cout << "Questions Level    : " << QuestionLevel << endl;
	cout << "Operation Type     : " << OperationType << endl;
	cout << "Number of Right Answers: " << WinTimes << endl;
	cout << "Number of Wrong Answers: " << NumberOfQuestions - WinTimes << endl;
}

void QuestionsGenerator(short NumberOfQuestions, enQuestionsLevel QuestionLevel, enOperationType ReadOperationType)
{
	short FirstNumber = 0;
	short SecondNumber = 0;
	char OperationType;
	short UserAnswer = 0; 
	short RightAnswer = 0;
	short WinTimes = 0;

	for (short i = 1; i <= NumberOfQuestions; i++)
	{
		printf("\nQuestion [%d/%d]\n\n", i, NumberOfQuestions);
		cout << (FirstNumber = GenerateNumberAccordingQuestionLevel(QuestionLevel)) << endl;
		cout << (SecondNumber = GenerateNumberAccordingQuestionLevel(QuestionLevel)) << " " 
			<< (OperationType = GenerateOperationAccordingToOperationType(ReadOperationType));
		cout << "\n_________________\n";
		cin >> UserAnswer;
		RightAnswer = SimpleCalculator(FirstNumber, SecondNumber, OperationType);
		if (IsRightAnswer(RightAnswer, UserAnswer))
		{
			WinTimes++;
		}
	}
	FinalResultScreen(NumberOfQuestions,WinTimes,ReturnLevelName(QuestionLevel),ReturnOperationType(ReadOperationType));
}

void StartGame()
{
	char Continue;
	do
	{
		system("cls");
		system("color 0F");
		short QuestionsNumber = NumberOfQuestions();
		enQuestionsLevel QuestionLevel = ReadQuestionLevel();
		enOperationType OperationType = ReadOperationType();

		QuestionsGenerator(QuestionsNumber, QuestionLevel, OperationType);
		cout << "\nDo you want to play again? (Y/N)? ";
		cin >> Continue;
	} while (Continue == 'y' || Continue == 'Y');
}

int main()
{
	srand((unsigned)time(NULL));

	StartGame();

	return 0;
}