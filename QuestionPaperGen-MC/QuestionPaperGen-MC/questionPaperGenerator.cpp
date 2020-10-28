#include "questionPaperGenerator.h"

bool questionPaperGenerator::genQuestionPaper(int templateId,vector<string>& qList)
{
	auto curTemplate = templates[templateId];
	auto curAttribType = curTemplate->getAttribute();
	auto curTotalMarks = curTemplate->getMarks();
	if(!attribToQuestionMap.count(curAttribType))
	{
		printError("No Questions Exist for given attribute type");
		return false;
	}
	auto questionSet = attribToQuestionMap[curAttribType];
	auto marksDist = curTemplate->getDistMap();

	for(auto & curDist : marksDist)
	{
		int curMarks = (curDist.second * curTotalMarks) / 100;
		vector<int> qIdList;
		if(getQuestions(questionSet[curDist.first],curMarks,qIdList))
		{
			for (int i = 0; i < qIdList.size(); i++)
				qList.push_back(questionList[qIdList[i]]->getText());
		} else
		{
			printError("Insufficient Questions for given marks distribution, generation aborted");
			return false;
		}
	}
	return true;
}

bool questionPaperGenerator::getQuestions(vector<int> questionIdsSet, int totalMarks, vector<int>& qIdList,int curIdx)
{
	if (totalMarks == 0)
		return true;
	if (totalMarks < 0 || curIdx >= questionIdsSet.size())
		return false;
	//select
	int curMarks = questionList[questionIdsSet[curIdx]]->getMarks();
	qIdList.push_back(questionIdsSet[curIdx]);
	if (getQuestions(questionIdsSet, totalMarks-curMarks,qIdList,curIdx+1))
		return true;
	qIdList.pop_back();
	//reject
	if (getQuestions(questionIdsSet, totalMarks, qIdList, curIdx + 1))
		return true;
}
