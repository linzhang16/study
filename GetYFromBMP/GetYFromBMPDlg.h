
// GetYFromBMPDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CGetYFromBMPDlg �Ի���
class CGetYFromBMPDlg : public CDialogEx
{
// ����
public:
	CGetYFromBMPDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_GETYFROMBMP_DIALOG };

public:
	unsigned int GetimageYlen(char *path);
	int readimage(char *path, unsigned char *yuv);
	CString GetAppPath(void);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonSelect();
	CString m_edit_path;
	afx_msg void OnBnClickedButtonGetY();
	CString m_edit_path_dst;
	CString m_sta_Y_length;
	CString m_sta_use_time;
	afx_msg void OnBnClickedButtonYBin();
};
