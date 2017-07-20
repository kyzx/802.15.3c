//����������SC-PHYǰ������ģ��,���룺vSC_Pre, 
//����������SC_preamble:SC PHYǰ����Pre_mod:ǰ��ģʽ��CMS-0��MR-1��HR-2

#include"genParam.h"
#include "stdafx.h"

using namespace std;

void SC_genPreamble(vector<complex<double> > &vSC_Pre, int Pre_mod)
{
	int a_golay_hex_32[32] = {0x0,0x5,0x3,0x6,0x6,0x3,0x5,0x0,0x0,0x5,0xC,0x9,0x6,0x3,0xA,0xF,
		0xF,0xA,0xC,0x9,0x9,0xC,0xA,0xF,0x0,0x5,0xC,0x9,0x6,0x3,0xA,0xF};
	int b_golay_hex_32[32] = {0x0,0xA,0x3,0x9,0x6,0xC,0x5,0xF,0x0,0xA,0xC,0x6,0x6,0xC,0xA,0x0,
		0xF,0x5,0xC,0x6,0x9,0x3,0xA,0x0,0x0,0xA,0xC,0x6,0x6,0xC,0xA,0x0};
	vector<int> a_golay_binary_128;
	hex2binary(a_golay_hex_32, a_golay_binary_128, 32);//a128
	vector<int> b_golay_binary_128;
	hex2binary(b_golay_hex_32, b_golay_binary_128, 32);//b128
	vector<int> a_golay_binary_128_N (128, 0);
	for (int i = 0; i < 128; i++)
		a_golay_binary_128_N[i]=floor((2-(a_golay_binary_128[i]*1.0))/2);//a128����
	vector<int> b_golay_binary_128_N (128, 0);
	for (int i = 0; i < 128; i++)
		b_golay_binary_128_N[i]=floor((2-(b_golay_binary_128[i]*1.0))/2);//b128����
	vector<int> a_golay_binary_256;
	for (int i = 0; i < 128; i++)
		a_golay_binary_256.push_back(a_golay_binary_128[i]);
	for (int i = 0; i < 128; i++)
		a_golay_binary_256.push_back(a_golay_binary_128_N[i]);
	vector<int> b_golay_binary_256;
	for (int i = 0; i < 128; i++)
		b_golay_binary_256.push_back(b_golay_binary_128[i]);
	for (int i = 0; i < 128; i++)
		b_golay_binary_256.push_back(b_golay_binary_128_N[i]);//b256
	switch (Pre_mod)
	{
	case 0:
		{
			int Lpreb = 48 * 128 + 7 * 128 + (5 * 256);//ǰ������
			vector<int> sync;//ǰ��sync����
			for (int i = 0; i < 48; i++)
			{
				for (int j = 0; j < 128; j++)
					sync.push_back(b_golay_binary_128[j]);
			}
			vector<int> sfd;//ǰ��sfd����
			int seed[7] = {1, -1, 1, 1, -1, -1, -1};
			for (int i = 0; i < 7; i++)
			{
				if (seed[i] == 1)
				{
					for (int j = 0; j < 128; j++)
						sfd.push_back(b_golay_binary_128[j]);
				}
				else
				{
					for (int j = 0; j < 128; j++)
						sfd.push_back(b_golay_binary_128_N[j]);
				}
			}
			vector<int> ces;//ǰ��ces����
			for (int i = 0; i < 128; i++)
				ces.push_back(a_golay_binary_128[i]);
			for (int i = 0; i < 256; i++)
				ces.push_back(a_golay_binary_256[i]);
			for (int i = 0; i < 256; i++)
				ces.push_back(b_golay_binary_256[i]);
			for (int i = 0; i < 256; i++)
				ces.push_back(a_golay_binary_256[i]);
			for (int i = 0; i < 256; i++)
				ces.push_back(b_golay_binary_256[i]);
			for (int i = 0; i < 128; i++)
				ces.push_back(b_golay_binary_128[i]);
			vector<int> Preamble;//Preamble
			for (int i = 0; i < sync.size(); i++)
				Preamble.push_back(sync[i]);
			for (int i = 0; i < sfd.size(); i++)
				Preamble.push_back(sfd[i]);
			for (int i = 0; i < ces.size(); i++)
				Preamble.push_back(ces[i]);
			SC_tx_modulation(Preamble, vSC_Pre, 1);//��preamble���е���
			break;
		}
	case 1:
		{
			int Lpreb = 14 * 128 + 4 * 128 + (4 * 256 + 128);//ǰ������
			vector<int> sync;//ǰ��sync����
			for (int i = 0; i < 14; i++)
			{
				for (int j = 0; j < 128; j++)
					sync.push_back(a_golay_binary_128[j]);
			}
			vector<int> sfd;//ǰ��sfd����
			int seed[4] = {1, -1, 1, -1};
			for (int i = 0; i < 4; i++)
			{
				if (seed[i] == 1)
				{
					for (int j = 0; j < 128; j++)
						sfd.push_back(a_golay_binary_128[j]);
				}
				else
				{
					for (int j = 0; j < 128; j++)
						sfd.push_back(a_golay_binary_128_N[j]);
				}
			}
			vector<int> ces;//ǰ��ces����
			for (int i = 0; i < 256; i++)
				ces.push_back(a_golay_binary_256[i]);
			for (int i = 0; i < 256; i++)
				ces.push_back(b_golay_binary_256[i]);
			for (int i = 0; i < 256; i++)
				ces.push_back(a_golay_binary_256[i]);
			for (int i = 0; i < 256; i++)
				ces.push_back(b_golay_binary_256[i]);
			for (int i = 0; i < 128; i++)
				ces.push_back(b_golay_binary_128[i]);
			vector<int> Preamble;//Preamble
			for (int i = 0; i < sync.size(); i++)
				Preamble.push_back(sync[i]);
			for (int i = 0; i < sfd.size(); i++)
				Preamble.push_back(sfd[i]);
			for (int i = 0; i < ces.size(); i++)
				Preamble.push_back(ces[i]);
			/***************************��������*****************************/
			/*ofstream SC_MCS0_preamble("SC_MCS0_preamble.txt");
			for (int i = 0; i < Preamble.size(); ++i)
				SC_MCS0_preamble << Preamble[i] << endl;*/
			/**************************************************************/
			SC_tx_modulation(Preamble, vSC_Pre, 1);//��preamble���е���
			/***************************��������*****************************/
			/*ofstream SC_MCS0_preamble_mapped("SC_MCS0_preamble_mapped.txt");
			for (int i = 0; i < vSC_Pre.size(); ++i)
				SC_MCS0_preamble_mapped << vSC_Pre[i] << endl;*/
			/**************************************************************/
			break;
		}
	case 2:
		{
			int Lpreb = 14 * 128 + 4 * 128 + (4 * 256 + 128);//ǰ������
			vector<int> sync;//ǰ��sync����
			for (int i = 0; i < 14; i++)
			{
				for (int j = 0; j < 128; j++)
					sync.push_back(a_golay_binary_128[j]);
			}
			vector<int> sfd;//ǰ��sfd����
			int seed[4] = {1, 1, -1, -1};
			for (int i = 0; i < 4; i++)
			{
				if (seed[i] == 1)
				{
					for (int j = 0; j < 128; j++)
						sfd.push_back(a_golay_binary_128[j]);
				}
				else
				{
					for (int j = 0; j < 128; j++)
						sfd.push_back(a_golay_binary_128_N[j]);
				}
			}
			vector<int> ces;//ǰ��ces����
			for (int i = 0; i < 256; i++)
				ces.push_back(a_golay_binary_256[i]);
			for (int i = 0; i < 256; i++)
				ces.push_back(b_golay_binary_256[i]);
			for (int i = 0; i < 256; i++)
				ces.push_back(a_golay_binary_256[i]);
			for (int i = 0; i < 256; i++)
				ces.push_back(b_golay_binary_256[i]);
			for (int i = 0; i < 128; i++)
				ces.push_back(b_golay_binary_128[i]);
			vector<int> Preamble;//Preamble
			for (int i = 0; i < sync.size(); i++)
				Preamble.push_back(sync[i]);
			for (int i = 0; i < sfd.size(); i++)
				Preamble.push_back(sfd[i]);
			for (int i = 0; i < ces.size(); i++)
				Preamble.push_back(ces[i]);
			SC_tx_modulation(Preamble, vSC_Pre, 1);//��preamble���е���
			break;
		}
	default:
		{
			cout << "ǰ��ģʽ���󣡣�" << endl;
			break;
		}
	}
}