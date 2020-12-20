#pragma once

#define _USE_MATH_DEFINES
#include <math.h>

//нахождение вектора по 2 точкам 
void VectorBP(double point[3], double nextpoint[3], double* Vector)
{
	Vector[0] = nextpoint[0] - point[0];
	Vector[1] = nextpoint[1] - point[1];
	Vector[2] = nextpoint[2] - point[2];
}

void NormalizeV(double* Vector)
{
	double Lenght = sqrt(pow(Vector[0], 2) + pow(Vector[1], 2) + pow(Vector[2], 2));

	Vector[0] /= Lenght;
	Vector[1] /= Lenght;
	Vector[2] /= Lenght;
}

double ScalarV(double* a, double* b)
{
	double ScalarProduct = a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
	return ScalarProduct;
}

void VectorP2(double* a, double* b, double* result)
{
	result[0] = a[1] * b[2] - a[2] * b[1];
	result[1] = (-1) * a[0] * b[2] + b[0] * a[2];
	result[2] = a[0] * b[1] - a[1] * b[0];
}


void NormalV(double* n, double a[3], double b[3])
{
	n[0] = a[1] * b[2] - b[1] * a[2];
	n[1] = (-1) * a[0] * b[2] + b[0] * a[2];
	n[2] = a[0] * b[1] - b[0] * a[1];
}


void Besie2(double p1[3], double p2[3], double p3[3], double p4[3], double t, double b[3])
{

	b[0]= pow(1 - t, 3) * p1[0] + 3 * t * pow(1 - t, 2) * p2[0] + 3 * pow(t, 2) * (1 - t) * p3[0] + pow(t, 3) * p4[0];
	b[1] = pow(1 - t, 3) * p1[1] + 3 * t * pow(1 - t, 2) * p2[1] + 3 * pow(t, 2) * (1 - t) * p3[1] + pow(t, 3) * p4[1];
	b[2] = pow(1 - t, 3) * p1[2] + 3 * t * pow(1 - t, 2) * p2[2] + 3 * pow(t, 2) * (1 - t) * p3[2] + pow(t, 3) * p4[2];
}


void Besie(double p1[3], double p2[3], double p3[3],double p4[3])
{
	double b[3];
	glBegin(GL_LINE_STRIP);

	for (double t = 0; t <= 1.0001; t += 0.01)
	{
		Besie2(p1, p2, p3, p4, t, b);
		glVertex3dv(b);
    }

	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex3dv(p1);
	glVertex3dv(p2);
	glVertex3dv(p3);
	glVertex3dv(p4);
	glEnd();
}


void Termit2(double P1[3], double P4[3], double r1[3], double r4[3], double t, double b[3])
{

	b[0] = P1[0] * (2 * pow(t, 3) - 3 * pow(t, 2) + 1) + P4[0] * (-2 * pow(t, 3) + 3 * pow(t, 2)) + r1[0] * (pow(t, 3) - 2 * pow(t, 2) + t) + r4[0] * (pow(t, 3) - pow(t, 2));
	b[1] = P1[1] * (2 * pow(t, 3) - 3 * pow(t, 2) + 1) + P4[1] * (-2 * pow(t, 3) + 3 * pow(t, 2)) + r1[1] * (pow(t, 3) - 2 * pow(t, 2) + t) + r4[1] * (pow(t, 3) - pow(t, 2));
	b[2] = P1[2] * (2 * pow(t, 3) - 3 * pow(t, 2) + 1) + P4[2] * (-2 * pow(t, 3) + 3 * pow(t, 2)) + r1[2] * (pow(t, 3) - 2 * pow(t, 2) + t) + r4[2] * (pow(t, 3) - pow(t, 2));


}

void Termit(double P1[3], double P2[3], double P3[3], double P4[3])
{
	double r1[3] = { 3 * (P2[0] - P1[0]),3 * (P2[1] - P1[1]),3 * (P2[2] - P1[2]) };
	double r4[3] = { 3 * (P4[0] - P3[0]),3 * (P4[1] - P3[1]),3 * (P4[2] - P3[2]) };

	double b[3];
	glBegin(GL_LINE_STRIP);

	for (double t = 0; t <= 1.0001; t += 0.01)
	{
		Termit2(P1,P4,r1,r4,t,b);
		glVertex3dv(b);
		
	}

	glEnd();

	glPointSize(10);
	glBegin(GL_POINTS);

	glVertex3dv(P1);
	glVertex3dv(P4);

	glEnd();

	glBegin(GL_LINES);

	glVertex3dv(P1);
	glVertex3dv(r1);
	glVertex3dv(P4);
	glVertex3dv(r4);

	glEnd();

}

class FIGURA
{
	double p[3] = { 1,0,0 };
	double f[3];

	double O[3] = { 0,0,0 };
	double O1[3] = { 0,0,1 };

	double A[3] = { 0,-1.3,0 };
	double A1[3] = { 0,-1.3,1 };

	double B[3] = { 1.2,-0.4,0 };
	double B1[3] = { 1.2,-0.4,1 };

	double C[3] = { 0.8,1,0 };
	double C1[3] = { 0.8,1,1 };

	double D[3] = { -0.8,1,0 };
	double D1[3] = { -0.8,1,1 };

	double E[3] = { -1.2,-0.4,0 };
	double E1[3] = { -1.2,-0.4,1 };

public:
	void figura()
	{

		glBegin(GL_POLYGON);
		glColor3d(0, 1, 1);

		glVertex3dv(A);
		glVertex3dv(B);
		glVertex3dv(C);
		glVertex3dv(D);
		glVertex3dv(E);

		glEnd();

		glBegin(GL_POLYGON);

		glVertex3dv(A1);
		glVertex3dv(B1);
		glVertex3dv(C1);
		glVertex3dv(D1);
		glVertex3dv(E1);

		glEnd();

		glBegin(GL_POLYGON);

		glVertex3dv(A);
		glVertex3dv(B);
		glVertex3dv(B1);
		glVertex3dv(A1);

		glEnd();

		glBegin(GL_POLYGON);

		glVertex3dv(B);
		glVertex3dv(C);
		glVertex3dv(C1);
		glVertex3dv(B1);

		glEnd();

		glBegin(GL_POLYGON);

		glVertex3dv(C);
		glVertex3dv(D);
		glVertex3dv(D1);
		glVertex3dv(C1);

		glEnd();

		glBegin(GL_POLYGON);

		glVertex3dv(D);
		glVertex3dv(E);
		glVertex3dv(E1);
		glVertex3dv(D1);

		glEnd();

		glBegin(GL_POLYGON);

		glVertex3dv(E);
		glVertex3dv(A);
		glVertex3dv(A1);
		glVertex3dv(E1);

		glEnd();
	}

	void figura2(double A1[3],double A2[3])
	{
		

		glPushMatrix();

		glTranslated(A1[0], A1[1], A1[2]);
		Corners(A1, A2);
		figura();

		glPopMatrix();

	}

	void Corners(double A1[3], double A2[3])
	{
		double Vec[3] = { 0,0,0 };
		VectorBP(A1, A2, Vec);
		NormalizeV(Vec);
		f[0] = Vec[0]; 
		f[1] = Vec[1]; 
		f[2] = 0;

		NormalizeV(f);

		double cos = ScalarV(p, f);
		double VecProduct[3] = { 0,0,0 };
		VectorP2(p, f, VecProduct);

		double sin = VecProduct[2] / abs(VecProduct[2]);
		double alpha = acos(cos) * 180.0 / M_PI * sin;
		double betta = acos(Vec[2]) * 180.0 / M_PI - 90;

		glRotated(alpha, 0, 0, 1);
		glRotated(betta, 0, 1, 0);
	}


	

};

//нахождение delta_time (разницы между прорисовками, кадрами)
double SearchDeltaTime() {
	static auto EndRender = std::chrono::steady_clock::now();
	auto CurTime = std::chrono::steady_clock::now();
	auto DeltaTime = CurTime - EndRender;
	double Delta = 1.0 * std::chrono::duration_cast<std::chrono::microseconds>(DeltaTime).count() / 1000000;
	EndRender = CurTime;
	return Delta;
}

double Tmax=0, Tmin=1, dt=0;
bool flag=true;

void Mforward(double Tmax,double P1[3], double P2[3], double P3[3], double P4[3], int M)
{
	double A1[3], A2[3];

	FIGURA F;

	if (M == 0)
	{
		double r1[3] = { 3 * (P2[0] - P1[0]),3 * (P2[1] - P1[1]),3 * (P2[2] - P1[2]) };
		double r4[3] = { 3 * (P4[0] - P3[0]),3 * (P4[1] - P3[1]),3 * (P4[2] - P3[2]) };
		Termit2( P1, P4, r1, r4, Tmax, A1);
		Termit2(P1, P4, r1, r4, Tmax+0.01 , A2);
		F.figura2(A1,A2);
	}

	if (M == 1)
	{
		Besie2(P1, P2, P3, P4, Tmax, A1);
		Besie2(P1, P4, P3, P4, Tmax + 0.01, A2);
		F.figura2(A1, A2);

	}


}


void Mback(double Tmin, double P1[3], double P2[3], double P3[3], double P4[3], int M)
{
	double A1[3], A2[3];

	FIGURA F;

	if (M == 0)
	{
		double r1[3] = { 3 * (P2[0] - P1[0]),3 * (P2[1] - P1[1]),3 * (P2[2] - P1[2]) };
		double r4[3] = { 3 * (P4[0] - P3[0]),3 * (P4[1] - P3[1]),3 * (P4[2] - P3[2]) };
		Termit2(P1, P4, r1, r4, Tmin, A1);
		Termit2(P1, P4, r1, r4, Tmin - 0.01, A2);
		F.figura2(A1, A2);
	}

	if (M == 1)
	{
		Besie2(P1, P2, P3, P4, Tmin, A1);
		Besie2(P1, P4, P3, P4, Tmin - 0.01, A2);
		F.figura2(A1, A2);

	}


}

void Trevel(double p1[3], double p2[3], double p3[3], double p4[3],int M)
{
	dt = SearchDeltaTime();

	if(Tmax>=1)
	{ 
		Tmax = 0;
		flag = false;
	}
	if(Tmin<=0)
	{ 
		Tmin = 1;
		flag = true;
	}
	if(flag == true)
	{ 
		Tmax += dt / 10;
		Mforward(Tmax,p1,p2,p3,p4,M);
	}
	else 
	{ 
		Tmin -= dt / 10;
		Mback(Tmin, p1, p2, p3, p4, M);
	}
}


class XYZ
{
public:
	double x, y, z;

	XYZ(double X, double Y, double Z)
	{
		x = X;
		y = Y;
		z = Z;
	}

	void Vertex() 
	{
		glVertex3d(x,y,z);

	}

};

int Factorial(int n)
{
	if (n < 0)
		return 0;
	if (n == 0)
		return 1;
	else
		return n * Factorial(n - 1);
}

double Polynom(int n, int i, double t)
{
	double res = (Factorial(n) / (Factorial(n - i) * Factorial(i))) * pow(t, i) * pow(1 - t, n - i);

	return res;
}


XYZ PERpoint(double u, double v, std::vector<std::vector<XYZ>> xyz)
{
	XYZ Res(0, 0, 0);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			double iu = Polynom(3, i, u);
			double jv = Polynom(3, j, v);
			Res.x += iu * jv * xyz[i][j].x;
			Res.y += iu * jv * xyz[i][j].y;
			Res.z += iu * jv * xyz[i][j].z;
		}
	}
	return Res;
}

void Print(std::vector<std::vector<XYZ>> xyz, GLuint texId)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			glPointSize(10);
			glColor3f(1, 0.5, 1);
			glBegin(GL_POINTS);
			xyz[i][j].Vertex();
			glEnd();
		}
	}

	glColor3f(0.8, 0.5, 1);
	for (int i = 0; i < 4; i++)
	{
		glBegin(GL_LINE_STRIP);
		for (int j = 0; j < 4; j++)
		{
			xyz[i][j].Vertex();

		}
		glEnd();
	}

	for (int i = 0; i < 4; i++)
	{
		glBegin(GL_LINE_STRIP);
		for (int j = 0; j < 4; j++)
		{
			xyz[j][i].Vertex();
		
		}
		glEnd();
	}

	std::vector<XYZ> p;
	std::vector<std::vector<XYZ>> Mass;


	for (double u = 0; u <= 1.0001; u += 0.1)
	{
		for (double v = 0; v <= 1.0001; v += 0.1)
		{
			p.push_back(PERpoint(u, v, xyz));
		}
		Mass.push_back(p);
		p.clear();
	}

	glColor3f(1, 1, 1);
	glBindTexture(GL_TEXTURE_2D, texId);
	glBegin(GL_TEXTURE_2D);

	for (int i = 0; i < Mass.size() - 1; i++)
	{
		
		for (int j = 0; j < Mass.size() - 1; j++)
		{
			double a[3];
			double b[3];
			double n[3];


			XYZ A = Mass[i][j];
			XYZ B = Mass[i][j+1];
			XYZ C = Mass[i+1][j+1];
			XYZ D = Mass[i+1][j];

			double a_[3] = { A.x,A.y,A.z };
			double b_[3] = { B.x,B.y,B.z };
			double c_[3] = { C.x,C.y,C.z };

			double i_ =1./ Mass.size();
			double j_ = 1. / Mass[i].size();

			
			double a_tex[2] = { i_ * i, j_ * j };
			double b_tex[2] = { i_ * i,j_ * (j + 1) };
			double c_tex[2] = { i_ * (i + 1),j_ * (j + 1) };
			double d_tex[2] = { i_ * (i + 1),j_ * j };


			glBegin(GL_QUADS);
			
			VectorBP(b_,a_,a);
			VectorBP(b_, c_, b);
			NormalV(n,a,b);
			glNormal3dv(n);

			glTexCoord2dv(a_tex);
			A.Vertex();

			glTexCoord2dv(b_tex);
			B.Vertex();

			glTexCoord2dv(c_tex);
			C.Vertex();

			glTexCoord2dv(d_tex);
			D.Vertex();

			glEnd();


		}
		
	}
	glDisable(GL_TEXTURE_2D);

}
