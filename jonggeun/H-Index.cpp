#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
	int answer = 0;
	sort(citations.begin(), citations.end());

	for (int i = 0; i < citations.size(); i++)
	{
		if (citations.size() - i >= citations[i])
			answer = citations[i];
		else if (citations.size() - i > answer)
			answer = citations.size() - i;

	}
	return answer;
}

int main()
{
	vector<int> citations = { 20,19,18,1 };
	int answer = solution(citations);
	cout << answer;
	return 0;
}