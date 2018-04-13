#pragma once
 
#ifndef PPVADLL_H
#define PPVADLL_H

#include <string>

class _declspec(dllexport) PVVADll
{
public:
	PVVADll();
	~PVVADll();

	void setInputFile(const std::string & file);
	void setModelFile(const std::string & file);

	void calculate(double fre, double dis);
	void SetReturnFloat(void(*returnFloat)(float, void*), void*_user);// ע��ص�����

private:

	std::string inputFieldFile;
	std::string stlMirrorFile;
	void(*returnFloat)(float, void*);
	void *user; // �ص���������ָ��
};


#endif // PPVADLL_H