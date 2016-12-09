#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <queue>

#define PLACESNUM 10

int places_index[PLACESNUM] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};	//位置索引
char placesname_index[PLACESNUM][100] = {"正门","软院","铜像","公教楼","图书馆",
"实验楼","体育馆","真草","假草","新天地"};

int distance_matrix_walk[PLACESNUM][PLACESNUM];	//距离矩阵
int distance_matrix_drive[PLACESNUM][PLACESNUM];
int shortest_matrix_walk[PLACESNUM][PLACESNUM];	//最短路径矩阵
int shortest_matrix_drive[PLACESNUM][PLACESNUM];
int trace_matrix_walk[PLACESNUM][PLACESNUM];	//追踪路径矩阵
int trace_matrix_drive[PLACESNUM][PLACESNUM];
std::queue<int> walk_pass;		//经过的点
std::queue<int> drive_pass;
int start = -1;	//初始化起点终点
int end = -1;
char result[500];

void readfile(const char filename[20]) {	//读数据文件
	std::ifstream inFile;
	inFile.open(filename);
	char trying;
	while(inFile.is_open() && !inFile.eof()) {	//先试探是否为结束符
		inFile >> trying;
		if (trying == '*')
			break;
		else {
			inFile.putback(trying);
			int number;
			inFile>>number;
			std::string name;
			inFile>>name;
			std::cout << "地点" << number << ":" << name << std::endl;
		}         
	}
	std::cout << std::endl;
	for (int i = 0; i < PLACESNUM; i++)	//读入步行矩阵
		for (int j = 0; j < PLACESNUM; j++) {
			int dis;
			inFile >> dis;
			distance_matrix_walk[i][j] = dis;
		}
	for (int i = 0; i < PLACESNUM; i++)	//读入驾车矩阵
		for (int j = 0; j < PLACESNUM; j++) {
			int dis;
			inFile >> dis;
			distance_matrix_drive[i][j] = dis;
		}
	inFile.close();
}


void checkoutput() {
	std::cout << "步行矩阵" << std::endl;
	for (int i = 0; i < PLACESNUM; i++) {
		for (int j = 0; j < PLACESNUM; j++)
			printf("%3d ", distance_matrix_walk[i][j]);
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << "步行最短矩阵" << std::endl;
	for (int i = 0; i < PLACESNUM; i++) {
		for (int j = 0; j < PLACESNUM; j++)
			printf("%3d ", shortest_matrix_walk[i][j]);
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << "步行追踪矩阵" << std::endl;
	for (int i = 0; i < PLACESNUM; i++) {
		for (int j = 0; j < PLACESNUM; j++)
			printf("%3d ", trace_matrix_walk[i][j]);
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << "驾车矩阵" << std::endl;
	for (int i = 0; i < PLACESNUM; i++) {
		for (int j = 0; j < PLACESNUM; j++)
			printf("%3d ", distance_matrix_drive[i][j]);
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << "驾车最短矩阵" << std::endl;
	for (int i = 0; i < PLACESNUM; i++) {
		for (int j = 0; j < PLACESNUM; j++)
			printf("%3d ", shortest_matrix_drive[i][j]);
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << "驾车追踪矩阵" << std::endl;
	for (int i = 0; i < PLACESNUM; i++) {
		for (int j = 0; j < PLACESNUM; j++)
			printf("%3d ", trace_matrix_drive[i][j]);
		std::cout << std::endl;
	}
}


void calculate() {	 //建立最短矩阵与追踪路径矩阵
	for (int i = 0; i < PLACESNUM; i++)
		for (int j = 0; j < PLACESNUM; j++) {
			shortest_matrix_walk[i][j] = distance_matrix_walk[i][j];
			shortest_matrix_drive[i][j] = distance_matrix_drive[i][j];
			trace_matrix_walk[i][j] = trace_matrix_drive[i][j] =  j;
		}
	//Floyd算法,
	for (int k = 0; k < PLACESNUM; k++)
		for (int i = 0; i < PLACESNUM; i++)
			for (int j = 0; j < PLACESNUM; j++) {
                    if (shortest_matrix_walk[i][k] + shortest_matrix_walk[k][j] < shortest_matrix_walk[i][j]) {
						shortest_matrix_walk[i][j] = shortest_matrix_walk[i][k] + shortest_matrix_walk[k][j];
						trace_matrix_walk[i][j] =  trace_matrix_walk[i][k];
                    }
			}
	for (int k = 0; k < PLACESNUM; k++)
		for (int i = 0; i < PLACESNUM; i++)
			for (int j = 0; j < PLACESNUM; j++) {
                    if (shortest_matrix_drive[i][k] + shortest_matrix_drive[k][j] < shortest_matrix_drive[i][j]) {
						shortest_matrix_drive[i][j] = shortest_matrix_drive[i][k] + shortest_matrix_drive[k][j];
						trace_matrix_drive[i][j] =  trace_matrix_drive[i][k];
                    }
			}
}

char* getshortestwalkpath(int s, int e) {
	int k =  trace_matrix_walk[s][e];
	memset(result, 0, 500);
	char buff[100];
	std::sprintf(result, "%s", placesname_index[s]);
	while (e != k) {
		std::sprintf(buff, "->%s", placesname_index[k]);
		std::strcat(result, buff);
		k = trace_matrix_walk[k][e];
	}
	std::sprintf(buff, "->%s", placesname_index[k]);
	std::strcat(result, buff);
	return result;
}

char* getshortestdrivepath(int s, int e) {
	int k =  trace_matrix_drive[s][e];
	memset(result, 0, 500);
	char buff[100];
	std::sprintf(result, "%s", placesname_index[s]);
	while (e != k) {
		std::sprintf(buff, "->%s", placesname_index[k]);
		std::strcat(result, buff);
		k = trace_matrix_drive[k][e];
	}
	std::sprintf(buff, "->%s", placesname_index[k]);
	std::strcat(result, buff);
	return result;
}