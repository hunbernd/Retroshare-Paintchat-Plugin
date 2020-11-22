#ifndef PAINTCHATPLUGIN_H
#define PAINTCHATPLUGIN_H

#include <retroshare/rsplugin.h>

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
	virtual uint16_t        rs_service_id()         const { return 0x255 ; }

    virtual ChatWidgetHolder *qt_get_chat_widget_holder(ChatWidget *chatWidget) const;

    virtual QIcon *qt_icon() const;

private:
    RsPluginHandler *mPlugInHandler;
    // keine ahnung warum mutable
    mutable QIcon *mIcon;
};

#endif // PAINTCHATPLUGIN_H
