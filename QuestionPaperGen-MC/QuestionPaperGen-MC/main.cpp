#include "commonHeaders.h";
#include "questions.h";
#include "questionPaperGenerator.h";
#include "qTemplate.h";

#define EASY "EASY"
#define MEDIUM "MEDIUM"
#define DIFFICULT "DIFFICULT"
#define DSA "DSA"
#define OS "OS"
#define DBMS "DBMS"

questions* getQuestion(string text, string subject,string author,string difficulty,int marks)
{
	return new questions(text, subject,author, difficulty, marks);
}

qTemplate* getTemplate(int marks,attribute _attribType,marksDistMap& marksDist)
{
	return new qTemplate(marks,_attribType, marksDist);
}
void main()
{
	printNormal("Beginning Execution");

	//generate questions;
	vector<questions*> questionList;
	//text Case-1 : marks : 100 , attribute : diff level , dist : easy : 20, medium : 40, diff : 40
	questionList.push_back(getQuestion("This is the First Question ",DSA,"Author-1","EASY",10));
	questionList.push_back(getQuestion("This is the Second Question", DBMS,"Author-2", "MEDIUM", 20));
	questionList.push_back(getQuestion("This is the Third Question",OS, "Author-3", "DIFFICULT", 30));
	questionList.push_back(getQuestion("This is the Fourth Question",DSA, "Author-1", "EASY", 10));
	questionList.push_back(getQuestion("This is the Fifth Question", OS,"Author-2", "DIFFICULT", 10));
	questionList.push_back(getQuestion("This is the Sixth Question",DBMS, "Author-3", "MEDIUM", 20));

	//text Case-2 : marks : 100 , attribute : diff level , dist : medium : 40, diff : 60
	questionList.push_back(getQuestion("This is the Fifth Question", OS,"Author-2", "DIFFICULT", 30));
	//test-case 3: marks : 100 , attribute : subject , dist DSA : 20, DBMS : 40 , OS : 40
	//test-case 4:  marks : 100 , attribute : subject , dist DBMS : 40, OS : 60

	//generate templates
	vector<qTemplate*> templateList;
	marksDistMap marksDist;
	//test case - 1
	int totalMarks = 100;
	marksDist[EASY] = 20;
	marksDist[MEDIUM] = 40;
	marksDist[DIFFICULT] = 40;	
	templateList.push_back(getTemplate(totalMarks,attribute::DIFFICULTY,marksDist));
	
	//test case - 2
	marksDist.erase(EASY);
	marksDist[MEDIUM] = 40;
	marksDist[DIFFICULT] = 60;
	templateList.push_back(getTemplate(totalMarks, attribute::DIFFICULTY, marksDist));

	//test case - 3
	marksDist.clear();
	marksDist[DSA] = 20;
	marksDist[DBMS] = 40;
	marksDist[OS] = 40;
	templateList.push_back(getTemplate(totalMarks, attribute::SUBJECT, marksDist));
	//test case - 4 : VALID
	marksDist.clear();
	marksDist[DBMS] = 40;
	marksDist[OS] = 60;
	templateList.push_back(getTemplate(totalMarks, attribute::SUBJECT, marksDist));

	//test case - 5 INVALID
	marksDist.clear();
	marksDist[DSA] = 40;
	marksDist[OS] = 60;
	templateList.push_back(getTemplate(totalMarks, attribute::SUBJECT, marksDist));
	//test case - 6 : INVALID
	marksDist.clear();
	marksDist[DSA] = 20;
	marksDist[DBMS] = 40;
	marksDist[OS] = 50;
	templateList.push_back(getTemplate(totalMarks, attribute::SUBJECT, marksDist));


	questionPaperGenerator qGen(templateList, questionList);
	for(int i=0;i< templateList.size();i++)
	{
		vector<string> finalQuestionsList;
		printNormal(templateList[i]->getDetails());
		if(!qGen.genQuestionPaper(i, finalQuestionsList))
		{
			printError("Could Not Generate the Question Paper");
			printNormal("-------------------------------------------");
		} else
		{
			printNormal("Here is the List of Questions for template : "+to_string(i));
			for(int q=0;q<finalQuestionsList.size();q++)
				printNormal(finalQuestionsList[q]);
			printNormal("-------------------------------------------");
		}
	}
	
	//make call to generate question papers;
	//questionPaperGenerator(vector<qTemplate*> & templateList,vector<questions*> questionList)
}