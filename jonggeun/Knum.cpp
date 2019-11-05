#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;
	vector<int> tmp = array;

	for (int i = 0; i < commands.size(); i++)
	{
		sort(array.begin()+ commands[i][0]-1, array.begin()+ commands[i][1]);
		answer.push_back(array[commands[i][0] + commands[i][2] - 2]);

		array = tmp;
	}
	return answer;
}

int main()
{
	vector<int> array = { 1,5,2,6,3,7,4 };
	vector<vector<int>> commands = { {2,5,3},{4,4,1},{1,7,3} };
	vector<int> result;
	result = solution(array, commands);
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i];
	}
	return 0;
}