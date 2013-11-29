/*
-----------------------------------------------------------------------------
Filename:    TutorialApplication.h
-----------------------------------------------------------------------------

This source file is part of the
   ___                 __    __ _ _    _ 
  /___\__ _ _ __ ___  / / /\ \ (_) | _(_)
 //  // _` | '__/ _ \ \ \/  \/ / | |/ / |
/ \_// (_| | | |  __/  \  /\  /| |   <| |
\___/ \__, |_|  \___|   \/  \/ |_|_|\_\_|
      |___/                              
      Tutorial Framework
      http://www.ogre3d.org/tikiwiki/
-----------------------------------------------------------------------------
*/
#ifndef __TutorialApplication_h_
#define __TutorialApplication_h_

#include "BaseApplication.h"
#include "Hydrax.h"

class TutorialApplication : public BaseApplication
{
public:
    TutorialApplication(void);
    virtual ~TutorialApplication(void);
	virtual bool frameStarted(const Ogre::FrameEvent& evt);

protected:
    virtual void createScene(void);
private:
	Ogre::AnimationState* mAnimState;
	Ogre::ParticleSystem* smoke_particle; //��������
	bool bind_smoke_to_rocket; //����Ƿ���������ϵͳ

	Ogre::Entity* ent_rocket_;  //���
	Ogre::Entity* ent_earth_;  //����
	Ogre::Entity* ent_satelite_; //����
	Ogre::SceneNode* ent_node_earth_; //���ڵ����
	Ogre::SceneNode* ent_node_satelite_; //���ǽڵ�
	Ogre::SceneNode* ent_node_rocket_;  //����ڵ�

	//���� �л�����
	void ChangeScene(int time);

	ExampleHydraxDemoListener* mHydraxListener;

};

#endif // #ifndef __TutorialApplication_h_
