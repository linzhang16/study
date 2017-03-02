
// GetYFromBMPDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "GetYFromBMP.h"
#include "GetYFromBMPDlg.h"
#include "afxdialogex.h"
#include <stdio.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CGetYFromBMPDlg �Ի���



CGetYFromBMPDlg::CGetYFromBMPDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CGetYFromBMPDlg::IDD, pParent)
	, m_edit_path(_T(""))
	, m_edit_path_dst(_T(""))
	, m_sta_Y_length(_T(""))
	, m_sta_use_time(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGetYFromBMPDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_PATH, m_edit_path);
	DDX_Text(pDX, IDC_EDIT_PATH_DIR, m_edit_path_dst);
	DDX_Text(pDX, IDC_STATIC_Y_LENGTH, m_sta_Y_length);
	DDX_Text(pDX, IDC_STATIC_TIME, m_sta_use_time);
}

BEGIN_MESSAGE_MAP(CGetYFromBMPDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_SELECT, &CGetYFromBMPDlg::OnBnClickedButtonSelect)
	ON_BN_CLICKED(IDC_BUTTON_GET_Y, &CGetYFromBMPDlg::OnBnClickedButtonGetY)
	ON_BN_CLICKED(IDC_BUTTON_Y_BIN, &CGetYFromBMPDlg::OnBnClickedButtonYBin)
END_MESSAGE_MAP()


// CGetYFromBMPDlg ��Ϣ�������

BOOL CGetYFromBMPDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������
int i=0;
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CGetYFromBMPDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CGetYFromBMPDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CGetYFromBMPDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CGetYFromBMPDlg::OnBnClickedButtonSelect()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CFileDialog dlg(TRUE, TEXT("*.*"), NULL, OFN_HIDEREADONLY, TEXT("BMPͼƬ (*.bmp)|*.bmp|�����ļ�(*.*)|*.*|"));
	CString csFileName;
	if (dlg.DoModal() == IDOK)
	{
		csFileName = dlg.GetPathName();    //ѡ����ļ�·��   
		m_edit_path = csFileName;
		UpdateData(FALSE);
	}

}
unsigned int CGetYFromBMPDlg::GetimageYlen(char *path)
{
	BITMAPFILEHEADER bmpFileHeader;
	BITMAPINFOHEADER bmpInfoHeader;
	unsigned int     y_len;
	FILE           *fd;
	int           ret;
	

	if (fopen_s(&fd, path, "rb") != 0)
	{
		printf("Open file :%s err LINE:%d\n", path, __LINE__);
		return -1;
	}


	//read file head
	ret = fread((void *)&bmpFileHeader.bfType, sizeof(WORD), 1, fd);
	ret = fread((void *)&bmpFileHeader.bfSize, sizeof(DWORD), 1, fd);
	ret = fread((void *)&bmpFileHeader.bfReserved1, sizeof(WORD), 1, fd);
	ret = fread((void *)&bmpFileHeader.bfReserved2, sizeof(WORD), 1, fd);
	ret = fread((void *)&bmpFileHeader.bfOffBits, sizeof(DWORD), 1, fd);

	//information head
	ret = fread((void *)&bmpInfoHeader.biSize, sizeof(DWORD), 1, fd);
	ret = fread((void *)&bmpInfoHeader.biWidth, sizeof(LONG), 1, fd);
	ret = fread((void *)&bmpInfoHeader.biHeight, sizeof(LONG), 1, fd);
	ret = fread((void *)&bmpInfoHeader.biPlanes, sizeof(WORD), 1, fd);
	ret = fread((void *)&bmpInfoHeader.biBitCount, sizeof(WORD), 1, fd);
	ret = fread((void *)&bmpInfoHeader.biCompression, sizeof(DWORD), 1, fd);
	ret = fread((void *)&bmpInfoHeader.biSizeImage, sizeof(DWORD), 1, fd);
	ret = fread((void *)&bmpInfoHeader.biXPelsPerMeter, sizeof(LONG), 1, fd);
	ret = fread((void *)&bmpInfoHeader.biYPelsPerMeter, sizeof(LONG), 1, fd);
	ret = fread((void *)&bmpInfoHeader.biClrUsed, sizeof(DWORD), 1, fd);
	ret = fread((void *)&bmpInfoHeader.biClrImportant, sizeof(DWORD), 1, fd);

	if (ret < 1)
	{
		printf("*** ERROR : Failed in reading!! LINE:%d\n", __LINE__);
		fclose(fd);
		return -1;
	}
	fclose(fd);
	y_len = bmpInfoHeader.biWidth*bmpInfoHeader.biHeight;
	return y_len;
}
/*******************************************************************************
* Function Name  : readBMP
* Description    : read bmp picture
* Input          : path: picture path
*                  yuv:  storing address
* Output         : none
*
* Return         : none
*******************************************************************************/
int CGetYFromBMPDlg::readimage(char *path, unsigned char *yuv)
{
	BITMAPFILEHEADER bmpFileHeader;
	BITMAPINFOHEADER bmpInfoHeader;
	unsigned int     buffer_size;
	unsigned long	bit_offset;

	FILE           *fd;
	size_t           ret;
	unsigned char *fptr;

	int           x, y;
	int           width;
	unsigned char *yuv888;

	float   Y, Cb, Cr, R, G, B;


	if (fopen_s(&fd, path, "rb") != 0)
	{
		printf("Open file :%s err LINE:%d\n", path, __LINE__);
		return -1;
	}


	//read file head
	ret = fread((void *)&bmpFileHeader.bfType, sizeof(WORD), 1, fd);
	ret = fread((void *)&bmpFileHeader.bfSize, sizeof(DWORD), 1, fd);
	ret = fread((void *)&bmpFileHeader.bfReserved1, sizeof(WORD), 1, fd);
	ret = fread((void *)&bmpFileHeader.bfReserved2, sizeof(WORD), 1, fd);
	ret = fread((void *)&bmpFileHeader.bfOffBits, sizeof(DWORD), 1, fd);

	//information head
	ret = fread((void *)&bmpInfoHeader.biSize, sizeof(DWORD), 1, fd);
	ret = fread((void *)&bmpInfoHeader.biWidth, sizeof(LONG), 1, fd);
	ret = fread((void *)&bmpInfoHeader.biHeight, sizeof(LONG), 1, fd);
	ret = fread((void *)&bmpInfoHeader.biPlanes, sizeof(WORD), 1, fd);
	ret = fread((void *)&bmpInfoHeader.biBitCount, sizeof(WORD), 1, fd);
	ret = fread((void *)&bmpInfoHeader.biCompression, sizeof(DWORD), 1, fd);
	ret = fread((void *)&bmpInfoHeader.biSizeImage, sizeof(DWORD), 1, fd);
	ret = fread((void *)&bmpInfoHeader.biXPelsPerMeter, sizeof(LONG), 1, fd);
	ret = fread((void *)&bmpInfoHeader.biYPelsPerMeter, sizeof(LONG), 1, fd);
	ret = fread((void *)&bmpInfoHeader.biClrUsed, sizeof(DWORD), 1, fd);
	ret = fread((void *)&bmpInfoHeader.biClrImportant, sizeof(DWORD), 1, fd);

	if (ret < 1)
	{
		printf("*** ERROR : Failed in reading!! LINE:%d\n", __LINE__);
		fclose(fd);
		return -1;
	}

	bit_offset = bmpFileHeader.bfOffBits;
	buffer_size = bmpInfoHeader.biWidth * bmpInfoHeader.biHeight*bmpInfoHeader.biBitCount/8;
	if (buffer_size < 3)
	{
		printf("*** ERROR : buffer_size!! LINE:%d\n", __LINE__);
		return -1;
	}


	fptr = (unsigned char *)malloc(buffer_size);
	if (fptr == NULL)
	{
		printf("*** ERROR : malloc!! LINE:%d\n", __LINE__);
		return -1;
	}

	//bitmap head
	ret = fread((void *)fptr, sizeof(unsigned char), buffer_size, fd);
	if (ret < buffer_size)
	{
		printf("*** ERROR : Failed in reading!! LINE:%d\n", __LINE__);
		return -1;
	}


	fclose(fd);
	yuv888 = (unsigned char *)malloc(buffer_size);
	if (yuv888 == NULL)
	{
		printf("*** ERROR : malloc!! LINE:%d\n", __LINE__);
		return -1;
	}
	width = bmpInfoHeader.biWidth;
	for (y = 0; y < bmpInfoHeader.biHeight - 2; y++)
	{
		for (x = 4; x < bmpInfoHeader.biWidth - 3; x++)
		{
			R = (float)fptr[(bmpInfoHeader.biHeight - y - 1) * bmpInfoHeader.biWidth * 3 + x * 3 + 0]; //R
			B = (float)fptr[(bmpInfoHeader.biHeight - y - 1) * bmpInfoHeader.biWidth * 3 + x * 3 + 1]; //B
			G = (float)fptr[(bmpInfoHeader.biHeight - y - 1) * bmpInfoHeader.biWidth * 3 + x * 3 + 2]; //G
			if (R == 255 && G == 255 && B == 255)
			{
				ret = 0;
			}

	//		Y = (float)((R + G + B) / 3);
			Y = 0.2568 * R + 0.5014 * G + 0.0979 * B;
			Cb = (float)(0.1482 * (B - R) + 0.2910 * (B - G) + 128);
			Cr = (float)(0.3678 * (R - G) - 0.0714 * (B - R) + 128);
			
			
			/*Y = 0.257*R + 0.504*G + 0.098*B + 16;
			Cb = -0.148*R - 0.291*G + 0.439*B + 128;
			Cr= 0.439*R - 0.368*G - 0.071*B + 128;*/

			/*R = Y + 1.37 * (Cr - 128);
			G = Y - 0.698 * (Cr - 128) - 0.336 * (Cb - 128);
			B = Y + 1.73 * (Cb - 128);
			*/
			yuv888[y * width * 3 + x * 3 + 0] = (unsigned char)Y;
			yuv888[y * width * 3 + x * 3 + 1] = (unsigned char)Cb;
			yuv888[y * width * 3 + x * 3 + 2] = (unsigned char)Cr;

		}
	}

	//convert to yuv separate
	for (y = 0; y < bmpInfoHeader.biHeight - 2; y++)
	{
		for (x = 4; x < bmpInfoHeader.biWidth - 3; x++)
		{
			yuv[y * width + x + 0] = yuv888[y * width * 3 + x * 3 + 0];

			if (x % 2 == 0)
			{
				yuv[bmpInfoHeader.biHeight * width + y * width + x + 0] = yuv888[y * width * 3 + x * 3 + 1]; //cb
			}
			else
			{
				yuv[bmpInfoHeader.biHeight * width + y * width + x + 0] = yuv888[y * width * 3 + x * 3 + 2]; //cb
			}

		}
	}

	free(fptr);
	free(yuv888);
	return 0;
}

void CGetYFromBMPDlg::OnBnClickedButtonGetY()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	long t1 = GetTickCount();//����ο�ʼǰȡ��ϵͳ����ʱ��(ms)
	USES_CONVERSION;
	unsigned char *p_Y_value = NULL;
	unsigned int y_len = 0;
	size_t ret = 0;
	char *szTemp = NULL;
	FILE *fd;

	szTemp = T2A(m_edit_path);
	OutputDebugString((LPCWSTR)szTemp);
	y_len = GetimageYlen(szTemp);

	p_Y_value = (unsigned char *)malloc(y_len*3);
	if (p_Y_value == NULL)
	{
		printf("*** ERROR : malloc!! LINE:%d\n", __LINE__);
		return;
	}
	memset(p_Y_value, 0, y_len*3);
	ret = readimage(szTemp, p_Y_value);
	if (ret < 0)
	{
		printf("*** ERROR :readimage!! LINE:%d\n", __LINE__);
		free(p_Y_value);
		return;
	}

	m_edit_path_dst = GetAppPath();
	m_edit_path_dst += TEXT("YDATA");
	
	szTemp = T2A(m_edit_path_dst);
	if (fopen_s(&fd, szTemp, "wb") != 0)
	{
		printf("Open \"YDATA\" file err LINE:%d\n", __LINE__);
		free(p_Y_value);
		return;
	}
	ret = fwrite(p_Y_value, sizeof(unsigned char), y_len, fd);
	
	if (ret < y_len)
	{
		printf("write file err LINE:%d\n", __LINE__);
		fclose(fd);
		free(p_Y_value);
		return;
	}
	fclose(fd);
	if (p_Y_value != NULL)
	{
		free(p_Y_value);
	}
	m_sta_Y_length.Format(TEXT("%d"), y_len);

	long t2 = GetTickCount();//����ν�����ȡ��ϵͳ����ʱ��(ms)
	m_sta_use_time.Format(TEXT("%d ms"), t2 - t1);//ǰ��֮� ��������ʱ��
	UpdateData(FALSE);
}

CString CGetYFromBMPDlg::GetAppPath() 
{
	CString strAppPath;  // ������
	TCHAR szModuleFileName[MAX_PATH]; // ȫ·����
	TCHAR drive[_MAX_DRIVE];  // �̷����ƣ�����˵C�̰���D�̰�
	TCHAR dir[_MAX_DIR]; // Ŀ¼
	TCHAR fname[_MAX_FNAME];  // ��������
	TCHAR ext[_MAX_EXT]; //��׺��һ��Ϊexe������dll
	if (NULL == GetModuleFileName(NULL, szModuleFileName, MAX_PATH)) //��õ�ǰ���̵��ļ�·��
		return FALSE;
	_tsplitpath_s(szModuleFileName, drive, dir, fname, ext);  //�ָ��·�����õ��̷���Ŀ¼���ļ�������׺��
	strAppPath = drive;
	strAppPath += dir;
	return strAppPath;
}

#define CONVER_10_TO_16            "0x%02x,"
void CGetYFromBMPDlg::OnBnClickedButtonYBin()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	unsigned char *p_Y_value = NULL;
	LPCTSTR pfilename = (LPCTSTR)m_edit_path_dst;
	CFile file(pfilename, CFile::modeRead);
	ULONGLONG filelen = file.GetLength();
	ULONGLONG i = 0, linenum = 0, useline = 0;

	p_Y_value = (unsigned char *)malloc((size_t)filelen);
	if (p_Y_value == NULL)
	{
		printf("*** ERROR : malloc!! LINE:%d\n", __LINE__);
		return;
	}
	memset(p_Y_value, 0, (size_t)filelen);

	file.Read((void*)p_Y_value, (UINT)filelen);

	file.Close();

	CString m_str_bin_path_dst = GetAppPath();
	m_str_bin_path_dst += TEXT("YDATA.c");
	pfilename = (LPCTSTR)m_str_bin_path_dst;

	CFile fileBIN(pfilename, CFile::modeCreate | CFile::modeWrite);
	int itemp = 0;
	char tempstr[6];
	unsigned char *ptempfile = NULL;

	char *para_name = "Y_value = {\r\n";
	char *para_end_f = "};";
	int para_len = (int)strlen(para_name);
	int para_end_f_len = (int)strlen(para_end_f);

	linenum = filelen / 16 + 1;
	ptempfile = (unsigned char *)malloc((size_t)(filelen*(sizeof(tempstr)-1) + linenum * 2 + para_len + para_end_f_len));
	if (ptempfile == NULL)
	{
		printf("*** ERROR : malloc!! LINE:%d\n", __LINE__);
		return;
	}
	memset(ptempfile, 0, (size_t)(filelen*(sizeof(tempstr)-1) + linenum * 2 + para_len + para_end_f_len));
	memset(tempstr, 0, sizeof(tempstr));

	memcpy(ptempfile, para_name, (size_t)para_len);
	ptempfile += para_len;

	for (i = 0; i < filelen; i++)
	{
		memset(tempstr, 0, sizeof(tempstr));
		if (p_Y_value[i] == 255)
		{
			itemp = 0;
		}
		sprintf_s(tempstr, sizeof(tempstr), CONVER_10_TO_16, p_Y_value[i]);
		memcpy(ptempfile, tempstr, (sizeof(tempstr)-1));
		ptempfile += (sizeof(tempstr)-1);
		if ((i+1)%16 == 0)
		{
			memcpy(ptempfile, "\r\n", 2);
			ptempfile += 2;
			useline++;
		}
	}
	memcpy(ptempfile, para_end_f, (size_t)para_end_f_len);
	ptempfile += para_end_f_len;

	 
	ptempfile -= filelen*(sizeof(tempstr)-1) + useline * 2 + para_len + para_end_f_len;
	fileBIN.Write((void*)ptempfile, (UINT)(filelen*(sizeof(tempstr)-1) + useline * 2 + para_len + para_end_f_len));

	fileBIN.Close();
	if (p_Y_value != NULL)
	{
		free(p_Y_value);
	}
	if (ptempfile != NULL)
	{
		free(ptempfile);
	}
	MessageBox(pfilename, TEXT("�����ļ�OK��·����"), MB_OK);
}
