#include "qTemplate.h"

marksDistMap qTemplate::getDistMap() const
{
    return marksDist;
}

attribute qTemplate::getAttribute() const
{
    return attribType;
}

int qTemplate::getMarks() const
{
    return marks;
}

string qTemplate::getDetails() const
{
    string retText = "Template Details : Attribute : " + getAttributeAsStr() + ", Marks : " + to_string(getMarks());
    retText += "Distribution : ";
	for(auto& iter : getDistMap())
	{
        retText += iter.first + " : " + to_string(iter.second);
	}
    return retText;
}

string qTemplate::getAttributeAsStr() const
{
    if (attribType == attribute::AUTHOR)
        return "author";
    else if (attribType == attribute::DIFFICULTY)
        return "difficulty";
    else if (attribType == attribute::SUBJECT)
        return "subject";
    return "";
}
