#ifndef Q_GEN_H
#define Q_GEN_H
#include "commonHeaders.h"
#include "questions.h"
#include "qTemplate.h"
typedef unordered_map<attribute, unordered_map<string,vector<int>>> attribBasedMap;
typedef unordered_map<int, qTemplate*> templateMap;
typedef unordered_map<int, questions*> questionsMap;
class questionPaperGenerator
{
	attribBasedMap attribToQuestionMap;
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
			attribToQuestionMap[attribute::AUTHOR][questionList[i]->getAuthor()].push_back(i);
			attribToQuestionMap[attribute::DIFFICULTY][questionList[i]->getDifficulty()].push_back(i);
			attribToQuestionMap[attribute::SUBJECT][questionList[i]->getSubject()].push_back(i);			
		}
	}
	bool addTemplate(qTemplate* questionTemplate);
	bool addQuestion(questions* question);
	bool genQuestionPaper(int templateId,  vector<string>& qList);
	bool getQuestions(vector<int> questionIdsSet, int totalMarks, vector<int>& qIdList, int curIdx = 0);
};

#endif

