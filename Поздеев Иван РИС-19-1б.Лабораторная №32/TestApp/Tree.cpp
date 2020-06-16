#include "Tree.h"
using namespace std;
int i = 0;
string* s = new string[100];

Tree::Tree()
{
	number = "";
	text = "";
	left = NULL;
	right = NULL;
	parent = NULL;
	cursor = false;
}

Tree::Tree(const Tree& a)
{

	number = a.number;
	text = a.text;
}

void Tree::operator<< (const Tree& point)
{
	cout << "���������� � ����: " << "\n����� ������ : " << point.number << "\n����� : " << point.text << endl;
}

void Tree::operator>>(Tree& point)
{
	cout << "������� ����� : ";
	cin >> point.number;
	cout << "������� ����� : ";
	cin >> point.text;
}

Tree::~Tree()
{
}

int Tree::height(Tree* node)  //��������� ������ ��. ������. ������
{
	int level = 1;
	while (node->left != NULL)
	{
		node = node->left;
		level++;
	}
	return level;
}

Tree* Tree::balancedTree(int n) //�������� ������
{
	if (n == 0)
		return NULL;
	Tree* tree = new Tree(V[k]);
	k++;
	tree->AddLeftTree(balancedTree(n / 2));
	tree->AddRightTree(balancedTree(n - n / 2 - 1));
	return tree;
}

void Tree::AddLeftTree(Tree* tree) //���������� ������ ���������
{
	if (tree != NULL) {
		tree->parent = this;
		left = tree;
	}
}

void Tree::AddRightTree(Tree* tree)//���������� ������� ���������
{
	if (tree != NULL) {
		tree->parent = this;
		right = tree;
	}
}

int Tree::GetLevelUntil(Tree* node, string data, int level) //��������� �������� ������ ���� (������)
{
	if (node == NULL)
		return 0;

	if (node->number == data)
		return level;

	int downlevel = GetLevelUntil(node->left, data, level + 1);
	if (downlevel != 0)
		return downlevel;

	downlevel = GetLevelUntil(node->right, data, level + 1);
	return downlevel;
}

int Tree::GetLevel(Tree* node, string data) //����� ���� ��� ����
{
	return GetLevelUntil(node, data, 1);
}

void Tree::reorderSetCoords(Tree* tree, char dir) //����������� ��������� � ����� ����� �� ������
{                                                  //�������� ����
	if (tree != NULL)
	{
		int curLevel = GetLevel(gc.tree, tree->getNumber());
		if (tree->parent == NULL)
			tree->b = '�';
		else if (tree->left == NULL && tree->right == NULL)
			tree->b = '�';
		else
			tree->b = '�';
		if (dir == '0')
		{
			tree->x = gc.winW / 2;
			tree->y = gc.winH - (gc.winH / gc.treeH / 2);
		}
		else if (dir == 'r') //�����
		{
			tree->x = tree->parent->x - gc.winW / pow(2, curLevel);

			if (curLevel == ((gc.treeH / 2) + 1) and gc.treeH % 2 == 1)
				tree->y = gc.winH / 2;
			else
				tree->y = tree->parent->y - gc.winH / gc.treeH;
		}
		else if (dir == 'l') //������
		{

			tree->x = tree->parent->x + gc.winW / pow(2, curLevel);

			if (curLevel == ((gc.treeH / 2) + 1) and gc.treeH % 2 == 1)
				tree->y = gc.winH / 2;
			else
				tree->y = tree->parent->y - gc.winH / gc.treeH;

		}
		reorderSetCoords(tree->left, 'r'); //������ �������� ���������
		reorderSetCoords(tree->right, 'l');//������� ������ ���� �������
	}
}

void Tree::reorderAtributes(Tree* tree)
{
	if (tree != NULL)
	{
		cout << "���������� � ����: " << "\n����� : " << tree->number << "\n����� : " << tree->text << endl;
		if (tree->left != NULL)
			cout << "������ �������: " << "\n����� : " << tree->left->number << "\n����� : " << tree->left->text << endl;
		else
			cout << "������ �������: " << "NULL\n";

		if (tree->right != NULL)
			cout << "����� �������: " << "\n����� : " << tree->right->number << "\n����� : " << tree->right->text << endl;
		else
			cout << "����� �������: " << "NULL\n";
		if (tree->parent != NULL)
			cout << "��������: " << "\n����� : " << tree->parent->number << "\n����� : " << tree->parent->text << endl;
		else
			cout << "��������: " << "NULL\n";
		cout << "��� ����: " << tree->b << endl << '\n';
		reorderAtributes(tree->left);
		reorderAtributes(tree->right);
	}
}

void Tree::Find(Tree* tree)
{
	if (tree != NULL) {
		s[i] = tree->text;
		i++;
		Find(tree->right);
		Find(tree->left);
	}
}

void Tree::searchMany(Tree* tree, int many)
{
	int o = 0;
	int k = 0;
	while (k < i) {
		for (int j = 0; j < i; j++)
			if (s[k] == s[j])
				o++;
		if (o != many) {
			k++;
			o = 0;
		}
		else {
			cout << "������� ������� ����������� �������� ���-�� ��� : " << s[k] << endl;
			break;
		}
	}
}

void Tree::searchOnlyOne(Tree* tree)
{
	int q = 0;
	int o = 0;
	int k = 0;
	while (k < i) {
		for (int j = 0; j < i; j++)
			if (s[k] == s[j])
				o++;
		if (o > 1) {
			k++;
			o = 0;
		}
		else {
			cout << "������� ����������� 1 ��� : " << s[k] << endl;
			k++;
			o = 0;
			q++;
		}
	}
	if (q == 0)
		cout << "��� ������� ������������� 1 ��� ! " << endl;
}

void Tree::searchMax(Tree* tree)
{
	{
		int q;
		int o = 0;
		int f = 0;
		int k = 0;
		while (k < i) {
			for (int j = 0; j < i; j++)
				if (s[k] == s[j])
					o++;
			if (o > f) {
				f = o;
				q = k;
				k++;
				o = 0;
			}
			else {
				k++;
				o = 0;
			}
		}
		cout << "������� ����������� max ���-�� ��� : " << s[q] << endl;
	}
}

void drawButton1()
{
	if (gc.b1_state == 1)
		glColor3f(0.3f, 0.3f, 0.3f);
	else
		glColor3f(1.0f, 0.5f, 0.5f);
	glBegin(GL_QUADS);

	glVertex2i(0, gc.winH);
	glVertex2i(0, gc.winH - gc.winH / 18);
	glVertex2i(gc.winW / 16, gc.winH - gc.winH / 18);
	glVertex2i(gc.winW / 16, gc.winH);
	glEnd();

	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINE_LOOP);
	glVertex2i(0, gc.winH);
	glVertex2i(0, gc.winH - gc.winH / 18);
	glVertex2i(gc.winW / 16, gc.winH - gc.winH / 18);
	glVertex2i(gc.winW / 16, gc.winH);
	glEnd();
	string button = "Add elem";
	glRasterPos2i(2, gc.winH - 12);
	for (int i = 0; i < button.length(); i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, button[i]);

	gc.b1_x = gc.winW / 16;
	gc.b1_y = gc.winH / 18;
}

void drawButton2()
{
	if (gc.b2_state == 1)
		glColor3f(0.3f, 0.3f, 0.3f);
	else
		glColor3f(1.0f, 0.5f, 0.5f);
	glBegin(GL_QUADS);
	glVertex2i(0, gc.winH - (3 / 2) * gc.b1_y);
	glVertex2i(0, (gc.winH - gc.winH / 18) - (3 / 2) * gc.b1_y);
	glVertex2i(gc.winW / 16, (gc.winH - gc.winH / 18) - (3 / 2) * gc.b1_y);
	glVertex2i(gc.winW / 16, gc.winH - (3 / 2) * gc.b1_y);
	glEnd();

	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINE_LOOP);

	glVertex2i(0, gc.winH - (3 / 2) * gc.b1_y);
	glVertex2i(0, (gc.winH - gc.winH / 18) - (3 / 2) * gc.b1_y);
	glVertex2i(gc.winW / 16, (gc.winH - gc.winH / 18) - (3 / 2) * gc.b1_y);
	glVertex2i(gc.winW / 16, (gc.winH - (3 / 2) * gc.b1_y));
	glEnd();
	string button = "Delete elem";
	glRasterPos2i(2, gc.winH - (3 / 2) * gc.b1_y - 12);
	for (int i = 0; i < button.length(); i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, button[i]);

	gc.b2_x = gc.winW / 16;
	gc.b2_y = gc.winH / 18 + (3 / 2) * gc.b1_y;
}

void drawButton3() //������ ������ ��������� � �������
{
	if (gc.b3_state == 1)
		glColor3f(0.3f, 0.3f, 0.3f);
	else
		glColor3f(1.0f, 0.5f, 0.5f);
	glBegin(GL_QUADS);
	glVertex2i(0, gc.winH - (3 / 2) * gc.b2_y);
	glVertex2i(0, (gc.winH - gc.winH / 18) - (3 / 2) * gc.b2_y);
	glVertex2i(gc.winW / 16, (gc.winH - gc.winH / 18) - (3 / 2) * gc.b2_y);
	glVertex2i(gc.winW / 16, (gc.winH - (3 / 2) * gc.b2_y));
	glEnd();

	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINE_LOOP);

	glVertex2i(0, gc.winH - (3 / 2) * gc.b2_y);
	glVertex2i(0, (gc.winH - gc.winH / 18) - (3 / 2) * gc.b2_y);
	glVertex2i(gc.winW / 16, (gc.winH - gc.winH / 18) - (3 / 2) * gc.b2_y);
	glVertex2i(gc.winW / 16, (gc.winH - (3 / 2) * gc.b2_y));
	glEnd();

	string button = "Only one";
	glRasterPos2i(2, gc.winH - (3 / 2) * gc.b2_y - 12);
	for (int i = 0; i < button.length(); i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, button[i]);

	gc.b3_x = gc.winW / 16;
	gc.b3_y = gc.winH / 18 + (3 / 2) * gc.b2_y;
}

void drawButton4()
{
	if (gc.b4_state == 1)
		glColor3f(0.3f, 0.3f, 0.3f);
	else
		glColor3f(1.0f, 0.5f, 0.5f);
	glBegin(GL_QUADS);
	glVertex2i(0, gc.winH - (3 / 2) * gc.b3_y);
	glVertex2i(0, (gc.winH - gc.winH / 18) - (3 / 2) * gc.b3_y);
	glVertex2i(gc.winW / 16, (gc.winH - gc.winH / 18) - (3 / 2) * gc.b3_y);
	glVertex2i(gc.winW / 16, (gc.winH - (3 / 2) * gc.b3_y));
	glEnd();

	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINE_LOOP);

	glVertex2i(0, gc.winH - (3 / 2) * gc.b3_y);
	glVertex2i(0, (gc.winH - gc.winH / 18) - (3 / 2) * gc.b3_y);
	glVertex2i(gc.winW / 16, (gc.winH - gc.winH / 18) - (3 / 2) * gc.b3_y);
	glVertex2i(gc.winW / 16, (gc.winH - (3 / 2) * gc.b3_y));
	glEnd();

	string button = "Maximum";

	glRasterPos2i(2, gc.winH - (3 / 2) * gc.b3_y - 12);
	for (int i = 0; i < button.length(); i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, button[i]);
	gc.b4_x = gc.winW / 16;
	gc.b4_y = gc.winH / 18 + (3 / 2) * gc.b3_y;
}

void drawButton5()
{
	if (gc.b5_state == 1)
		glColor3f(0.3f, 0.3f, 0.3f);
	else
		glColor3f(1.0f, 0.5f, 0.5f);
	glBegin(GL_QUADS);
	glVertex2i(0, gc.winH - (3 / 2) * gc.b4_y);
	glVertex2i(0, (gc.winH - gc.winH / 18) - (3 / 2) * gc.b4_y);
	glVertex2i(gc.winW / 16, (gc.winH - gc.winH / 18) - (3 / 2) * gc.b4_y);
	glVertex2i(gc.winW / 16, (gc.winH - (3 / 2) * gc.b4_y));
	glEnd();

	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINE_LOOP);

	glVertex2i(0, gc.winH - (3 / 2) * gc.b4_y);
	glVertex2i(0, (gc.winH - gc.winH / 18) - (3 / 2) * gc.b4_y);
	glVertex2i(gc.winW / 16, (gc.winH - gc.winH / 18) - (3 / 2) * gc.b4_y);
	glVertex2i(gc.winW / 16, (gc.winH - (3 / 2) * gc.b4_y));
	glEnd();

	string button = "How many";
	string button2 = "you need";

	glRasterPos2i(2, gc.winH - (3 / 2) * gc.b4_y - 12);
	for (int i = 0; i < button.length(); i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, button[i]);
	glRasterPos2i(2, gc.winH - (3 / 2) * gc.b4_y - 24);
	for (int i = 0; i < button2.length(); i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, button2[i]);
	gc.b5_x = gc.winW / 16;
	gc.b5_y = gc.winH / 18 + (3 / 2) * gc.b4_y;
}

void drawCircle(int x, int y)
{
	glColor3f(0.7f, 0.7f, 0.7f);
	float x1, y1;
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++)
	{
		float theta = 2.0f * 3.1415926f * float(i) / float(360);
		y1 = gc.R * cos(theta) + y;
		x1 = gc.R * sin(theta) + x;;

		glVertex2f(x1, y1);

	}
	glEnd();

	glColor3f(0.0f, 0.0f, 0.0f);
	float x2, y2;
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < 360; i++)
	{
		float theta = 2.0f * 3.1415926f * float(i) / float(360);
		y2 = gc.R * cos(theta) + y;
		x2 = gc.R * sin(theta) + x;;

		glVertex2f(x2, y2);

	}
	glEnd();

}

void drawBorderedCircle(int x, int y)
{
	glColor3f(0.1f, 0.2f, 0.3f);
	float x1, y1;
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++)
	{
		float theta = 2.0f * 3.1415926f * float(i) / float(360);
		y1 = gc.R * cos(theta) + y;
		x1 = gc.R * sin(theta) + x;;

		glVertex2f(x1, y1);

	}
	glEnd();

	glColor3f(0.0f, 0.0f, 1.0f);
	float x2, y2;
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < 360; i++)
	{
		float theta = 2.0f * 3.1415926f * float(i) / float(360);
		y2 = gc.R * cos(theta) + y;
		x2 = gc.R * sin(theta) + x;;

		glVertex2f(x2, y2);
	}
	glEnd();

}

void drawLine(int x0, int y0, int x1, int y1) //����������� �����
{
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINES);
	glVertex2i(x0, y0);
	glVertex2i(x1, y1);
	glEnd();
}

Tree* checkCircle(Tree* node, int x, int y) //��������� ������ �� ���� � ���� �����
{
	if (pow(x - node->get_X(), 2) + pow(y - node->get_Y(), 2) <= pow(gc.R, 2))
		return node;
	Tree* temp = NULL;
	if (node->getLeft() != NULL)
		temp = checkCircle(node->getLeft(), x, y);
	if (temp != NULL)
		return temp;
	if (node->getRight() != NULL)
		temp = checkCircle(node->getRight(), x, y);
	return temp;
}

Tree* Tree::GetNode(int x, int y)
{
	Tree* node = this;
	node = checkCircle(node, x, y);
	return node;
}

void display() //������� �����������
{
	glShadeModel(GL_SMOOTH);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, gc.winW, 0, gc.winH); //������ ������ ��������� � ����� ������ ����
	glViewport(0, 0, gc.winW, gc.winH);
	glClearColor(0.9, 0.98, 1.000, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	Tree* tree = gc.tree;
	int R = 3 * (gc.winH / gc.treeH) / 4;   //����������� ������ ������
	gc.R = (R / 2) / (gc.winH / gc.winW + 1) - gc.shift;
	tree->reorderSetCoords(tree, '0'); //����������� ����������
	queue<Tree*> Q; //������� ��� ������ DATA
	Tree* current = NULL;; //������� �������

	Q.push(tree);
	int x0, y0, x1, y1;

	drawButton1();  //��������� ������
	drawButton2();
	drawButton3();
	drawButton4();
	drawButton5();

	while (!Q.empty())
	{
		tree = Q.front();   //1 ������� �������
		Q.pop();
		x0 = tree->get_X();  //�������� ��� ����������
		y0 = tree->get_Y();
		if (tree->getLeft())    //���� � ���� ���� ����� �������
		{
			current = tree->getLeft();
			Q.push(current);    //���������� � �������
			x1 = current->get_X();   //� �������� ��� ����������
			y1 = current->get_Y();
			drawLine(x0, y0, x1, y1);   //��������� ����. �����
		}
		if (tree->getRight()) //� �� �� ����� � ������
		{
			current = tree->getRight();
			Q.push(current);
			x1 = current->get_X();
			y1 = current->get_Y();
			drawLine(x1, y1, x0, y0);
		}
		drawCircle(x0, y0);		//�������� ����� 
		drawText(tree->getNumber(), x0, y0, false);    //� ������

		if (tree->getCursor())  //���� ������ � ���� �����
		{
			drawBorderedCircle(x0, y0); //������ ������ ����
			drawText(tree->getNumber(), x0, y0, true);//� �����
			tree->drawAtribute();   //� ����� ��� ��� � �������� ��� ��������
			tree->setCursor(false);
		}
	}
	glutSwapBuffers();

}

void Tree::drawAtribute()//��������� ���� � �������� ���� ��� ��������
{
	if (gc.winH > 200)
	{
		glColor3f(0.0f, 0.0f, 0.0f);
		GLvoid* font_style = GLUT_BITMAP_HELVETICA_18;
		int newX = 2;
		int newY = gc.winH - gc.b5_y - 10;
		int ka = 18;
		string temp;
		string fullB;
		if (this->b == '�')
			fullB = "Root";
		else if (this->b == '�')
			fullB = "Node";
		else if (this->b == '�')
			fullB = "Leaf";


		string fullNode = this->number + '(' + fullB + ')';

		glRasterPos2i(newX, newY - ka);
		for (int i = 0; i < fullNode.length(); i++)
			glutBitmapCharacter(font_style, fullNode[i]);
	}
}

void mouseMove(int x, int y) //������� ������������ �������� ����
{
	Tree* node = gc.tree->GetNode(x, gc.winH - y);

	if (node != NULL)
	{
		node->setCursor(true);
	}

	if (x <= gc.b1_x and y <= gc.b1_y)  //���� ������ � ���� �� ������
		gc.b1_state = 1;
	else
		gc.b1_state = 0;

	if (x <= gc.b2_x and y <= gc.b2_y and y >= gc.b1_y)
		gc.b2_state = 1;
	else
		gc.b2_state = 0;

	if (x <= gc.b3_x and y <= gc.b3_y and y >= gc.b2_y)
		gc.b3_state = 1;
	else
		gc.b3_state = 0;
	if (x <= gc.b4_x and y <= gc.b4_y and y >= gc.b3_y)
		gc.b4_state = 1;
	else
		gc.b4_state = 0;
	if (x <= gc.b5_x and y <= gc.b5_y and y >= gc.b4_y)
		gc.b5_state = 1;
	else
		gc.b5_state = 0;
	glutPostRedisplay(); //�����������
}

void mouseClick(int button, int state, int x, int y) //������������ �������
{
	if (x <= gc.b1_x and y <= gc.b1_y) //1 ������ +
	{
		if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) //���� ������
		{
			k = 0;
			drawTree(gc.winW, gc.winH, 10, 1);//��������� 1 ����
		}
	}
	if (x <= gc.b2_x and y <= gc.b2_y and y >= gc.b1_y) //2 ������ -
	{
		if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
		{
			if (gc.nodes == 1)
				cout << "\n������ ������� ������!\n";
			else
			{
				Tree dt;
				k = 0;
				cout << "\n������� : ";
				dt.operator>>(dt);

				for (vector<Tree>::iterator i = V.begin(); i != V.end(); i++) //���� �������� ����
				{
					if (dt == *i)
					{
						vector<Tree>::iterator j = i;
						V.erase(j); //� ������� ���
						gc.nodes--;
						break;
					}
				}
				drawTree(gc.winW, gc.winH, 10, 0); //�������������� ������
				cout << "������� �����." << endl;
			}
		}
	}
	if (x <= gc.b3_x and y <= gc.b3_y and y >= gc.b2_y)
	{
		if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
		{
			i = 0;
			gc.tree->Find(gc.tree);
			gc.tree->searchOnlyOne(gc.tree);
		}
	}

	if (x <= gc.b4_x and y <= gc.b4_y and y >= gc.b3_y)
	{
		if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
		{
			i = 0;
			gc.tree->Find(gc.tree);
			gc.tree->searchMax(gc.tree);
		}
	}
	if (x <= gc.b5_x and y <= gc.b5_y and y >= gc.b4_y)
	{
		if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
		{
			cin.ignore(32767, '\n');
			int many;
			cout << "������� ���������� ���������� ������ ";
			cin >> many;
			i = 0;
			gc.tree->Find(gc.tree);
			gc.tree->searchMany(gc.tree, many);
		}
	}
}

void reshape(int w, int h)
{
	gc.winW = w;
	gc.winH = h;
	glViewport(0, 0, (GLsizei)gc.winW, (GLsizei)gc.winH);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, (GLdouble)gc.winW, 0, (GLdouble)gc.winH);
	glutPostRedisplay();
}
void drawText(string data, int x0, int y0, bool state) //��������� ������ �� �����
{
	if (gc.winH < 375 or gc.winW < 375)
		return;

	GLvoid* font_style;
	int counter = 0;
	vector<string> v;
	string temp;
	int strX;
	int strY = 12;

	if (state == true) //���� ���� � ���� ������
	{
		font_style = GLUT_BITMAP_9_BY_15;
		glColor3f(1.0f, 1.00f, 1.0f);
		strX = 9;
	}
	else   //�����
	{
		glColor3f(0.0f, 0.0f, 0.0f);
		font_style = GLUT_BITMAP_8_BY_13;
		strX = 8;
	}

	for (int i = 0; i < data.length() + 1; i++) //���� ��������� ���� ����� ������
	{
		temp += data[i];
		if (data[i] == ' ' or data[i] == '\0')
		{
			counter++;
			v.push_back(temp);
			temp = "";
		}
	}
	int y = y0 + ((strY * counter / 2)) - 5; // �������������� ������ �� Y �����
	for (int i = 0; i < v.size(); i++) //���-�� ����
	{
		int ka = v[i].length() / 2;    //������ �����
		glRasterPos2i(x0 - ka * strX, y - (strY * i)); //������ ����������
		for (int j = 0; j < v[i].length(); j++)
			glutBitmapCharacter(font_style, v[i][j]);
	}
}

void drawTree(int window_width, int window_height, int shift, int n) // ������� ������������� ������
{
	static bool start = false;
	for (int i = 0; i < n; i++)
	{

		bool yes = false;
		Tree dt;
		cout << gc.nodes + 1 << ": �������: ";
		dt.operator>>(dt);
		for (int i = 0; i < V.size(); i++)
			if (dt == V[i])
				yes = true;
		if (!yes)
		{
			V.push_back(dt);
			gc.nodes++;
		}
		else
		{
			if (!start)
			{
				cout << "������!" << endl;
				n++;
			}
			else
			{
				if (gc.nodes == 1)
					cout << "\n������ ������� ������!\n";   //������ ������� ������
				else
				{
					for (vector<Tree>::iterator i = V.begin(); i != V.end(); i++) //���� �������� ����
					{
						if (dt == *i)
						{
							vector<Tree>::iterator j = i;
							V.erase(j); //� ������� ���
							gc.nodes--;
							break;
						}
					}
					cout << "�������� ������� ������ � ������. ������� �����." << endl;
				}
			}

		}

	}
	Tree* tree = Tree::balancedTree(gc.nodes);
	gc.tree = tree;
	gc.winW = window_width;
	gc.winH = window_height;
	gc.shift = shift;
	gc.treeH = tree->height(tree);
	gc.treeW = pow(2, gc.treeH - 1); //����. ������ ������
	tree->reorderSetCoords(tree, '0'); //������ ����������
	glViewport(0, 0, gc.winW, gc.winH);
	start = true;
}

bool operator==(Tree& a, Tree& b)
{
	if (a.number == b.number)
		return true;
	else
		return false;
}
