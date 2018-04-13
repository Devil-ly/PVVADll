/*
*	created by liyun 2017/12/27
*   function ��ʾ�� 3D 2D ��λ ���� dB
*   version 2.0 �ع��˱������ݵ����ݽṹ
*/
#ifndef FIELD_H
#define FIELD_H

#include <vector>
#include <fstream>
#include <complex>
#include <String>

#include "GraphTrans.h"

#include "Vector3.h"

#include <vtkSmartPointer.h>
#include <vtkImageActor.h>
#include <vtkActor.h>

using namespace std;

class Field
{
public:
	Field();
	//Field(const Field & _field); // ��д���캯��
	//Field& operator =(const Field & _field);

	virtual ~Field();

	void init();

	void freeMemory();
	void allocateMemory();

	void setNM(int N, int M);
	void getNM(int& N, int &M) const;
	void setPlane(const GraphTrans & _graphTransPara, double _ds);

	void setField(complex<double> ** _Ex, complex<double> ** _Ey, complex<double> ** _Ez,
		complex<double> ** _Hx, complex<double> ** _Hy, complex<double> ** _Hz);
	void setField(const vector<vector<complex<double>>>& _Ex, const vector<vector<complex<double>>>& _Ey);
	void setField(complex<double> ** _Ex, complex<double> ** _Ey);

	const vector<vector<complex<double>>>& getEx() const;
	const vector<vector<complex<double>>>& getEy() const;

	void setDs(double _Ds);
	double getDs() const;

	//�õ����Ĳ���
	void getSourcePara(GraphTrans & _graphTransPara, 
		int & _N_width, int & _M_depth, double &_ds) const;

	void setShowPara(int _content, bool _isLinear, bool _isPhs);
	void getShowPara(int &_content, bool &_isLinear, bool &_isPhs);
	void set3D(bool _is3D);
	bool get3D() const;

	void calActor3D();
	void calActor();

	vtkSmartPointer<vtkImageActor> getActor() const;
	vtkSmartPointer<vtkActor> getActor3D() const;

	double getWidth() const { return data[7]; }
	double getDepth() const { return data[8]; }

	void save(const std::string &fileName) const;

	virtual void updateData();

	// �Ƿ���ʾ
	void setIsShow(bool);

	void setIsSource(bool);

	const vector<double>& getData() const { return data; }
	//void setData(const vector<double>&);

	GraphTrans getGraphTrans() const { return graphTrans; }
	//void setGraphTrans(const GraphTrans&);

	void readData(const string & fileAddress);


protected:

	GraphTrans graphTrans; // ��תƽ�Ʋ���
	vector<double> data;


	// ������
	vector<vector<complex<double>>> Ex, Ey, Ez;
	vector<vector<complex<double>>> Hx, Hy, Hz;

	int content;
	bool isLinear;
	bool isPhs;
	bool is3D;
	// ��Ҫ��ͼ������ content 0~5��ʾEx~H
	// isLinear �Ƿ�������
	// isPhs ����λ ���Ƿ���

	int N_width, M_depth;  //N_width = para[0] /ds

	double ds;
	
	vtkSmartPointer<vtkImageActor> actor;
	vtkSmartPointer<vtkActor> actor3D;

	bool isSource;
	//int Name; // �ж���ʲô��
};

#endif // !DRAW_H

