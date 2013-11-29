#ifndef _SATELLITE_H
#define _SATELLITE_H


//��ʼ�����ǵ�λ�õ�
void SetParameter(double near = 318.55 + 300/2.0,double far = 800.0);

//ÿһ֡Ҫ���õĺ���
void OnEnterFrame();

//���������ǵ�һЩ������������һЩ����
//Ϊ�˼�㣬���ǽ�����Ϊһ����̬��
//ÿ�γ�������ֻ��1������
//һЩȫ�ֵ�״̬��ϢҲ��������У����統ǰ���ӽ�
class SatelliteStatus
{
public:
	enum ViewPort{
		IN_ATMOSPHERE, //�ڴ�������
		OUTER_SPACE, //��̫��,������ǽ��������������-2000,2000,0����� look At 0��0��0
		ABOVE_NORTH_POLE, //�����Ͽգ����ǽ�������������� 0,0,2000����㣬look At 0,0,0
		FREE_VIEW  //�ü��̺����������
	};  //��ǰ���ӽ�
	static ViewPort current_view_port;  //��ǰ�ӽǣ�Ĭ��ΪFREE_VIEW
	static float near_radius;  //���ع���뾶
	static float far_radius;   //Զ�ع���뾶
	enum Status{  //���ǵ�״̬
		UNLAUNCHED, //δ����
		RISING,  //������
		NEAR_TRACK, //���ع��
		ECLLIPSE, //��Բ���
		FAR_TRACK, //Զ�ع��
		OUT_CONTROL //ʧ��,�������ʱ�����ʵ����
	};
	static Status current_status; //Ĭ��ΪUNLAUNCHED
	static bool show_track;  //�Ƿ���ʾ���ǵĹ����Ĭ��Ϊfalse
	//���ǵ�����
	static float satellite_x;
	static float satellite_y;
	static float satellite_z;
	//���ǵ���ת�Ƕȣ�Y�� Z X���ֶ�����
	static float satellite_angle;
	//�������ٶ�
	static float satellite_lv;
	//���ǽ��ٶ�
	static float satellite_wv;
	//�����߼��ٶ�
	static float satellite_a; 
};

#endif