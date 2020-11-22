#ifndef PAINTCHATWINDOW_H
#define PAINTCHATWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <gui/chat/ChatWidget.h>

namespace Ui {
class PaintChatWindow;
}

class PaintChatWindow : public QMainWindow
{
    Q_OBJECT
    
public:
	explicit PaintChatWindow(QWidget *parent, ChatId chatId, ChatWidget *chatWidget);
    ~PaintChatWindow();

private slots:
    void on_haveUpdate();
    void on_timer();

    void on_pushButtonPrimaryColor_clicked();
    
    void on_pushButtonPen_clicked();

    void on_pushButtonWhite_clicked();

    void on_pushButton1px_clicked();

    void on_pushButton4px_clicked();

    void on_pushButton8px_clicked();

    void on_pushButtonClear_clicked();

    void on_pushButtonCopy_clicked();

    void on_pushButtonSend_clicked();

    void penChanged();

private:
    void updateImage();
    void resetPenButtons();
    void colorChanged();
	uint32_t maxMessageSize();
    
    QColor currentColor;
    Ui::PaintChatWindow *ui;
	ChatId chatId;
    ChatWidget::ChatType chatType;
    ChatWidget *chatWidget;
	int MAX_LOBBY_MSG_SIZE;

    QTimer *timer;
};

#endif // PAINTCHATWINDOW_H
