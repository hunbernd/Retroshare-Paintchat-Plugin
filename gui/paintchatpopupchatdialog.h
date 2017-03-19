#ifndef PAINTCHATPOPUPCHATDIALOG_H
#define PAINTCHATPOPUPCHATDIALOG_H

#include <gui/chat/ChatWidget.h>
#include <QToolButton>
#include "paintchatwindow.h"
#include <retroshare/rsmsgs.h>
#include <retroshare/rsidentity.h>

class PaintChatPopupChatDialog : public QObject, public ChatWidgetHolder
{
    Q_OBJECT
public:
	PaintChatPopupChatDialog(ChatWidget *chatWidget, RsIdentity *identity, RsMsgs *msgs);

private slots:
    void togglePaintChatWindow();

protected:

private:
    QToolButton *paintChatWindowToggleButton;
    PaintChatWindow *paintChatWindow;
};

#endif // PAINTCHATPOPUPCHATDIALOG_H
