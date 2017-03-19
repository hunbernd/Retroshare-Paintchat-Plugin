#include <util/rsversioninfo.h>

#include "paintchatplugin.h"

#include "gui/paintchatpopupchatdialog.h"

#define IMAGE_PAINTCHAT ":/images/colors.png"

extern "C" {

    // This is *the* functions required by RS plugin system to give RS access to the plugin.
    // Be careful to:
    // - always respect the C linkage convention
    // - always return an object of type RsPlugin*
    //
    void *RETROSHARE_PLUGIN_provide()
    {
        static PaintChatPlugin *p = new PaintChatPlugin() ;

        return (void*)p ;
    }

    // This symbol contains the svn revision number grabbed from the executable.
    // It will be tested by RS to load the plugin automatically, since it is safe to load plugins
    // with same revision numbers, assuming that the revision numbers are up-to-date.
    //
	uint32_t RETROSHARE_PLUGIN_revision = RS_REVISION_NUMBER ;

    // This symbol contains the svn revision number grabbed from the executable.
    // It will be tested by RS to load the plugin automatically, since it is safe to load plugins
    // with same revision numbers, assuming that the revision numbers are up-to-date.
    //
    uint32_t RETROSHARE_PLUGIN_api = RS_PLUGIN_API_VERSION ;
}

PaintChatPlugin::PaintChatPlugin():mService(NULL), mIcon(NULL) {
    std::cerr<<"PaintChatPlugin::PaintChatPlugin()"<<std::endl;
}
PaintChatPlugin::~PaintChatPlugin(){
    std::cerr<<"PaintChatPlugin::~PaintChatPlugin()"<<std::endl;
}

std::string PaintChatPlugin::getShortPluginDescription()const{
    return std::string("this is the PaintChatPlugin");
}
std::string PaintChatPlugin::getPluginName()const{
    return std::string("PaintChat");
}
void PaintChatPlugin::getPluginVersion(int &major, int &minor, int &build, int &svn_rev)const{
	major = RS_MAJOR_VERSION;
	minor = RS_MINOR_VERSION;
	build = RS_BUILD_NUMBER;
	svn_rev = RS_REVISION_NUMBER;
}
void PaintChatPlugin::setInterfaces(RsPlugInInterfaces &interfaces){
	mIdentity = interfaces.mIdentity;
	mMsgs = interfaces.mMsgs;
}
void PaintChatPlugin::setPlugInHandler(RsPluginHandler *pgHandler){
    std::cerr<<"PaintChatPlugin::setPlugInHandler()"<<std::endl;
    mPlugInHandler = pgHandler;
}

RsPQIService *PaintChatPlugin::rs_pqi_service()const{
    std::cerr<<"PaintChatPlugin::rs_pqi_service()"<<std::endl;
    if(mService==NULL){
        std::cerr<<"PaintChatPlugin::rs_pqi_service(): creating new p3PaintChatService"<<std::endl;
        mService=new p3PaintChatService(mPlugInHandler);
        paintChatService=mService;
    }
    return mService;
}

ChatWidgetHolder *PaintChatPlugin::qt_get_chat_widget_holder(ChatWidget *chatWidget) const{
    switch (chatWidget->chatType()) {
    case ChatWidget::CHATTYPE_LOBBY:
		 return new PaintChatPopupChatDialog(chatWidget, mIdentity, mMsgs);
	case ChatWidget::CHATTYPE_PRIVATE:
    case ChatWidget::CHATTYPE_UNKNOWN:
    case ChatWidget::CHATTYPE_DISTANT:
        break;
    }
    return NULL;
}

QIcon *PaintChatPlugin::qt_icon() const
{
    if (mIcon == NULL) {
        Q_INIT_RESOURCE(paintchat_images);

        mIcon = new QIcon(IMAGE_PAINTCHAT);
    }

    return mIcon;
}
