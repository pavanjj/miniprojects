#ifndef qTEMP_H
#define qTEMP_H
#include "commonHeaders.h"
enum class attribute
{
	SUBJECT,
	DIFFICULTY,
	AUTHOR,
	INVALID
} ;

typedef unordered_map<string, int> marksDist;
typedef unordered_map<attribute, marksDist> attribDist;
class qTemplate
{
	int totalMarks;
	attribDist attribDistMap;	
public:
	qTemplate(int pTotalMarks,attribute _attribType,marksDist& _marksDist)
	{		
		attribDistMap[_attribType] = _marksDist;
		totalMarks = pTotalMarks;
	}
	attribDist getDistMap() const;
	int getTotalMarks() const;
	string getDetails() const;
	string getAttributeAsStr(attribute attribType) const;
	bool mergeTemplate(qTemplate* newTemplate);
};


#endif
