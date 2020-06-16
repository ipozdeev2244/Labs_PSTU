#pragma once
#include"glut.h"
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <Windows.h>
#include <cmath>
using namespace std;

const int maxSize = 20;                      //максимальное число вершин
extern int WinW;
extern int WinH;
struct vertCoord		                     //структура координат вершин
{
	int x, y;
};

class Graph
{
private:
	vector<int> vertList;					 //вектор вершин
	int adjMatrix[maxSize][maxSize];		 //матрица смежности
public:
	Graph();                                 //конструктор (заполн€ет матрицу спежности нул€ми)
	~Graph();                                //деструктор 
	bool IsEmpty();		                     //проверка на пустоту
	bool IsFull();		                     //проверка на полноту

	int getVertText(int i) { return vertList[i]; }                               //получить значение вершины
	vector<int> getVertList() { return  vertList; }                              //получить вектор вершин
	int getAdjMatrixElem(int i, int j) { return adjMatrix[i][j]; }               //получить элемент матрицы смежности
	void setEdgeZero(int i, int j) { adjMatrix[i][j] = 0; adjMatrix[j][i] = 0; } //занулить элемент матрицы (дл€  оммиво€жера)
	int GetAmountVerts() { return vertList.size(); }                             //получить количество вершин графа
	int GetVertPos(const int& vertex);		                                     //получить позицию вершины в векторе вершин
	int GetAmountEdges();                                                        //получить количество ребер графа
	void InsertVertex(const int& vertex);					                     //добавить вершину (в конец вектора вершин)
	void InsertEdge(const int& vertex1, const int& vertex2, int weigth);	     //добавить ребро весом weight между vertex1 и vertex2
	void Print();		                                                         //вывод матрицы смежности в консоль
	void eraseLastVert();                                                        //удалить последнюю вершину в векторе вершин
	void eraseEdge(const int& vertex1, const int& vertex2);                      //удалить ребро между vertex1 и vertex2
	void drawGraph();                                                            //рисоавание графа OpenGL
};
extern Graph graph;		                                                         //создаетс€ объект класса Graph

int** Make_TSPMatrix();	                                                         //создаетс€ матрица, замен€€ 0 на -1
int* Find_Min(int* line, int n);	                                             //поиск минимального элемента в строке матрицы
void Print_Matrix(int** matrix);		                                         //вывод текущей матрицы
int** Reduct_Matrix(int** oldmatrix);		                                     //редукци€ матрицы
int** Rebuild_Matrix(int** oldmatrix);
void Print_Result();                                                             //вывод результата решени€ задачи  оммиво€жера
//
// –исование кнопок (OpenGL)
//
void drawButton1();
void drawButton2();
void drawButton3();
void drawButton4();
// drawButton6();
//void drawButton7();
//void drawRadius();
//
// –исование элементов графа (OpenGL)
//
void drawCircle(int x, int y, int R);                                            //рисование круга 
void drawBorderedCircle(int x, int y, int R);                                    //рисование круга, если курсор в зоне вершины
void drawText(int nom, int x1, int y1);                                          //рисование веса ребра
void drawLine(int text, int x0, int y0, int x1, int y1);                         //рисование ребра 
void drawVertex(int n);                                                          //рисование вершины 

void makeGraph();                                                                //создание графа
void setCoords(int i, int n);                                                    //установка координат дл€ вершин графа

bool Salesman_Check(int** matrix);                                               //проверка: можно ли решить задачу  оммиво€жера
int Circle_Check(int x, int y);                                                  //проверка: курсор в зоне вершины или нет
void Button_Check(int x, int y);                                                 //проверка: курсор в зоне кнопки или нет

void mouseMove(int x, int y);                                                    //отслеживание движени€ курсора мыши
void mouseClick(int button, int state, int x, int y);                            //функци€ регистрации нажатий мыши
void reshape(int w, int h);                                                      //отвечает за масштабирование
void display();                                                                  //отвечает за изображение 


