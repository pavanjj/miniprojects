#ifndef qTEMP_H
#define qTEMP_H
#include "commonHeaders.h"
enum class attribute
{
	SUBJECT,
	DIFFICULTY,
	AUTHOR
} ;

typedef unordered_map<string, int> marksDistMap;
class qTemplate
{
	int marks;
	attribute attribType;
	marksDistMap marksDist;
public:
	qTemplate(int _marks,attribute _attribType,marksDistMap& _marksDist)
	{
		attribType = _attribType;
		marksDist = _marksDist;
		marks = _marks;
	}
	marksDistMap getDistMap() const;
	attribute getAttribute() const;
	int getMarks() const;
	string getDetails() const;
	string getAttributeAsStr() const;
};


#endif
