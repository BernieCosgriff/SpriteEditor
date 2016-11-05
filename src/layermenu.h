#ifndef LAYERMENU_H
#define LAYERMENU_H

#include <QWidget>
#include <QListView>
#include <QGroupBox>
#include <QIcon>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QWidget>
#include <QListWidget>
#include <vector>
#include <memory>
#include "frame.h"
#include "layer.h"
#include "animationwidgets.h"

class LayerWidget;

using namespace std;

class LayerMenu : public QWidget, public FrameWidget {
    Q_OBJECT
public:
    explicit LayerMenu(QWidget *parent, vector<unique_ptr<Frame>> *frames);

    void setCurrentFrame(int index);
    void addLayer(int index) override;
    void moveLayer(int from, int to) override;
    void removeLayer(int index) override;
    void setActiveLayer(int index) override;
    void addExistingLayer(int index);
    void clear();

    //These signals allow the LayerMenu to send information to the model
    //every time the ordering or number of layers in the LayerMenu is changed.
    //All information is given in terms of index numbers, with 0 representing
    //the bottom layer. A LayerMenu is initialized with one layer.
    //There is only one active layer at a time. It is highlighted and changes when
    //the user clicks in the QLineEdit text box containing the layer's name.
signals:
    void layerAddedSignal (int indexOfAddedLayer);
    void layersSwappedSignal (int indexOfLayer1, int indexOfLayer2);
    void layerDeletedSignal (int indexOfDeletedLayer);
    void activeLayerChangedSignal (int indexOfActiveLayer);

public slots:
    void updateLayer();
    void addLayerButtonClicked();
    void deleteLayerButtonClicked();
    void moveLayerUpButtonClicked();
    void moveLayerDownButtonClicked();
    void layerClicked();

private:
    int currentFrameNumber = 0;
    vector<unique_ptr<Frame>> *frames;
    QPushButton* addLayerButton;
    QPushButton* removeLayerButton;
    QPushButton* moveLayerUp;
    QPushButton* moveLayerDown;
    QVBoxLayout* layerMenuLayout;
    QHBoxLayout* layerButtons;
    QListWidget* list;

    QIcon deleteIcon = QIcon(QPixmap(":/icons/delete"));
    QIcon addIcon = QIcon(QPixmap(":/icons/add"));
};

#endif // LAYERMENU_H
