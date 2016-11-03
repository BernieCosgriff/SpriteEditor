#ifndef KEYBINDINGDIALOG_H
#define KEYBINDINGDIALOG_H

#include <QDialog>

namespace Ui {
class KeyBindingDialog;
}

class KeyBindingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit KeyBindingDialog(QWidget *parent = 0);
    ~KeyBindingDialog();

signals:
    void colorSignal(const QKeySequence&);
    void eraserSignal(const QKeySequence&);
    void lineSignal(const QKeySequence&);
    void addFrameSignal(const QKeySequence&);
    void addLayerSignal(const QKeySequence&);
    void frameRightSignal(const QKeySequence&);
    void layerUpSignal(const QKeySequence&);
    void removeFrameSignal(const QKeySequence&);
    void removeLayerSignal(const QKeySequence&);
    void brushSignal(const QKeySequence&);
    void fillSignal(const QKeySequence&);
    void selectSignal(const QKeySequence&);
    void circleSignal(const QKeySequence&);
    void squareSignal(const QKeySequence&);
    void frameLeftSignal(const QKeySequence&);
    void layerDownSignal(const QKeySequence&);

private slots:

private:
    Ui::KeyBindingDialog *ui;

    QKeySequence colorKey;
    QKeySequence eraserKey;
    QKeySequence lineKey;
    QKeySequence addFrameKey;
    QKeySequence addLayerKey;
    QKeySequence nextFrameKey;
    QKeySequence nextLayerKey;
    QKeySequence removeFrameKey;
    QKeySequence removeLayerKey;
    QKeySequence brushKey;
    QKeySequence fillKey;
    QKeySequence selectKey;
    QKeySequence circleKey;
    QKeySequence squareKey;
    QKeySequence previousFrameKey;
    QKeySequence previousLayerKey;

    void initWidgets();
    void initConnections();

public:
    void colorChanged();
    void eraserChanged();
    void lineChanged();
    void addFrameChanged();
    void addLayerChanged();
    void frameRightChanged();
    void layerUpChanged();
    void removeFrameChanged();
    void removeLayerChanged();
    void brushChanged();
    void fillChanged();
    void selectChanged();
    void circleChanged();
    void squareChanged();
    void frameLeftChanged();
    void layerDownChanged();

};

#endif // KEYBINDINGDIALOG_H
