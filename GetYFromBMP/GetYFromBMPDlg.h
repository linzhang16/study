
// GetYFromBMPDlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// CGetYFromBMPDlg 对话框
class CGetYFromBMPDlg : public CDialogEx
{
// 构造
public:
	CGetYFromBMPDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_GETYFROMBMP_DIALOG };

public:
	unsigned int GetimageYlen(char *path);
	int readimage(char *path, unsigned char *yuv);
	CString GetAppPath(void);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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
