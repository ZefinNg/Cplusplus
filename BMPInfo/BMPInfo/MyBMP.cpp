#include "MyBMP.h"

MyBMP::MyBMP()
{
}

MyBMP::~MyBMP()
{
}

bool MyBMP::readFile(const string & filePath)
{
	FILE *fp = fopen(filePath.data(), "rb");
	if (fp == nullptr) {
		cout << filePath << " open failed." << endl;
		return false;
	}

	LPBITMAPFILEHEADER lpBmpFileHeader = new BITMAPFILEHEADER;
	LPBITMAPINFOHEADER lpBmpInfoHeader = new BITMAPINFOHEADER;

	fread(lpBmpFileHeader, sizeof(BITMAPFILEHEADER), 1, fp);
	fread(lpBmpInfoHeader, sizeof(BITMAPINFOHEADER), 1, fp);

	m_rows = lpBmpInfoHeader->biHeight;
	m_cols = lpBmpInfoHeader->biWidth;
	m_bitCount = lpBmpInfoHeader->biBitCount;

	cout << "ͼƬ���ƣ�" << filePath << endl;
	cout << "ͼƬ��ȣ�" << m_cols << endl;
	cout << "ͼƬ�߶ȣ�" << m_rows << endl;
	cout << "ͼƬɫ��λ����" << m_bitCount << endl;

	if (m_bitCount == 24) {
		cout << "24bit λͼ�������£�" << endl;
		fseek(fp, lpBmpFileHeader->bfOffBits, 0);
		//Windows ��λͼ�洢�Ŀ���ֽڴ�С������4�ı���
		int lineBytes = (m_cols * m_bitCount / 8 + 3) / 4 * 4;
		UCHAR *pDataTemp = new UCHAR[m_rows * lineBytes];

		fread(pDataTemp, sizeof(UCHAR), m_rows * lineBytes, fp);
		for (int i = 0; i < m_rows; i++) {
			for (int j = 0; j < m_cols; j++) {
				cout << "<" \
					<< (int)pDataTemp[i * lineBytes + j * 3 + 0] << "," \
					<< (int)pDataTemp[i * lineBytes + j * 3 + 1] << "," \
					<< (int)pDataTemp[i * lineBytes + j * 3 + 2] << "> \t";
			}
			cout << endl;
		}
		delete[]pDataTemp;
	}

	delete lpBmpFileHeader;
	delete lpBmpInfoHeader;

	lpBmpFileHeader = nullptr;
	lpBmpInfoHeader = nullptr;
	fclose(fp);

	return true;
}
