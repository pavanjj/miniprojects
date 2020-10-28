#include "questionPaperGenerator.h"

bool questionPaperGenerator::getQuestionsList(attribDist& distMap,attribDist::iterator& curIter,bitset<BITSET_SIZE> selectedSet,int marks,vector<int>& questionIdList)
{
	if (curIter != distMap.begin())
		++curIter;
	if(curIter == distMap.end())
	{
		if (getQuestions(selectedSet, marks, questionIdList))
		{
			return true;
		}
		else
		{
			printError("Insufficient Questions for given marks distribution, generation aborted");
			return false;
		}
		
	}
	auto curAttribType = curIter->first;
	for(auto iter = curIter->second.begin();iter != curIter->second.end();++iter)
	{
		int curMarks = (marks * iter->second) / 100;
		const auto& curQuestionBitSet = attribToQuestionBitMap[curAttribType][iter->first];
		if (!getQuestionsList(distMap, curIter, selectedSet & curQuestionBitSet, curMarks, questionIdList))
			return false;
	}
	return true;
}

bool questionPaperGenerator::genQuestionPaper(int templateId,vector<string>& qList)
{
	auto curTemplate = templates[templateId];
	auto curTotalMarks = curTemplate->getTotalMarks();
	auto marksDistMap = curTemplate->getDistMap();
	bitset<BITSET_SIZE> selectedSet;
	selectedSet.set();
	vector<int> qIdList;
	auto startIter = marksDistMap.begin();
	if(!getQuestionsList(marksDistMap,startIter,selectedSet,curTotalMarks,qIdList))
	{
		printError("Could Not Generate the Question Paper");
		return false;
	}
	
	return true;
}

bool questionPaperGenerator::getQuestions(bitset<BITSET_SIZE>& questionIdsBitSet, int totalMarks, vector<int>& qIdList,int curIdx)
{
	//if (totalMarks == 0)
	//	return true;
	//if (totalMarks < 0 || curIdx >= questionIdsSet.size())
	//	return false;
	////select
	//int curMarks = questionList[questionIdsSet[curIdx]]->getMarks();
	//qIdList.push_back(questionIdsSet[curIdx]);
	//if (getQuestions(questionIdsSet, totalMarks-curMarks,qIdList,curIdx+1))
	//	return true;
	//qIdList.pop_back();
	////reject
	//if (getQuestions(questionIdsSet, totalMarks, qIdList, curIdx + 1))
		return true;
}
