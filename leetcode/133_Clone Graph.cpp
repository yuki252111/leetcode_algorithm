#include <vector>
#include <iostream>
using namespace std;

struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if (node == NULL) {
			return NULL;
		}
		UndirectedGraphNode* result = new UndirectedGraphNode(node->label);
		int size = node->neighbors.size();
		for (int i = 0; i < size; i++) {
			UndirectedGraphNode* neighbor = node->neighbors[i];
			if (neighbor->label == node->label) {
				result->neighbors.push_back(result);
			}
			else {
				result->neighbors.push_back(cloneGraph(node->neighbors[i]));
			}
		}
		return result;
	}
};

int main() {

}