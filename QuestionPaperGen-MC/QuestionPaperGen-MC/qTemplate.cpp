#include "qTemplate.h"
attribDist qTemplate::getDistMap() const
{
    return attribDistMap;
}

int qTemplate::getTotalMarks() const
{
    return totalMarks;
}

string qTemplate::getDetails() const
{
    string retText;
	//string retText = "Template Details : Attribute : " + getAttributeAsStr() + ", Marks : " + to_string(getTotalMarks());
    //retText += "Distribution : ";

    return retText;
}

string qTemplate::getAttributeAsStr(attribute attribType) const
{
    if (attribType == attribute::AUTHOR)
        return "author";
    else if (attribType == attribute::DIFFICULTY)
        return "difficulty";
    else if (attribType == attribute::SUBJECT)
        return "subject";
    return "";
}

bool qTemplate::mergeTemplate(qTemplate* pInputTemplate)
{
	if(getTotalMarks() != pInputTemplate->getTotalMarks())
	{
        printError("The input Marks of the two templates does not match,aborting merge");
        return false;
	}
    auto inputDistMap = pInputTemplate->getDistMap();
     
	for(auto &inpMapIter : inputDistMap)
	{
		if(attribDistMap.count(inpMapIter.first))
		{
            printError("Incompatible template types, both share an attribute, aborting merge");
            return false;
		}        
	}
    vector<vector<string>> tempStr,inputDistributionVec;
    int newSize = marksDistribution.size() * inputMarks.size();
    vector<int> newMarksVec(newSize);
    vector<string> newDistVec(newSize);
	
	for(int i=0;i<tempStr.size();i++)
	{
        for (int j = 0; j < inputDistributionVec.size(); j++)
        {
        	combine(newDistVec,tempStr[i],inputDistributionVec[j],newMarksVec,marksDistribution[i],inputMarks[j])
        }
	}
}
