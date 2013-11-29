#pragma once


#include <Windows.h>
#include <mmsystem.h>
#include <d3dx9.h>
class MyD3DEngine;
class CCamera
{
public:
	CCamera();
	virtual ~CCamera();

	D3DXVECTOR3 GetEyePosition();

	/** ���������Ӿ�������Ĳ���
	*/
	void SetViewParams( D3DXVECTOR3 &pos, D3DXVECTOR3 &lookat, D3DXVECTOR3 &up );
	/** ��������͸��ͶӰ��������Ĳ���
	*/
	void SetProjParams( float fFOV, float fAspect, float fNear, float fFar  );
	/** ����������ƽ��ͶӰ��������Ĳ���
	*/
	void SetOrthoProjParams( float w, float h, float fNear, float fFar );
	/** ���ص�ǰ���Ӿ���
	*/
	const D3DXMATRIX *GetViewTrans() const;
	/** ���ص�ǰ��ͶӰ����
	*/
	const D3DXMATRIX *GetProjTrans() const;

	/** ����������ƶ��ٶ�
	*/
	void SetMoveVelocity( float fVelocity );

	/** ����Ϣѭ���ﴦ����Ϣ
	*/
	virtual LRESULT HandleMessage(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	/**  ���߼�֡���洦����Ϣ
	*/
	//virtual void ProcessKey(float fElapsedTime);

	/** �������������
		@remarks
		ͨ�����߼�֡������ô˺����������ڲ����Զ��ж���Ҫ������Щ���ԡ�
	*/
	virtual void	Update();
	/** ���Ӿ����ͶӰ�������ø�D3D�豸
	*/
	void	ApplyDevice( LPDIRECT3DDEVICE9  pDevice );

	D3DXVECTOR3& getEyePos()
	{
		return m_EyePos;
	}

	D3DXVECTOR3& getLookAtPos()
	{
		return m_LookAt;
	}

	D3DXVECTOR3& getUpPos()
	{
		return m_Up;
	}


public:
	/// �Ӿ���
	D3DXMATRIX	m_ViewTrans;
	/// ͶӰ����
	D3DXMATRIX	m_ProjTrans;

	/// �����λ��
	D3DXVECTOR3 m_EyePos;
	/// ������Ĺ۲��
	D3DXVECTOR3 m_LookAt;
	/// �������UP����
	D3DXVECTOR3 m_Up;
	/// �������RIGHT����
	D3DXVECTOR3 m_Right;
	/// ������ķ���
	D3DXVECTOR3 m_Direction;

	/// ���ӱ���ľ���
	float		m_fNear;
	/// Զ�ӱ���ľ���
	float		m_fFar;
	/// �ӽǣ�����
	float		m_fFOV;
	/// �����
	float		m_fAspect;

	/// ��һ�����λ��
	POINT		m_LastPoint;
	/// �û��Ƿ���ת�������
	bool		m_bIsRot;
	/// �û��Ƿ�ƽ���������
	bool		m_bIsTrans;

	/// �������ʼ״̬��ŷ����Yaw����SetViewParamsʱ��ʼ��
	float		m_fCameraYawAngle;		
	/// �������ʼ״̬��ŷ����Pitch����SetViewParamsʱ��ʼ��
	float		m_fCameraPitchAngle;

	/// �������ƽ����
	D3DXVECTOR3	m_vDelta;
	/// ��������ƶ��ٶȣ���λ/��
	float		m_fVelocity;

	/// ��������������ֵ
	float m_fMaxPitch;
	/// �������������Сֵ
	float m_fMinPitch;

	//�������ĵ�ǰ����
	POINT ptCurrentPos;

};