#ifndef QUESTION_H
#define QUESTION_H
#include "commonHeaders.h"
class questions
{
	string text;
	string subject;
	string difficulty;
	string author;
	int marks;
public:
	questions(string& _text, string _subject, string& _author, string& _difficulty,  int _marks) :
	text(_text), subject(_subject), author(_author), difficulty(_difficulty), marks(_marks)
	{};
	int getMarks() const;
	string getAuthor() const;
	string getDifficulty() const;
	string getSubject() const;
	string getText() const;
};

#endif
