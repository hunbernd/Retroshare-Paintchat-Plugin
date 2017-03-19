#ifndef PAINTCHATPLUGIN_H
#define PAINTCHATPLUGIN_H

#include <retroshare/rsplugin.h>
#include "services/paintchatitems.h"
#include "services/p3paintchatservice.h"
#include <retroshare/rsmsgs.h>
#include <retroshare/rsidentity.h>

class PaintChatPlugin : public RsPlugin
{
public:
    PaintChatPlugin();
    virtual ~PaintChatPlugin();

	virtual void getPluginVersion(int& major,int& minor, int& build, int& svn_rev) const ;
    virtual void setPlugInHandler(RsPluginHandler *pgHandler);


    virtual std::string getShortPluginDescription() const ;
    virtual std::string getPluginName() const;
    virtual void setInterfaces(RsPlugInInterfaces& interfaces);

    virtual RsPQIService   *rs_pqi_service() 			const	;
    virtual uint16_t        rs_service_id()         const { return RS_SERVICE_TYPE_PAINTCHAT_PLUGIN ; }

    virtual ChatWidgetHolder *qt_get_chat_widget_holder(ChatWidget *chatWidget) const;

    virtual QIcon *qt_icon() const;

private:
    RsPluginHandler *mPlugInHandler;
    // keine ahnung warum mutable
    mutable p3PaintChatService *mService;
    mutable QIcon *mIcon;
	RsMsgs *mMsgs;
	RsIdentity *mIdentity;
};

#endif // PAINTCHATPLUGIN_H
