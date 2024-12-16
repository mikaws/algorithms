#include<iostream>
#include<string>
#include<fstream>
#include<vector>

struct LinkedList
{
	int val;
	LinkedList* next = NULL;
	LinkedList(int v) {
		val = v;
	}
};

void getNums(int* nums, std::string *line)
{
	std::string val = "";
	bool is_space = false;
	for(int i=0;i<=line->size();i++)
	{
		if(i == line->size())
		{
			nums[1] = stoi(val);
			return;
		}
		else if(line->at(i) == ' ' && !is_space)
		{
			nums[0] = stoi(val);
			val = "";
			is_space = true;
		} else if (line->at(i) != ' ')
		{
			is_space = false;
			val += line->at(i);
		}
	}
}

LinkedList* insertNumber(int num, LinkedList *head)
{
	LinkedList *prev = NULL;
	LinkedList *node = head;
	LinkedList *newNode = new LinkedList(num);
	newNode->val = num;
	if (head->val == 0)
	{
		newNode->next = NULL;
		return newNode;
	}
	while(node != NULL)
	{
		if (num <= node->val)
		{
			newNode->next = node;
			if (prev) {
				prev->next = newNode;
				return head;
			}
			return newNode;
		}
		prev = node;
		node = node->next;
	}
	prev->next = newNode;
	return head;
}

int main()
{
	std::string line;
	std::fstream fs ("./d1_input.txt");
	LinkedList *l1 = new LinkedList(0);
	LinkedList *l2 = new LinkedList(0);
	int i = 0;
	int count = 0;
	int nums[2];
	while(std::getline(fs, line))
	{
		getNums(nums, &line);
		l1 = insertNumber(nums[0], l1);
		l2 = insertNumber(nums[1], l2);
		i++;
	}
	while(l1 != NULL && l2 != NULL) {
		count = count + std::abs(l1->val - l2->val);
		l1 = l1->next;
		l2 = l2->next;
	}
	std::cout << count << std::endl;
	fs.close();
	return 0;
}
