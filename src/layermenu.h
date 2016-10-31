#ifndef LAYERMENU_H
#define LAYERMENU_H

#include <QPoint>
#include <QWidget>
#include <QListView>
#include <QPushButton>
#include <QStringListModel>
#include <QVBoxLayout>
#include <iostream>
#include <QLineEdit>
#include <QGroupBox>
#include <QIcon>

class LayerMenu : public QWidget {
    Q_OBJECT
public:
    explicit LayerMenu(QWidget *parent = 0);

    //These signals allow the LayerMenu to send information to the model
    //every time the ordering or number of layers in the LayerMenu is changed.
    //All information is given in terms of index numbers, with 0 representing
    //the bottom layer. And index of -1 indicates that no layers exist in the LayerMenu
    //(because the last one has been deleted). A LayerMenu is initialized with one layer.
    //There is only one active layer at a time. It is highlighted and changes when
    //the user clicks in the QLineEdit text box containing the layer's name.
signals:
    void layerAddedSignal (int indexOfAddedLayer);
    void layersSwappedSignal (int indexOfLayer1, int indexOfLayer2);
    void layerDeletedSignal (int indexOfDeletedLayer);

    //If there is no active layer (because all layers have been deleted)
    //then a -1 is emitted.
    void activeLayerChangedSignal (int indexOfActiveLayer);

public slots:
    void addLayerButtonClicked();
    void deleteLayerButtonClicked();
    void textChanged();
    void moveLayerUpButtonClicked();
    void moveLayerDownButtonClicked();
    void activeLayerChanged();

protected:

private:
    QIcon upArrow = QIcon(QPixmap(":/icons/up"));
    QIcon downArrow = QIcon(QPixmap(":/icons/down"));
    QIcon deleteX = QIcon(QPixmap(":/icons/delete"));
    QVector<QGroupBox*> layers;
    QVector<QString> layerNames;
    QPushButton* addLayerButton;
    QVBoxLayout* layerMenuLayout;
    int indexOfActiveLayer;


    void deleteLayer(QGroupBox* layerToBeDeleted);
    void addLayer(QString layerName);
    void highlightGroupBox(QGroupBox*);
    void unhighlightGroupBox(QGroupBox*);
};

#endif // LAYERMENU_H
