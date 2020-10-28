#include "questions.h"

int questions::getMarks() const
{
    return marks;
}

string questions::getAuthor() const
{
    return author;
}

string questions::getDifficulty() const
{
    return difficulty;
}

string questions::getSubject() const
{
    return subject;
}

string questions::getText() const
{
    string retText = " Text : " + text;
    retText += ", Author : " + getAuthor();
    retText += ", Difficulty : " + getDifficulty();
    retText += ", Subject : " + getSubject();
    retText += ", Marks : " + to_string(getMarks());
    return retText;
}
