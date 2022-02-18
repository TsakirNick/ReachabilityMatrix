#include <iostream>
#include <vector>

//Function to print the input matrix
void printMatrix(std::vector<std::vector<int>> inputMatrix, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			std::cout << inputMatrix[i][j] << " ";
		}

		std::cout << std::endl;
	}
}

int InDegree(std::vector<std::vector<int>> inputMatrix, int size, int node)
{
	int sum = 0;

	for (int i = 0; i < size; i++)
	{
		sum += inputMatrix[i][node];
	}

	return sum;
}

int OutDegree(std::vector<std::vector<int>> inputMatrix, int size, int node)
{
	int sum = 0;

	for (int i = 0; i < size; i++)
	{
		sum += inputMatrix[node][i];
	}

	return sum;
}

int numLoop(std::vector<std::vector<int>> inputMatrix, int size)
{
	int sum = 0;

	for (int i = 0; i < size; i++)
	{
		if (inputMatrix[i][i] != 0)
		{
			sum += inputMatrix[i][i];
		}
	}

	return sum;
}

void DFS(int start, std::vector<std::vector<int>> reachMatrix, std::vector<bool>& visited, int size)
{
	// The current node is set to visited
	visited[start] = true;

	
	for (int i = 0; i < reachMatrix[start].size(); i++)
	{

		if (reachMatrix[start][i] == 1 && (!visited[i])) 
		{
			DFS(i, reachMatrix, visited, size);
		}
	}
}

int lengthPathCount(std::vector<std::vector<int>> inputMatrix, int size)
{
	int sum = 0;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			sum += inputMatrix[i][j];
		}
	}

	return sum;
}

int maxPathCount(std::vector<std::vector<int>> inputMatrix, int size)
{
	int sum = 0;

	for (int i = 0; i < size; i++)
	{
		sum += inputMatrix[0][i];
		
	}

	return sum;
}

int main()
{
	int numNodes = 0;
	int userInput = 0;


	//Adjacency matrix implemented using vectors due to the dynamic user defined size
	std::vector<std::vector<int>> A1;
	std::vector<std::vector<int>> A2;
	std::vector<std::vector<int>> A3;
	std::vector<std::vector<int>> A4;
	std::vector<std::vector<int>> A5;
	std::vector<std::vector<int>> reachMatrix;

	do
	{

		//Displaying the main menu for the user to input an option
		std::cout << "----MAIN MENU----" << std::endl;
		std::cout << "1. Enter Graph Data" << std::endl;
		std::cout << "2. Print Outputs" << std::endl;
		std::cout << "3. Exit Program" << std::endl;
		std::cout << "Enter option number :" << std::endl;

		if (!(std::cin >> userInput))
		{
			//Checking if the user enters an integer value
			std::cout << "Please enter an integer" << std::endl;
			std::cin.clear();
		}

		switch (userInput)
		{
		case 1:
		{
			//Prompting the user to enter the number of nodes in the graph
			do
			{
				std::cout << "Enter number of nodes in the graph (Between 1 and 5):" << std::endl;
				std::cin >> numNodes;
			} while (numNodes < 1 || numNodes > 5);

			int matrixInput;

			//Input the values for A1
			for (int i = 0; i < numNodes; i++)
			{
				A1.push_back(std::vector<int>());

				for (int j = 0; j < numNodes; j++)
				{
					std::cout << "Enter A1[" << i << "][" << j << "]: ";
					std::cin >> matrixInput;
					
					A1[i].push_back(matrixInput);

					
					std::cout << std::endl;
				}
			}

			//Exit the switch statement if there is only one node
			if (numNodes == 1)
			{
				break;
			}

			//Calculate A2 matrix
			for (int i = 0; i < numNodes; i++)
			{
				A2.push_back(std::vector<int>());
				for (int j = 0; j < numNodes; j++)
				{

					int sum = 0;

					for (int k = 0; k < numNodes; k++)
					{
						sum += A1[k][j] * A1[i][k];
					}

					A2[i].push_back(sum);

				}
			}

			//Sum together A1 and A2 to create reachability matrix
			reachMatrix.clear();
			for (int i = 0; i < numNodes; i++)
			{
				reachMatrix.push_back(std::vector<int>());
				for (int j = 0; j < numNodes; j++)
				{
					reachMatrix[i].push_back( A1[i][j] + A2[i][j]);
				}
			}

			//Exit the switch statement if there are two nodes
			if (numNodes == 2)
			{
				break;
			}

			//Calculate A3 matrix
			for (int i = 0; i < numNodes; i++)
			{
				A3.push_back(std::vector<int>());
				for (int j = 0; j < numNodes; j++)
				{

					int sum = 0;

					for (int k = 0; k < numNodes; k++)
					{
						sum += A1[k][j] * A2[i][k];
					}

					A3[i].push_back(sum);

				}

			}

			//Sum together A1, A2, and A3 to create reachability matrix.
			reachMatrix.clear();
			for (int i = 0; i < numNodes; i++)
			{
				reachMatrix.push_back(std::vector<int>());
				for (int j = 0; j < numNodes; j++)
				{
					reachMatrix[i].push_back(A1[i][j] + A2[i][j] + A3[i][j]);
				}
			}

			//Exit the switch statement if there are three nodes
			if (numNodes == 3)
			{
				break;
			}

			//Calculate A4 matrix
			for (int i = 0; i < numNodes; i++)
			{
				A4.push_back(std::vector<int>());
				for (int j = 0; j < numNodes; j++)
				{

					int sum = 0;

					for (int k = 0; k < numNodes; k++)
					{
						sum += A1[k][j] * A3[i][k];
					}

					A4[i].push_back(sum);

				}

			}

			//Sum together A1, A2, A3, and A4 to create reachability matrix.
			reachMatrix.clear();
			for (int i = 0; i < numNodes; i++)
			{
				reachMatrix.push_back(std::vector<int>());
				for (int j = 0; j < numNodes; j++)
				{
					reachMatrix[i].push_back(A1[i][j] + A2[i][j] + A3[i][j] + A4[i][j]);
				}
			}

			//Exit the switch statement if there are four nodes
			if (numNodes == 4)
			{
				break;
			}

			//Calculate A5 matrix
			for (int i = 0; i < numNodes; i++)
			{
				A5.push_back(std::vector<int>());
				for (int j = 0; j < numNodes; j++)
				{

					int sum = 0;

					for (int k = 0; k < numNodes; k++)
					{
						sum += A1[k][j] * A4[i][k];
					}

					A5[i].push_back(sum);

				}

			}

			//Sum together A1, A2, A3, A4, and A5 to create reachability matrix.
			reachMatrix.clear();
			for (int i = 0; i < numNodes; i++)
			{
				reachMatrix.push_back(std::vector<int>());
				for (int j = 0; j < numNodes; j++)
				{
					reachMatrix[i].push_back(A1[i][j] + A2[i][j] + A3[i][j] + A4[i][j] + A5[i][j]);
				}
			}
			
			break;
		}

		case 2:
		{
			//Printing the input matrix
			std::cout << "Input matrix A1: " << std::endl;
			printMatrix(A1, numNodes);

			//Printing the reachability matrix
			std::cout << "Reachability matrix: " << std::endl;
			printMatrix(reachMatrix, numNodes);

			//Outputting the in-degrees of the graph
			std::cout << "In-degrees:" << std::endl;
			for (int i = 0; i < numNodes; i++)
			{
				std::cout << "Node " << i + 1 << " in-degree is " << InDegree(A1, numNodes, i) << std::endl;
			}

			std::cout << std::endl;

			//Outputting the out-degrees of the graph
			std::cout << "Out-degrees:" << std::endl;
			for (int i = 0; i < numNodes; i++)
			{
				std::cout << "Node " << i + 1 << " out-degree is " << OutDegree(A1, numNodes, i) << std::endl;
			}

			std::cout << std::endl;

			//Outputting the number of self-loops
			std::cout << "Total number of self-loops: " << numLoop(A1, numNodes) << std::endl;
			std::cout << "Total number of paths of length " << numNodes << " edges: " << maxPathCount(reachMatrix, numNodes) << std::endl;
			std::cout << "Total number of paths of length 1 edge: " << lengthPathCount(A1, numNodes) << std::endl;
			std::cout << "Total number of paths of length 1 to " << numNodes << " edges: " << lengthPathCount(reachMatrix, numNodes) << std::endl;

		}
		}
	}
	while (userInput != 3);

}

