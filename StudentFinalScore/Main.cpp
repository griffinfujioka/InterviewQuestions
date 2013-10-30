// Amazon Interview Question (Online Assessment)


#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
class TestResult {
public:
  int studentId;
  string testDate;
  int testScore;
};
 
map<int, double>  calculateFinalScores (vector<TestResult> results) 
{
	map<int, double> returnMap; 
	int id; 
	vector<TestResult>::iterator it1 = results.begin();
	

	if(results.size() == 0)
		return returnMap; 

	map<int, vector<int>> id_scores;			// used for helping us select the top 5 scores 
	
	while(it1 != results.end())
	{
		if(id_scores[it1->studentId].size() == 0)
		{
			// There are no entries for this student, add to the map 
			id_scores[it1->studentId].push_back(it1->testScore); 
		}
		else
		{
			id_scores[it1->studentId].push_back(it1->testScore); 
			sort(id_scores[it1->studentId].begin(), id_scores[it1->studentId].end());		// sort the student's scores 
			reverse(id_scores[it1->studentId].begin(), id_scores[it1->studentId].end());	// now we're in reverse-ascending order (i.e,. largest to smallest in reverse)
		}

		if(returnMap[it1->studentId] == 0)
		{
			// There are no entries for this student, add to the map 
			returnMap[it1->studentId] = 0; 
		}

		it1++; 
	}

	it1 = results.begin();

	while(it1 != results.end())
	{
		// This works because the vectors of scores are sorted 
		// Look up the vector of scores for the student 
		double score1 = id_scores[it1->studentId][0]; 
		double score2 = id_scores[it1->studentId][1]; 
		double score3 = id_scores[it1->studentId][2]; 
		double score4 = id_scores[it1->studentId][3]; 
		double score5 = id_scores[it1->studentId][4]; 

		double finalScore = (score1 + score2 + score3 + score4 + score5) / 5; 

		returnMap[it1->studentId] = finalScore; 

		it1++; 
	}

	return returnMap; 
}

void ExecuteTestSuite()
{
	vector<TestResult> results; 
	TestResult tr; 
	tr.studentId = 1; 
	tr.testDate = "10/21/13"; 
	tr.testScore = 95; 

	results.push_back(tr); 

	tr; 
	tr.studentId = 1; 
	tr.testDate = "10/21/13"; 
	tr.testScore = 87; 

	results.push_back(tr); 

	tr;
	tr.studentId = 1; 
	tr.testDate = "10/21/13"; 
	tr.testScore = 99; 

	results.push_back(tr); 

	tr; 
	tr.studentId = 1; 
	tr.testDate = "10/21/13"; 
	tr.testScore = 88; 

	results.push_back(tr); 

	tr;
	tr.studentId = 1; 
	tr.testDate = "10/21/13"; 
	tr.testScore = 70; 

	results.push_back(tr); 

	tr;
	tr.studentId = 1; 
	tr.testDate = "10/21/13"; 
	tr.testScore = 88; 

	results.push_back(tr); 

	calculateFinalScores(results); 
}

int main()
{
	ExecuteTestSuite(); 

	return 0; 
}