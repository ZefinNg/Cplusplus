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

	cout << "图片名称：" << filePath << endl;
	cout << "图片宽度：" << m_cols << endl;
	cout << "图片高度：" << m_rows << endl;
	cout << "图片色素位数：" << m_bitCount << endl;

	if (m_bitCount == 24) {
		cout << "24bit 位图数据如下：" << endl;
		fseek(fp, lpBmpFileHeader->bfOffBits, 0);
		//Windows 下位图存储的宽度字节大小必须是4的倍数
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
