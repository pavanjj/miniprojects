#ifndef Q_GEN_H
#define Q_GEN_H
#define BITSET_SIZE 512
#include "commonHeaders.h"
#include "questions.h"
#include "qTemplate.h"
#include <bitset>
typedef unordered_map<attribute, unordered_map<string,vector<int>>> attribBasedMap;
typedef unordered_map<int, qTemplate*> templateMap;
typedef unordered_map<int, questions*> questionsMap;
typedef unordered_map<attribute, unordered_map<string, bitset<BITSET_SIZE>>> attribBasedBitMap;
class questionPaperGenerator
{
	attribBasedMap attribToQuestionMap;
	attribBasedBitMap attribToQuestionBitMap;
	templateMap templates;
	questionsMap questionList;
public:
	questionPaperGenerator(vector<qTemplate*> & templateList,vector<questions*>& questionsList)
	{
		for(int i=0;i<templateList.size();i++)
		{
			templates[i] = templateList[i];
		}
		for (int i = 0; i < questionsList.size(); i++)
		{
			questionList[i] = questionsList[i];
			attribToQuestionBitMap[attribute::AUTHOR][questionList[i]->getAuthor()].set(i);
			attribToQuestionBitMap[attribute::DIFFICULTY][questionList[i]->getDifficulty()].set(i);
			attribToQuestionBitMap[attribute::SUBJECT][questionList[i]->getSubject()].set(i);
		}
	}
	bool addTemplate(qTemplate* questionTemplate);
	bool addQuestion(questions* question);
	bool genQuestionPaper(int templateId,  vector<string>& qList);
	bool getQuestions(vector<int> questionIdsSet, int totalMarks, vector<int>& qIdList, int curIdx = 0);
};

#endif

