#include <cassert>
#include "MyGUISystem.h"

//-----------------------------------------------------------------------------  
MyGUISystem* MyGUISystem::ms_singleton = NULL;  
//-----------------------------------------------------------------------------  
MyGUISystem::~MyGUISystem()  
{  
    destroy();  
}  
//-----------------------------------------------------------------------------  
bool MyGUISystem::destroy()  
{  
    CEGUI::OgreRenderer::destroySystem();  
    delete ms_singleton;  
    ms_singleton = 0;  
    return true;  
}  
//-----------------------------------------------------------------------------  
CEGUI::MouseButton MyGUISystem::convertButton(OIS::MouseButtonID buttonId)  
{  
    switch(buttonId)  
    {  
    case OIS::MB_Left:  
        return CEGUI::LeftButton;  
    case OIS::MB_Right:  
        return CEGUI::RightButton;  
    case OIS::MB_Middle:  
        return CEGUI::MiddleButton;  
    default:  
        return CEGUI::LeftButton;  
    }  
}  

//-----------------------------------------------------------------------------  
bool MyGUISystem::init()  
{  
    if(!mGUIRender)  
    { 	
	    mGUIRender = &CEGUI::OgreRenderer::bootstrapSystem();  
		mGUISystem = CEGUI::System::getSingletonPtr();  
        //����GUI���⣬ ����Ĭ�ϲ���  
        CEGUI::Imageset::setDefaultResourceGroup("Imagesets");  
        CEGUI::Font::setDefaultResourceGroup("Fonts");  
        CEGUI::Scheme::setDefaultResourceGroup("Schemes");  
        CEGUI::WidgetLookManager::setDefaultResourceGroup("LookNFeel");  
        CEGUI::WindowManager::setDefaultResourceGroup("Layouts");  
        CEGUI::SchemeManager::getSingleton().create("TaharezLook.scheme");  
		CEGUI::SchemeManager::getSingleton().create("VanillaSkin.scheme"); 
		CEGUI::SchemeManager::getSingleton().create("OgreTray.scheme");
        CEGUI::FontManager::getSingleton().create("SimHei-14.font");  
        mGUISystem->setDefaultFont("SimHei-14");  
        /* 
         *  �˴�����ͼƬ��Դ(Imageset) 
         */  
        //����Ĭ�������ʽ  
        setDefaultMouseCursor("TaharezLook", "MouseArrow");  
        //����GUI����Ƿ�ɼ�  
        showGUICursor(true);  
        return true;  
    }  
    return false;  
}  
//-----------------------------------------------------------------------------  
void MyGUISystem::update(float timeSinceLastFrame)  
{  
    mGUISystem->injectTimePulse(timeSinceLastFrame);  
}  
//-----------------------------------------------------------------------------  
void MyGUISystem::createImageset(const std::string& name, const std::string& filename)  
{  
    CEGUI::ImagesetManager::getSingleton().createFromImageFile(name, filename);  
}  
//-----------------------------------------------------------------------------  
bool MyGUISystem::loadLayout(const std::string& layoutName)  
{  
    CEGUI::Window *guiSheet;  
    // ������layout���ļ��Ƿ����,û�м��������  
    if(!getGUIWindowManager()->isWindowPresent(layoutName))  
    {  
        // �� .layout�ű��ļ���ȡһ��UI������ƣ���������õ�GUI��Դ���С�  
        guiSheet = getGUIWindowManager()->loadWindowLayout(layoutName + ".layout");  
    }  
    else  
    {     
        // ����Ѿ�������ֱ����ʾ  
        guiSheet = getGUIWindowManager()->getWindow(layoutName);  
    }  
    // ���������Ǹ���CEGUI��ʾ�ķ�UI���֡���Ȼ���ǿ�����ʱ������ʾ��UI���֡�  
    mGUISystem->setGUISheet(guiSheet);  
    //��ʾUI����  
    guiSheet->show();  
    return true;  
}  
//-----------------------------------------------------------------------------  
bool MyGUISystem::destroyWindow(const std::string& windowName)  
{  
    getGUIWindowManager()->destroyWindow(windowName);  
    return true;  
}  
//-----------------------------------------------------------------------------  
void MyGUISystem::subscribeEvent(const CEGUI::String& windowName,  
    const CEGUI::String &eventName, const CEGUI::Event::Subscriber &subscriber)  
{  
    CEGUI::WindowManager::getSingleton().getWindow(CEGUI::String(windowName))  
        ->subscribeEvent(eventName,subscriber);  
}  
//-----------------------------------------------------------------------------  
void MyGUISystem::setProperty(const std::string& windowName,   
    const std::string& key, const std::string& value)  
{  
    MyGUISystem::getSingletonPtr()->getWindow(windowName)->setProperty(key, value);  
}  
//-----------------------------------------------------------------------------  
